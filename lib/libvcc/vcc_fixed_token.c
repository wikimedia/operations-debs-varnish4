/*
 * NB:  This file is machine generated, DO NOT EDIT!
 *
 * Edit and run lib/libvcc/generate.py instead.
 */



#include "config.h"

#include <ctype.h>
#include <stdio.h>

#include "vcc_compile.h"

#define M1()	do {*q = p + 1; return (p[0]); } while (0)
#define M2(c,t)	do {if (p[1] == (c)) { *q = p + 2; return (t); }} while (0)

unsigned
vcl_fixed_token(const char *p, const char **q)
{

	switch (p[0]) {
	case '!':
		M2('=', T_NEQ);
		M2('~', T_NOMATCH);
		M1();
	case '%':
		M1();
	case '&':
		M2('&', T_CAND);
		M1();
	case '(':
		M1();
	case ')':
		M1();
	case '*':
		M2('=', T_MUL);
		M1();
	case '+':
		M2('+', T_INC);
		M2('=', T_INCR);
		M1();
	case ',':
		M1();
	case '-':
		M2('-', T_DEC);
		M2('=', T_DECR);
		M1();
	case '.':
		M1();
	case '/':
		M2('=', T_DIV);
		M1();
	case ';':
		M1();
	case '<':
		M2('<', T_SHL);
		M2('=', T_LEQ);
		M1();
	case '=':
		M2('=', T_EQ);
		M1();
	case '>':
		M2('=', T_GEQ);
		M2('>', T_SHR);
		M1();
	case '{':
		M1();
	case '|':
		M2('|', T_COR);
		M1();
	case '}':
		M1();
	case '~':
		M1();
	default:
		return (0);
	}
}

const char * const vcl_tnames[256] = {
	['!'] = "'!'",
	['%'] = "'%'",
	['&'] = "'&'",
	['('] = "'('",
	[')'] = "')'",
	['*'] = "'*'",
	['+'] = "'+'",
	[','] = "','",
	['-'] = "'-'",
	['.'] = "'.'",
	['/'] = "'/'",
	[';'] = "';'",
	['<'] = "'<'",
	['='] = "'='",
	['>'] = "'>'",
	['{'] = "'{'",
	['|'] = "'|'",
	['}'] = "'}'",
	['~'] = "'~'",
	[CNUM] = "CNUM",
	[CSRC] = "CSRC",
	[CSTR] = "CSTR",
	[EOI] = "EOI",
	[ID] = "ID",
	[T_CAND] = "&&",
	[T_COR] = "||",
	[T_DEC] = "--",
	[T_DECR] = "-=",
	[T_DIV] = "/=",
	[T_EQ] = "==",
	[T_GEQ] = ">=",
	[T_INC] = "++",
	[T_INCR] = "+=",
	[T_LEQ] = "<=",
	[T_MUL] = "*=",
	[T_NEQ] = "!=",
	[T_NOMATCH] = "!~",
	[T_SHL] = "<<",
	[T_SHR] = ">>",
};

void
vcl_output_lang_h(struct vsb *sb)
{

	/* ../include/vdef.h */

	VSB_cat(sb, "/* ---===### include/vdef.h ###===--- */\n\n");
	VSB_cat(sb, "/*-\n * Copyright (c) 2006 Verdens Gang AS\n"
	    " * Copyright (c) 2012 Fastly Inc\n * Copyright (c) 2006-2015 "
	    "Varnish Software AS\n * All rights reserved.\n *\n"
	    " * Author: Poul-Henning Kamp <phk@phk.freebsd.dk>\n"
	    " * Author: Rogier 'DocWilco' Mulhuijzen <rogier@fastly.com>\n"
	    " *\n * Inspired by FreeBSD's <sys/cdefs.h>\n *\n * Redistributio"
	    "n and use in source and binary forms, with or without\n"
	    " * modification, are permitted provided that the following "
	    "conditions\n * are met:\n * 1. Redistributions of source code "
	    "must retain the above copyright\n *    notice, this list of "
	    "conditions and the following disclaimer.\n * 2. Redistributions "
	    "in binary form must reproduce the above copyright\n"
	    " *    notice, this list of conditions and the following disclaim"
	    "er in the\n *    documentation and/or other materials provided "
	    "with the distribution.\n *\n * THIS SOFTWARE IS PROVIDED BY "
	    "THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND\n * ANY EXPRESS "
	    "OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE\n"
	    " * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A "
	    "PARTICULAR PURPOSE\n * ARE DISCLAIMED.  IN NO EVENT SHALL "
	    "AUTHOR OR CONTRIBUTORS BE LIABLE\n * FOR ANY DIRECT, INDIRECT, "
	    "INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL\n"
	    " * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF "
	    "SUBSTITUTE GOODS\n * OR SERVICES; LOSS OF USE, DATA, OR PROFITS;"
	    " OR BUSINESS INTERRUPTION)\n * HOWEVER CAUSED AND ON ANY THEORY "
	    "OF LIABILITY, WHETHER IN CONTRACT, STRICT\n * LIABILITY, OR "
	    "TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY\n"
	    " * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE "
	    "POSSIBILITY OF\n * SUCH DAMAGE.\n *\n */\n\n#ifndef VDEF_H_INCLU"
	    "DED\n#define VDEF_H_INCLUDED\n\n/* Safe printf into a fixed-size"
	    " buffer */\n#define bprintf(buf, fmt, ...)\t\t\t\t\t\t\\\n"
	    "\tdo {\t\t\t\t\t\t\t\t\\\n\t\tassert(snprintf(buf, sizeof "
	    "buf, fmt, __VA_ARGS__)\t\\\n\t\t    < sizeof buf);\t\t\t\t\t"
	    "\\\n\t} while (0)\n\n/* Safe printf into a fixed-size buffer "
	    "*/\n#define vbprintf(buf, fmt, ap)\t\t\t\t\t\t\\\n"
	    "\tdo {\t\t\t\t\t\t\t\t\\\n\t\tassert(vsnprintf(buf, sizeof "
	    "buf, fmt, ap)\t\t\\\n\t\t    < sizeof buf);\t\t\t\t\t\\\n"
	    "\t} while (0)\n\n/* Close and discard filedescriptor */\n"
	    "#define closefd(fdp)\t\t\t\t\\\n\tdo {\t\t\t\t\t\\\n"
	    "\t\tassert(*(fdp) >= 0);\t\t\\\n\t\tAZ(close(*(fdp)));\t\t\\\n"
	    "\t\t*(fdp) = -1;\t\t\t\\\n\t} while (0)\n\n#ifndef __GNUC_PREREQ"
	    "\n# if defined __GNUC__ && defined __GNUC_MINOR__\n"
	    "#  define __GNUC_PREREQ(maj, min) \\\n\t(__GNUC__ > (maj) "
	    "|| (__GNUC__ == (maj) && __GNUC_MINOR__ >= (min)))\n"
	    "# else\n#  define __GNUC_PREREQ(maj, min) 0\n# endif\n"
	    "#endif\n\n#ifdef __printflike\n#  define __v_printflike(f,a) "
	    "__printflike(f,a)\n#elif __GNUC_PREREQ(2, 95) || defined(__INTEL"
	    "_COMPILER)\n#  define __v_printflike(f,a) __attribute__((format("
	    "printf, f, a)))\n#else\n#  define __v_printflike(f,a)\n"
	    "#endif\n\n/*****************************************************"
	    "****************\n * Pointer alignment magic\n */\n"
	    "\n#if defined(__sparc__)\n/* NB: Overbroad test for 32bit "
	    "userland on 64bit SPARC cpus. */\n#  define PALGN\t    (sizeof(d"
	    "ouble) - 1)\t/* size of alignment */\n#else\n#  define PALGN\t"
	    "    (sizeof(void *) - 1)\t/* size of alignment */\n"
	    "#endif\n#define PAOK(p)\t    (((uintptr_t)(p) & PALGN) == "
	    "0)\t/* is aligned */\n#define PRNDDN(p)   ((uintptr_t)(p) "
	    "& ~PALGN)\t\t/* Round down */\n#define PRNDUP(p)   (((uintptr_t)"
	    "(p) + PALGN) & ~PALGN)\t/* Round up */\n\n/*********************"
	    "************************************************\n"
	    " * To be used as little as possible to wash off const/volatile "
	    "etc.\n */\n#define TRUST_ME(ptr)\t((void*)(uintptr_t)(ptr))\n"
	    "\n/*************************************************************"
	    "*********\n * Generic power-2 rounding macros\n */\n"
	    "\n#define PWR2(x)     ((((x)-1UL)&(x))==0)\t\t/* Is a power "
	    "of two */\n#define RDN2(x, y)  ((x)&(~((uintptr_t)(y)-1UL)))\t"
	    "/* PWR2(y) true */\n#define RUP2(x, y)  (((x)+((y)-1))&(~((uintp"
	    "tr_t)(y)-1UL))) /* PWR2(y) true */\n\n/*************************"
	    "*********************************************\n * FlexeLint "
	    "and compiler shutuppery\n */\n\n/*\n * In OO-light situations, "
	    "functions have to match their prototype\n * even if that means "
	    "not const'ing a const'able argument.\n * The typedef should "
	    "be specified as argument to the macro.\n */\n#define __match_pro"
	    "to__(xxx)\t\t/*lint -e{818} */\n\n/*\n * State variables may "
	    "change value before we have considered the\n * previous value\n"
	    " */\n#define __state_variable__(varname)\tvarname /*lint -esym(8"
	    "38,varname) */\n\n#ifdef __SUNPRO_C\n#define NEEDLESS(s)\t\t"
	    "{}\n#define __unused\n#else\n#define NEEDLESS(s)\t\ts\n"
	    "#endif\n\n#endif /* VDEF_H_INCLUDED */\n"
	);
	VSB_cat(sb, "\n");

	/* ../include/vcl.h */

	VSB_cat(sb, "/* ---===### include/vcl.h ###===--- */\n\n");
	VSB_cat(sb, "/*\n * NB:  This file is machine generated, DO "
	    "NOT EDIT!\n *\n * Edit and run lib/libvcc/generate.py instead.\n"
	    " */\n\n\nstruct vrt_ctx;\n#define VRT_CTX const struct vrt_ctx "
	    "*ctx\nstruct req;\nstruct busyobj;\nstruct ws;\nstruct cli;\n"
	    "struct worker;\n\nenum vcl_event_e {\n\tVCL_EVENT_LOAD,\n"
	    "\tVCL_EVENT_WARM,\n\tVCL_EVENT_COLD,\n\tVCL_EVENT_DISCARD,\n"
	    "};\n\ntypedef int vcl_event_f(VRT_CTX, enum vcl_event_e);\n"
	    "typedef int vcl_init_f(VRT_CTX);\ntypedef void vcl_fini_f(VRT_CT"
	    "X);\ntypedef void vcl_func_f(VRT_CTX);\n\n/* VCL Methods */\n"
	    "#define VCL_MET_RECV\t\t\t(1U << 1)\n#define VCL_MET_PIPE\t"
	    "\t\t(1U << 2)\n#define VCL_MET_PASS\t\t\t(1U << 3)\n"
	    "#define VCL_MET_HASH\t\t\t(1U << 4)\n#define VCL_MET_PURGE\t"
	    "\t\t(1U << 5)\n#define VCL_MET_MISS\t\t\t(1U << 6)\n"
	    "#define VCL_MET_HIT\t\t\t(1U << 7)\n#define VCL_MET_DELIVER\t"
	    "\t\t(1U << 8)\n#define VCL_MET_SYNTH\t\t\t(1U << 9)\n"
	    "#define VCL_MET_BACKEND_FETCH\t\t(1U << 10)\n#define VCL_MET_BAC"
	    "KEND_RESPONSE\t(1U << 11)\n#define VCL_MET_BACKEND_ERROR\t\t"
	    "(1U << 12)\n#define VCL_MET_INIT\t\t\t(1U << 13)\n"
	    "#define VCL_MET_FINI\t\t\t(1U << 14)\n\n#define VCL_MET_MAX\t"
	    "\t\t15\n\n#define VCL_MET_MASK\t\t\t0x7fff\n\n/* VCL Returns "
	    "*/\n#define VCL_RET_ABANDON\t\t\t1\n#define VCL_RET_DELIVER\t"
	    "\t\t2\n#define VCL_RET_FAIL\t\t\t3\n#define VCL_RET_FETCH\t"
	    "\t\t4\n#define VCL_RET_HASH\t\t\t5\n#define VCL_RET_LOOKUP\t"
	    "\t\t6\n#define VCL_RET_MISS\t\t\t7\n#define VCL_RET_OK\t\t\t"
	    "8\n#define VCL_RET_PASS\t\t\t9\n#define VCL_RET_PIPE\t\t\t10\n"
	    "#define VCL_RET_PURGE\t\t\t11\n#define VCL_RET_RESTART\t\t\t"
	    "12\n#define VCL_RET_RETRY\t\t\t13\n#define VCL_RET_SYNTH\t\t"
	    "\t14\n#define VCL_RET_VCL\t\t\t15\n\n#define VCL_RET_MAX\t\t"
	    "\t16\n\nstruct VCL_conf {\n\tunsigned\t\t\tmagic;\n"
	    "#define VCL_CONF_MAGIC\t\t\t0x7406c509\t/* from /dev/random "
	    "*/\n\n\tstruct director\t\t\t**default_director;\n"
	    "\tconst struct vrt_backend_probe\t*default_probe;\n"
	    "\tunsigned\t\t\tnref;\n\tstruct vrt_ref\t\t\t*ref;\n"
	    "\n\tunsigned\t\t\tnsrc;\n\tconst char\t\t\t**srcname;\n"
	    "\tconst char\t\t\t**srcbody;\n\n\tvcl_event_f\t\t\t*event_vcl;\n"
	    "\tvcl_func_f\t*recv_func;\n\tvcl_func_f\t*pipe_func;\n"
	    "\tvcl_func_f\t*pass_func;\n\tvcl_func_f\t*hash_func;\n"
	    "\tvcl_func_f\t*purge_func;\n\tvcl_func_f\t*miss_func;\n"
	    "\tvcl_func_f\t*hit_func;\n\tvcl_func_f\t*deliver_func;\n"
	    "\tvcl_func_f\t*synth_func;\n\tvcl_func_f\t*backend_fetch_func;\n"
	    "\tvcl_func_f\t*backend_response_func;\n\tvcl_func_f\t*backend_er"
	    "ror_func;\n\tvcl_func_f\t*init_func;\n\tvcl_func_f\t*fini_func;\n"
	    "\n};\n"
	);
	VSB_cat(sb, "\n");

	/* ../include/vrt.h */

	VSB_cat(sb, "/* ---===### include/vrt.h ###===--- */\n\n");
	VSB_cat(sb, "/*-\n * Copyright (c) 2006 Verdens Gang AS\n"
	    " * Copyright (c) 2006-2015 Varnish Software AS\n * All rights "
	    "reserved.\n *\n * Author: Poul-Henning Kamp <phk@phk.freebsd.dk>"
	    "\n *\n * Redistribution and use in source and binary forms, "
	    "with or without\n * modification, are permitted provided that "
	    "the following conditions\n * are met:\n * 1. Redistributions "
	    "of source code must retain the above copyright\n *    notice, "
	    "this list of conditions and the following disclaimer.\n"
	    " * 2. Redistributions in binary form must reproduce the above "
	    "copyright\n *    notice, this list of conditions and the followi"
	    "ng disclaimer in the\n *    documentation and/or other materials"
	    " provided with the distribution.\n *\n * THIS SOFTWARE IS "
	    "PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND\n"
	    " * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED"
	    " TO, THE\n * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS "
	    "FOR A PARTICULAR PURPOSE\n * ARE DISCLAIMED.  IN NO EVENT "
	    "SHALL AUTHOR OR CONTRIBUTORS BE LIABLE\n * FOR ANY DIRECT, "
	    "INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL\n"
	    " * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF "
	    "SUBSTITUTE GOODS\n * OR SERVICES; LOSS OF USE, DATA, OR PROFITS;"
	    " OR BUSINESS INTERRUPTION)\n * HOWEVER CAUSED AND ON ANY THEORY "
	    "OF LIABILITY, WHETHER IN CONTRACT, STRICT\n * LIABILITY, OR "
	    "TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY\n"
	    " * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE "
	    "POSSIBILITY OF\n * SUCH DAMAGE.\n *\n * Runtime support for "
	    "compiled VCL programs and VMODs.\n *\n * NB: When this file "
	    "is changed, lib/libvcc/generate.py *MUST* be rerun.\n"
	    " */\n\n/********************************************************"
	    "***************\n * Major and minor VRT API versions.\n"
	    " *\n * Whenever something is added, increment MINOR version\n"
	    " * Whenever something is deleted or changed in a way which "
	    "is not\n * binary/load-time compatible, increment MAJOR version\n"
	    " *\n *\n * 6.1 (unreleased):\n *\thttp_CollectHdrSep added\n"
	    " * 6.0 (2017-03-15):\n *\tVRT_hit_for_pass added\n"
	    " *\tVRT_ipcmp added\n *\tVRT_Vmod_Init signature changed\n"
	    " *\tVRT_vcl_lookup removed\n *\tVRT_vcl_get added\n"
	    " *\tVRT_vcl_rel added\n *\tVRT_fail added\n *\tWS_Reset and "
	    "WS_Snapshot signatures changed\n *\tWS_Front added\n"
	    " *\tWS_ReserveLumps added\n *\tWS_Inside added\n *\tWS_Assert_Al"
	    "located added\n * 5.0:\n *\tVarnish 5.0 release \"better safe "
	    "than sorry\" bump\n * 4.0:\n *\tVCL_BYTES changed to long "
	    "long\n *\tVRT_CacheReqBody changed signature\n * 3.2:\n"
	    " *\tvrt_backend grew .proxy_header field\n *\tvrt_ctx grew "
	    ".sp field.\n *\tvrt_acl type added\n */\n\n#define VRT_MAJOR_VER"
	    "SION\t6U\n\n#define VRT_MINOR_VERSION\t0U\n\n\n/****************"
	    "*******************************************************/\n"
	    "\n#ifdef __v_printflike\n#  define __vrt_printflike(a,b) __v_pri"
	    "ntflike(a,b)\n#else\n#  define __vrt_printflike(a,b)\n"
	    "#endif\n\nstruct VCL_conf;\nstruct vrt_acl;\nstruct busyobj;\n"
	    "struct director;\nstruct http;\nstruct req;\nstruct stevedore;\n"
	    "struct suckaddr;\nstruct vcl;\nstruct vmod;\nstruct vsb;\n"
	    "struct vsl_log;\nstruct ws;\n\n/********************************"
	    "***************************************\n * This is the central "
	    "definition of the mapping from VCL types to\n * C-types.  "
	    "The python scripts read these from here.\n * (alphabetic order)\n"
	    " */\n\ntypedef const struct vrt_acl *\t\t\tVCL_ACL;\n"
	    "typedef const struct director *\t\t\tVCL_BACKEND;\n"
	    "typedef const struct vmod_priv *\t\tVCL_BLOB;\ntypedef const "
	    "char *\t\t\t\tVCL_BODY;\ntypedef unsigned\t\t\t\tVCL_BOOL;\n"
	    "typedef long long\t\t\t\tVCL_BYTES;\ntypedef double\t\t\t\t"
	    "\tVCL_DURATION;\ntypedef const char *\t\t\t\tVCL_ENUM;\n"
	    "typedef const struct gethdr_s *\t\t\tVCL_HEADER;\n"
	    "typedef struct http *\t\t\t\tVCL_HTTP;\ntypedef void\t\t\t\t"
	    "\tVCL_INSTANCE;\ntypedef long\t\t\t\t\tVCL_INT;\n"
	    "typedef const struct suckaddr *\t\t\tVCL_IP;\ntypedef const "
	    "struct vrt_backend_probe *\tVCL_PROBE;\ntypedef double\t\t\t"
	    "\t\tVCL_REAL;\ntypedef const struct stevedore *\t\tVCL_STEVEDORE"
	    ";\ntypedef const char *\t\t\t\tVCL_STRING;\ntypedef double\t"
	    "\t\t\t\tVCL_TIME;\ntypedef struct vcl *\t\t\t\tVCL_VCL;\n"
	    "typedef void\t\t\t\t\tVCL_VOID;\n\n/****************************"
	    "*******************************************\n * This is the "
	    "composite argument we pass to compiled VCL and VRT\n"
	    " * functions.\n */\n\nstruct vrt_ctx {\n\tunsigned\t\t\tmagic;\n"
	    "#define VRT_CTX_MAGIC\t\t\t0x6bb8f0db\n\n\tunsigned\t\t\tmethod;"
	    "\n\tunsigned\t\t\t*handling;\n\n\tstruct vsb\t\t\t*msg;\t// "
	    "Only in ...init()\n\tstruct vsl_log\t\t\t*vsl;\n\tstruct vcl\t"
	    "\t\t*vcl;\n\tstruct ws\t\t\t*ws;\n\n\tstruct sess\t\t\t*sp;\n"
	    "\n\tstruct req\t\t\t*req;\n\tstruct http\t\t\t*http_req;\n"
	    "\tstruct http\t\t\t*http_req_top;\n\tstruct http\t\t\t*http_resp"
	    ";\n\n\tstruct busyobj\t\t\t*bo;\n\tstruct http\t\t\t*http_bereq;"
	    "\n\tstruct http\t\t\t*http_beresp;\n\n\tdouble\t\t\t\tnow;\n"
	    "\n\t/*\n\t * method specific argument:\n\t *    hash:\t\tstruct "
	    "SHA256Context\n\t *    synth+error:\tstruct vsb *\n"
	    "\t */\n\tvoid\t\t\t\t*specific;\n};\n\n#define VRT_CTX\t\tconst "
	    "struct vrt_ctx *ctx\n\n/****************************************"
	    "*******************************/\n\nstruct vmod_data {\n"
	    "\t/* The version/id fields must be first, they protect the "
	    "rest */\n\tunsigned\t\t\tvrt_major;\n\tunsigned\t\t\tvrt_minor;\n"
	    "\tconst char\t\t\t*file_id;\n\n\tconst char\t\t\t*name;\n"
	    "\tconst void\t\t\t*func;\n\tint\t\t\t\tfunc_len;\n"
	    "\tconst char\t\t\t*proto;\n\tconst char\t\t\t* const *spec;\n"
	    "\tconst char\t\t\t*abi;\n};\n\n/********************************"
	    "***************************************/\n\nenum gethdr_e "
	    "{ HDR_REQ, HDR_REQ_TOP, HDR_RESP, HDR_OBJ, HDR_BEREQ,\n"
	    "\t\tHDR_BERESP };\n\nstruct gethdr_s {\n\tenum gethdr_e\twhere;\n"
	    "\tconst char\t*what;\n};\n\nextern const void * const vrt_magic_"
	    "string_end;\nextern const void * const vrt_magic_string_unset;\n"
	    "\n/*************************************************************"
	    "**********\n * We want the VCC to spit this structs out as "
	    "const, but when VMODs\n * come up with them we want to clone "
	    "them into malloc'ed space which\n * we can free again.\n"
	    " * We collect all the knowledge here by macroizing the fields "
	    "and make\n * a macro for handling them all.\n * See also: "
	    " cache_backend.h & cache_backend_cfg.c\n * One of those things.."
	    ".\n */\n\n#define VRT_BACKEND_FIELDS(rigid)\t\t\t\t\\\n"
	    "\trigid char\t\t\t*vcl_name;\t\t\\\n\trigid char\t\t\t*ipv4_addr"
	    ";\t\t\\\n\trigid char\t\t\t*ipv6_addr;\t\t\\\n\trigid char\t"
	    "\t\t*port;\t\t\t\\\n\trigid char\t\t\t*hosthdr;\t\t\\\n"
	    "\tdouble\t\t\t\tconnect_timeout;\t\\\n\tdouble\t\t\t\tfirst_byte"
	    "_timeout;\t\\\n\tdouble\t\t\t\tbetween_bytes_timeout;\t\\\n"
	    "\tunsigned\t\t\tmax_connections;\t\\\n\tunsigned\t\t\tproxy_head"
	    "er;\n\n#define VRT_BACKEND_HANDLE()\t\t\t\\\n\tdo {\t\t\t\t"
	    "\t\\\n\t\tDA(vcl_name);\t\t\t\\\n\t\tDA(ipv4_addr);\t\t\t\\\n"
	    "\t\tDA(ipv6_addr);\t\t\t\\\n\t\tDA(port);\t\t\t\\\n"
	    "\t\tDA(hosthdr);\t\t\t\\\n\t\tDN(connect_timeout);\t\t\\\n"
	    "\t\tDN(first_byte_timeout);\t\t\\\n\t\tDN(between_bytes_timeout)"
	    ";\t\\\n\t\tDN(max_connections);\t\t\\\n\t\tDN(proxy_header);\t"
	    "\t\\\n\t} while(0)\n\nstruct vrt_backend {\n\tunsigned\t\t\t"
	    "magic;\n#define VRT_BACKEND_MAGIC\t\t0x4799ce6b\n"
	    "\tVRT_BACKEND_FIELDS(const)\n\tconst struct suckaddr\t\t*ipv4_su"
	    "ckaddr;\n\tconst struct suckaddr\t\t*ipv6_suckaddr;\n"
	    "\tconst struct vrt_backend_probe\t*probe;\n};\n\n"
	    "#define VRT_BACKEND_PROBE_FIELDS(rigid)\t\t\t\t\\\n"
	    "\tdouble\t\t\t\ttimeout;\t\t\\\n\tdouble\t\t\t\tinterval;\t"
	    "\t\\\n\tunsigned\t\t\texp_status;\t\t\\\n\tunsigned\t\t\twindow;"
	    "\t\t\t\\\n\tunsigned\t\t\tthreshold;\t\t\\\n\tunsigned\t\t\t"
	    "initial;\n\n#define VRT_BACKEND_PROBE_HANDLE()\t\t\\\n"
	    "\tdo {\t\t\t\t\t\\\n\t\tDN(timeout);\t\t\t\\\n\t\tDN(interval);\t"
	    "\t\t\\\n\t\tDN(exp_status);\t\t\t\\\n\t\tDN(window);\t\t\t\\\n"
	    "\t\tDN(threshold);\t\t\t\\\n\t\tDN(initial);\t\t\t\\\n"
	    "\t} while (0)\n\nstruct vrt_backend_probe {\n\tunsigned\t\t"
	    "\tmagic;\n#define VRT_BACKEND_PROBE_MAGIC\t\t0x84998490\n"
	    "\tconst char\t\t\t*url;\n\tconst char\t\t\t*request;\n"
	    "\tVRT_BACKEND_PROBE_FIELDS(const)\n};\n\n/**********************"
	    "*************************************************/\n"
	    "\n/*\n * other stuff.\n * XXX: document when bored\n"
	    " */\n\nstruct vrt_ref {\n\tunsigned\tsource;\n\tunsigned\toffset"
	    ";\n\tunsigned\tline;\n\tunsigned\tpos;\n\tconst char\t*token;\n"
	    "};\n\n/* ACL related */\n#define VRT_ACL_MAXADDR\t\t16\t/* "
	    "max(IPv4, IPv6) */\n\ntypedef int acl_match_f(VRT_CTX, const "
	    "VCL_IP);\n\nstruct vrt_acl {\n\tunsigned\tmagic;\n"
	    "#define VRT_ACL_MAGIC\t0x78329d96\n\tacl_match_f\t*match;\n"
	    "};\n\nvoid VRT_acl_log(VRT_CTX, const char *msg);\n"
	    "int VRT_acl_match(VRT_CTX, VCL_ACL, VCL_IP);\n\n/* req related "
	    "*/\n\nVCL_BYTES VRT_CacheReqBody(VRT_CTX, VCL_BYTES maxsize);\n"
	    "\n/* Regexp related */\nvoid VRT_re_init(void **, const char "
	    "*);\nvoid VRT_re_fini(void *);\nint VRT_re_match(VRT_CTX, "
	    "const char *, void *re);\nconst char *VRT_regsub(VRT_CTX, "
	    "int all, const char *, void *, const char *);\n\n"
	    "void VRT_ban_string(VRT_CTX, const char *);\nvoid VRT_purge(VRT_"
	    "CTX, double ttl, double grace, double keep);\n\nvoid VRT_count(V"
	    "RT_CTX, unsigned);\nvoid VRT_synth(VRT_CTX, unsigned, const "
	    "char *);\nvoid VRT_hit_for_pass(VRT_CTX, VCL_DURATION);\n"
	    "\nstruct http *VRT_selecthttp(VRT_CTX, enum gethdr_e);\n"
	    "const char *VRT_GetHdr(VRT_CTX, const struct gethdr_s *);\n"
	    "void VRT_SetHdr(VRT_CTX, const struct gethdr_s *, const char "
	    "*, ...);\nvoid VRT_handling(VRT_CTX, unsigned hand);\n"
	    "void VRT_fail(VRT_CTX, const char *fmt, ...) __vrt_printflike(2,"
	    "3);\n\nvoid VRT_hashdata(VRT_CTX, const char *str, ...);\n"
	    "\n/* Simple stuff */\nint VRT_strcmp(const char *s1, const "
	    "char *s2);\nvoid VRT_memmove(void *dst, const void *src, unsigne"
	    "d len);\nint VRT_ipcmp(const struct suckaddr *sua1, const "
	    "struct suckaddr *sua2);\n\nvoid VRT_Rollback(VRT_CTX, const "
	    "struct http *);\n\n/* Synthetic pages */\nvoid VRT_synth_page(VR"
	    "T_CTX, const char *, ...);\n\n/* Backend related */\n"
	    "struct director *VRT_new_backend(VRT_CTX, const struct vrt_backe"
	    "nd *);\nvoid VRT_delete_backend(VRT_CTX, struct director **);\n"
	    "\n/* Suckaddr related */\nint VRT_VSA_GetPtr(const struct "
	    "suckaddr *sua, const unsigned char ** dst);\n\n/* VMOD/Modules "
	    "related */\nint VRT_Vmod_Init(VRT_CTX, struct vmod **hdl, "
	    "void *ptr, int len,\n    const char *nm, const char *path, "
	    "const char *file_id, const char *backup);\nvoid VRT_Vmod_Fini(st"
	    "ruct vmod **hdl);\n\n/* VCL program related */\nVCL_VCL VRT_vcl_"
	    "get(VRT_CTX, const char *);\nvoid VRT_vcl_rel(VRT_CTX, VCL_VCL);"
	    "\nvoid VRT_vcl_select(VRT_CTX, VCL_VCL);\n\nstruct vmod_priv;\n"
	    "typedef void vmod_priv_free_f(void *);\nstruct vmod_pri");
	VSB_cat(sb, "v {\n\tvoid\t\t\t*priv;\n\tint\t\t\tlen;\n"
	    "\tvmod_priv_free_f\t*free;\n};\n\n#ifdef VCL_RET_MAX\n"
	    "typedef int vmod_event_f(VRT_CTX, struct vmod_priv *, enum "
	    "vcl_event_e);\n#endif\n\nstruct vclref;\nstruct vclref * VRT_ref"
	    "_vcl(VRT_CTX, const char *);\nvoid VRT_rel_vcl(VRT_CTX, struct "
	    "vclref **);\n\nvoid VRT_priv_fini(const struct vmod_priv *p);\n"
	    "struct vmod_priv *VRT_priv_task(VRT_CTX, void *vmod_id);\n"
	    "struct vmod_priv *VRT_priv_top(VRT_CTX, void *vmod_id);\n"
	    "\n/* Stevedore related functions */\nint VRT_Stv(const char "
	    "*nm);\nVCL_STEVEDORE VRT_stevedore(const char *nm);\n"
	    "\n/* Convert things to string */\n\nchar *VRT_IP_string(VRT_CTX,"
	    " VCL_IP);\nchar *VRT_INT_string(VRT_CTX, VCL_INT);\n"
	    "char *VRT_REAL_string(VRT_CTX, VCL_REAL);\nchar *VRT_TIME_string"
	    "(VRT_CTX, VCL_TIME);\nconst char *VRT_BOOL_string(VCL_BOOL);\n"
	    "const char *VRT_BACKEND_string(VCL_BACKEND);\nconst char *VRT_ST"
	    "EVEDORE_string(VCL_STEVEDORE);\nconst char *VRT_CollectString(VR"
	    "T_CTX, const char *p, ...);\n"
	);
	VSB_cat(sb, "\n");

	/* ../include/vrt_obj.h */

	VSB_cat(sb, "/* ---===### include/vrt_obj.h ###===--- */\n\n");
	VSB_cat(sb, "/*\n * NB:  This file is machine generated, DO "
	    "NOT EDIT!\n *\n * Edit and run lib/libvcc/generate.py instead.\n"
	    " */\n\n\nVCL_HTTP VRT_r_bereq(VRT_CTX);\n\nVCL_BACKEND VRT_r_ber"
	    "eq_backend(VRT_CTX);\nvoid VRT_l_bereq_backend(VRT_CTX, VCL_BACK"
	    "END);\n\nVCL_DURATION VRT_r_bereq_between_bytes_timeout(VRT_CTX)"
	    ";\nvoid VRT_l_bereq_between_bytes_timeout(VRT_CTX, VCL_DURATION)"
	    ";\n\nvoid VRT_l_bereq_body(VRT_CTX, const char *, ...);\n"
	    "\nVCL_DURATION VRT_r_bereq_connect_timeout(VRT_CTX);\n"
	    "void VRT_l_bereq_connect_timeout(VRT_CTX, VCL_DURATION);\n"
	    "\nVCL_DURATION VRT_r_bereq_first_byte_timeout(VRT_CTX);\n"
	    "void VRT_l_bereq_first_byte_timeout(VRT_CTX, VCL_DURATION);\n"
	    "\n\nVCL_STRING VRT_r_bereq_method(VRT_CTX);\nvoid VRT_l_bereq_me"
	    "thod(VRT_CTX, const char *, ...);\n\nVCL_STRING VRT_r_bereq_prot"
	    "o(VRT_CTX);\nvoid VRT_l_bereq_proto(VRT_CTX, const char *, "
	    "...);\n\nVCL_INT VRT_r_bereq_retries(VRT_CTX);\n\n"
	    "VCL_BOOL VRT_r_bereq_uncacheable(VRT_CTX);\n\nVCL_STRING VRT_r_b"
	    "ereq_url(VRT_CTX);\nvoid VRT_l_bereq_url(VRT_CTX, const char "
	    "*, ...);\n\nVCL_STRING VRT_r_bereq_xid(VRT_CTX);\n"
	    "\nVCL_HTTP VRT_r_beresp(VRT_CTX);\n\nVCL_DURATION VRT_r_beresp_a"
	    "ge(VRT_CTX);\n\nVCL_BACKEND VRT_r_beresp_backend(VRT_CTX);\n"
	    "\nVCL_IP VRT_r_beresp_backend_ip(VRT_CTX);\n\nVCL_STRING VRT_r_b"
	    "eresp_backend_name(VRT_CTX);\n\nvoid VRT_l_beresp_body(VRT_CTX, "
	    "const char *, ...);\n\nVCL_BOOL VRT_r_beresp_do_esi(VRT_CTX);\n"
	    "void VRT_l_beresp_do_esi(VRT_CTX, VCL_BOOL);\n\nVCL_BOOL VRT_r_b"
	    "eresp_do_gunzip(VRT_CTX);\nvoid VRT_l_beresp_do_gunzip(VRT_CTX, "
	    "VCL_BOOL);\n\nVCL_BOOL VRT_r_beresp_do_gzip(VRT_CTX);\n"
	    "void VRT_l_beresp_do_gzip(VRT_CTX, VCL_BOOL);\n\n"
	    "VCL_BOOL VRT_r_beresp_do_stream(VRT_CTX);\nvoid VRT_l_beresp_do_"
	    "stream(VRT_CTX, VCL_BOOL);\n\nVCL_DURATION VRT_r_beresp_grace(VR"
	    "T_CTX);\nvoid VRT_l_beresp_grace(VRT_CTX, VCL_DURATION);\n"
	    "\n\nVCL_DURATION VRT_r_beresp_keep(VRT_CTX);\nvoid VRT_l_beresp_"
	    "keep(VRT_CTX, VCL_DURATION);\n\nVCL_STRING VRT_r_beresp_proto(VR"
	    "T_CTX);\nvoid VRT_l_beresp_proto(VRT_CTX, const char *, ...);\n"
	    "\nVCL_STRING VRT_r_beresp_reason(VRT_CTX);\nvoid VRT_l_beresp_re"
	    "ason(VRT_CTX, const char *, ...);\n\nVCL_INT VRT_r_beresp_status"
	    "(VRT_CTX);\nvoid VRT_l_beresp_status(VRT_CTX, VCL_INT);\n"
	    "\nVCL_STEVEDORE VRT_r_beresp_storage(VRT_CTX);\nvoid VRT_l_beres"
	    "p_storage(VRT_CTX, VCL_STEVEDORE);\n\nVCL_STRING VRT_r_beresp_st"
	    "orage_hint(VRT_CTX);\nvoid VRT_l_beresp_storage_hint(VRT_CTX, "
	    "const char *, ...);\n\nVCL_DURATION VRT_r_beresp_ttl(VRT_CTX);\n"
	    "void VRT_l_beresp_ttl(VRT_CTX, VCL_DURATION);\n\n"
	    "VCL_BOOL VRT_r_beresp_uncacheable(VRT_CTX);\nvoid VRT_l_beresp_u"
	    "ncacheable(VRT_CTX, VCL_BOOL);\n\nVCL_BOOL VRT_r_beresp_was_304("
	    "VRT_CTX);\n\nVCL_STRING VRT_r_client_identity(VRT_CTX);\n"
	    "void VRT_l_client_identity(VRT_CTX, const char *, ...);\n"
	    "\nVCL_IP VRT_r_client_ip(VRT_CTX);\n\nVCL_IP VRT_r_local_ip(VRT_"
	    "CTX);\n\nVCL_TIME VRT_r_now(VRT_CTX);\n\nVCL_DURATION VRT_r_obj_"
	    "age(VRT_CTX);\n\nVCL_DURATION VRT_r_obj_grace(VRT_CTX);\n"
	    "\nVCL_INT VRT_r_obj_hits(VRT_CTX);\n\n\nVCL_DURATION VRT_r_obj_k"
	    "eep(VRT_CTX);\n\nVCL_STRING VRT_r_obj_proto(VRT_CTX);\n"
	    "\nVCL_STRING VRT_r_obj_reason(VRT_CTX);\n\nVCL_INT VRT_r_obj_sta"
	    "tus(VRT_CTX);\n\nVCL_DURATION VRT_r_obj_ttl(VRT_CTX);\n"
	    "\nVCL_BOOL VRT_r_obj_uncacheable(VRT_CTX);\n\nVCL_IP VRT_r_remot"
	    "e_ip(VRT_CTX);\n\nVCL_HTTP VRT_r_req(VRT_CTX);\n\n"
	    "VCL_BACKEND VRT_r_req_backend_hint(VRT_CTX);\nvoid VRT_l_req_bac"
	    "kend_hint(VRT_CTX, VCL_BACKEND);\n\nVCL_BOOL VRT_r_req_can_gzip("
	    "VRT_CTX);\n\nVCL_BOOL VRT_r_req_esi(VRT_CTX);\nvoid VRT_l_req_es"
	    "i(VRT_CTX, VCL_BOOL);\n\nVCL_INT VRT_r_req_esi_level(VRT_CTX);\n"
	    "\nVCL_BOOL VRT_r_req_hash_always_miss(VRT_CTX);\n"
	    "void VRT_l_req_hash_always_miss(VRT_CTX, VCL_BOOL);\n"
	    "\nVCL_BOOL VRT_r_req_hash_ignore_busy(VRT_CTX);\n"
	    "void VRT_l_req_hash_ignore_busy(VRT_CTX, VCL_BOOL);\n"
	    "\n\nVCL_STRING VRT_r_req_method(VRT_CTX);\nvoid VRT_l_req_method"
	    "(VRT_CTX, const char *, ...);\n\nVCL_STRING VRT_r_req_proto(VRT_"
	    "CTX);\nvoid VRT_l_req_proto(VRT_CTX, const char *, ...);\n"
	    "\nVCL_INT VRT_r_req_restarts(VRT_CTX);\n\nVCL_STEVEDORE VRT_r_re"
	    "q_storage(VRT_CTX);\nvoid VRT_l_req_storage(VRT_CTX, VCL_STEVEDO"
	    "RE);\n\nVCL_DURATION VRT_r_req_ttl(VRT_CTX);\nvoid VRT_l_req_ttl"
	    "(VRT_CTX, VCL_DURATION);\n\nVCL_STRING VRT_r_req_url(VRT_CTX);\n"
	    "void VRT_l_req_url(VRT_CTX, const char *, ...);\n"
	    "\nVCL_STRING VRT_r_req_xid(VRT_CTX);\n\n\nVCL_STRING VRT_r_req_t"
	    "op_method(VRT_CTX);\n\nVCL_STRING VRT_r_req_top_proto(VRT_CTX);\n"
	    "\nVCL_STRING VRT_r_req_top_url(VRT_CTX);\n\nVCL_HTTP VRT_r_resp("
	    "VRT_CTX);\n\nvoid VRT_l_resp_body(VRT_CTX, const char *, ...);\n"
	    "\n\nVCL_BOOL VRT_r_resp_is_streaming(VRT_CTX);\n\n"
	    "VCL_STRING VRT_r_resp_proto(VRT_CTX);\nvoid VRT_l_resp_proto(VRT"
	    "_CTX, const char *, ...);\n\nVCL_STRING VRT_r_resp_reason(VRT_CT"
	    "X);\nvoid VRT_l_resp_reason(VRT_CTX, const char *, ...);\n"
	    "\nVCL_INT VRT_r_resp_status(VRT_CTX);\nvoid VRT_l_resp_status(VR"
	    "T_CTX, VCL_INT);\n\nVCL_STRING VRT_r_server_hostname(VRT_CTX);\n"
	    "\nVCL_STRING VRT_r_server_identity(VRT_CTX);\n\nVCL_IP VRT_r_ser"
	    "ver_ip(VRT_CTX);\nlong long VRT_Stv_free_space(const char "
	    "*);\nlong long VRT_Stv_used_space(const char *);\n"
	    "unsigned VRT_Stv_happy(const char *);\n"
	);
	VSB_cat(sb, "\n");

}
