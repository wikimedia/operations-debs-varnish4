/*
 * NB:  This file is machine generated, DO NOT EDIT!
 *
 * Edit and run lib/libvcc/generate.py instead.
 */



#include "config.h"

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
	[FNUM] = "FNUM",
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
	    "POSSIBILITY OF\n * SUCH DAMAGE.\n *\n * Names of the form "
	    "\"v_[a-z_]*_\" is reserved for this file.\n *\n * This file "
	    "should always be the first non <...> include in a .c file.\n"
	    " */\n\n#ifdef VDEF_H_INCLUDED\n#  error \"vdef.h included "
	    "multiple times\"\n#endif\n#define VDEF_H_INCLUDED\n"
	    "\n/* Safe printf into a fixed-size buffer */\n#define bprintf(bu"
	    "f, fmt, ...)\t\t\t\t\t\t\\\n\tdo {\t\t\t\t\t\t\t\t\\\n"
	    "\t\tint ibprintf;\t\t\t\t\t\t\\\n\t\tibprintf = snprintf(buf, "
	    "sizeof buf, fmt, __VA_ARGS__);\t\\\n\t\tassert(ibprintf >= "
	    "0 && ibprintf < (int)sizeof buf);\t\\\n\t} while (0)\n"
	    "\n/* Safe printf into a fixed-size buffer */\n#define vbprintf(b"
	    "uf, fmt, ap)\t\t\t\t\t\t\\\n\tdo {\t\t\t\t\t\t\t\t\\\n"
	    "\t\tint ivbprintf;\t\t\t\t\t\t\\\n\t\tivbprintf = vsnprintf(buf,"
	    " sizeof buf, fmt, ap);\t\\\n\t\tassert(ivbprintf >= 0 && ivbprin"
	    "tf < (int)sizeof buf);\t\\\n\t} while (0)\n\n/* Close and "
	    "discard filedescriptor */\n#define closefd(fdp)\t\t\t\t\\\n"
	    "\tdo {\t\t\t\t\t\\\n\t\tassert(*(fdp) >= 0);\t\t\\\n"
	    "\t\tAZ(close(*(fdp)));\t\t\\\n\t\t*(fdp) = -1;\t\t\t\\\n"
	    "\t} while (0)\n\n#ifndef __GNUC_PREREQ__\n# if defined __GNUC__ "
	    "&& defined __GNUC_MINOR__\n#  define __GNUC_PREREQ__(maj, "
	    "min) \\\n\t(__GNUC__ > (maj) || (__GNUC__ == (maj) && __GNUC_MIN"
	    "OR__ >= (min)))\n# else\n#  define __GNUC_PREREQ__(maj, min) "
	    "0\n# endif\n#endif\n\n#ifdef __printflike\n#  define v_printflik"
	    "e_(f,a) __printflike(f,a)\n#elif __GNUC_PREREQ__(2, 95) || "
	    "defined(__INTEL_COMPILER)\n#  define v_printflike_(f,a) __attrib"
	    "ute__((format(printf, f, a)))\n#else\n#  define v_printflike_(f,"
	    "a)\n#endif\n\n#define v_noreturn_ __attribute__((__noreturn__))\n"
	    "\n#ifdef __GNUC__\n#  define v_deprecated_ __attribute__((deprec"
	    "ated))\n#else\n#  define v_deprecated_\n#endif\n\n"
	    "/***************************************************************"
	    "******\n * Pointer alignment magic\n */\n\n#if defined(__sparc__"
	    ")\n/* NB: Overbroad test for 32bit userland on 64bit SPARC "
	    "cpus. */\n#  define PALGN\t    (sizeof(double) - 1)\t/* size "
	    "of alignment */\n#else\n#  define PALGN\t    (sizeof(void "
	    "*) - 1)\t/* size of alignment */\n#endif\n#define PAOK(p)\t"
	    "    (((uintptr_t)(p) & PALGN) == 0)\t/* is aligned */\n"
	    "#define PRNDDN(p)   ((uintptr_t)(p) & ~PALGN)\t\t/* Round "
	    "down */\n#define PRNDUP(p)   (((uintptr_t)(p) + PALGN) & ~PALGN)"
	    "\t/* Round up */\n\n/*******************************************"
	    "**************************\n * To be used as little as possible "
	    "to wash off const/volatile etc.\n */\n#define TRUST_ME(ptr)\t"
	    "((void*)(uintptr_t)(ptr))\n\n/**********************************"
	    "************************************\n * Generic power-2 roundin"
	    "g macros\n */\n\n#define PWR2(x)     ((((x)-1UL)&(x))==0)\t"
	    "\t/* Is a power of two */\n#define RDN2(x, y)  ((x)&(~((uintptr_"
	    "t)(y)-1UL)))\t/* PWR2(y) true */\n#define RUP2(x, y)  (((x)+((y)"
	    "-1))&(~((uintptr_t)(y)-1UL))) /* PWR2(y) true */\n"
	    "\n/*************************************************************"
	    "*********\n * FlexeLint and compiler shutuppery\n"
	    " */\n\n/*\n * In OO-light situations, functions have to match "
	    "their prototype\n * even if that means not const'ing a const'abl"
	    "e argument.\n * The typedef should be specified as argument "
	    "to the macro.\n */\n#define v_matchproto_(xxx)\t\t/*lint --e{818"
	    "} */\n\n/*\n * State variables may change value before we "
	    "have considered the\n * previous value\n */\n#define v_statevari"
	    "able_(varname)\tvarname /*lint -esym(838,varname) */\n"
	    "\n#ifdef __SUNPRO_C\n#define NEEDLESS(s)\t\t{}\n#else\n"
	    "#define NEEDLESS(s)\t\ts\n#endif\n\n#if __GNUC_PREREQ__(2, "
	    "7)\n#  define v_unused_ __attribute__((__unused__))\n"
	    "#else\n#  define v_unused_\n#endif\n\n/*\n * Most of this "
	    "nightmare is stolen from FreeBSD's <cdefs.h>\n */\n"
	    "#ifndef __has_extension\n#  define __has_extension(x)\t0\n"
	    "#endif\n\n#if defined(_Static_assert)\n    /* Nothing, somebody "
	    "already did this for us */\n#elif __has_extension(c_static_asser"
	    "t)\n    /* Nothing, we should be fine */\n#elif (defined(__cplus"
	    "plus) && __cplusplus >= 201103L) || \\\n       __has_extension(c"
	    "xx_static_assert)\n#   define _Static_assert(x, y)\tstatic_asser"
	    "t(x, y)\n#elif __GNUC_PREREQ__(4,6) && !defined(__cplusplus)\n"
	    "    /* Nothing, gcc 4.6 and higher has _Static_assert built-in "
	    "*/\n#else\n#   if defined(__COUNTER__)\n#\tdefine _Static_assert"
	    "(x, y)\t__Static_assert(x, __COUNTER__)\n#   else\n"
	    "#\tdefine _Static_assert(x, y)\t__Static_assert(x, __LINE__)\n"
	    "#   endif\n#   define __Static_assert(x, y)\t___Static_assert(x,"
	    " y)\n#   define ___Static_assert(x, y) \\\n\t\ttypedef char "
	    "__assert_## y[(x) ? 1 : -1] v_unused_\n#endif\n\n"
	    "/* VTIM API overhaul WIP */\ntypedef double vtim_mono;\n"
	    "typedef double vtim_real;\ntypedef double vtim_dur;\n"
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
	    " */\n\n#ifdef CACHE_H_INCLUDED\n#  error \"vrt.h included "
	    "after cache.h - they are inclusive\"\n#endif\n\n#ifdef VRT_H_INC"
	    "LUDED\n#  error \"vrt.h included multiple times\"\n"
	    "#endif\n#define VRT_H_INCLUDED\n\n#ifndef VDEF_H_INCLUDED\n"
	    "#  error \"include vdef.h before vrt.h\"\n#endif\n"
	    "\n/*************************************************************"
	    "**********\n * Major and minor VRT API versions.\n"
	    " *\n * Whenever something is added, increment MINOR version\n"
	    " * Whenever something is deleted or changed in a way which "
	    "is not\n * binary/load-time compatible, increment MAJOR version\n"
	    " *\n *\n * 7.1 (unreleased)\n *\tVRT_Strands() added\n"
	    " *\tVRT_StrandsWS() added\n *\tVRT_CollectStrands() added\n"
	    " *\tVRT_STRANDS_string() removed from vrt.h (never implemented)\n"
	    " * 7.0 (2018-03-15)\n *\tlots of stuff moved from cache.h "
	    "to cache_varnishd.h\n *\t   (ie: from \"$Abi vrt\" to \"$Abi "
	    "strict\")\n *\tVCL_INT and VCL_BYTES are always 64 bits.\n"
	    " *\tpath field added to struct vrt_backend\n *\tVRT_Healthy() "
	    "added\n *\tVRT_VSC_Alloc() added\n *\tVRT_VSC_Destroy() added\n"
	    " *\tVRT_VSC_Hide() added\n *\tVRT_VSC_Reveal() added\n"
	    " *\tVRT_VSC_Overhead() added\n *\tstruct director.event added\n"
	    " *\tstruct director.destroy added\n *\tVRT_r_beresp_storage_hint"
	    "() VCL <= 4.0  #2509\n *\tVRT_l_beresp_storage_hint() VCL "
	    "<= 4.0  #2509\n *\tVRT_blob() added\n *\tVCL_STRANDS added\n"
	    " * 6.1 (2017-09-15 aka 5.2)\n *\thttp_CollectHdrSep added\n"
	    " *\tVRT_purge modified (may fail a transaction, signature "
	    "changed)\n *\tVRT_r_req_hash() added\n *\tVRT_r_bereq_hash() "
	    "added\n * 6.0 (2017-03-15):\n *\tVRT_hit_for_pass added\n"
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
	    "SION\t7U\n\n#define VRT_MINOR_VERSION\t1U\n\n/******************"
	    "*****************************************************/\n"
	    "\n#include <stddef.h>\t\t// NULL, size_t\n#include <stdint.h>\t"
	    "\t// [u]int%d_t\n\nstruct VCL_conf;\nstruct busyobj;\n"
	    "struct director;\nstruct http;\nstruct req;\nstruct stevedore;\n"
	    "struct suckaddr;\nstruct vcl;\nstruct vmod;\nstruct vmod_priv;\n"
	    "struct vrt_acl;\nstruct vsb;\nstruct vsc_seg;\nstruct vsmw_clust"
	    "er;\nstruct vsl_log;\nstruct ws;\nstruct VSC_main;\n"
	    "\nstruct strands {\n\tint\t\tn;\n\tconst char\t**p;\n"
	    "};\n\n/*********************************************************"
	    "**************\n * This is the central definition of the mapping"
	    " from VCL types to\n * C-types.  The python scripts read these "
	    "from here.\n * (alphabetic order)\n */\n\ntypedef const struct "
	    "vrt_acl *\t\t\tVCL_ACL;\ntypedef const struct director *\t\t"
	    "\tVCL_BACKEND;\ntypedef const struct vmod_priv *\t\tVCL_BLOB;\n"
	    "typedef const char *\t\t\t\tVCL_BODY;\ntypedef unsigned\t\t"
	    "\t\tVCL_BOOL;\ntypedef int64_t\t\t\t\t\tVCL_BYTES;\n"
	    "typedef vtim_dur\t\t\t\tVCL_DURATION;\ntypedef const char "
	    "*\t\t\t\tVCL_ENUM;\ntypedef const struct gethdr_s *\t\t\tVCL_HEA"
	    "DER;\ntypedef struct http *\t\t\t\tVCL_HTTP;\ntypedef void\t"
	    "\t\t\t\tVCL_INSTANCE;\ntypedef int64_t\t\t\t\t\tVCL_INT;\n"
	    "typedef const struct suckaddr *\t\t\tVCL_IP;\ntypedef const "
	    "struct vrt_backend_probe *\tVCL_PROBE;\ntypedef double\t\t\t"
	    "\t\tVCL_REAL;\ntypedef const struct stevedore *\t\tVCL_STEVEDORE"
	    ";\ntypedef const struct strands *\t\t\tVCL_STRANDS;\n"
	    "typedef const char *\t\t\t\tVCL_STRING;\ntypedef vtim_real\t"
	    "\t\t\tVCL_TIME;\ntypedef struct vcl *\t\t\t\tVCL_VCL;\n"
	    "typedef void\t\t\t\t\tVCL_VOID;\n\nstruct vrt_type {\n"
	    "\tunsigned\t\t\tmagic;\n#define VRT_TYPE_MAGIC\t\t\t0xa943bc32\n"
	    "\tconst char\t\t\t*lname;\n\tconst char\t\t\t*uname;\n"
	    "\tconst char\t\t\t*ctype;\n\tsize_t\t\t\t\tszof;\n"
	    "};\n\n/*********************************************************"
	    "**************\n * This is the composite argument we pass "
	    "to compiled VCL and VRT\n * functions.\n */\n\nstruct vrt_ctx "
	    "{\n\tunsigned\t\t\tmagic;\n#define VRT_CTX_MAGIC\t\t\t0x6bb8f0db"
	    "\n\n\tunsigned\t\t\tsyntax;\n\tunsigned\t\t\tmethod;\n"
	    "\tunsigned\t\t\t*handling;\t// not in director context\n"
	    "\tunsigned\t\t\tvclver;\n\n\tstruct vsb\t\t\t*msg;\t// Only "
	    "in ...init()\n\tstruct vsl_log\t\t\t*vsl;\n\tstruct vcl\t\t"
	    "\t*vcl;\n\tstruct ws\t\t\t*ws;\n\n\tstruct sess\t\t\t*sp;\n"
	    "\n\tstruct req\t\t\t*req;\n\tstruct http\t\t\t*http_req;\n"
	    "\tstruct http\t\t\t*http_req_top;\n\tstruct http\t\t\t*http_resp"
	    ";\n\n\tstruct busyobj\t\t\t*bo;\n\tstruct http\t\t\t*http_bereq;"
	    "\n\tstruct http\t\t\t*http_beresp;\n\n\tvtim_real\t\t\tnow;\n"
	    "\n\t/*\n\t * method specific argument:\n\t *    hash:\t\tstruct "
	    "VSHA256Context\n\t *    synth+error:\tstruct vsb *\n"
	    "\t */\n\tvoid\t\t\t\t*specific;\n};\n\n#define VRT_CTX\t\tconst "
	    "struct vrt_ctx *ctx\n\n/****************************************"
	    "*******************************\n * This is the interface "
	    "structure to a compiled VMOD\n */\n\nstruct vmod_data {\n"
	    "\t/* The version/id fields must be first, they protect the "
	    "rest */\n\tunsigned\t\t\tvrt_major;\n\tunsigned\t\t\tvrt_minor;\n"
	    "\tconst char\t\t\t*file_id;\n\n\tconst char\t\t\t*name;\n"
	    "\tconst void\t\t\t*func;\n\tint\t\t\t\tfunc_len;\n"
	    "\tconst char\t\t\t*proto;\n\tconst char\t\t\t*json;\n"
	    "\tconst char\t\t\t*abi;\n};\n\n/********************************"
	    "***************************************\n * Enum for events "
	    "sent to compiled VCL and from there to Vmods\n */\n"
	    "\nenum vcl_event_e {\n\tVCL_EVENT_LOAD,\n\tVCL_EVENT_WARM,\n"
	    "\tVCL_EVENT_COLD,\n\tVCL_EVENT_DISCARD,\n};\n\n/****************"
	    "*******************************************************/\n"
	    "\nextern const void * const vrt_magic_string_end;\n"
	    "extern const void * const vrt_magic_string_unset;\n"
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
	    "\t\t*port;\t\t\t\\\n\trigid char\t\t\t*path;\t\t\t\\\n"
	    "\trigid char\t\t\t*hosthdr;\t\t\\\n\tvtim_dur\t\t\tconnect_timeo"
	    "ut;\t\\\n\tvtim_dur\t\t\tfirst_byte_timeout;\t\\\n"
	    "\tvtim_dur\t\t\tbetween_bytes_timeout;\t\\\n\tunsigned\t\t\t"
	    "max_connections;\t\\\n\tunsigned\t\t\tproxy_header;\n"
	    "\n#define VRT_BACKEND_HANDLE()\t\t\t\\\n\tdo {\t\t\t\t\t\\\n"
	    "\t\tDA(vcl_name);\t\t\t\\\n\t\tDA(ipv4_addr);\t\t\t\\\n"
	    "\t\tDA(ipv6_addr);\t\t\t\\\n\t\tDA(port);\t\t\t\\\n"
	    "\t\tDA(path);\t\t\t\\\n\t\tDA(hosthdr);\t\t\t\\\n"
	    "\t\tDN(connect_timeout);\t\t\\\n\t\tDN(first_byte_timeout);\t"
	    "\t\\\n\t\tDN(between_bytes_timeout);\t\\\n\t\tDN(max_connections"
	    ");\t\t\\\n\t\tDN(proxy_header);\t\t\\\n\t} while(0)\n"
	    "\nstruct vrt_backend {\n\tunsigned\t\t\tmagic;\n#define VRT_BACK"
	    "END_MAGIC\t\t0x4799ce6b\n\tVRT_BACKEND_FIELDS(const)\n"
	    "\tconst struct suckaddr\t\t*ipv4_suckaddr;\n\tconst struct "
	    "suckaddr\t\t*ipv6_suckaddr;\n\tconst struct vrt_backend_probe\t"
	    "*probe;\n};\n\n#define VRT_BACKEND_PROBE_FIELDS(rigid)\t\t\t"
	    "\t\\\n\tvtim_dur\t\t\ttimeout;\t\t\\\n\tvtim_dur\t\t\tinterval;\t"
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
	    "*************************************************\n"
	    " * VRT_count() refers to this structure for coordinates into "
	    "the VCL source.\n */\n\nstruct vrt_ref {\n\tunsigned\tsource;\n"
	    "\tunsigned\toffset;\n\tunsigned\tline;\n\tunsigned\tpos;\n"
	    "\tconst char\t*token;\n};\n\nvoid VRT_count(VRT_CTX, unsigned);\n"
	    "\n/*************************************************************"
	    "**********\n * Implementation details of ACLs\n */\n"
	    "\ntypedef int acl_match_f(VRT_CTX, const VCL_IP);\n"
	    "\nstruct vrt_acl {\n\tunsigned\tmagic;\n#define VRT_ACL_MAGIC\t"
	    "0x78329d96\n\tacl_match_f\t*match;\n};\n\nvoid VRT_acl_log(VRT_C"
	    "TX, const char *);\nint VRT_acl_match(VRT_CTX, VCL_ACL, VCL_IP);"
	    "\n\n/********************************************************");
	VSB_cat(sb, "***************\n * Compile time regexp\n"
	    " */\n\nvoid VRT_re_init(void **, const char *);\n"
	    "void VRT_re_fini(void *);\nint VRT_re_match(VRT_CTX, const "
	    "char *, void *);\n\n/*******************************************"
	    "****************************\n * Getting hold of the various "
	    "struct http\n */\n\nenum gethdr_e {\n\tHDR_REQ,\n"
	    "\tHDR_REQ_TOP,\n\tHDR_RESP,\n\tHDR_OBJ,\n\tHDR_BEREQ,\n"
	    "\tHDR_BERESP\n};\n\nstruct gethdr_s {\n\tenum gethdr_e\twhere;\n"
	    "\tconst char\t*what;\n};\n\nVCL_HTTP VRT_selecthttp(VRT_CTX, "
	    "enum gethdr_e);\nVCL_STRING VRT_GetHdr(VRT_CTX, const struct "
	    "gethdr_s *);\n\n/***********************************************"
	    "************************\n * req related\n */\n\n"
	    "VCL_BYTES VRT_CacheReqBody(VRT_CTX, VCL_BYTES maxsize);\n"
	    "\n/* Regexp related */\n\nconst char *VRT_regsub(VRT_CTX, "
	    "int all, const char *, void *, const char *);\nVCL_VOID VRT_ban_"
	    "string(VRT_CTX, VCL_STRING);\nVCL_INT VRT_purge(VRT_CTX, VCL_DUR"
	    "ATION, VCL_DURATION, VCL_DURATION);\nVCL_VOID VRT_synth(VRT_CTX,"
	    " VCL_INT, VCL_STRING);\nVCL_VOID VRT_hit_for_pass(VRT_CTX, "
	    "VCL_DURATION);\n\nVCL_VOID VRT_SetHdr(VRT_CTX, const struct "
	    "gethdr_s *, const char *, ...);\nVCL_VOID VRT_handling(VRT_CTX, "
	    "unsigned hand);\nVCL_VOID VRT_fail(VRT_CTX, const char *fmt, "
	    "...) v_printflike_(2,3);\nVCL_VOID VRT_hashdata(VRT_CTX, const "
	    "char *str, ...);\n\n/* Simple stuff */\nint VRT_strcmp(const "
	    "char *s1, const char *s2);\nvoid VRT_memmove(void *dst, const "
	    "void *src, unsigned len);\nVCL_BOOL VRT_ipcmp(VCL_IP, VCL_IP);\n"
	    "VCL_BLOB VRT_blob(VRT_CTX, const char *, const void *, size_t);\n"
	    "\nVCL_VOID VRT_Rollback(VRT_CTX, VCL_HTTP);\n\n/* Synthetic "
	    "pages */\nVCL_VOID VRT_synth_page(VRT_CTX, const char *, ...);\n"
	    "\n/* Backend related */\nstruct director *VRT_new_backend(VRT_CT"
	    "X, const struct vrt_backend *);\nstruct director *VRT_new_backen"
	    "d_clustered(VRT_CTX,\n    struct vsmw_cluster *, const struct "
	    "vrt_backend *);\nsize_t VRT_backend_vsm_need(VRT_CTX);\n"
	    "void VRT_delete_backend(VRT_CTX, struct director **);\n"
	    "int VRT_backend_healthy(VRT_CTX, struct director *);\n"
	    "\n/* VSM related */\nstruct vsmw_cluster *VRT_VSM_Cluster_New(VR"
	    "T_CTX, size_t);\nvoid VRT_VSM_Cluster_Destroy(VRT_CTX, struct "
	    "vsmw_cluster **);\n\n/* cache_director.c */\nint VRT_Healthy(VRT"
	    "_CTX, VCL_BACKEND);\n\n/* Suckaddr related */\nint VRT_VSA_GetPt"
	    "r(const struct suckaddr *sua, const unsigned char ** dst);\n"
	    "\n/* VMOD/Modules related */\nint VRT_Vmod_Init(VRT_CTX, struct "
	    "vmod **hdl, unsigned nbr, void *ptr, int len,\n    const char "
	    "*nm, const char *path, const char *file_id, const char *backup);"
	    "\nvoid VRT_Vmod_Unload(VRT_CTX, struct vmod **hdl);\n"
	    "\n/* VCL program related */\nVCL_VCL VRT_vcl_get(VRT_CTX, "
	    "const char *);\nvoid VRT_vcl_rel(VRT_CTX, VCL_VCL);\n"
	    "void VRT_vcl_select(VRT_CTX, VCL_VCL);\n\ntypedef int vmod_event"
	    "_f(VRT_CTX, struct vmod_priv *, enum vcl_event_e);\n"
	    "\ntypedef void vmod_priv_free_f(void *);\nstruct vmod_priv "
	    "{\n\tvoid\t\t\t*priv;\n\tint\t\t\tlen;\n\tvmod_priv_free_f\t"
	    "*free;\n};\n\nstruct vclref;\nstruct vclref * VRT_ref_vcl(VRT_CT"
	    "X, const char *);\nvoid VRT_rel_vcl(VRT_CTX, struct vclref "
	    "**);\n\nvoid VRT_priv_fini(const struct vmod_priv *p);\n"
	    "struct vmod_priv *VRT_priv_task(VRT_CTX, const void *vmod_id);\n"
	    "struct vmod_priv *VRT_priv_top(VRT_CTX, const void *vmod_id);\n"
	    "\n/* Stevedore related functions */\nint VRT_Stv(const char "
	    "*nm);\nVCL_STEVEDORE VRT_stevedore(const char *nm);\n"
	    "\n/* Convert things to string */\n\nVCL_STRANDS VRT_BundleStrand"
	    "s(int, struct strands *, char const **,\n    const char *f, "
	    "...);\nint VRT_CompareStrands(VCL_STRANDS a, VCL_STRANDS b);\n"
	    "char *VRT_Strands(char *, size_t, VCL_STRANDS);\n"
	    "VCL_STRING VRT_StrandsWS(struct ws *, const char *, VCL_STRANDS)"
	    ";\nVCL_STRING VRT_CollectStrands(VRT_CTX, VCL_STRANDS);\n"
	    "\nVCL_STRING VRT_BACKEND_string(VCL_BACKEND);\nVCL_STRING "
	    "VRT_BOOL_string(VCL_BOOL);\nVCL_STRING VRT_CollectString(VRT_CTX"
	    ", const char *p, ...);\nVCL_STRING VRT_INT_string(VRT_CTX, "
	    "VCL_INT);\nVCL_STRING VRT_IP_string(VRT_CTX, VCL_IP);\n"
	    "VCL_STRING VRT_REAL_string(VRT_CTX, VCL_REAL);\nVCL_STRING "
	    "VRT_STEVEDORE_string(VCL_STEVEDORE);\nVCL_STRING VRT_TIME_string"
	    "(VRT_CTX, VCL_TIME);\n\n#ifdef va_start\t// XXX: hackish\n"
	    "void *VRT_VSC_Alloc(struct vsmw_cluster *, struct vsc_seg "
	    "**,\n    const char *, size_t, const unsigned char *, size_t, "
	    "const char *, va_list);\n#endif\nvoid VRT_VSC_Destroy(const "
	    "char *, struct vsc_seg *);\nvoid VRT_VSC_Hide(const struct "
	    "vsc_seg *);\nvoid VRT_VSC_Reveal(const struct vsc_seg *);\n"
	    "size_t VRT_VSC_Overhead(size_t);\n"
	);
	VSB_cat(sb, "\n");

	/* ../include/vcl.h */

	VSB_cat(sb, "/* ---===### include/vcl.h ###===--- */\n\n");
	VSB_cat(sb, "/*\n * NB:  This file is machine generated, DO "
	    "NOT EDIT!\n *\n * Edit and run lib/libvcc/generate.py instead.\n"
	    " */\n\n\n#ifdef VCL_H_INCLUDED\n#  error \"vcl.h included "
	    "multiple times\"\n#endif\n#define VCL_H_INCLUDED\n"
	    "\n#ifndef VRT_H_INCLUDED\n#  error \"include vrt.h before "
	    "vcl.h\"\n#endif\n\n/* VCL Methods */\n#define VCL_MET_RECV\t"
	    "\t\t(1U << 1)\n#define VCL_MET_PIPE\t\t\t(1U << 2)\n"
	    "#define VCL_MET_PASS\t\t\t(1U << 3)\n#define VCL_MET_HASH\t"
	    "\t\t(1U << 4)\n#define VCL_MET_PURGE\t\t\t(1U << 5)\n"
	    "#define VCL_MET_MISS\t\t\t(1U << 6)\n#define VCL_MET_HIT\t\t"
	    "\t(1U << 7)\n#define VCL_MET_DELIVER\t\t\t(1U << 8)\n"
	    "#define VCL_MET_SYNTH\t\t\t(1U << 9)\n#define VCL_MET_BACKEND_FE"
	    "TCH\t\t(1U << 10)\n#define VCL_MET_BACKEND_RESPONSE\t(1U << "
	    "11)\n#define VCL_MET_BACKEND_ERROR\t\t(1U << 12)\n"
	    "#define VCL_MET_INIT\t\t\t(1U << 13)\n#define VCL_MET_FINI\t"
	    "\t\t(1U << 14)\n\n#define VCL_MET_MAX\t\t\t15\n\n"
	    "#define VCL_MET_MASK\t\t\t0x7fff\n\n#define VCL_MET_TASK_B\t"
	    "\t\t( VCL_MET_BACKEND_FETCH | \\\n\t\t\t\t\t  VCL_MET_BACKEND_RE"
	    "SPONSE | \\\n\t\t\t\t\t  VCL_MET_BACKEND_ERROR )\n"
	    "#define VCL_MET_TASK_C\t\t\t( VCL_MET_RECV | \\\n"
	    "\t\t\t\t\t  VCL_MET_PIPE | \\\n\t\t\t\t\t  VCL_MET_PASS | "
	    "\\\n\t\t\t\t\t  VCL_MET_HASH | \\\n\t\t\t\t\t  VCL_MET_PURGE "
	    "| \\\n\t\t\t\t\t  VCL_MET_MISS | \\\n\t\t\t\t\t  VCL_MET_HIT "
	    "| \\\n\t\t\t\t\t  VCL_MET_DELIVER | \\\n\t\t\t\t\t  VCL_MET_SYNT"
	    "H )\n#define VCL_MET_TASK_H\t\t\t( VCL_MET_INIT | \\\n"
	    "\t\t\t\t\t  VCL_MET_FINI )\n\n/* VCL Returns */\n"
	    "#define VCL_RET_ABANDON\t\t\t1\n#define VCL_RET_DELIVER\t\t"
	    "\t2\n#define VCL_RET_ERROR\t\t\t3\n#define VCL_RET_FAIL\t\t"
	    "\t4\n#define VCL_RET_FETCH\t\t\t5\n#define VCL_RET_HASH\t\t"
	    "\t6\n#define VCL_RET_LOOKUP\t\t\t7\n#define VCL_RET_MISS\t\t"
	    "\t8\n#define VCL_RET_OK\t\t\t9\n#define VCL_RET_PASS\t\t\t10\n"
	    "#define VCL_RET_PIPE\t\t\t11\n#define VCL_RET_PURGE\t\t\t12\n"
	    "#define VCL_RET_RESTART\t\t\t13\n#define VCL_RET_RETRY\t\t\t"
	    "14\n#define VCL_RET_SYNTH\t\t\t15\n#define VCL_RET_VCL\t\t\t"
	    "16\n\n#define VCL_RET_MAX\t\t\t17\n\n/* VCL Types */\n"
	    "extern const struct vrt_type VCL_TYPE_ACL[1];\nextern const "
	    "struct vrt_type VCL_TYPE_BACKEND[1];\nextern const struct "
	    "vrt_type VCL_TYPE_BLOB[1];\nextern const struct vrt_type VCL_TYP"
	    "E_BODY[1];\nextern const struct vrt_type VCL_TYPE_BOOL[1];\n"
	    "extern const struct vrt_type VCL_TYPE_BYTES[1];\n"
	    "extern const struct vrt_type VCL_TYPE_DURATION[1];\n"
	    "extern const struct vrt_type VCL_TYPE_ENUM[1];\nextern const "
	    "struct vrt_type VCL_TYPE_HEADER[1];\nextern const struct vrt_typ"
	    "e VCL_TYPE_HTTP[1];\nextern const struct vrt_type VCL_TYPE_INSTA"
	    "NCE[1];\nextern const struct vrt_type VCL_TYPE_INT[1];\n"
	    "extern const struct vrt_type VCL_TYPE_IP[1];\nextern const "
	    "struct vrt_type VCL_TYPE_PROBE[1];\nextern const struct vrt_type"
	    " VCL_TYPE_REAL[1];\nextern const struct vrt_type VCL_TYPE_STEVED"
	    "ORE[1];\nextern const struct vrt_type VCL_TYPE_STRANDS[1];\n"
	    "extern const struct vrt_type VCL_TYPE_STRING[1];\n"
	    "extern const struct vrt_type VCL_TYPE_STRINGS[1];\n"
	    "extern const struct vrt_type VCL_TYPE_STRING_LIST[1];\n"
	    "extern const struct vrt_type VCL_TYPE_SUB[1];\nextern const "
	    "struct vrt_type VCL_TYPE_TIME[1];\nextern const struct vrt_type "
	    "VCL_TYPE_VCL[1];\nextern const struct vrt_type VCL_TYPE_VOID[1];"
	    "\n\n/* Compiled VCL Interface */\ntypedef int vcl_event_f(VRT_CT"
	    "X, enum vcl_event_e);\ntypedef int vcl_init_f(VRT_CTX);\n"
	    "typedef void vcl_fini_f(VRT_CTX);\ntypedef void vcl_func_f(VRT_C"
	    "TX);\n\nstruct VCL_conf {\n    unsigned            magic;\n"
	    "#define VCL_CONF_MAGIC          0x7406c509      /* from /dev/ran"
	    "dom */\n\n    unsigned            syntax;\n    struct director "
	    "        **default_director;\n    const struct vrt_backend_probe "
	    " *default_probe;\n    unsigned            nref;\n"
	    "    const struct vrt_ref        *ref;\n\n    unsigned     "
	    "       nsrc;\n    const char              **srcname;\n"
	    "    const char              **srcbody;\n\n    unsigned    "
	    "        nvmod;\n\n    vcl_event_f             *event_vcl;\n"
	    "\tvcl_func_f\t\t\t*recv_func;\n\tvcl_func_f\t\t\t*pipe_func;\n"
	    "\tvcl_func_f\t\t\t*pass_func;\n\tvcl_func_f\t\t\t*hash_func;\n"
	    "\tvcl_func_f\t\t\t*purge_func;\n\tvcl_func_f\t\t\t*miss_func;\n"
	    "\tvcl_func_f\t\t\t*hit_func;\n\tvcl_func_f\t\t\t*deliver_func;\n"
	    "\tvcl_func_f\t\t\t*synth_func;\n\tvcl_func_f\t\t\t*backend_fetch"
	    "_func;\n\tvcl_func_f\t\t\t*backend_response_func;\n"
	    "\tvcl_func_f\t\t\t*backend_error_func;\n\tvcl_func_f\t\t\t*init_"
	    "func;\n\tvcl_func_f\t\t\t*fini_func;\n\n};\n"
	);
	VSB_cat(sb, "\n");

	/* ../include/vrt_obj.h */

	VSB_cat(sb, "/* ---===### include/vrt_obj.h ###===--- */\n\n");
	VSB_cat(sb, "/*\n * NB:  This file is machine generated, DO "
	    "NOT EDIT!\n *\n * Edit and run lib/libvcc/generate.py instead.\n"
	    " */\n\n\nVCL_IP VRT_r_local_ip(VRT_CTX);\n\nVCL_STRING VRT_r_loc"
	    "al_endpoint(VRT_CTX);\n\nVCL_STRING VRT_r_local_socket(VRT_CTX);"
	    "\n\nVCL_IP VRT_r_remote_ip(VRT_CTX);\n\nVCL_IP VRT_r_client_ip(V"
	    "RT_CTX);\n\nVCL_STRING VRT_r_client_identity(VRT_CTX);\n"
	    "void VRT_l_client_identity(VRT_CTX, const char *, ...);\n"
	    "\nVCL_IP VRT_r_server_ip(VRT_CTX);\n\nVCL_STRING VRT_r_server_ho"
	    "stname(VRT_CTX);\n\nVCL_STRING VRT_r_server_identity(VRT_CTX);\n"
	    "\nVCL_HTTP VRT_r_req(VRT_CTX);\n\nVCL_STRING VRT_r_req_method(VR"
	    "T_CTX);\nvoid VRT_l_req_method(VRT_CTX, const char *, ...);\n"
	    "\nVCL_BLOB VRT_r_req_hash(VRT_CTX);\n\nVCL_STRING VRT_r_req_url("
	    "VRT_CTX);\nvoid VRT_l_req_url(VRT_CTX, const char *, ...);\n"
	    "\nVCL_STRING VRT_r_req_proto(VRT_CTX);\nvoid VRT_l_req_proto(VRT"
	    "_CTX, const char *, ...);\n\n\nvoid VRT_u_req_http_(VRT_CTX);\n"
	    "\nVCL_INT VRT_r_req_restarts(VRT_CTX);\n\nVCL_STEVEDORE VRT_r_re"
	    "q_storage(VRT_CTX);\nvoid VRT_l_req_storage(VRT_CTX, VCL_STEVEDO"
	    "RE);\n\nVCL_INT VRT_r_req_esi_level(VRT_CTX);\n\n"
	    "VCL_DURATION VRT_r_req_ttl(VRT_CTX);\nvoid VRT_l_req_ttl(VRT_CTX"
	    ", VCL_DURATION);\n\nVCL_DURATION VRT_r_req_grace(VRT_CTX);\n"
	    "void VRT_l_req_grace(VRT_CTX, VCL_DURATION);\n\nVCL_STRING "
	    "VRT_r_req_xid(VRT_CTX);\n\nVCL_BOOL VRT_r_req_esi(VRT_CTX);\n"
	    "void VRT_l_req_esi(VRT_CTX, VCL_BOOL);\n\nVCL_BOOL VRT_r_req_can"
	    "_gzip(VRT_CTX);\n\nVCL_BACKEND VRT_r_req_backend_hint(VRT_CTX);\n"
	    "void VRT_l_req_backend_hint(VRT_CTX, VCL_BACKEND);\n"
	    "\nVCL_BOOL VRT_r_req_hash_ignore_busy(VRT_CTX);\n"
	    "void VRT_l_req_hash_ignore_busy(VRT_CTX, VCL_BOOL);\n"
	    "\nVCL_BOOL VRT_r_req_hash_always_miss(VRT_CTX);\n"
	    "void VRT_l_req_hash_always_miss(VRT_CTX, VCL_BOOL);\n"
	    "\nVCL_BOOL VRT_r_req_is_hitmiss(VRT_CTX);\n\nVCL_BOOL VRT_r_req_"
	    "is_hitpass(VRT_CTX);\n\nVCL_STRING VRT_r_req_top_method(VRT_CTX)"
	    ";\n\nVCL_STRING VRT_r_req_top_url(VRT_CTX);\n\n\n"
	    "VCL_STRING VRT_r_req_top_proto(VRT_CTX);\n\nVCL_HTTP VRT_r_bereq"
	    "(VRT_CTX);\n\nVCL_STRING VRT_r_bereq_xid(VRT_CTX);\n"
	    "\nVCL_INT VRT_r_bereq_retries(VRT_CTX);\n\nVCL_BACKEND VRT_r_ber"
	    "eq_backend(VRT_CTX);\nvoid VRT_l_bereq_backend(VRT_CTX, VCL_BACK"
	    "END);\n\nvoid VRT_u_bereq_body(VRT_CTX);\n\nVCL_BLOB VRT_r_bereq"
	    "_hash(VRT_CTX);\n\nVCL_STRING VRT_r_bereq_method(VRT_CTX);\n"
	    "void VRT_l_bereq_method(VRT_CTX, const char *, ...);\n"
	    "\nVCL_STRING VRT_r_bereq_url(VRT_CTX);\nvoid VRT_l_bereq_url(VRT"
	    "_CTX, const char *, ...);\n\nVCL_STRING VRT_r_bereq_proto(VRT_CT"
	    "X);\nvoid VRT_l_bereq_proto(VRT_CTX, const char *, ...);\n"
	    "\n\nvoid VRT_u_bereq_http_(VRT_CTX);\n\nVCL_BOOL VRT_r_bereq_unc"
	    "acheable(VRT_CTX);\n\nVCL_DURATION VRT_r_bereq_connect_timeout(V"
	    "RT_CTX);\nvoid VRT_l_bereq_connect_timeout(VRT_CTX, VCL_DURATION"
	    ");\n\nVCL_DURATION VRT_r_bereq_first_byte_timeout(VRT_CTX);\n"
	    "void VRT_l_bereq_first_byte_timeout(VRT_CTX, VCL_DURATION);\n"
	    "\nVCL_DURATION VRT_r_bereq_between_bytes_timeout(VRT_CTX);\n"
	    "void VRT_l_bereq_between_bytes_timeout(VRT_CTX, VCL_DURATION);\n"
	    "\nVCL_BOOL VRT_r_bereq_is_bgfetch(VRT_CTX);\n\nVCL_HTTP VRT_r_be"
	    "resp(VRT_CTX);\n\nvoid VRT_l_beresp_body(VRT_CTX, const char "
	    "*, ...);\n\nVCL_STRING VRT_r_beresp_proto(VRT_CTX);\n"
	    "void VRT_l_beresp_proto(VRT_CTX, const char *, ...);\n"
	    "\n\nVCL_INT VRT_r_beresp_status(VRT_CTX);\nvoid VRT_l_beresp_sta"
	    "tus(VRT_CTX, VCL_INT);\n\nVCL_STRING VRT_r_beresp_reason(VRT_CTX"
	    ");\nvoid VRT_l_beresp_reason(VRT_CTX, const char *, ...);\n"
	    "\nvoid VRT_u_beresp_http_(VRT_CTX);\n\nVCL_BOOL VRT_r_beresp_do_"
	    "esi(VRT_CTX);\nvoid VRT_l_beresp_do_esi(VRT_CTX, VCL_BOOL);\n"
	    "\nVCL_BOOL VRT_r_beresp_do_stream(VRT_CTX);\nvoid VRT_l_beresp_d"
	    "o_stream(VRT_CTX, VCL_BOOL);\n\nVCL_BOOL VRT_r_beresp_do_gzip(VR"
	    "T_CTX);\nvoid VRT_l_beresp_do_gzip(VRT_CTX, VCL_BOOL);\n"
	    "\nVCL_BOOL VRT_r_beresp_do_gunzip(VRT_CTX);\nvoid VRT_l_beresp_d"
	    "o_gunzip(VRT_CTX, VCL_BOOL);\n\nVCL_BOOL VRT_r_beresp_was_304(VR"
	    "T_CTX);\n\nVCL_BOOL VRT_r_beresp_uncacheable(VRT_CTX);\n"
	    "void VRT_l_beresp_uncacheable(VRT_CTX, VCL_BOOL);\n"
	    "\nVCL_DURATION VRT_r_beresp_ttl(VRT_CTX);\nvoid VRT_l_beresp_ttl"
	    "(VRT_CTX, VCL_DURATION);\n\nVCL_DURATION VRT_r_beresp_age(VRT_CT"
	    "X);\n\nVCL_DURATION VRT_r_beresp_grace(VRT_CTX);\n"
	    "void VRT_l_beresp_grace(VRT_CTX, VCL_DURATION);\n"
	    "\nVCL_DURATION VRT_r_beresp_keep(VRT_CTX);\nvoid VRT_l_beresp_ke"
	    "ep(VRT_CTX, VCL_DURATION);\n\nVCL_BACKEND VRT_r_beresp_backend(V"
	    "RT_CTX);\n\nVCL_STRING VRT_r_beresp_backend_name(VRT_CTX);\n"
	    "\nVCL_IP VRT_r_beresp_backend_ip(VRT_CTX);\n\nVCL_STEVEDORE "
	    "VRT_r_beresp_storage(VRT_CTX);\nvoid VRT_l_beresp_storage(VRT_CT"
	    "X, VCL_STEVEDORE);\n\nVCL_STRING VRT_r_beresp_storage_hint(VRT_C"
	    "TX);\nvoid VRT_l_beresp_storage_hint(VRT_CTX, const char *, "
	    "...);\n\nVCL_STRING VRT_r_obj_proto(VRT_CTX);\n\n"
	    "VCL_INT VRT_r_obj_status(VRT_CTX);\n\nVCL_STRING VRT_r_obj_reaso"
	    "n(VRT_CTX);\n\nVCL_INT VRT_r_obj_hits(VRT_CTX);\n"
	    "\n\nVCL_DURATION VRT_r_obj_ttl(VRT_CTX);\n\nVCL_DURATION VRT_r_o"
	    "bj_age(VRT_CTX);\n\nVCL_DURATION VRT_r_obj_grace(VRT_CTX);\n"
	    "\nVCL_DURATION VRT_r_obj_keep(VRT_CTX);\n\nVCL_BOOL VRT_r_obj_un"
	    "cacheable(VRT_CTX);\n\nVCL_STEVEDORE VRT_r_obj_storage(VRT_CTX);"
	    "\n\nVCL_HTTP VRT_r_resp(VRT_CTX);\n\nvoid VRT_l_resp_body(VRT_CT"
	    "X, const char *, ...);\n\nVCL_STRING VRT_r_resp_proto(VRT_CTX);\n"
	    "void VRT_l_resp_proto(VRT_CTX, const char *, ...);\n"
	    "\n\nVCL_INT VRT_r_resp_status(VRT_CTX);\nvoid VRT_l_resp_status("
	    "VRT_CTX, VCL_INT);\n\nVCL_STRING VRT_r_resp_reason(VRT_CTX);\n"
	    "void VRT_l_resp_reason(VRT_CTX, const char *, ...);\n"
	    "\nvoid VRT_u_resp_http_(VRT_CTX);\n\nVCL_BOOL VRT_r_resp_do_esi("
	    "VRT_CTX);\nvoid VRT_l_resp_do_esi(VRT_CTX, VCL_BOOL);\n"
	    "\nVCL_BOOL VRT_r_resp_is_streaming(VRT_CTX);\n\nVCL_TIME VRT_r_n"
	    "ow(VRT_CTX);\n\nVCL_STRING VRT_r_sess_xid(VRT_CTX);\n"
	    "\nVCL_DURATION VRT_r_sess_timeout_idle(VRT_CTX);\n"
	    "void VRT_l_sess_timeout_idle(VRT_CTX, VCL_DURATION);\n"
	    "int64_t VRT_Stv_free_space(const char *);\nint64_t VRT_Stv_used_"
	    "space(const char *);\nunsigned VRT_Stv_happy(const char *);\n"
	);
	VSB_cat(sb, "\n");

}
