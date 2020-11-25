/*-
 * Copyright (c) 2010-2015 Varnish Software AS
 * All rights reserved.
 *
 * Author: Poul-Henning Kamp <phk@FreeBSD.org>
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
 *
 */

#include "config.h"

#include <ctype.h>
#include <limits.h>
#include <string.h>
#include <stdlib.h>
#include <sys/socket.h>

#include <netdb.h>

#include "cache/cache.h"

#include "vnum.h"
#include "vsa.h"
#include "vss.h"
#include "vtim.h"
#include "vcc_if.h"

VCL_DURATION v_matchproto_(td_std_duration)
vmod_duration(VRT_CTX, VCL_STRING p, VCL_DURATION d)
{
	double r = VNUM_duration(p);

	(void) ctx;

	return (isnan(r) ? d : r);
}

VCL_INT v_matchproto_(td_std_integer)
vmod_integer(VRT_CTX, VCL_STRING p, VCL_INT i)
{
	const char *e;
	double r;

	CHECK_OBJ_NOTNULL(ctx, VRT_CTX_MAGIC);

	if (p == NULL)
		return (i);

	r = VNUMpfx(p, &e);
	if (isnan(r) || e != NULL)
		return (i);

	r = trunc(r);
	if (r > (double)LONG_MAX || r < (double)LONG_MIN)
		return (i);

	return ((VCL_INT)r);
}

VCL_IP
vmod_ip(VRT_CTX, VCL_STRING s, VCL_IP d, VCL_BOOL n, VCL_STRING default_port)
{
	void *p;
	VCL_IP retval = NULL;

	CHECK_OBJ_NOTNULL(ctx, VRT_CTX_MAGIC);
	AN(d);
	assert(VSA_Sane(d));

	p = WS_Alloc(ctx->ws, vsa_suckaddr_len);
	if (p == NULL) {
		VRT_fail(ctx, "std.ip: insufficient workspace");
		return (NULL);
	}

	if (s != NULL)
		retval = VSS_ResolveFirst(p, s, default_port, AF_UNSPEC,
		    SOCK_STREAM, n ? 0 : AI_NUMERICHOST|AI_NUMERICSERV);

	if (retval != NULL)
		return (retval);

	WS_Reset(ctx->ws, (uintptr_t)p);
	return (d);
}

VCL_REAL v_matchproto_(td_std_real)
vmod_real(VRT_CTX, VCL_STRING p, VCL_REAL d)
{
	double r;

	CHECK_OBJ_NOTNULL(ctx, VRT_CTX_MAGIC);

	if (p == NULL)
		return (d);

	r = VNUM(p);

	if (isnan(r))
		return (d);

	return (r);
}

VCL_INT v_matchproto_(td_std_real2integer)
vmod_real2integer(VRT_CTX, VCL_REAL r, VCL_INT i)
{
	CHECK_OBJ_NOTNULL(ctx, VRT_CTX_MAGIC);

	if (!isfinite(r))
		return (i);
	r = round(r);
	if (r > (double)LONG_MAX || r < (double)LONG_MIN)
		return(i);
	return ((VCL_INT)r);
}

VCL_TIME v_matchproto_(td_std_real2time)
vmod_real2time(VRT_CTX, VCL_REAL r, VCL_TIME t)
{
	CHECK_OBJ_NOTNULL(ctx, VRT_CTX_MAGIC);

	if (!isfinite(r))
		return (t);

	return (r);
}

VCL_INT v_matchproto_(td_std_time2integer)
vmod_time2integer(VRT_CTX, VCL_TIME t, VCL_INT i)
{
	CHECK_OBJ_NOTNULL(ctx, VRT_CTX_MAGIC);

	if (!isfinite(t))
		return (i);
	t = round(t);
	if (t > (double)LONG_MAX || t < (double)LONG_MIN)
		return(i);
	return ((VCL_INT)t);
}

VCL_REAL v_matchproto_(td_std_time2real)
vmod_time2real(VRT_CTX, VCL_TIME t, VCL_REAL r)
{
	CHECK_OBJ_NOTNULL(ctx, VRT_CTX_MAGIC);

	if (!isfinite(t))
		return (r);

	return (t);
}

VCL_TIME v_matchproto_(td_std_time)
vmod_time(VRT_CTX, VCL_STRING p, VCL_TIME d)
{
	double r;

	CHECK_OBJ_NOTNULL(ctx, VRT_CTX_MAGIC);

	r = VTIM_parse(p);
	if (r)
		return (r);
	return (vmod_real(ctx, p, d));
}
