/*
 * NB:  This file is machine generated, DO NOT EDIT!
 *
 * Edit and run lib/libvcc/generate.py instead.
 */


#include "config.h"

#include <stdio.h>

#include "vcc_compile.h"

const struct var vcc_vars[] = {
	{ "bereq", HTTP,
	    "VRT_r_bereq(ctx)",
		VCL_MET_BACKEND_ERROR | VCL_MET_BACKEND_FETCH
		 | VCL_MET_BACKEND_RESPONSE,
	    NULL,	/* No writes allowed */
		0,
	},
	{ "bereq.backend", BACKEND,
	    "VRT_r_bereq_backend(ctx)",
		VCL_MET_BACKEND_ERROR | VCL_MET_BACKEND_FETCH
		 | VCL_MET_BACKEND_RESPONSE | VCL_MET_PIPE,
	    "VRT_l_bereq_backend(ctx, ",
		VCL_MET_BACKEND_ERROR | VCL_MET_BACKEND_FETCH
		 | VCL_MET_BACKEND_RESPONSE | VCL_MET_PIPE,
	},
	{ "bereq.between_bytes_timeout", DURATION,
	    "VRT_r_bereq_between_bytes_timeout(ctx)",
		VCL_MET_BACKEND_ERROR | VCL_MET_BACKEND_FETCH
		 | VCL_MET_BACKEND_RESPONSE,
	    "VRT_l_bereq_between_bytes_timeout(ctx, ",
		VCL_MET_BACKEND_ERROR | VCL_MET_BACKEND_FETCH
		 | VCL_MET_BACKEND_RESPONSE,
	},
	{ "bereq.body", BODY,
	    NULL,	/* No reads allowed */
		0,
	    "VRT_l_bereq_body(ctx, ",
		VCL_MET_BACKEND_FETCH,
	},
	{ "bereq.connect_timeout", DURATION,
	    "VRT_r_bereq_connect_timeout(ctx)",
		VCL_MET_BACKEND_ERROR | VCL_MET_BACKEND_FETCH
		 | VCL_MET_BACKEND_RESPONSE | VCL_MET_PIPE,
	    "VRT_l_bereq_connect_timeout(ctx, ",
		VCL_MET_BACKEND_ERROR | VCL_MET_BACKEND_FETCH
		 | VCL_MET_BACKEND_RESPONSE | VCL_MET_PIPE,
	},
	{ "bereq.first_byte_timeout", DURATION,
	    "VRT_r_bereq_first_byte_timeout(ctx)",
		VCL_MET_BACKEND_ERROR | VCL_MET_BACKEND_FETCH
		 | VCL_MET_BACKEND_RESPONSE,
	    "VRT_l_bereq_first_byte_timeout(ctx, ",
		VCL_MET_BACKEND_ERROR | VCL_MET_BACKEND_FETCH
		 | VCL_MET_BACKEND_RESPONSE,
	},
	{ "bereq.http.", HEADER,
	    "HDR_BEREQ",
		VCL_MET_BACKEND_ERROR | VCL_MET_BACKEND_FETCH
		 | VCL_MET_BACKEND_RESPONSE | VCL_MET_PIPE,
	    "HDR_BEREQ",
		VCL_MET_BACKEND_ERROR | VCL_MET_BACKEND_FETCH
		 | VCL_MET_BACKEND_RESPONSE | VCL_MET_PIPE,
	},
	{ "bereq.method", STRING,
	    "VRT_r_bereq_method(ctx)",
		VCL_MET_BACKEND_ERROR | VCL_MET_BACKEND_FETCH
		 | VCL_MET_BACKEND_RESPONSE | VCL_MET_PIPE,
	    "VRT_l_bereq_method(ctx, ",
		VCL_MET_BACKEND_ERROR | VCL_MET_BACKEND_FETCH
		 | VCL_MET_BACKEND_RESPONSE | VCL_MET_PIPE,
	},
	{ "bereq.proto", STRING,
	    "VRT_r_bereq_proto(ctx)",
		VCL_MET_BACKEND_ERROR | VCL_MET_BACKEND_FETCH
		 | VCL_MET_BACKEND_RESPONSE | VCL_MET_PIPE,
	    "VRT_l_bereq_proto(ctx, ",
		VCL_MET_BACKEND_ERROR | VCL_MET_BACKEND_FETCH
		 | VCL_MET_BACKEND_RESPONSE | VCL_MET_PIPE,
	},
	{ "bereq.retries", INT,
	    "VRT_r_bereq_retries(ctx)",
		VCL_MET_BACKEND_ERROR | VCL_MET_BACKEND_FETCH
		 | VCL_MET_BACKEND_RESPONSE,
	    NULL,	/* No writes allowed */
		0,
	},
	{ "bereq.uncacheable", BOOL,
	    "VRT_r_bereq_uncacheable(ctx)",
		VCL_MET_BACKEND_ERROR | VCL_MET_BACKEND_FETCH
		 | VCL_MET_BACKEND_RESPONSE,
	    NULL,	/* No writes allowed */
		0,
	},
	{ "bereq.url", STRING,
	    "VRT_r_bereq_url(ctx)",
		VCL_MET_BACKEND_ERROR | VCL_MET_BACKEND_FETCH
		 | VCL_MET_BACKEND_RESPONSE | VCL_MET_PIPE,
	    "VRT_l_bereq_url(ctx, ",
		VCL_MET_BACKEND_ERROR | VCL_MET_BACKEND_FETCH
		 | VCL_MET_BACKEND_RESPONSE | VCL_MET_PIPE,
	},
	{ "bereq.xid", STRING,
	    "VRT_r_bereq_xid(ctx)",
		VCL_MET_BACKEND_ERROR | VCL_MET_BACKEND_FETCH
		 | VCL_MET_BACKEND_RESPONSE,
	    NULL,	/* No writes allowed */
		0,
	},
	{ "beresp", HTTP,
	    "VRT_r_beresp(ctx)",
		VCL_MET_BACKEND_ERROR | VCL_MET_BACKEND_RESPONSE,
	    NULL,	/* No writes allowed */
		0,
	},
	{ "beresp.age", DURATION,
	    "VRT_r_beresp_age(ctx)",
		VCL_MET_BACKEND_ERROR | VCL_MET_BACKEND_RESPONSE,
	    NULL,	/* No writes allowed */
		0,
	},
	{ "beresp.backend", BACKEND,
	    "VRT_r_beresp_backend(ctx)",
		VCL_MET_BACKEND_ERROR | VCL_MET_BACKEND_RESPONSE,
	    NULL,	/* No writes allowed */
		0,
	},
	{ "beresp.backend.ip", IP,
	    "VRT_r_beresp_backend_ip(ctx)",
		VCL_MET_BACKEND_RESPONSE,
	    NULL,	/* No writes allowed */
		0,
	},
	{ "beresp.backend.name", STRING,
	    "VRT_r_beresp_backend_name(ctx)",
		VCL_MET_BACKEND_ERROR | VCL_MET_BACKEND_RESPONSE,
	    NULL,	/* No writes allowed */
		0,
	},
	{ "beresp.body", BODY,
	    NULL,	/* No reads allowed */
		0,
	    "VRT_l_beresp_body(ctx, ",
		VCL_MET_BACKEND_ERROR,
	},
	{ "beresp.do_esi", BOOL,
	    "VRT_r_beresp_do_esi(ctx)",
		VCL_MET_BACKEND_ERROR | VCL_MET_BACKEND_RESPONSE,
	    "VRT_l_beresp_do_esi(ctx, ",
		VCL_MET_BACKEND_ERROR | VCL_MET_BACKEND_RESPONSE,
	},
	{ "beresp.do_gunzip", BOOL,
	    "VRT_r_beresp_do_gunzip(ctx)",
		VCL_MET_BACKEND_ERROR | VCL_MET_BACKEND_RESPONSE,
	    "VRT_l_beresp_do_gunzip(ctx, ",
		VCL_MET_BACKEND_ERROR | VCL_MET_BACKEND_RESPONSE,
	},
	{ "beresp.do_gzip", BOOL,
	    "VRT_r_beresp_do_gzip(ctx)",
		VCL_MET_BACKEND_ERROR | VCL_MET_BACKEND_RESPONSE,
	    "VRT_l_beresp_do_gzip(ctx, ",
		VCL_MET_BACKEND_ERROR | VCL_MET_BACKEND_RESPONSE,
	},
	{ "beresp.do_stream", BOOL,
	    "VRT_r_beresp_do_stream(ctx)",
		VCL_MET_BACKEND_ERROR | VCL_MET_BACKEND_RESPONSE,
	    "VRT_l_beresp_do_stream(ctx, ",
		VCL_MET_BACKEND_ERROR | VCL_MET_BACKEND_RESPONSE,
	},
	{ "beresp.grace", DURATION,
	    "VRT_r_beresp_grace(ctx)",
		VCL_MET_BACKEND_ERROR | VCL_MET_BACKEND_RESPONSE,
	    "VRT_l_beresp_grace(ctx, ",
		VCL_MET_BACKEND_ERROR | VCL_MET_BACKEND_RESPONSE,
	},
	{ "beresp.http.", HEADER,
	    "HDR_BERESP",
		VCL_MET_BACKEND_ERROR | VCL_MET_BACKEND_RESPONSE,
	    "HDR_BERESP",
		VCL_MET_BACKEND_ERROR | VCL_MET_BACKEND_RESPONSE,
	},
	{ "beresp.keep", DURATION,
	    "VRT_r_beresp_keep(ctx)",
		VCL_MET_BACKEND_ERROR | VCL_MET_BACKEND_RESPONSE,
	    "VRT_l_beresp_keep(ctx, ",
		VCL_MET_BACKEND_ERROR | VCL_MET_BACKEND_RESPONSE,
	},
	{ "beresp.proto", STRING,
	    "VRT_r_beresp_proto(ctx)",
		VCL_MET_BACKEND_ERROR | VCL_MET_BACKEND_RESPONSE,
	    "VRT_l_beresp_proto(ctx, ",
		VCL_MET_BACKEND_ERROR | VCL_MET_BACKEND_RESPONSE,
	},
	{ "beresp.reason", STRING,
	    "VRT_r_beresp_reason(ctx)",
		VCL_MET_BACKEND_ERROR | VCL_MET_BACKEND_RESPONSE,
	    "VRT_l_beresp_reason(ctx, ",
		VCL_MET_BACKEND_ERROR | VCL_MET_BACKEND_RESPONSE,
	},
	{ "beresp.status", INT,
	    "VRT_r_beresp_status(ctx)",
		VCL_MET_BACKEND_ERROR | VCL_MET_BACKEND_RESPONSE,
	    "VRT_l_beresp_status(ctx, ",
		VCL_MET_BACKEND_ERROR | VCL_MET_BACKEND_RESPONSE,
	},
	{ "beresp.storage", STEVEDORE,
	    "VRT_r_beresp_storage(ctx)",
		VCL_MET_BACKEND_ERROR | VCL_MET_BACKEND_RESPONSE,
	    "VRT_l_beresp_storage(ctx, ",
		VCL_MET_BACKEND_ERROR | VCL_MET_BACKEND_RESPONSE,
	},
	{ "beresp.storage_hint", STRING,
	    "VRT_r_beresp_storage_hint(ctx)",
		VCL_MET_BACKEND_ERROR | VCL_MET_BACKEND_RESPONSE,
	    "VRT_l_beresp_storage_hint(ctx, ",
		VCL_MET_BACKEND_ERROR | VCL_MET_BACKEND_RESPONSE,
	},
	{ "beresp.ttl", DURATION,
	    "VRT_r_beresp_ttl(ctx)",
		VCL_MET_BACKEND_ERROR | VCL_MET_BACKEND_RESPONSE,
	    "VRT_l_beresp_ttl(ctx, ",
		VCL_MET_BACKEND_ERROR | VCL_MET_BACKEND_RESPONSE,
	},
	{ "beresp.uncacheable", BOOL,
	    "VRT_r_beresp_uncacheable(ctx)",
		VCL_MET_BACKEND_ERROR | VCL_MET_BACKEND_RESPONSE,
	    "VRT_l_beresp_uncacheable(ctx, ",
		VCL_MET_BACKEND_ERROR | VCL_MET_BACKEND_RESPONSE,
	},
	{ "beresp.was_304", BOOL,
	    "VRT_r_beresp_was_304(ctx)",
		VCL_MET_BACKEND_ERROR | VCL_MET_BACKEND_RESPONSE,
	    NULL,	/* No writes allowed */
		0,
	},
	{ "client.identity", STRING,
	    "VRT_r_client_identity(ctx)",
		VCL_MET_DELIVER | VCL_MET_HASH | VCL_MET_HIT | VCL_MET_MISS
		 | VCL_MET_PASS | VCL_MET_PIPE | VCL_MET_PURGE
		 | VCL_MET_RECV | VCL_MET_SYNTH,
	    "VRT_l_client_identity(ctx, ",
		VCL_MET_DELIVER | VCL_MET_HASH | VCL_MET_HIT | VCL_MET_MISS
		 | VCL_MET_PASS | VCL_MET_PIPE | VCL_MET_PURGE
		 | VCL_MET_RECV | VCL_MET_SYNTH,
	},
	{ "client.ip", IP,
	    "VRT_r_client_ip(ctx)",
		VCL_MET_BACKEND_ERROR | VCL_MET_BACKEND_FETCH
		 | VCL_MET_BACKEND_RESPONSE | VCL_MET_DELIVER | VCL_MET_HASH
		 | VCL_MET_HIT | VCL_MET_MISS | VCL_MET_PASS | VCL_MET_PIPE
		 | VCL_MET_PURGE | VCL_MET_RECV | VCL_MET_SYNTH,
	    NULL,	/* No writes allowed */
		0,
	},
	{ "local.ip", IP,
	    "VRT_r_local_ip(ctx)",
		VCL_MET_BACKEND_ERROR | VCL_MET_BACKEND_FETCH
		 | VCL_MET_BACKEND_RESPONSE | VCL_MET_DELIVER | VCL_MET_HASH
		 | VCL_MET_HIT | VCL_MET_MISS | VCL_MET_PASS | VCL_MET_PIPE
		 | VCL_MET_PURGE | VCL_MET_RECV | VCL_MET_SYNTH,
	    NULL,	/* No writes allowed */
		0,
	},
	{ "now", TIME,
	    "VRT_r_now(ctx)",
		VCL_MET_BACKEND_ERROR | VCL_MET_BACKEND_FETCH
		 | VCL_MET_BACKEND_RESPONSE | VCL_MET_DELIVER | VCL_MET_FINI
		 | VCL_MET_HASH | VCL_MET_HIT | VCL_MET_INIT | VCL_MET_MISS
		 | VCL_MET_PASS | VCL_MET_PIPE | VCL_MET_PURGE
		 | VCL_MET_RECV | VCL_MET_SYNTH,
	    NULL,	/* No writes allowed */
		0,
	},
	{ "obj.age", DURATION,
	    "VRT_r_obj_age(ctx)",
		VCL_MET_DELIVER | VCL_MET_HIT,
	    NULL,	/* No writes allowed */
		0,
	},
	{ "obj.grace", DURATION,
	    "VRT_r_obj_grace(ctx)",
		VCL_MET_DELIVER | VCL_MET_HIT,
	    NULL,	/* No writes allowed */
		0,
	},
	{ "obj.hits", INT,
	    "VRT_r_obj_hits(ctx)",
		VCL_MET_DELIVER | VCL_MET_HIT,
	    NULL,	/* No writes allowed */
		0,
	},
	{ "obj.http.", HEADER,
	    "HDR_OBJ",
		VCL_MET_HIT,
	    NULL,	/* No writes allowed */
		0,
	},
	{ "obj.keep", DURATION,
	    "VRT_r_obj_keep(ctx)",
		VCL_MET_DELIVER | VCL_MET_HIT,
	    NULL,	/* No writes allowed */
		0,
	},
	{ "obj.proto", STRING,
	    "VRT_r_obj_proto(ctx)",
		VCL_MET_HIT,
	    NULL,	/* No writes allowed */
		0,
	},
	{ "obj.reason", STRING,
	    "VRT_r_obj_reason(ctx)",
		VCL_MET_HIT,
	    NULL,	/* No writes allowed */
		0,
	},
	{ "obj.status", INT,
	    "VRT_r_obj_status(ctx)",
		VCL_MET_HIT,
	    NULL,	/* No writes allowed */
		0,
	},
	{ "obj.ttl", DURATION,
	    "VRT_r_obj_ttl(ctx)",
		VCL_MET_DELIVER | VCL_MET_HIT,
	    NULL,	/* No writes allowed */
		0,
	},
	{ "obj.uncacheable", BOOL,
	    "VRT_r_obj_uncacheable(ctx)",
		VCL_MET_DELIVER,
	    NULL,	/* No writes allowed */
		0,
	},
	{ "remote.ip", IP,
	    "VRT_r_remote_ip(ctx)",
		VCL_MET_BACKEND_ERROR | VCL_MET_BACKEND_FETCH
		 | VCL_MET_BACKEND_RESPONSE | VCL_MET_DELIVER | VCL_MET_HASH
		 | VCL_MET_HIT | VCL_MET_MISS | VCL_MET_PASS | VCL_MET_PIPE
		 | VCL_MET_PURGE | VCL_MET_RECV | VCL_MET_SYNTH,
	    NULL,	/* No writes allowed */
		0,
	},
	{ "req", HTTP,
	    "VRT_r_req(ctx)",
		VCL_MET_DELIVER | VCL_MET_HASH | VCL_MET_HIT | VCL_MET_MISS
		 | VCL_MET_PASS | VCL_MET_PIPE | VCL_MET_PURGE
		 | VCL_MET_RECV | VCL_MET_SYNTH,
	    NULL,	/* No writes allowed */
		0,
	},
	{ "req.backend_hint", BACKEND,
	    "VRT_r_req_backend_hint(ctx)",
		VCL_MET_DELIVER | VCL_MET_HASH | VCL_MET_HIT | VCL_MET_MISS
		 | VCL_MET_PASS | VCL_MET_PIPE | VCL_MET_PURGE
		 | VCL_MET_RECV | VCL_MET_SYNTH,
	    "VRT_l_req_backend_hint(ctx, ",
		VCL_MET_DELIVER | VCL_MET_HASH | VCL_MET_HIT | VCL_MET_MISS
		 | VCL_MET_PASS | VCL_MET_PIPE | VCL_MET_PURGE
		 | VCL_MET_RECV | VCL_MET_SYNTH,
	},
	{ "req.can_gzip", BOOL,
	    "VRT_r_req_can_gzip(ctx)",
		VCL_MET_DELIVER | VCL_MET_HASH | VCL_MET_HIT | VCL_MET_MISS
		 | VCL_MET_PASS | VCL_MET_PIPE | VCL_MET_PURGE
		 | VCL_MET_RECV | VCL_MET_SYNTH,
	    NULL,	/* No writes allowed */
		0,
	},
	{ "req.esi", BOOL,
	    "VRT_r_req_esi(ctx)",
		VCL_MET_DELIVER | VCL_MET_HASH | VCL_MET_HIT | VCL_MET_MISS
		 | VCL_MET_PASS | VCL_MET_PIPE | VCL_MET_PURGE
		 | VCL_MET_RECV | VCL_MET_SYNTH,
	    "VRT_l_req_esi(ctx, ",
		VCL_MET_DELIVER | VCL_MET_HASH | VCL_MET_HIT | VCL_MET_MISS
		 | VCL_MET_PASS | VCL_MET_PIPE | VCL_MET_PURGE
		 | VCL_MET_RECV | VCL_MET_SYNTH,
	},
	{ "req.esi_level", INT,
	    "VRT_r_req_esi_level(ctx)",
		VCL_MET_DELIVER | VCL_MET_HASH | VCL_MET_HIT | VCL_MET_MISS
		 | VCL_MET_PASS | VCL_MET_PIPE | VCL_MET_PURGE
		 | VCL_MET_RECV | VCL_MET_SYNTH,
	    NULL,	/* No writes allowed */
		0,
	},
	{ "req.hash_always_miss", BOOL,
	    "VRT_r_req_hash_always_miss(ctx)",
		VCL_MET_RECV,
	    "VRT_l_req_hash_always_miss(ctx, ",
		VCL_MET_RECV,
	},
	{ "req.hash_ignore_busy", BOOL,
	    "VRT_r_req_hash_ignore_busy(ctx)",
		VCL_MET_RECV,
	    "VRT_l_req_hash_ignore_busy(ctx, ",
		VCL_MET_RECV,
	},
	{ "req.http.", HEADER,
	    "HDR_REQ",
		VCL_MET_DELIVER | VCL_MET_HASH | VCL_MET_HIT | VCL_MET_MISS
		 | VCL_MET_PASS | VCL_MET_PIPE | VCL_MET_PURGE
		 | VCL_MET_RECV | VCL_MET_SYNTH,
	    "HDR_REQ",
		VCL_MET_DELIVER | VCL_MET_HASH | VCL_MET_HIT | VCL_MET_MISS
		 | VCL_MET_PASS | VCL_MET_PIPE | VCL_MET_PURGE
		 | VCL_MET_RECV | VCL_MET_SYNTH,
	},
	{ "req.method", STRING,
	    "VRT_r_req_method(ctx)",
		VCL_MET_DELIVER | VCL_MET_HASH | VCL_MET_HIT | VCL_MET_MISS
		 | VCL_MET_PASS | VCL_MET_PIPE | VCL_MET_PURGE
		 | VCL_MET_RECV | VCL_MET_SYNTH,
	    "VRT_l_req_method(ctx, ",
		VCL_MET_DELIVER | VCL_MET_HASH | VCL_MET_HIT | VCL_MET_MISS
		 | VCL_MET_PASS | VCL_MET_PIPE | VCL_MET_PURGE
		 | VCL_MET_RECV | VCL_MET_SYNTH,
	},
	{ "req.proto", STRING,
	    "VRT_r_req_proto(ctx)",
		VCL_MET_DELIVER | VCL_MET_HASH | VCL_MET_HIT | VCL_MET_MISS
		 | VCL_MET_PASS | VCL_MET_PIPE | VCL_MET_PURGE
		 | VCL_MET_RECV | VCL_MET_SYNTH,
	    "VRT_l_req_proto(ctx, ",
		VCL_MET_DELIVER | VCL_MET_HASH | VCL_MET_HIT | VCL_MET_MISS
		 | VCL_MET_PASS | VCL_MET_PIPE | VCL_MET_PURGE
		 | VCL_MET_RECV | VCL_MET_SYNTH,
	},
	{ "req.restarts", INT,
	    "VRT_r_req_restarts(ctx)",
		VCL_MET_DELIVER | VCL_MET_HASH | VCL_MET_HIT | VCL_MET_MISS
		 | VCL_MET_PASS | VCL_MET_PIPE | VCL_MET_PURGE
		 | VCL_MET_RECV | VCL_MET_SYNTH,
	    NULL,	/* No writes allowed */
		0,
	},
	{ "req.storage", STEVEDORE,
	    "VRT_r_req_storage(ctx)",
		VCL_MET_RECV,
	    "VRT_l_req_storage(ctx, ",
		VCL_MET_RECV,
	},
	{ "req.ttl", DURATION,
	    "VRT_r_req_ttl(ctx)",
		VCL_MET_DELIVER | VCL_MET_HASH | VCL_MET_HIT | VCL_MET_MISS
		 | VCL_MET_PASS | VCL_MET_PIPE | VCL_MET_PURGE
		 | VCL_MET_RECV | VCL_MET_SYNTH,
	    "VRT_l_req_ttl(ctx, ",
		VCL_MET_DELIVER | VCL_MET_HASH | VCL_MET_HIT | VCL_MET_MISS
		 | VCL_MET_PASS | VCL_MET_PIPE | VCL_MET_PURGE
		 | VCL_MET_RECV | VCL_MET_SYNTH,
	},
	{ "req.url", STRING,
	    "VRT_r_req_url(ctx)",
		VCL_MET_DELIVER | VCL_MET_HASH | VCL_MET_HIT | VCL_MET_MISS
		 | VCL_MET_PASS | VCL_MET_PIPE | VCL_MET_PURGE
		 | VCL_MET_RECV | VCL_MET_SYNTH,
	    "VRT_l_req_url(ctx, ",
		VCL_MET_DELIVER | VCL_MET_HASH | VCL_MET_HIT | VCL_MET_MISS
		 | VCL_MET_PASS | VCL_MET_PIPE | VCL_MET_PURGE
		 | VCL_MET_RECV | VCL_MET_SYNTH,
	},
	{ "req.xid", STRING,
	    "VRT_r_req_xid(ctx)",
		VCL_MET_DELIVER | VCL_MET_HASH | VCL_MET_HIT | VCL_MET_MISS
		 | VCL_MET_PASS | VCL_MET_PIPE | VCL_MET_PURGE
		 | VCL_MET_RECV | VCL_MET_SYNTH,
	    NULL,	/* No writes allowed */
		0,
	},
	{ "req_top.http.", HEADER,
	    "HDR_REQ_TOP",
		VCL_MET_DELIVER | VCL_MET_HASH | VCL_MET_HIT | VCL_MET_MISS
		 | VCL_MET_PASS | VCL_MET_PIPE | VCL_MET_PURGE
		 | VCL_MET_RECV | VCL_MET_SYNTH,
	    NULL,	/* No writes allowed */
		0,
	},
	{ "req_top.method", STRING,
	    "VRT_r_req_top_method(ctx)",
		VCL_MET_DELIVER | VCL_MET_HASH | VCL_MET_HIT | VCL_MET_MISS
		 | VCL_MET_PASS | VCL_MET_PIPE | VCL_MET_PURGE
		 | VCL_MET_RECV | VCL_MET_SYNTH,
	    NULL,	/* No writes allowed */
		0,
	},
	{ "req_top.proto", STRING,
	    "VRT_r_req_top_proto(ctx)",
		VCL_MET_DELIVER | VCL_MET_HASH | VCL_MET_HIT | VCL_MET_MISS
		 | VCL_MET_PASS | VCL_MET_PIPE | VCL_MET_PURGE
		 | VCL_MET_RECV | VCL_MET_SYNTH,
	    NULL,	/* No writes allowed */
		0,
	},
	{ "req_top.url", STRING,
	    "VRT_r_req_top_url(ctx)",
		VCL_MET_DELIVER | VCL_MET_HASH | VCL_MET_HIT | VCL_MET_MISS
		 | VCL_MET_PASS | VCL_MET_PIPE | VCL_MET_PURGE
		 | VCL_MET_RECV | VCL_MET_SYNTH,
	    NULL,	/* No writes allowed */
		0,
	},
	{ "resp", HTTP,
	    "VRT_r_resp(ctx)",
		VCL_MET_DELIVER | VCL_MET_SYNTH,
	    NULL,	/* No writes allowed */
		0,
	},
	{ "resp.body", BODY,
	    NULL,	/* No reads allowed */
		0,
	    "VRT_l_resp_body(ctx, ",
		VCL_MET_SYNTH,
	},
	{ "resp.http.", HEADER,
	    "HDR_RESP",
		VCL_MET_DELIVER | VCL_MET_SYNTH,
	    "HDR_RESP",
		VCL_MET_DELIVER | VCL_MET_SYNTH,
	},
	{ "resp.is_streaming", BOOL,
	    "VRT_r_resp_is_streaming(ctx)",
		VCL_MET_DELIVER | VCL_MET_SYNTH,
	    NULL,	/* No writes allowed */
		0,
	},
	{ "resp.proto", STRING,
	    "VRT_r_resp_proto(ctx)",
		VCL_MET_DELIVER | VCL_MET_SYNTH,
	    "VRT_l_resp_proto(ctx, ",
		VCL_MET_DELIVER | VCL_MET_SYNTH,
	},
	{ "resp.reason", STRING,
	    "VRT_r_resp_reason(ctx)",
		VCL_MET_DELIVER | VCL_MET_SYNTH,
	    "VRT_l_resp_reason(ctx, ",
		VCL_MET_DELIVER | VCL_MET_SYNTH,
	},
	{ "resp.status", INT,
	    "VRT_r_resp_status(ctx)",
		VCL_MET_DELIVER | VCL_MET_SYNTH,
	    "VRT_l_resp_status(ctx, ",
		VCL_MET_DELIVER | VCL_MET_SYNTH,
	},
	{ "server.hostname", STRING,
	    "VRT_r_server_hostname(ctx)",
		VCL_MET_BACKEND_ERROR | VCL_MET_BACKEND_FETCH
		 | VCL_MET_BACKEND_RESPONSE | VCL_MET_DELIVER | VCL_MET_FINI
		 | VCL_MET_HASH | VCL_MET_HIT | VCL_MET_INIT | VCL_MET_MISS
		 | VCL_MET_PASS | VCL_MET_PIPE | VCL_MET_PURGE
		 | VCL_MET_RECV | VCL_MET_SYNTH,
	    NULL,	/* No writes allowed */
		0,
	},
	{ "server.identity", STRING,
	    "VRT_r_server_identity(ctx)",
		VCL_MET_BACKEND_ERROR | VCL_MET_BACKEND_FETCH
		 | VCL_MET_BACKEND_RESPONSE | VCL_MET_DELIVER | VCL_MET_FINI
		 | VCL_MET_HASH | VCL_MET_HIT | VCL_MET_INIT | VCL_MET_MISS
		 | VCL_MET_PASS | VCL_MET_PIPE | VCL_MET_PURGE
		 | VCL_MET_RECV | VCL_MET_SYNTH,
	    NULL,	/* No writes allowed */
		0,
	},
	{ "server.ip", IP,
	    "VRT_r_server_ip(ctx)",
		VCL_MET_BACKEND_ERROR | VCL_MET_BACKEND_FETCH
		 | VCL_MET_BACKEND_RESPONSE | VCL_MET_DELIVER | VCL_MET_HASH
		 | VCL_MET_HIT | VCL_MET_MISS | VCL_MET_PASS | VCL_MET_PIPE
		 | VCL_MET_PURGE | VCL_MET_RECV | VCL_MET_SYNTH,
	    NULL,	/* No writes allowed */
		0,
	},
	{ NULL }
};

