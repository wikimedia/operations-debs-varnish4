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
 *
 * VCL management stuff
 */

#include "config.h"

#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>

#include "mgt/mgt.h"
#include "common/heritage.h"

#include "libvcc.h"
#include "vcli_serve.h"
#include "vct.h"
#include "vev.h"
#include "vtim.h"

#define VCL_STATE(sym, str)					\
	static const char * const VCL_STATE_ ## sym = str;
#include "tbl/vcl_states.h"

static const char * const VCL_STATE_LABEL = "label";
static int vcl_count;

struct vclprog;
struct vmodfile;

struct vmoddep {
	unsigned		magic;
#define VMODDEP_MAGIC		0xc1490542
	VTAILQ_ENTRY(vmoddep)	lfrom;
	struct vmodfile		*to;
	VTAILQ_ENTRY(vmoddep)	lto;
};

struct vcldep {
	unsigned		magic;
#define VCLDEP_MAGIC		0xa9a17dc2
	struct vclprog		*from;
	VTAILQ_ENTRY(vcldep)	lfrom;
	struct vclprog		*to;
	VTAILQ_ENTRY(vcldep)	lto;
};

struct vclprog {
	unsigned		magic;
#define VCLPROG_MAGIC		0x9ac09fea
	VTAILQ_ENTRY(vclprog)	list;
	char			*name;
	char			*fname;
	unsigned		warm;
	const char *		state;
	double			go_cold;
	VTAILQ_HEAD(, vcldep)	dfrom;
	VTAILQ_HEAD(, vcldep)	dto;
	int			nto;
	int			loaded;
	VTAILQ_HEAD(, vmoddep)	vmods;
};

struct vmodfile {
	unsigned		magic;
#define VMODFILE_MAGIC		0xffa1a0d5
	char			*fname;
	VTAILQ_ENTRY(vmodfile)	list;
	VTAILQ_HEAD(, vmoddep)	vcls;
};

static VTAILQ_HEAD(, vclprog)	vclhead = VTAILQ_HEAD_INITIALIZER(vclhead);
static VTAILQ_HEAD(, vmodfile)	vmodhead = VTAILQ_HEAD_INITIALIZER(vmodhead);
static struct vclprog		*active_vcl;
static struct vev *e_poker;

static int mgt_vcl_setstate(struct cli *, struct vclprog *, const char *);
static int mgt_vcl_settemp(struct cli *, struct vclprog *, unsigned);
static int mgt_vcl_tellchild(struct cli *, struct vclprog *, unsigned);
static void mgt_vcl_set_cooldown(struct vclprog *, vtim_mono);

/*--------------------------------------------------------------------*/

static const char *
mcf_vcl_parse_state(const char *s)
{
	if (s == NULL || *s == '\0')
		return (NULL);
#define VCL_STATE(sym, str)					\
	if (!strcmp(s, VCL_STATE_ ## sym))			\
		return (VCL_STATE_ ## sym);
#include "tbl/vcl_states.h"
	return (NULL);
}

static struct vclprog *
mcf_vcl_byname(const char *name)
{
	struct vclprog *vp;

	VTAILQ_FOREACH(vp, &vclhead, list)
		if (!strcmp(name, vp->name))
			return (vp);
	return (NULL);
}

static int
mcf_invalid_vclname(struct cli *cli, const char *name)
{
	const char *bad;

	AN(name);
	bad = VCT_invalid_name(name, NULL);

	if (bad != NULL) {
		VCLI_SetResult(cli, CLIS_PARAM);
		VCLI_Out(cli, "Illegal character in VCL name ");
		if (*bad > 0x20 && *bad < 0x7f)
			VCLI_Out(cli, "('%c')", *bad);
		else
			VCLI_Out(cli, "(0x%02x)", *bad & 0xff);
		return (-1);
	}
	return (0);
}

static struct vclprog *
mcf_find_vcl(struct cli *cli, const char *name)
{
	struct vclprog *vp;

	if (mcf_invalid_vclname(cli, name))
		return (NULL);

	vp = mcf_vcl_byname(name);
	if (vp == NULL) {
		VCLI_SetResult(cli, CLIS_PARAM);
		VCLI_Out(cli, "No VCL named %s known.", name);
	}
	return (vp);
}

static int
mcf_find_no_vcl(struct cli *cli, const char *name)
{

	if (mcf_invalid_vclname(cli, name))
		return (0);

	if (mcf_vcl_byname(name) != NULL) {
		VCLI_SetResult(cli, CLIS_PARAM);
		VCLI_Out(cli, "Already a VCL named %s", name);
		return (0);
	}
	return (1);
}

static int
mcf_is_label(const struct vclprog *vp)
{
	return (vp->state == VCL_STATE_LABEL);
}

/*--------------------------------------------------------------------*/

static void
mgt_vcl_dep_add(struct vclprog *vp_from, struct vclprog *vp_to)
{
	struct vcldep *vd;

	CHECK_OBJ_NOTNULL(vp_from, VCLPROG_MAGIC);
	CHECK_OBJ_NOTNULL(vp_to, VCLPROG_MAGIC);
	ALLOC_OBJ(vd, VCLDEP_MAGIC);

	mgt_vcl_set_cooldown(vp_from, -1);
	mgt_vcl_set_cooldown(vp_to, -1);

	XXXAN(vd);
	vd->from = vp_from;
	VTAILQ_INSERT_TAIL(&vp_from->dfrom, vd, lfrom);
	vd->to = vp_to;
	VTAILQ_INSERT_TAIL(&vp_to->dto, vd, lto);
	vp_to->nto++;

	assert(vp_to->state == VCL_STATE_WARM ||	/* vcl.label ... */
	       vp_to->state == VCL_STATE_AUTO ||	/* vcl.label ... */
	    vp_to->state == VCL_STATE_LABEL);		/* return(vcl(...)) */
}

static void
mgt_vcl_dep_del(struct vcldep *vd)
{

	CHECK_OBJ_NOTNULL(vd, VCLDEP_MAGIC);
	VTAILQ_REMOVE(&vd->from->dfrom, vd, lfrom);
	VTAILQ_REMOVE(&vd->to->dto, vd, lto);
	vd->to->nto--;
	if (vd->to->nto == 0)
		mgt_vcl_set_cooldown(vd->to, VTIM_mono());
	FREE_OBJ(vd);
}

/*--------------------------------------------------------------------*/

static struct vclprog *
mgt_vcl_add(const char *name, const char *state)
{
	struct vclprog *vp;

	assert(state == VCL_STATE_WARM ||
	       state == VCL_STATE_COLD ||
	       state == VCL_STATE_AUTO ||
	       state == VCL_STATE_LABEL);
	ALLOC_OBJ(vp, VCLPROG_MAGIC);
	XXXAN(vp);
	REPLACE(vp->name, name);
	VTAILQ_INIT(&vp->dfrom);
	VTAILQ_INIT(&vp->dto);
	VTAILQ_INIT(&vp->vmods);
	vp->state = state;

	if (vp->state != VCL_STATE_COLD)
		vp->warm = 1;

	VTAILQ_INSERT_TAIL(&vclhead, vp, list);
	if (vp->state != VCL_STATE_LABEL)
		vcl_count++;
	return (vp);
}

static void
mgt_vcl_del(struct vclprog *vp)
{
	char *p;
	struct vmoddep *vd;
	struct vmodfile *vf;

	CHECK_OBJ_NOTNULL(vp, VCLPROG_MAGIC);
	while (!VTAILQ_EMPTY(&vp->dto))
		mgt_vcl_dep_del(VTAILQ_FIRST(&vp->dto));
	while (!VTAILQ_EMPTY(&vp->dfrom))
		mgt_vcl_dep_del(VTAILQ_FIRST(&vp->dfrom));

	VTAILQ_REMOVE(&vclhead, vp, list);
	if (vp->state != VCL_STATE_LABEL)
		vcl_count--;
	if (vp->fname != NULL) {
		if (!MGT_DO_DEBUG(DBG_VCL_KEEP))
			AZ(unlink(vp->fname));
		p = strrchr(vp->fname, '/');
		AN(p);
		*p = '\0';
		VJ_master(JAIL_MASTER_FILE);
		/*
		 * This will fail if any files are dropped next to the library
		 * without us knowing.  This happens for instance with GCOV.
		 * Assume developers know how to clean up after themselves
		 * (or alternatively:  How to run out of disk space).
		 */
		(void)rmdir(vp->fname);
		VJ_master(JAIL_MASTER_LOW);
		free(vp->fname);
	}
	while (!VTAILQ_EMPTY(&vp->vmods)) {
		vd = VTAILQ_FIRST(&vp->vmods);
		CHECK_OBJ(vd, VMODDEP_MAGIC);
		vf = vd->to;
		CHECK_OBJ(vf, VMODFILE_MAGIC);
		VTAILQ_REMOVE(&vp->vmods, vd, lfrom);
		VTAILQ_REMOVE(&vf->vcls, vd, lto);
		FREE_OBJ(vd);

		if (VTAILQ_EMPTY(&vf->vcls)) {
			if (!MGT_DO_DEBUG(DBG_VMOD_SO_KEEP))
				AZ(unlink(vf->fname));
			VTAILQ_REMOVE(&vmodhead, vf, list);
			free(vf->fname);
			FREE_OBJ(vf);
		}
	}
	free(vp->name);
	FREE_OBJ(vp);
}

void
mgt_vcl_depends(struct vclprog *vp1, const char *name)
{
	struct vclprog *vp2;

	CHECK_OBJ_NOTNULL(vp1, VCLPROG_MAGIC);

	vp2 = mcf_vcl_byname(name);
	CHECK_OBJ_NOTNULL(vp2, VCLPROG_MAGIC);
	mgt_vcl_dep_add(vp1, vp2);
}

static int
mgt_vcl_cache_vmod(const char *nm, const char *fm, const char *to)
{
	int fi, fo;
	int ret = 0;
	ssize_t sz;
	char buf[BUFSIZ];

	fo = open(to, O_WRONLY | O_CREAT | O_EXCL, 0744);
	if (fo < 0 && errno == EEXIST)
		return (0);
	if (fo < 0) {
		fprintf(stderr, "Creating copy of vmod %s: %s\n",
		    nm, strerror(errno));
		return (1);
	}
	fi = open(fm, O_RDONLY);
	if (fi < 0) {
		fprintf(stderr, "Opening vmod %s from %s: %s\n",
		    nm, fm, strerror(errno));
		AZ(unlink(to));
		closefd(&fo);
		return (1);
	}
	while (1) {
		sz = read(fi, buf, sizeof buf);
		if (sz == 0)
			break;
		if (sz < 0 || sz != write(fo, buf, sz)) {
			fprintf(stderr, "Copying vmod %s: %s\n",
			    nm, strerror(errno));
			AZ(unlink(to));
			ret = 1;
			break;
		}
	}
	closefd(&fi);
	AZ(fchmod(fo, 0444));
	closefd(&fo);
	return(ret);
}

void
mgt_vcl_vmod(struct vclprog *vp, const char *src, const char *dst)
{
	struct vmodfile *vf;
	struct vmoddep *vd;

	CHECK_OBJ_NOTNULL(vp, VCLPROG_MAGIC);
	AN(src);
	AN(dst);
	assert(!strncmp(dst, "./vmod_cache/", 13));

	VTAILQ_FOREACH(vf, &vmodhead, list)
		if (!strcmp(vf->fname, dst))
			break;
	if (vf == NULL) {
		ALLOC_OBJ(vf, VMODFILE_MAGIC);
		AN(vf);
		REPLACE(vf->fname, dst);
		AN(vf->fname);
		VTAILQ_INIT(&vf->vcls);
		AZ(mgt_vcl_cache_vmod(vp->name, src, dst));
		VTAILQ_INSERT_TAIL(&vmodhead, vf, list);
	}
	ALLOC_OBJ(vd, VMODDEP_MAGIC);
	AN(vd);
	vd->to = vf;
	VTAILQ_INSERT_TAIL(&vp->vmods, vd, lfrom);
	VTAILQ_INSERT_TAIL(&vf->vcls, vd, lto);
}

int
mgt_has_vcl(void)
{

	return (!VTAILQ_EMPTY(&vclhead));
}

/*
 * go_cold
 *
 * -1: leave alone
 *  0: timer not started - not currently used
 * >0: when timer started
 */
static void
mgt_vcl_set_cooldown(struct vclprog *vp, vtim_mono now)
{
	CHECK_OBJ_NOTNULL(vp, VCLPROG_MAGIC);

	if (vp == active_vcl ||
	    vp->state != VCL_STATE_AUTO ||
	    vp->warm == 0 ||
	    !VTAILQ_EMPTY(&vp->dto) ||
	    !VTAILQ_EMPTY(&vp->dfrom))
		vp->go_cold = -1;
	else
		vp->go_cold = now;
}

static unsigned
mgt_vcl_cooldown(struct vclprog *vp, vtim_mono now)
{
	CHECK_OBJ_NOTNULL(vp, VCLPROG_MAGIC);

	if (vp->go_cold < 0)
		return (0);

	if (vp->go_cold == 0) {
		mgt_vcl_set_cooldown(vp, now);
		return (0);
	}

	assert(vp->go_cold > 0);

	if (vp->go_cold + mgt_param.vcl_cooldown < now)
		return (1);

	return (0);
}

static int
mgt_vcl_settemp(struct cli *cli, struct vclprog *vp, unsigned warm)
{
	int i;

	CHECK_OBJ_NOTNULL(vp, VCLPROG_MAGIC);

	if (warm == vp->warm)
		return (0);

	if (vp->state == VCL_STATE_AUTO || vp->state == VCL_STATE_LABEL) {
		mgt_vcl_set_cooldown(vp, -1);
		i = mgt_vcl_tellchild(cli, vp, warm);
		mgt_vcl_set_cooldown(vp, VTIM_mono());
	} else {
		i = mgt_vcl_setstate(cli, vp,
		    warm ? VCL_STATE_WARM : VCL_STATE_COLD);
	}

	return (i);
}

static int
mgt_vcl_requirewarm(struct cli *cli, struct vclprog *vp)
{
	if (vp->state == VCL_STATE_COLD) {
		VCLI_SetResult(cli, CLIS_CANT);
		VCLI_Out(cli, "VCL '%s' is cold - set to auto or warm first",
		    vp->name);
		return (1);
	}
	return (mgt_vcl_settemp(cli, vp, 1));
}

static int
mgt_vcl_tellchild(struct cli *cli, struct vclprog *vp, unsigned warm)
{
	unsigned status;
	char *p;
	int i;

	CHECK_OBJ_NOTNULL(vp, VCLPROG_MAGIC);

	if (!MCH_Running()) {
		vp->warm = warm;
		return (0);
	}

	i = mgt_cli_askchild(&status, &p, "vcl.state %s %d%s\n",
	    vp->name, warm, vp->state);
	if (i && cli != NULL) {
		VCLI_SetResult(cli, status);
		VCLI_Out(cli, "%s", p);
	} else if (i) {
		MGT_Complain(C_ERR,
		    "Please file ticket: VCL poker problem: "
		    "'vcl.state %s %d%s' -> %03d '%s'",
		    vp->name, warm, vp->state, i, p);
	} else {
		/* Success, update mgt's VCL state to reflect child's
		   state */
		vp->warm = warm;
	}

	free(p);
	return (i);
}

static int
mgt_vcl_setstate(struct cli *cli, struct vclprog *vp, const char *vs)
{
	unsigned warm;
	int i;
	const char *os;

	CHECK_OBJ_NOTNULL(vp, VCLPROG_MAGIC);

	assert(vs != VCL_STATE_LABEL);

	if (mcf_is_label(vp)) {
		AN(vp->warm);
		/* do not touch labels */
		return (0);
	}

	if (vp->state == vs)
		return (0);

	os = vp->state;
	vp->state = vs;

	if (vp == active_vcl) {
		assert (vs == VCL_STATE_WARM || vs == VCL_STATE_AUTO);
		AN(vp->warm);
		warm = 1;
	} else if (vs == VCL_STATE_AUTO) {
		warm = vp->warm;
	} else {
		warm = (vs == VCL_STATE_WARM ? 1 : 0);
	}

	i = mgt_vcl_tellchild(cli, vp, warm);
	if (i == 0)
		mgt_vcl_set_cooldown(vp, VTIM_mono());
	else
		vp->state = os;
	return (i);
}

/*--------------------------------------------------------------------*/

static void
mgt_new_vcl(struct cli *cli, const char *vclname, const char *vclsrc,
    const char *vclsrcfile, const char *state, int C_flag)
{
	unsigned status;
	char *lib, *p;
	struct vclprog *vp;
	char buf[32];

	AN(cli);

	if (C_flag) {
		bprintf(buf, ".CflagTest.%d", (int)getpid());
		vclname = buf;
	} else if (vcl_count >= mgt_param.max_vcl &&
	    mgt_param.max_vcl_handling == 2) {
		VCLI_Out(cli, "Too many (%d) VCLs already loaded\n", vcl_count);
		VCLI_Out(cli, "(See max_vcl and max_vcl_handling parameters)");
		VCLI_SetResult(cli, CLIS_CANT);
		return;
	}

	if (state == NULL)
		state = VCL_STATE_AUTO;
	else
		state = mcf_vcl_parse_state(state);

	if (state == NULL) {
		VCLI_Out(cli, "State must be one of auto, cold or warm.");
		VCLI_SetResult(cli, CLIS_PARAM);
		return;
	}

	vp = mgt_vcl_add(vclname, state);
	lib = mgt_VccCompile(cli, vp, vclname, vclsrc, vclsrcfile, C_flag);
	if (lib == NULL) {
		mgt_vcl_del(vp);
		return;
	}

	AZ(C_flag);
	vp->fname = lib;

	if (active_vcl == NULL)
		active_vcl = vp;

	if ((cli->result == CLIS_OK || cli->result == CLIS_TRUNCATED) &&
	    vcl_count > mgt_param.max_vcl &&
	    mgt_param.max_vcl_handling == 1) {
		VCLI_Out(cli, "%d VCLs loaded\n", vcl_count);
		VCLI_Out(cli, "Remember to vcl.discard the old/unused VCLs.\n");
		VCLI_Out(cli, "(See max_vcl and max_vcl_handling parameters)");
	}

	if (!MCH_Running())
		return;

	if (mgt_cli_askchild(&status, &p, "vcl.load %s %s %d%s\n",
	    vp->name, vp->fname, vp->warm, vp->state)) {
		mgt_vcl_del(vp);
		VCLI_Out(cli, "%s", p);
		VCLI_SetResult(cli, status);
		free(p);
		return;
	}
	free(p);

	mgt_vcl_set_cooldown(vp, VTIM_mono());
}

/*--------------------------------------------------------------------*/

void
mgt_vcl_startup(struct cli *cli, const char *vclsrc, const char *vclname,
    const char *origin, int C_flag)
{
	char buf[20];
	static int n = 0;

	AN(vclsrc);
	AN(origin);
	if (vclname == NULL) {
		bprintf(buf, "boot%d", n++);
		vclname = buf;
	}
	active_vcl = NULL;
	mgt_new_vcl(cli, vclname, vclsrc, origin, NULL, C_flag);
}

/*--------------------------------------------------------------------*/

void
mgt_vcl_export_labels(struct vcc *vcc)
{
	struct vclprog *vp;
	VTAILQ_FOREACH(vp, &vclhead, list) {
		if (mcf_is_label(vp))
			VCC_Predef(vcc, "VCL_VCL", vp->name);
	}
}

/*--------------------------------------------------------------------*/

int
mgt_push_vcls(struct cli *cli, unsigned *status, char **p)
{
	struct vclprog *vp;
	struct vcldep *vd;
	int done;

	AN(active_vcl);

	/* The VCL has not been loaded yet, it cannot fail */
	(void)cli;

	VTAILQ_FOREACH(vp, &vclhead, list)
		vp->loaded = 0;

	do {
		done = 1;
		VTAILQ_FOREACH(vp, &vclhead, list) {
			if (vp->loaded)
				continue;
			VTAILQ_FOREACH(vd, &vp->dfrom, lfrom)
				if (!vd->to->loaded)
					break;
			if (vd != NULL) {
				done = 0;
				continue;
			}
			if (mcf_is_label(vp)) {
				vd = VTAILQ_FIRST(&vp->dfrom);
				AN(vd);
				if (mgt_cli_askchild(status, p,
				    "vcl.label %s %s\n",
				    vp->name, vd->to->name))
					return (1);
			} else {
				if (mgt_cli_askchild(status, p,
				    "vcl.load \"%s\" %s %d%s\n",
				    vp->name, vp->fname, vp->warm, vp->state))
					return (1);
			}
			vp->loaded = 1;
			free(*p);
			*p = NULL;
		}
	} while (!done);

	if (mgt_cli_askchild(status, p, "vcl.use \"%s\"\n", active_vcl->name))
		return (1);
	free(*p);
	*p = NULL;
	return (0);
}

/*--------------------------------------------------------------------*/

static void v_matchproto_(cli_func_t)
mcf_vcl_inline(struct cli *cli, const char * const *av, void *priv)
{

	(void)priv;

	if (!mcf_find_no_vcl(cli, av[2]))
		return;

	mgt_new_vcl(cli, av[2], av[3], "<vcl.inline>", av[4], 0);
}

static void v_matchproto_(cli_func_t)
mcf_vcl_load(struct cli *cli, const char * const *av, void *priv)
{

	(void)priv;
	if (!mcf_find_no_vcl(cli, av[2]))
		return;

	mgt_new_vcl(cli, av[2], NULL, av[3], av[4], 0);
}


static void v_matchproto_(cli_func_t)
mcf_vcl_state(struct cli *cli, const char * const *av, void *priv)
{
	const char *state;
	struct vclprog *vp;

	(void)priv;
	vp = mcf_find_vcl(cli, av[2]);
	if (vp == NULL)
		return;

	if (mcf_is_label(vp)) {
		VCLI_Out(cli, "Labels are always warm");
		VCLI_SetResult(cli, CLIS_PARAM);
		return;
	}

	state = mcf_vcl_parse_state(av[3]);
	if (state == NULL) {
		VCLI_Out(cli, "State must be one of auto, cold or warm.");
		VCLI_SetResult(cli, CLIS_PARAM);
		return;
	}

	if (state == VCL_STATE_COLD) {
		if (!VTAILQ_EMPTY(&vp->dto)) {
			assert(vp->state != VCL_STATE_COLD);
			VCLI_Out(cli, "A labeled VCL cannot be set cold");
			VCLI_SetResult(cli, CLIS_CANT);
			return;
		}
		if (vp == active_vcl) {
			VCLI_Out(cli, "Cannot set the active VCL cold.");
			VCLI_SetResult(cli, CLIS_CANT);
			return;
		}
	}

	(void)mgt_vcl_setstate(cli, vp, state);
}

static void v_matchproto_(cli_func_t)
mcf_vcl_use(struct cli *cli, const char * const *av, void *priv)
{
	unsigned status;
	char *p = NULL;
	struct vclprog *vp, *vp2;
	vtim_mono now;

	(void)priv;
	vp = mcf_find_vcl(cli, av[2]);
	if (vp == NULL)
		return;
	if (vp == active_vcl)
		return;

	if (mgt_vcl_requirewarm(cli, vp))
		return;

	if (MCH_Running() &&
	    mgt_cli_askchild(&status, &p, "vcl.use %s\n", av[2])) {
		VCLI_SetResult(cli, status);
		VCLI_Out(cli, "%s", p);
	} else {
		VCLI_Out(cli, "VCL '%s' now active", av[2]);
		vp2 = active_vcl;
		active_vcl = vp;
		now = VTIM_mono();
		mgt_vcl_set_cooldown(vp, now);
		if (vp2 != NULL)
			mgt_vcl_set_cooldown(vp2, now);
	}
	free(p);
}

static void v_matchproto_(cli_func_t)
mcf_vcl_discard(struct cli *cli, const char * const *av, void *priv)
{
	unsigned status;
	char *p = NULL;
	struct vclprog *vp;
	struct vcldep *vd;
	int n;

	(void)priv;
	vp = mcf_find_vcl(cli, av[2]);
	if (vp == NULL)
		return;
	if (vp == active_vcl) {
		VCLI_SetResult(cli, CLIS_CANT);
		VCLI_Out(cli, "Cannot discard active VCL program\n");
		return;
	}
	if (!VTAILQ_EMPTY(&vp->dto)) {
		VCLI_SetResult(cli, CLIS_CANT);
		AN(vp->warm);
		if (!mcf_is_label(vp))
			VCLI_Out(cli, "Cannot discard labeled VCL program.\n");
		else
			VCLI_Out(cli,
			    "Cannot discard this VCL label, "
			    "other VCLs depend on it.\n");
		n = 0;
		VTAILQ_FOREACH(vd, &vp->dto, lto) {
			if (n++ == 5) {
				VCLI_Out(cli, "\t[...]");
				break;
			}
			VCLI_Out(cli, "\t%s\n", vd->from->name);
		}
		return;
	}
	if (mcf_is_label(vp)) {
		AN(vp->warm);
		vp->warm = 0;
	} else {
		(void)mgt_vcl_setstate(cli, vp, VCL_STATE_COLD);
	}
	if (MCH_Running()) {
		AZ(vp->warm);
		if (mgt_cli_askchild(&status, &p, "vcl.discard %s\n", av[2]))
			assert(status == CLIS_OK || status == CLIS_COMMS);
		free(p);
	}
	mgt_vcl_del(vp);
}

static void v_matchproto_(cli_func_t)
mcf_vcl_list(struct cli *cli, const char * const *av, void *priv)
{
	unsigned status;
	char *p;
	struct vclprog *vp;
	struct vcldep *vd;

	/* NB: Shall generate same output as vcl_cli_list() */

	(void)av;
	(void)priv;
	if (MCH_Running()) {
		if (!mgt_cli_askchild(&status, &p, "vcl.list\n")) {
			VCLI_SetResult(cli, status);
			VCLI_Out(cli, "%s", p);
		}
		free(p);
	} else {
		VTAILQ_FOREACH(vp, &vclhead, list) {
			VCLI_Out(cli, "%-10s %5s",
			    vp == active_vcl ? "active" : "available",
			    vp->state);
			VCLI_Out(cli, "/%-8s", vp->warm ?
			    VCL_STATE_WARM : VCL_STATE_COLD);
			VCLI_Out(cli, " %6s %s", "-", vp->name);
			if (mcf_is_label(vp)) {
				vd = VTAILQ_FIRST(&vp->dfrom);
				AN(vd);
				VCLI_Out(cli, " -> %s", vd->to->name);
				if (vp->nto > 0)
					VCLI_Out(cli, " (%d return(vcl)%s)",
					    vp->nto, vp->nto > 1 ? "'s" : "");
			} else if (vp->nto > 0) {
				VCLI_Out(cli, " (%d label%s)",
				    vp->nto, vp->nto > 1 ? "s" : "");
			}
			VCLI_Out(cli, "\n");
		}
	}
}

static void v_matchproto_(cli_func_t)
mcf_vcl_list_json(struct cli *cli, const char * const *av, void *priv)
{
	unsigned status;
	char *p;
	struct vclprog *vp;
	struct vcldep *vd;

	/* NB: Shall generate same output as vcl_cli_list() */

	(void)priv;
	if (MCH_Running()) {
		if (!mgt_cli_askchild(&status, &p, "vcl.list -j\n")) {
			VCLI_SetResult(cli, status);
			VCLI_Out(cli, "%s", p);
		}
		free(p);
	} else {
		VCLI_JSON_begin(cli, 2, av);
		VCLI_Out(cli, ",\n");
		VTAILQ_FOREACH(vp, &vclhead, list) {
			VCLI_Out(cli, "{\n");
			VSB_indent(cli->sb, 2);
			VCLI_Out(cli, "\"status\": \"%s\",\n",
			    vp == active_vcl ? "active" : "available");
			VCLI_Out(cli, "\"state\": \"%s\",\n", vp->state);
			VCLI_Out(cli, "\"temperature\": \"%s\",\n",
			    vp->warm ? VCL_STATE_WARM : VCL_STATE_COLD);
			VCLI_Out(cli, "\"name\": \"%s\"", vp->name);
			if (mcf_is_label(vp)) {
				vd = VTAILQ_FIRST(&vp->dfrom);
				AN(vd);
				VCLI_Out(cli, ",\n");
				VCLI_Out(cli, "\"label\": {\n");
				VSB_indent(cli->sb, 2);
				VCLI_Out(cli, "\"name\": \"%s\"", vd->to->name);
				if (vp->nto > 0)
					VCLI_Out(cli, ",\n\"refs\": %d",
						 vp->nto);
				VSB_indent(cli->sb, -2);
				VCLI_Out(cli, "\n");
				VCLI_Out(cli, "}");
			} else if (vp->nto > 0) {
				VCLI_Out(cli, ",\n");
				VCLI_Out(cli, "\"labels\": %d", vp->nto);
			}
			VSB_indent(cli->sb, -2);
			VCLI_Out(cli, "\n}");
			if (VTAILQ_NEXT(vp, list) != NULL)
				VCLI_Out(cli, ",\n");
		}
		VCLI_JSON_end(cli);
	}
}

static void v_matchproto_(cli_func_t)
mcf_vcl_label(struct cli *cli, const char * const *av, void *priv)
{
	struct vclprog *vpl;
	struct vclprog *vpt;
	unsigned status;
	char *p;
	int i;

	(void)priv;
	if (mcf_invalid_vclname(cli, av[2]))
		return;
	if (mcf_invalid_vclname(cli, av[3]))
		return;
	vpt = mcf_find_vcl(cli, av[3]);
	if (vpt == NULL)
		return;
	if (mcf_is_label(vpt)) {
		VCLI_SetResult(cli, CLIS_CANT);
		VCLI_Out(cli, "VCL labels cannot point to labels");
		return;
	}
	vpl = mcf_vcl_byname(av[2]);
	if (vpl != NULL) {
		if (!mcf_is_label(vpl)) {
			VCLI_SetResult(cli, CLIS_PARAM);
			VCLI_Out(cli, "%s is not a label", vpl->name);
			return;
		}
		if (!VTAILQ_EMPTY(&vpt->dfrom) &&
		    !VTAILQ_EMPTY(&vpl->dto)) {
			VCLI_SetResult(cli, CLIS_PARAM);
			VCLI_Out(cli, "return(vcl) can only be used from"
			    " the active VCL.\n\n");
			VCLI_Out(cli,
			    "Label %s is used in return(vcl) from VCL %s\n",
			    vpl->name, VTAILQ_FIRST(&vpl->dto)->from->name);
			VCLI_Out(cli, "and VCL %s also has return(vcl)",
			    vpt->name);
			return;
		}
	}

	if (mgt_vcl_requirewarm(cli, vpt))
		return;

	if (vpl != NULL) {
		/* potentially fail before we delete the dependency */
		if (mgt_vcl_requirewarm(cli, vpl))
			return;
		mgt_vcl_dep_del(VTAILQ_FIRST(&vpl->dfrom));
		AN(VTAILQ_EMPTY(&vpl->dfrom));
	} else {
		vpl = mgt_vcl_add(av[2], VCL_STATE_LABEL);
	}

	AN(vpl);
	if (mgt_vcl_requirewarm(cli, vpl))
		return;
	mgt_vcl_dep_add(vpl, vpt);

	if (!MCH_Running())
		return;

	i = mgt_cli_askchild(&status, &p, "vcl.label %s %s\n", av[2], av[3]);
	if (i) {
		VCLI_SetResult(cli, status);
		VCLI_Out(cli, "%s", p);
	}
	free(p);
}

/*--------------------------------------------------------------------*/

static int v_matchproto_(vev_cb_f)
mgt_vcl_poker(const struct vev *e, int what)
{
	struct vclprog *vp;
	vtim_mono now;

	(void)e;
	(void)what;
	e_poker->timeout = mgt_param.vcl_cooldown * .45;
	now = VTIM_mono();
	VTAILQ_FOREACH(vp, &vclhead, list) {
		if (mgt_vcl_cooldown(vp, now))
			(void)mgt_vcl_settemp(NULL, vp, 0);
	}
	return (0);
}

/*--------------------------------------------------------------------*/

static struct cli_proto cli_vcl[] = {
	{ CLICMD_VCL_LOAD,		"", mcf_vcl_load },
	{ CLICMD_VCL_INLINE,		"", mcf_vcl_inline },
	{ CLICMD_VCL_USE,		"", mcf_vcl_use },
	{ CLICMD_VCL_STATE,		"", mcf_vcl_state },
	{ CLICMD_VCL_DISCARD,		"", mcf_vcl_discard },
	{ CLICMD_VCL_LIST,		"", mcf_vcl_list, mcf_vcl_list_json },
	{ CLICMD_VCL_LABEL,		"", mcf_vcl_label },
	{ NULL }
};

/*--------------------------------------------------------------------*/

static void
mgt_vcl_atexit(void)
{
	struct vclprog *vp;

	if (getpid() != heritage.mgt_pid)
		return;
	active_vcl = NULL;
	do {
		vp = VTAILQ_FIRST(&vclhead);
		if (vp != NULL)
			mgt_vcl_del(vp);
	} while (vp != NULL);
}

void
mgt_vcl_init(void)
{

	e_poker = VEV_Alloc();
	AN(e_poker);
	e_poker->timeout = 3;		// random, prime

	e_poker->callback = mgt_vcl_poker;
	e_poker->name = "vcl poker";
	AZ(VEV_Start(mgt_evb, e_poker));

	AZ(atexit(mgt_vcl_atexit));

	VCLS_AddFunc(mgt_cls, MCF_AUTH, cli_vcl);
}
