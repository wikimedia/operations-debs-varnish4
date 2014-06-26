/*
 * NB:  This file is machine generated, DO NOT EDIT!
 *
 * Edit and run generate.py instead
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

	/* ../include/vcl.h */

	VSB_cat(sb, "/* ---===### include/vcl.h ###===--- */\n\n");
	VSB_cat(sb, "/*\n * NB:  This file is machine generated, DO "
	    "NOT EDIT!\n *\n * Edit and run generate.py instead\n"
	    " */\n\nstruct vrt_ctx;\nstruct req;\nstruct busyobj;\n"
	    "struct ws;\nstruct cli;\nstruct worker;\n\ntypedef int vcl_init_"
	    "f(struct cli *);\ntypedef void vcl_fini_f(struct cli *);\n"
	    "typedef int vcl_func_f(const struct vrt_ctx *ctx);\n"
	    "\n/* VCL Methods */\n#define VCL_MET_RECV\t\t(1U << 0)\n"
	    "#define VCL_MET_PIPE\t\t(1U << 1)\n#define VCL_MET_PASS\t\t"
	    "(1U << 2)\n#define VCL_MET_HASH\t\t(1U << 3)\n#define VCL_MET_PU"
	    "RGE\t\t(1U << 4)\n#define VCL_MET_MISS\t\t(1U << 5)\n"
	    "#define VCL_MET_HIT\t\t(1U << 6)\n#define VCL_MET_DELIVER\t"
	    "\t(1U << 7)\n#define VCL_MET_SYNTH\t\t(1U << 8)\n"
	    "#define VCL_MET_BACKEND_FETCH\t\t(1U << 9)\n#define VCL_MET_BACK"
	    "END_RESPONSE\t\t(1U << 10)\n#define VCL_MET_BACKEND_ERROR\t"
	    "\t(1U << 11)\n#define VCL_MET_INIT\t\t(1U << 12)\n"
	    "#define VCL_MET_FINI\t\t(1U << 13)\n\n#define VCL_MET_MAX\t"
	    "\t14\n\n#define VCL_MET_MASK\t\t0x3fff\n\n/* VCL Returns */\n"
	    "#define VCL_RET_ABANDON\t\t0\n#define VCL_RET_DELIVER\t\t1\n"
	    "#define VCL_RET_FETCH\t\t2\n#define VCL_RET_HASH\t\t3\n"
	    "#define VCL_RET_LOOKUP\t\t4\n#define VCL_RET_OK\t\t5\n"
	    "#define VCL_RET_PASS\t\t6\n#define VCL_RET_PIPE\t\t7\n"
	    "#define VCL_RET_PURGE\t\t8\n#define VCL_RET_RESTART\t\t9\n"
	    "#define VCL_RET_RETRY\t\t10\n#define VCL_RET_SYNTH\t\t11\n"
	    "\n#define VCL_RET_MAX\t\t12\n\nstruct VCL_conf {\n"
	    "\tunsigned\tmagic;\n#define VCL_CONF_MAGIC\t0x7406c509\t/* "
	    "from /dev/random */\n\n\tstruct director\t**director;\n"
	    "\tunsigned\tndirector;\n\tstruct vrt_ref\t*ref;\n"
	    "\tunsigned\tnref;\n\tunsigned\tbusy;\n\tunsigned\tdiscard;\n"
	    "\n\tunsigned\tnsrc;\n\tconst char\t**srcname;\n\tconst char\t"
	    "**srcbody;\n\n\tvcl_init_f\t*init_vcl;\n\tvcl_fini_f\t*fini_vcl;"
	    "\n\tvcl_func_f\t*recv_func;\n\tvcl_func_f\t*pipe_func;\n"
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
	    " * Copyright (c) 2006-2014 Varnish Software AS\n * All rights "
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
	    " */\n\n#define VRT_MAJOR_VERSION\t1U\n\n#define VRT_MINOR_VERSIO"
	    "N\t1U\n\n\n/****************************************************"
	    "*******************/\n\nstruct req;\nstruct busyobj;\n"
	    "struct vsl_log;\nstruct http;\nstruct ws;\nstruct cli;\n"
	    "struct director;\nstruct VCL_conf;\nstruct suckaddr;\n"
	    "\n/*************************************************************"
	    "**********\n * This is the central definition of the mapping "
	    "from VCL types to\n * C-types.  The python scripts read these "
	    "from here.\n */\n\ntypedef struct director *\t\tVCL_BACKEND;\n"
	    "typedef unsigned\t\t\tVCL_BOOL;\ntypedef double\t\t\t\tVCL_BYTES"
	    ";\ntypedef double\t\t\t\tVCL_DURATION;\ntypedef const char "
	    "*\t\t\tVCL_ENUM;\ntypedef const struct gethdr_s *\t\tVCL_HEADER;"
	    "\ntypedef long\t\t\t\tVCL_INT;\ntypedef const struct suckaddr "
	    "*\t\tVCL_IP;\ntypedef double\t\t\t\tVCL_REAL;\ntypedef const "
	    "char *\t\t\tVCL_STRING;\ntypedef double\t\t\t\tVCL_TIME;\n"
	    "typedef void\t\t\t\tVCL_VOID;\ntypedef const struct vmod_priv "
	    "*\tVCL_BLOB;\n\n/***********************************************"
	    "************************\n * This is the composite argument "
	    "we pass to compiled VCL and VRT\n * functions.\n */\n"
	    "\nstruct vrt_ctx {\n\tunsigned\t\t\tmagic;\n#define VRT_CTX_MAGI"
	    "C\t\t\t0x6bb8f0db\n\n\tunsigned\t\t\tmethod;\n\tunsigned\t\t"
	    "\t*handling;\n\n\tstruct vsl_log\t\t\t*vsl;\n\tstruct VCL_conf\t"
	    "\t\t*vcl;\n\tstruct ws\t\t\t*ws;\n\n\tstruct req\t\t\t*req;\n"
	    "\tstruct http\t\t\t*http_req;\n\tstruct http\t\t\t*http_obj;\n"
	    "\tstruct http\t\t\t*http_resp;\n\n\tstruct busyobj\t\t\t*bo;\n"
	    "\tstruct http\t\t\t*http_bereq;\n\tstruct http\t\t\t*http_beresp"
	    ";\n\n};\n\n/****************************************************"
	    "*******************/\n\nstruct vmod_data {\n\t/* The version/id "
	    "fields must be first, they protect the rest */\n\tunsigned\t"
	    "\t\tvrt_major;\n\tunsigned\t\t\tvrt_minor;\n\tconst char\t\t"
	    "\t*file_id;\n\n\tconst char\t\t\t*name;\n\tconst void\t\t\t"
	    "*func;\n\tint\t\t\t\tfunc_len;\n\tconst char\t\t\t*proto;\n"
	    "\tconst char\t\t\t* const *spec;\n\tconst char\t\t\t*abi;\n"
	    "};\n\n/*********************************************************"
	    "**************/\n\nenum gethdr_e { HDR_REQ, HDR_RESP, HDR_OBJ, "
	    "HDR_BEREQ, HDR_BERESP };\n\nstruct gethdr_s {\n\tenum gethdr_e\t"
	    "where;\n\tconst char\t*what;\n};\n\n/*\n * A backend probe "
	    "specification\n */\n\nextern const void * const vrt_magic_string"
	    "_end;\nextern const void * const vrt_magic_string_unset;\n"
	    "\nstruct vrt_backend_probe {\n\tconst char\t*url;\n"
	    "\tconst char\t*request;\n\tdouble\t\ttimeout;\n\tdouble\t\t"
	    "interval;\n\tunsigned\texp_status;\n\tunsigned\twindow;\n"
	    "\tunsigned\tthreshold;\n\tunsigned\tinitial;\n};\n"
	    "\n/*\n * A backend is a host+port somewhere on the network\n"
	    " */\nstruct vrt_backend {\n\tconst char\t\t\t*vcl_name;\n"
	    "\tconst char\t\t\t*ipv4_addr;\n\tconst char\t\t\t*ipv6_addr;\n"
	    "\tconst char\t\t\t*port;\n\n\tconst struct suckaddr\t\t*ipv4_suc"
	    "kaddr;\n\tconst struct suckaddr\t\t*ipv6_suckaddr;\n"
	    "\n\tconst char\t\t\t*hosthdr;\n\n\tdouble\t\t\t\tconnect_timeout"
	    ";\n\tdouble\t\t\t\tfirst_byte_timeout;\n\tdouble\t\t\t\tbetween_"
	    "bytes_timeout;\n\tunsigned\t\t\tmax_connections;\n"
	    "\tconst struct vrt_backend_probe\t*probe;\n};\n\n"
	    "/*\n * A director with an unpredictable reply\n */\n"
	    "\nstruct vrt_dir_random_entry {\n\tint\t\t\t\t\thost;\n"
	    "\tdouble\t\t\t\t\tweight;\n};\n\nstruct vrt_dir_random {\n"
	    "\tconst char\t\t\t\t*name;\n\tunsigned\t\t\t\tretries;\n"
	    "\tunsigned\t\t\t\tnmember;\n\tconst struct vrt_dir_random_entry\t"
	    "*members;\n};\n\n/*\n * A director with dns-based selection\n"
	    " */\n\nstruct vrt_dir_dns_entry {\n\tint\t\t\t\t\thost;\n"
	    "};\n\nstruct vrt_dir_dns {\n\tconst char\t\t\t\t*name;\n"
	    "\tconst char\t\t\t\t*suffix;\n\tconst double\t\t\t\tttl;\n"
	    "\tunsigned\t\t\t\tnmember;\n\tconst struct vrt_dir_dns_entry\t"
	    "\t*members;\n};\n\n/*\n * other stuff.\n * XXX: document when "
	    "bored\n */\n\nstruct vrt_ref {\n\tunsigned\tsource;\n"
	    "\tunsigned\toffset;\n\tunsigned\tline;\n\tunsigned\tpos;\n"
	    "\tunsigned\tcount;\n\tconst char\t*token;\n};\n\n"
	    "/* ACL related */\n#define VRT_ACL_MAXADDR\t\t16\t/* max(IPv4, "
	    "IPv6) */\n\nvoid VRT_acl_log(const struct vrt_ctx *, const "
	    "char *msg);\n\n/* req related */\n\nint VRT_CacheReqBody(const "
	    "struct vrt_ctx *, long long maxsize);\n\n/* Regexp related "
	    "*/\nvoid VRT_re_init(void **, const char *);\nvoid VRT_re_fini(v"
	    "oid *);\nint VRT_re_match(const struct vrt_ctx *, const char "
	    "*, void *re);\nconst char *VRT_regsub(const struct vrt_ctx "
	    "*, int all, const char *,\n    void *, const char *);\n"
	    "\nvoid VRT_ban_string(const struct vrt_ctx *, const char *);\n"
	    "void VRT_purge(const struct vrt_ctx *, double ttl, double "
	    "grace, double keep);\n\nvoid VRT_count(const struct vrt_ctx "
	    "*, unsigned);\nint VRT_rewrite(const char *, const char *);\n"
	    "void VRT_error(const struct vrt_ctx *, unsigned, const char "
	    "*);\nint VRT_switch_config(const char *);\n\nchar *VRT_GetHdr(co"
	    "nst struct vrt_ctx *, const struct gethdr_s *);\n"
	    "void VRT_SetHdr(const struct vrt_ctx *, const struct gethdr_s "
	    "*,\n    const char *, ...);\nvoid VRT_handling(const struct "
	    "vrt_ctx *, unsigned hand);\n\nvoid VRT_hashdata(const struct "
	    "vrt_ctx *, const char *str, ...);\n\n/* Simple stuff */\n"
	    "int VRT_strcmp(const char *s1, const char *s2);\n"
	    "void VRT_memmove(void *dst, const void *src, unsigned len);\n"
	    "\nvoid VRT_Rollback(const struct vrt_ctx *);\n\n/* Synthetic "
	    "pages */\nvoid VRT_synth_page(const struct vrt_ctx *, const "
	    "char *, ...);\n\n/* Backend related */\nvoid VRT_init_dir(struct"
	    " cli *, struct director **, int idx, const void *priv);\n"
	    "void VRT_fini_dir(struct cli *, struct director *);\n"
	    "\n/* Suckaddr related */\nint VRT_VSA_GetPtr(const struct "
	    "suckaddr *sua, const unsigned char ** dst);\n\n/* VMOD/Modules "
	    "related */\nint VRT_Vmod_Init(void **hdl, void *ptr, int len, "
	    "const char *nm,\n    const char *path, const char *file_id, "
	    "struct cli *cli);\nvoid VRT_Vmod_Fini(void **hdl);\n"
	    "\nstruct vmod_priv;\ntypedef void vmod_priv_free_f(void *);\n"
	    "struct vmod_priv {\n\tvoid\t\t\t*priv;\n\tint\t\t\tlen;\n"
	    "\tvmod_priv_free_f\t*free;\n};\n\ntypedef int vmod_init_f(struct"
	    " vmod_priv *,  const struct VCL_conf *);\n\nvoid VRT_priv_fini(c"
	    "onst struct vmod_priv *p);\n\n/* Stevedore related functions "
	    "*/\nint VRT_Stv(const char *nm);\n\n/* Convert things to string "
	    "*/\n\nchar *VRT_IP_string(const struct vrt_ctx *, VCL_IP);\n"
	    "char *VRT_INT_string(const struct vrt_ctx *, VCL_INT);\n"
	    "char *VRT_REAL_string(const struct vrt_ctx *, VCL_REAL);\n"
	    "char *VRT_TIME_string(const struct vrt_ctx *, VCL_TIME);\n"
	    "const char *VRT_BOOL_string(VCL_BOOL);\nconst char *VRT_BACKEND_"
	    "string(VCL_BACKEND);\nconst char *VRT_CollectString(const "
	    "struct vrt_ctx *, const char *p, ...);\n"
	);
	VSB_cat(sb, "\n");

	/* ../include/vrt_obj.h */

	VSB_cat(sb, "/* ---===### include/vrt_obj.h ###===--- */\n\n");
	VSB_cat(sb, "/*\n * NB:  This file is machine generated, DO "
	    "NOT EDIT!\n *\n * Edit and run generate.py instead\n"
	    " */\n\nVCL_BACKEND VRT_r_bereq_backend(const struct vrt_ctx "
	    "*);\nvoid VRT_l_bereq_backend(const struct vrt_ctx *, VCL_BACKEN"
	    "D);\n\nVCL_DURATION VRT_r_bereq_between_bytes_timeout(const "
	    "struct vrt_ctx *);\nvoid VRT_l_bereq_between_bytes_timeout(const"
	    " struct vrt_ctx *, VCL_DURATION);\n\nVCL_DURATION VRT_r_bereq_co"
	    "nnect_timeout(const struct vrt_ctx *);\nvoid VRT_l_bereq_connect"
	    "_timeout(const struct vrt_ctx *, VCL_DURATION);\n"
	    "\nVCL_DURATION VRT_r_bereq_first_byte_timeout(const struct "
	    "vrt_ctx *);\nvoid VRT_l_bereq_first_byte_timeout(const struct "
	    "vrt_ctx *, VCL_DURATION);\n\n\nVCL_STRING VRT_r_bereq_method(con"
	    "st struct vrt_ctx *);\nvoid VRT_l_bereq_method(const struct "
	    "vrt_ctx *, const char *, ...);\n\nVCL_STRING VRT_r_bereq_proto(c"
	    "onst struct vrt_ctx *);\nvoid VRT_l_bereq_proto(const struct "
	    "vrt_ctx *, const char *, ...);\n\nVCL_INT VRT_r_bereq_retries(co"
	    "nst struct vrt_ctx *);\n\nVCL_BOOL VRT_r_bereq_uncacheable(const"
	    " struct vrt_ctx *);\nvoid VRT_l_bereq_uncacheable(const struct "
	    "vrt_ctx *, VCL_BOOL);\n\nVCL_STRING VRT_r_bereq_url(const "
	    "struct vrt_ctx *);\nvoid VRT_l_bereq_url(const struct vrt_ctx "
	    "*, const char *, ...);\n\nVCL_STRING VRT_r_bereq_xid(const "
	    "struct vrt_ctx *);\n\nVCL_IP VRT_r_beresp_backend_ip(const "
	    "struct vrt_ctx *);\n\nVCL_STRING VRT_r_beresp_backend_name(const"
	    " struct vrt_ctx *);\n\nVCL_BOOL VRT_r_beresp_do_esi(const "
	    "struct vrt_ctx *);\nvoid VRT_l_beresp_do_esi(const struct "
	    "vrt_ctx *, VCL_BOOL);\n\nVCL_BOOL VRT_r_beresp_do_gunzip(const "
	    "struct vrt_ctx *);\nvoid VRT_l_beresp_do_gunzip(const struct "
	    "vrt_ctx *, VCL_BOOL);\n\nVCL_BOOL VRT_r_beresp_do_gzip(const "
	    "struct vrt_ctx *);\nvoid VRT_l_beresp_do_gzip(const struct "
	    "vrt_ctx *, VCL_BOOL);\n\nVCL_BOOL VRT_r_beresp_do_stream(const "
	    "struct vrt_ctx *);\nvoid VRT_l_beresp_do_stream(const struct "
	    "vrt_ctx *, VCL_BOOL);\n\nVCL_DURATION VRT_r_beresp_grace(const "
	    "struct vrt_ctx *);\nvoid VRT_l_beresp_grace(const struct vrt_ctx"
	    " *, VCL_DURATION);\n\n\nVCL_DURATION VRT_r_beresp_keep(const "
	    "struct vrt_ctx *);\nvoid VRT_l_beresp_keep(const struct vrt_ctx "
	    "*, VCL_DURATION);\n\nVCL_STRING VRT_r_beresp_proto(const struct "
	    "vrt_ctx *);\nvoid VRT_l_beresp_proto(const struct vrt_ctx "
	    "*, const char *, ...);\n\nVCL_STRING VRT_r_beresp_reason(const "
	    "struct vrt_ctx *);\nvoid VRT_l_beresp_reason(const struct "
	    "vrt_ctx *, const char *, ...);\n\nVCL_INT VRT_r_beresp_status(co"
	    "nst struct vrt_ctx *);\nvoid VRT_l_beresp_status(const struct "
	    "vrt_ctx *, VCL_INT);\n\nVCL_STRING VRT_r_beresp_storage_hint(con"
	    "st struct vrt_ctx *);\nvoid VRT_l_beresp_storage_hint(const "
	    "struct vrt_ctx *, const char *, ...);\n\nVCL_DURATION VRT_r_bere"
	    "sp_ttl(const struct vrt_ctx *);\nvoid VRT_l_beresp_ttl(const "
	    "struct vrt_ctx *, VCL_DURATION);\n\nVCL_BOOL VRT_r_beresp_uncach"
	    "eable(const struct vrt_ctx *);\nvoid VRT_l_beresp_uncacheable(co"
	    "nst struct vrt_ctx *, VCL_BOOL);\n\nVCL_STRING VRT_r_client_iden"
	    "tity(const struct vrt_ctx *);\nvoid VRT_l_client_identity(const "
	    "struct vrt_ctx *, const char *, ...);\n\nVCL_IP VRT_r_client_ip("
	    "const struct vrt_ctx *);\n\nVCL_TIME VRT_r_now(const struct "
	    "vrt_ctx *);\n\nVCL_DURATION VRT_r_obj_grace(const struct vrt_ctx"
	    " *);\n\nVCL_INT VRT_r_obj_hits(const struct vrt_ctx *);\n"
	    "\n\nVCL_DURATION VRT_r_obj_keep(const struct vrt_ctx *);\n"
	    "\nVCL_STRING VRT_r_obj_proto(const struct vrt_ctx *);\n"
	    "\nVCL_STRING VRT_r_obj_reason(const struct vrt_ctx *);\n"
	    "\nVCL_INT VRT_r_obj_status(const struct vrt_ctx *);\n"
	    "\nVCL_DURATION VRT_r_obj_ttl(const struct vrt_ctx *);\n"
	    "\nVCL_BOOL VRT_r_obj_uncacheable(const struct vrt_ctx *);\n"
	    "\nVCL_BACKEND VRT_r_req_backend_hint(const struct vrt_ctx "
	    "*);\nvoid VRT_l_req_backend_hint(const struct vrt_ctx *, VCL_BAC"
	    "KEND);\n\nVCL_BOOL VRT_r_req_can_gzip(const struct vrt_ctx "
	    "*);\n\nVCL_BOOL VRT_r_req_esi(const struct vrt_ctx *);\n"
	    "void VRT_l_req_esi(const struct vrt_ctx *, VCL_BOOL);\n"
	    "\nVCL_INT VRT_r_req_esi_level(const struct vrt_ctx *);\n"
	    "\nVCL_BOOL VRT_r_req_hash_always_miss(const struct vrt_ctx "
	    "*);\nvoid VRT_l_req_hash_always_miss(const struct vrt_ctx "
	    "*, VCL_BOOL);\n\nVCL_BOOL VRT_r_req_hash_ignore_busy(const "
	    "struct vrt_ctx *);\nvoid VRT_l_req_hash_ignore_busy(const "
	    "struct vrt_ctx *, VCL_BOOL);\n\n\nVCL_STRING VRT_r_req_method(co"
	    "nst struct vrt_ctx *);\nvoid VRT_l_req_method(const struct "
	    "vrt_ctx *, const char *, ...);\n\nVCL_STRING VRT_r_req_proto(con"
	    "st struct vrt_ctx *);\nvoid VRT_l_req_proto(const struct vrt_ctx"
	    " *, const char *, ...);\n\nVCL_INT VRT_r_req_restarts(const "
	    "struct vrt_ctx *);\n\nVCL_DURATION VRT_r_req_ttl(const struct "
	    "vrt_ctx *);\nvoid VRT_l_req_ttl(const struct vrt_ctx *, VCL_DURA"
	    "TION);\n\nVCL_STRING VRT_r_req_url(const struct vrt_ctx *);\n"
	    "void VRT_l_req_url(const struct vrt_ctx *, const char *, ...);\n"
	    "\nVCL_STRING VRT_r_req_xid(const struct vrt_ctx *);\n"
	    "\n\nVCL_STRING VRT_r_resp_proto(const struct vrt_ctx *);\n"
	    "void VRT_l_resp_proto(const struct vrt_ctx *, const char *, "
	    "...);\n\nVCL_STRING VRT_r_resp_reason(const struct vrt_ctx "
	    "*);\nvoid VRT_l_resp_reason(const struct vrt_ctx *, const "
	    "char *, ...);\n\nVCL_INT VRT_r_resp_status(const struct vrt_ctx "
	    "*);\nvoid VRT_l_resp_status(const struct vrt_ctx *, VCL_INT);\n"
	    "\nVCL_STRING VRT_r_server_hostname(const struct vrt_ctx *);\n"
	    "\nVCL_STRING VRT_r_server_identity(const struct vrt_ctx *);\n"
	    "\nVCL_IP VRT_r_server_ip(const struct vrt_ctx *);\n"
	    "\ndouble VRT_Stv_free_space(const char *);\ndouble VRT_Stv_used_"
	    "space(const char *);\nunsigned VRT_Stv_happy(const char *);\n"
	);
	VSB_cat(sb, "\n");

}
