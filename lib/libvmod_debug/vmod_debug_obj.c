/*-
 * Copyright (c) 2013-2015 Varnish Software AS
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
 */

#include "config.h"

#include <stdlib.h>
#include <string.h>

#include "cache/cache.h"

#include "vcc_if.h"

struct xyzzy_debug_obj {
	unsigned		magic;
#define VMOD_DEBUG_OBJ_MAGIC	0xccbd9b77
	int foobar;
	const char *string, *number;
};

VCL_VOID
xyzzy_obj__init(VRT_CTX, struct xyzzy_debug_obj **op,
    const char *vcl_name, VCL_STRING s, VCL_ENUM e)
{
	struct xyzzy_debug_obj *o;

	CHECK_OBJ_NOTNULL(ctx, VRT_CTX_MAGIC);
	(void)vcl_name;
	AN(op);
	AZ(*op);
	ALLOC_OBJ(o, VMOD_DEBUG_OBJ_MAGIC);
	AN(o);
	*op = o;
	o->foobar = 42;
	o->string = s;
	o->number = e;
	AN(*op);
}

VCL_VOID
xyzzy_obj__fini(struct xyzzy_debug_obj **op)
{

	AN(op);
	AN(*op);
	FREE_OBJ(*op);
}

VCL_VOID v_matchproto_()
xyzzy_obj_enum(VRT_CTX, struct xyzzy_debug_obj *o, VCL_ENUM e)
{

	CHECK_OBJ_NOTNULL(ctx, VRT_CTX_MAGIC);
	CHECK_OBJ_NOTNULL(o, VMOD_DEBUG_OBJ_MAGIC);
	assert(!strcmp(e, "martin"));
}

VCL_STRING v_matchproto_()
xyzzy_obj_foo(VRT_CTX, struct xyzzy_debug_obj *o, VCL_STRING s)
{

	CHECK_OBJ_NOTNULL(ctx, VRT_CTX_MAGIC);
	(void)s;
	CHECK_OBJ_NOTNULL(o, VMOD_DEBUG_OBJ_MAGIC);
	assert(o->foobar == 42);
	return ("BOO");
}

VCL_TIME v_matchproto_()
xyzzy_obj_date(VRT_CTX, struct xyzzy_debug_obj *o)
{

	CHECK_OBJ_NOTNULL(ctx, VRT_CTX_MAGIC);
	CHECK_OBJ_NOTNULL(o, VMOD_DEBUG_OBJ_MAGIC);
	assert(o->foobar == 42);
	return (21.4);
}

VCL_STRING v_matchproto_()
xyzzy_obj_string(VRT_CTX, struct xyzzy_debug_obj *o)
{

	CHECK_OBJ_NOTNULL(ctx, VRT_CTX_MAGIC);
	CHECK_OBJ_NOTNULL(o, VMOD_DEBUG_OBJ_MAGIC);
	assert(o->foobar == 42);
	return (o->string);
}

VCL_STRING v_matchproto_()
xyzzy_obj_number(VRT_CTX, struct xyzzy_debug_obj *o)
{

	CHECK_OBJ_NOTNULL(ctx, VRT_CTX_MAGIC);
	CHECK_OBJ_NOTNULL(o, VMOD_DEBUG_OBJ_MAGIC);
	assert(o->foobar == 42);
	return (o->number);
}

VCL_VOID v_matchproto_()
xyzzy_obj_test_priv_call(VRT_CTX,
    struct xyzzy_debug_obj *o, struct vmod_priv *priv)
{
	(void)o;
	xyzzy_test_priv_call(ctx, priv);
}

VCL_VOID v_matchproto_()
xyzzy_obj_test_priv_vcl(VRT_CTX,
    struct xyzzy_debug_obj *o, struct vmod_priv *priv)
{
	(void)o;
	xyzzy_test_priv_vcl(ctx, priv);
}

VCL_STRING v_matchproto_()
xyzzy_obj_test_priv_task(VRT_CTX,
    struct xyzzy_debug_obj *o, struct vmod_priv *priv, VCL_STRING s)
{
	(void)o;
	return (xyzzy_test_priv_task(ctx, priv, s));
}

VCL_STRING v_matchproto_()
xyzzy_obj_test_priv_top(VRT_CTX,
    struct xyzzy_debug_obj *o, struct vmod_priv *priv, VCL_STRING s)
{
	(void)o;
	return (xyzzy_test_priv_top(ctx, priv, s));
}

/* ----------------------------------------------------------------------------
 * obj_opt (optional arguments and privs)
 */
struct xyzzy_debug_obj_opt {
	unsigned			  magic;
#define VMOD_DEBUG_OBJ_OPT_MAGIC	  0xccbd9b78
	char				  *name;
	struct xyzzy_obj_opt_meth_opt_arg args;
	void				  *freeptr;
};

VCL_VOID v_matchproto_()
xyzzy_obj_opt__init(VRT_CTX,
    struct xyzzy_debug_obj_opt **op, const char *vcl_name,
    struct xyzzy_obj_opt__init_arg *args)
{
	struct xyzzy_debug_obj_opt *o;

	CHECK_OBJ_NOTNULL(ctx, VRT_CTX_MAGIC);
	AN(args);

	AN(args->arg1); // priv_call
	AN(args->arg2); // priv_vcl
	AN(args->arg3); // priv_task
	assert(args->arg1 != args->arg2);
	assert(args->arg2 != args->arg3);

	if (args->valid_s)
		AN(args->s);
	(void)args->valid_b;
	(void)args->b;

	AN(op);
	AZ(*op);
	ALLOC_OBJ(o, VMOD_DEBUG_OBJ_OPT_MAGIC);
	AN(o);
	*op = o;
	REPLACE(o->name, vcl_name);
	memcpy(&o->args, args, sizeof o->args);
	if (args->valid_s) {
		REPLACE(o->freeptr, args->s);
		o->args.s = o->freeptr;
	}
}

VCL_VOID v_matchproto_()
xyzzy_obj_opt__fini(struct xyzzy_debug_obj_opt **op)
{
	struct xyzzy_debug_obj_opt *o;

	AN(op);
	AN(*op);

	TAKE_OBJ_NOTNULL(o, op, VMOD_DEBUG_OBJ_OPT_MAGIC);

	REPLACE(o->name, NULL);
	if (o->freeptr) {
		AN(o->args.valid_s);
		REPLACE(o->freeptr, NULL);
	}
	FREE_OBJ(o);
	AZ(o);
}

VCL_STRING v_matchproto_()
xyzzy_obj_opt_meth_opt(VRT_CTX,
    struct xyzzy_debug_obj_opt *o,
    struct xyzzy_obj_opt_meth_opt_arg *args)
{
	CHECK_OBJ_NOTNULL(ctx, VRT_CTX_MAGIC);
	CHECK_OBJ_NOTNULL(o, VMOD_DEBUG_OBJ_OPT_MAGIC);

	AN(args);
	AN(args->arg1); // priv_call
	AN(args->arg2); // priv_vcl
	AN(args->arg3); // priv_task
	assert(args->arg1 != args->arg2);
	assert(args->arg2 != args->arg3);

	return (VRT_CollectString(ctx,
	    "obj ", o->name,
	    " obj_s ", (o->args.valid_s ? o->args.s : "*undef*"),
	    " obj_b ", (o->args.valid_b
			? (o->args.b ? "true" : "false" )
			: "*undef*"),
	    " met_s ", (args->valid_s ? args->s : "*undef*"),
	    " met_b ", (args->valid_b
			? (args->b ? "true" : "false" )
			: "*undef*"),
	    vrt_magic_string_end));
}
