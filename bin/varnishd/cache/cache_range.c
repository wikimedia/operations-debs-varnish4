/*-
 * Copyright (c) 2006 Verdens Gang AS
 * Copyright (c) 2006-2015 Varnish Software AS
 * All rights reserved.
 *
 * Author: Poul-Henning Kamp <phk@phk.freebsd.dk>
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL AUTHOR OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 */

#include "config.h"

#include "cache_varnishd.h"
#include "cache_filter.h"

#include "vct.h"
#include <vtim.h>

/*--------------------------------------------------------------------*/

struct vrg_priv {
	unsigned		magic;
#define VRG_PRIV_MAGIC		0xb886e711
	ssize_t			range_low;
	ssize_t			range_high;
	ssize_t			range_off;
};

static int v_matchproto_(vdp_fini_f)
vrg_range_fini(struct req *req, void **priv)
{
	struct vrg_priv *vrg_priv;

	CHECK_OBJ_NOTNULL(req, REQ_MAGIC);
	CAST_OBJ_NOTNULL(vrg_priv, *priv, VRG_PRIV_MAGIC);
	if (vrg_priv->range_off < vrg_priv->range_high)
		Req_Fail(req, SC_RANGE_SHORT);
	*priv = NULL;	/* struct on ws, no need to free */
	return (0);
}

static int v_matchproto_(vdp_bytes_f)
vrg_range_bytes(struct req *req, enum vdp_action act, void **priv,
    const void *ptr, ssize_t len)
{
	int retval = 0;
	ssize_t l;
	const char *p = ptr;
	struct vrg_priv *vrg_priv;

	CHECK_OBJ_NOTNULL(req, REQ_MAGIC);
	CAST_OBJ_NOTNULL(vrg_priv, *priv, VRG_PRIV_MAGIC);

	l = vrg_priv->range_low - vrg_priv->range_off;
	if (l > 0) {
		if (l > len)
			l = len;
		vrg_priv->range_off += l;
		p += l;
		len -= l;
	}
	l = vrg_priv->range_high - vrg_priv->range_off;
	if (l > len)
		l = len;
	if (l > 0)
		retval = VDP_bytes(req, act, p, l);
	else if (act > VDP_NULL)
		retval = VDP_bytes(req, act, p, 0);
	vrg_priv->range_off += len;
	return (retval ||
	    vrg_priv->range_off >= vrg_priv->range_high ? 1 : 0);
}

/*--------------------------------------------------------------------*/

static const char *
vrg_dorange(struct req *req, const char *r, void **priv)
{
	ssize_t low, high, has_low, has_high, t;
	struct vrg_priv *vrg_priv;

	if (strncasecmp(r, "bytes=", 6))
		return ("Not Bytes");
	r += 6;

	/* The low end of range */
	has_low = low = 0;
	while (vct_isdigit(*r)) {
		has_low = 1;
		t = low;
		low *= 10;
		low += *r++ - '0';
		if (low < t)
			return ("Low number too big");
	}

	if (*r++ != '-')
		return ("Missing hyphen");

	/* The high end of range */
	has_high = high = 0;
	while (vct_isdigit(*r)) {
		has_high = 1;
		t = high;
		high *= 10;
		high += *r++ - '0';
		if (high < t)
			return ("High number too big");
	}

	if (*r != '\0')
		return ("Trailing stuff");

	if (has_high + has_low == 0)
		return ("Neither high nor low");

	if (!has_low) {
		if (req->resp_len < 0)
			return (NULL);		// Allow 200 response
		if (high == 0)
			return ("No low, high is zero");
		low = req->resp_len - high;
		if (low < 0)
			low = 0;
		high = req->resp_len - 1;
	} else if (req->resp_len >= 0 && (high >= req->resp_len || !has_high))
		high = req->resp_len - 1;
	else if (!has_high || req->resp_len < 0)
		return (NULL);			// Allow 200 response
	/*
	 * else (bo != NULL) {
	 *    We assume that the client knows what it's doing and trust
	 *    that both low and high make sense.
	 * }
	 */

	if (high < low)
		return ("high smaller than low");

	if (req->resp_len >= 0 && low >= req->resp_len)
		return ("low range beyond object");

	if (req->resp_len >= 0)
		http_PrintfHeader(req->resp, "Content-Range: bytes %jd-%jd/%jd",
		    (intmax_t)low, (intmax_t)high, (intmax_t)req->resp_len);
	else
		http_PrintfHeader(req->resp, "Content-Range: bytes %jd-%jd/*",
		    (intmax_t)low, (intmax_t)high);
	req->resp_len = (intmax_t)(1 + high - low);

	vrg_priv = WS_Alloc(req->ws, sizeof *vrg_priv);
	if (vrg_priv == NULL)
		return ("WS too small");

	XXXAN(vrg_priv);
	INIT_OBJ(vrg_priv, VRG_PRIV_MAGIC);
	vrg_priv->range_off = 0;
	vrg_priv->range_low = low;
	vrg_priv->range_high = high + 1;
	*priv = vrg_priv;
	http_PutResponse(req->resp, "HTTP/1.1", 206, NULL);
	return (NULL);
}

/*
 * return 1 if range should be observed, based on if-range value
 * if-range can either be a date or an ETag [RFC7233 3.2 p8]
 */
static int
vrg_ifrange(struct req *req)
{
	const char *p, *e;
	vtim_real ims, lm, d;

	if (!http_GetHdr(req->http, H_If_Range, &p))	// rfc7233,l,455,456
		return (1);

	/* strong validation needed */
	if (p[0] == 'W' && p[1] == '/')			// rfc7233,l,500,501
		return (0);

	/* ETag */
	if (p[0] == '"') {				// rfc7233,l,512,514
		if (!http_GetHdr(req->resp, H_ETag, &e))
			return (0);
		if ((e[0] == 'W' && e[1] == '/'))	// rfc7232,l,547,548
			return (0);
		return (strcmp(p, e) == 0);		// rfc7232,l,548,548
	}

	/* assume date, strong check [RFC7232 2.2.2 p7] */
	if (!(ims = VTIM_parse(p)))			// rfc7233,l,502,512
		return (0);

	/* the response needs a Date */
	// rfc7232 fc7232,l,439,440
	if (!http_GetHdr(req->resp, H_Date, &p) || !(d = VTIM_parse(p)))
		return (0);

	/* grab the Last Modified value */
	if (!http_GetHdr(req->resp, H_Last_Modified, &p))
		return (0);

	lm = VTIM_parse(p);
	if (!lm)
		return (0);
	
	/* Last Modified must be 60 seconds older than Date */
	if (lm > d + 60)				// rfc7232,l,442,443
		return (0);

	if (lm != ims)					// rfc7233,l,455,456
		return (0);
	return (1);
}

static int v_matchproto_(vdp_init_f)
vrg_range_init(struct req *req, void **priv)
{
	const char *r;
	const char *err;

	assert(http_GetHdr(req->http, H_Range, &r));
	if (!vrg_ifrange(req))	// rfc7233,l,455,456
		return (1);
	err = vrg_dorange(req, r, priv);
	if (err == NULL)
		return (*priv == NULL ? 1 : 0);

	VSLb(req->vsl, SLT_Debug, "RANGE_FAIL %s", err);
	if (req->resp_len >= 0)
		http_PrintfHeader(req->resp,
		    "Content-Range: bytes */%jd",
		    (intmax_t)req->resp_len);
	http_PutResponse(req->resp, "HTTP/1.1", 416, NULL);
	/*
	 * XXX: We ought to produce a body explaining things.
	 * XXX: That really calls for us to hit vcl_synth{}
	 */
	req->resp_len = 0;
	return (1);
}

static const struct vdp vrg_vdp = {
	.name =		"range",
	.init =		vrg_range_init,
	.bytes =	vrg_range_bytes,
	.fini =		vrg_range_fini,
};

void
VRG_dorange(struct req *req, const char *r)
{

	(void)r;
	AZ(VDP_Push(req, &vrg_vdp, NULL));
}
