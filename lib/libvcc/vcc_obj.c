/*
 * NB:  This file is machine generated, DO NOT EDIT!
 *
 * Edit and run generate.py instead
 */

#include "config.h"

#include <stdio.h>

#include "vcc_compile.h"

const struct var vcc_vars[] = {
	{ "bereq", HTTP, 5,
	    "VRT_r_bereq(ctx)",
		VCL_MET_BACKEND_ERROR | VCL_MET_BACKEND_FETCH
		 | VCL_MET_BACKEND_RESPONSE,
	    NULL,	/* No writes allowed */
		0,
	},
	{ "bereq.backend", BACKEND, 13,
	    "VRT_r_bereq_backend(ctx)",
		VCL_MET_BACKEND_ERROR | VCL_MET_BACKEND_FETCH
		 | VCL_MET_BACKEND_RESPONSE | VCL_MET_PIPE,
	    "VRT_l_bereq_backend(ctx, ",
		VCL_MET_BACKEND_ERROR | VCL_MET_BACKEND_FETCH
		 | VCL_MET_BACKEND_RESPONSE | VCL_MET_PIPE,
	},
	{ "bereq.between_bytes_timeout", DURATION, 27,
	    "VRT_r_bereq_between_bytes_timeout(ctx)",
		VCL_MET_BACKEND_ERROR | VCL_MET_BACKEND_FETCH
		 | VCL_MET_BACKEND_RESPONSE,
	    "VRT_l_bereq_between_bytes_timeout(ctx, ",
		VCL_MET_BACKEND_ERROR | VCL_MET_BACKEND_FETCH
		 | VCL_MET_BACKEND_RESPONSE,
	},
	{ "bereq.connect_timeout", DURATION, 21,
	    "VRT_r_bereq_connect_timeout(ctx)",
		VCL_MET_BACKEND_ERROR | VCL_MET_BACKEND_FETCH
		 | VCL_MET_BACKEND_RESPONSE | VCL_MET_PIPE,
	    "VRT_l_bereq_connect_timeout(ctx, ",
		VCL_MET_BACKEND_ERROR | VCL_MET_BACKEND_FETCH
		 | VCL_MET_BACKEND_RESPONSE | VCL_MET_PIPE,
	},
	{ "bereq.first_byte_timeout", DURATION, 24,
	    "VRT_r_bereq_first_byte_timeout(ctx)",
		VCL_MET_BACKEND_ERROR | VCL_MET_BACKEND_FETCH
		 | VCL_MET_BACKEND_RESPONSE,
	    "VRT_l_bereq_first_byte_timeout(ctx, ",
		VCL_MET_BACKEND_ERROR | VCL_MET_BACKEND_FETCH
		 | VCL_MET_BACKEND_RESPONSE,
	},
	{ "bereq.http.", HEADER, 11,
	    "HDR_BEREQ",
		VCL_MET_BACKEND_ERROR | VCL_MET_BACKEND_FETCH
		 | VCL_MET_BACKEND_RESPONSE | VCL_MET_PIPE,
	    "HDR_BEREQ",
		VCL_MET_BACKEND_ERROR | VCL_MET_BACKEND_FETCH
		 | VCL_MET_BACKEND_RESPONSE | VCL_MET_PIPE,
	},
	{ "bereq.method", STRING, 12,
	    "VRT_r_bereq_method(ctx)",
		VCL_MET_BACKEND_ERROR | VCL_MET_BACKEND_FETCH
		 | VCL_MET_BACKEND_RESPONSE | VCL_MET_PIPE,
	    "VRT_l_bereq_method(ctx, ",
		VCL_MET_BACKEND_ERROR | VCL_MET_BACKEND_FETCH
		 | VCL_MET_BACKEND_RESPONSE | VCL_MET_PIPE,
	},
	{ "bereq.proto", STRING, 11,
	    "VRT_r_bereq_proto(ctx)",
		VCL_MET_BACKEND_ERROR | VCL_MET_BACKEND_FETCH
		 | VCL_MET_BACKEND_RESPONSE | VCL_MET_PIPE,
	    "VRT_l_bereq_proto(ctx, ",
		VCL_MET_BACKEND_ERROR | VCL_MET_BACKEND_FETCH
		 | VCL_MET_BACKEND_RESPONSE | VCL_MET_PIPE,
	},
	{ "bereq.retries", INT, 13,
	    "VRT_r_bereq_retries(ctx)",
		VCL_MET_BACKEND_ERROR | VCL_MET_BACKEND_FETCH
		 | VCL_MET_BACKEND_RESPONSE,
	    NULL,	/* No writes allowed */
		0,
	},
	{ "bereq.uncacheable", BOOL, 17,
	    "VRT_r_bereq_uncacheable(ctx)",
		VCL_MET_BACKEND_ERROR | VCL_MET_BACKEND_FETCH
		 | VCL_MET_BACKEND_RESPONSE,
	    "VRT_l_bereq_uncacheable(ctx, ",
		VCL_MET_BACKEND_ERROR | VCL_MET_BACKEND_FETCH
		 | VCL_MET_BACKEND_RESPONSE,
	},
	{ "bereq.url", STRING, 9,
	    "VRT_r_bereq_url(ctx)",
		VCL_MET_BACKEND_ERROR | VCL_MET_BACKEND_FETCH
		 | VCL_MET_BACKEND_RESPONSE | VCL_MET_PIPE,
	    "VRT_l_bereq_url(ctx, ",
		VCL_MET_BACKEND_ERROR | VCL_MET_BACKEND_FETCH
		 | VCL_MET_BACKEND_RESPONSE | VCL_MET_PIPE,
	},
	{ "bereq.xid", STRING, 9,
	    "VRT_r_bereq_xid(ctx)",
		VCL_MET_BACKEND_ERROR | VCL_MET_BACKEND_FETCH
		 | VCL_MET_BACKEND_RESPONSE,
	    NULL,	/* No writes allowed */
		0,
	},
	{ "beresp", HTTP, 6,
	    "VRT_r_beresp(ctx)",
		VCL_MET_BACKEND_ERROR | VCL_MET_BACKEND_RESPONSE,
	    NULL,	/* No writes allowed */
		0,
	},
	{ "beresp.backend.ip", IP, 17,
	    "VRT_r_beresp_backend_ip(ctx)",
		VCL_MET_BACKEND_ERROR | VCL_MET_BACKEND_RESPONSE,
	    NULL,	/* No writes allowed */
		0,
	},
	{ "beresp.backend.name", STRING, 19,
	    "VRT_r_beresp_backend_name(ctx)",
		VCL_MET_BACKEND_ERROR | VCL_MET_BACKEND_RESPONSE,
	    NULL,	/* No writes allowed */
		0,
	},
	{ "beresp.do_esi", BOOL, 13,
	    "VRT_r_beresp_do_esi(ctx)",
		VCL_MET_BACKEND_ERROR | VCL_MET_BACKEND_RESPONSE,
	    "VRT_l_beresp_do_esi(ctx, ",
		VCL_MET_BACKEND_ERROR | VCL_MET_BACKEND_RESPONSE,
	},
	{ "beresp.do_gunzip", BOOL, 16,
	    "VRT_r_beresp_do_gunzip(ctx)",
		VCL_MET_BACKEND_ERROR | VCL_MET_BACKEND_RESPONSE,
	    "VRT_l_beresp_do_gunzip(ctx, ",
		VCL_MET_BACKEND_ERROR | VCL_MET_BACKEND_RESPONSE,
	},
	{ "beresp.do_gzip", BOOL, 14,
	    "VRT_r_beresp_do_gzip(ctx)",
		VCL_MET_BACKEND_ERROR | VCL_MET_BACKEND_RESPONSE,
	    "VRT_l_beresp_do_gzip(ctx, ",
		VCL_MET_BACKEND_ERROR | VCL_MET_BACKEND_RESPONSE,
	},
	{ "beresp.do_stream", BOOL, 16,
	    "VRT_r_beresp_do_stream(ctx)",
		VCL_MET_BACKEND_ERROR | VCL_MET_BACKEND_RESPONSE,
	    "VRT_l_beresp_do_stream(ctx, ",
		VCL_MET_BACKEND_ERROR | VCL_MET_BACKEND_RESPONSE,
	},
	{ "beresp.grace", DURATION, 12,
	    "VRT_r_beresp_grace(ctx)",
		VCL_MET_BACKEND_ERROR | VCL_MET_BACKEND_RESPONSE,
	    "VRT_l_beresp_grace(ctx, ",
		VCL_MET_BACKEND_ERROR | VCL_MET_BACKEND_RESPONSE,
	},
	{ "beresp.http.", HEADER, 12,
	    "HDR_BERESP",
		VCL_MET_BACKEND_ERROR | VCL_MET_BACKEND_RESPONSE,
	    "HDR_BERESP",
		VCL_MET_BACKEND_ERROR | VCL_MET_BACKEND_RESPONSE,
	},
	{ "beresp.keep", DURATION, 11,
	    "VRT_r_beresp_keep(ctx)",
		VCL_MET_BACKEND_ERROR | VCL_MET_BACKEND_RESPONSE,
	    "VRT_l_beresp_keep(ctx, ",
		VCL_MET_BACKEND_ERROR | VCL_MET_BACKEND_RESPONSE,
	},
	{ "beresp.proto", STRING, 12,
	    "VRT_r_beresp_proto(ctx)",
		VCL_MET_BACKEND_ERROR | VCL_MET_BACKEND_RESPONSE,
	    "VRT_l_beresp_proto(ctx, ",
		VCL_MET_BACKEND_ERROR | VCL_MET_BACKEND_RESPONSE,
	},
	{ "beresp.reason", STRING, 13,
	    "VRT_r_beresp_reason(ctx)",
		VCL_MET_BACKEND_ERROR | VCL_MET_BACKEND_RESPONSE,
	    "VRT_l_beresp_reason(ctx, ",
		VCL_MET_BACKEND_ERROR | VCL_MET_BACKEND_RESPONSE,
	},
	{ "beresp.status", INT, 13,
	    "VRT_r_beresp_status(ctx)",
		VCL_MET_BACKEND_ERROR | VCL_MET_BACKEND_RESPONSE,
	    "VRT_l_beresp_status(ctx, ",
		VCL_MET_BACKEND_ERROR | VCL_MET_BACKEND_RESPONSE,
	},
	{ "beresp.storage_hint", STRING, 19,
	    "VRT_r_beresp_storage_hint(ctx)",
		VCL_MET_BACKEND_ERROR | VCL_MET_BACKEND_RESPONSE,
	    "VRT_l_beresp_storage_hint(ctx, ",
		VCL_MET_BACKEND_ERROR | VCL_MET_BACKEND_RESPONSE,
	},
	{ "beresp.ttl", DURATION, 10,
	    "VRT_r_beresp_ttl(ctx)",
		VCL_MET_BACKEND_ERROR | VCL_MET_BACKEND_RESPONSE,
	    "VRT_l_beresp_ttl(ctx, ",
		VCL_MET_BACKEND_ERROR | VCL_MET_BACKEND_RESPONSE,
	},
	{ "beresp.uncacheable", BOOL, 18,
	    "VRT_r_beresp_uncacheable(ctx)",
		VCL_MET_BACKEND_ERROR | VCL_MET_BACKEND_RESPONSE,
	    "VRT_l_beresp_uncacheable(ctx, ",
		VCL_MET_BACKEND_ERROR | VCL_MET_BACKEND_RESPONSE,
	},
	{ "client.identity", STRING, 15,
	    "VRT_r_client_identity(ctx)",
		VCL_MET_DELIVER | VCL_MET_HASH | VCL_MET_HIT | VCL_MET_MISS
		 | VCL_MET_PASS | VCL_MET_PIPE | VCL_MET_PURGE
		 | VCL_MET_RECV | VCL_MET_SYNTH,
	    "VRT_l_client_identity(ctx, ",
		VCL_MET_DELIVER | VCL_MET_HASH | VCL_MET_HIT | VCL_MET_MISS
		 | VCL_MET_PASS | VCL_MET_PIPE | VCL_MET_PURGE
		 | VCL_MET_RECV | VCL_MET_SYNTH,
	},
	{ "client.ip", IP, 9,
	    "VRT_r_client_ip(ctx)",
		VCL_MET_DELIVER | VCL_MET_HASH | VCL_MET_HIT | VCL_MET_MISS
		 | VCL_MET_PASS | VCL_MET_PIPE | VCL_MET_PURGE
		 | VCL_MET_RECV | VCL_MET_SYNTH,
	    NULL,	/* No writes allowed */
		0,
	},
	{ "now", TIME, 3,
	    "VRT_r_now(ctx)",
		VCL_MET_BACKEND_ERROR | VCL_MET_BACKEND_FETCH
		 | VCL_MET_BACKEND_RESPONSE | VCL_MET_DELIVER | VCL_MET_FINI
		 | VCL_MET_HASH | VCL_MET_HIT | VCL_MET_INIT | VCL_MET_MISS
		 | VCL_MET_PASS | VCL_MET_PIPE | VCL_MET_PURGE
		 | VCL_MET_RECV | VCL_MET_SYNTH,
	    NULL,	/* No writes allowed */
		0,
	},
	{ "obj.grace", DURATION, 9,
	    "VRT_r_obj_grace(ctx)",
		VCL_MET_HIT,
	    NULL,	/* No writes allowed */
		0,
	},
	{ "obj.hits", INT, 8,
	    "VRT_r_obj_hits(ctx)",
		VCL_MET_DELIVER | VCL_MET_HIT,
	    NULL,	/* No writes allowed */
		0,
	},
	{ "obj.http.", HEADER, 9,
	    "HDR_OBJ",
		VCL_MET_HIT,
	    NULL,	/* No writes allowed */
		0,
	},
	{ "obj.keep", DURATION, 8,
	    "VRT_r_obj_keep(ctx)",
		VCL_MET_HIT,
	    NULL,	/* No writes allowed */
		0,
	},
	{ "obj.proto", STRING, 9,
	    "VRT_r_obj_proto(ctx)",
		VCL_MET_HIT,
	    NULL,	/* No writes allowed */
		0,
	},
	{ "obj.reason", STRING, 10,
	    "VRT_r_obj_reason(ctx)",
		VCL_MET_HIT,
	    NULL,	/* No writes allowed */
		0,
	},
	{ "obj.status", INT, 10,
	    "VRT_r_obj_status(ctx)",
		VCL_MET_HIT,
	    NULL,	/* No writes allowed */
		0,
	},
	{ "obj.ttl", DURATION, 7,
	    "VRT_r_obj_ttl(ctx)",
		VCL_MET_HIT,
	    NULL,	/* No writes allowed */
		0,
	},
	{ "obj.uncacheable", BOOL, 15,
	    "VRT_r_obj_uncacheable(ctx)",
		VCL_MET_HIT,
	    NULL,	/* No writes allowed */
		0,
	},
	{ "req", HTTP, 3,
	    "VRT_r_req(ctx)",
		VCL_MET_DELIVER | VCL_MET_HASH | VCL_MET_HIT | VCL_MET_MISS
		 | VCL_MET_PASS | VCL_MET_PIPE | VCL_MET_PURGE
		 | VCL_MET_RECV | VCL_MET_SYNTH,
	    NULL,	/* No writes allowed */
		0,
	},
	{ "req.backend_hint", BACKEND, 16,
	    "VRT_r_req_backend_hint(ctx)",
		VCL_MET_DELIVER | VCL_MET_HASH | VCL_MET_HIT | VCL_MET_MISS
		 | VCL_MET_PASS | VCL_MET_PIPE | VCL_MET_PURGE
		 | VCL_MET_RECV | VCL_MET_SYNTH,
	    "VRT_l_req_backend_hint(ctx, ",
		VCL_MET_DELIVER | VCL_MET_HASH | VCL_MET_HIT | VCL_MET_MISS
		 | VCL_MET_PASS | VCL_MET_PIPE | VCL_MET_PURGE
		 | VCL_MET_RECV | VCL_MET_SYNTH,
	},
	{ "req.can_gzip", BOOL, 12,
	    "VRT_r_req_can_gzip(ctx)",
		VCL_MET_DELIVER | VCL_MET_HASH | VCL_MET_HIT | VCL_MET_MISS
		 | VCL_MET_PASS | VCL_MET_PIPE | VCL_MET_PURGE
		 | VCL_MET_RECV | VCL_MET_SYNTH,
	    NULL,	/* No writes allowed */
		0,
	},
	{ "req.esi", BOOL, 7,
	    "VRT_r_req_esi(ctx)",
		VCL_MET_DELIVER | VCL_MET_HASH | VCL_MET_HIT | VCL_MET_MISS
		 | VCL_MET_PASS | VCL_MET_PIPE | VCL_MET_PURGE
		 | VCL_MET_RECV | VCL_MET_SYNTH,
	    "VRT_l_req_esi(ctx, ",
		VCL_MET_DELIVER | VCL_MET_HASH | VCL_MET_HIT | VCL_MET_MISS
		 | VCL_MET_PASS | VCL_MET_PIPE | VCL_MET_PURGE
		 | VCL_MET_RECV | VCL_MET_SYNTH,
	},
	{ "req.esi_level", INT, 13,
	    "VRT_r_req_esi_level(ctx)",
		VCL_MET_DELIVER | VCL_MET_HASH | VCL_MET_HIT | VCL_MET_MISS
		 | VCL_MET_PASS | VCL_MET_PIPE | VCL_MET_PURGE
		 | VCL_MET_RECV | VCL_MET_SYNTH,
	    NULL,	/* No writes allowed */
		0,
	},
	{ "req.hash_always_miss", BOOL, 20,
	    "VRT_r_req_hash_always_miss(ctx)",
		VCL_MET_RECV,
	    "VRT_l_req_hash_always_miss(ctx, ",
		VCL_MET_RECV,
	},
	{ "req.hash_ignore_busy", BOOL, 20,
	    "VRT_r_req_hash_ignore_busy(ctx)",
		VCL_MET_RECV,
	    "VRT_l_req_hash_ignore_busy(ctx, ",
		VCL_MET_RECV,
	},
	{ "req.http.", HEADER, 9,
	    "HDR_REQ",
		VCL_MET_DELIVER | VCL_MET_HASH | VCL_MET_HIT | VCL_MET_MISS
		 | VCL_MET_PASS | VCL_MET_PIPE | VCL_MET_PURGE
		 | VCL_MET_RECV | VCL_MET_SYNTH,
	    "HDR_REQ",
		VCL_MET_DELIVER | VCL_MET_HASH | VCL_MET_HIT | VCL_MET_MISS
		 | VCL_MET_PASS | VCL_MET_PIPE | VCL_MET_PURGE
		 | VCL_MET_RECV | VCL_MET_SYNTH,
	},
	{ "req.method", STRING, 10,
	    "VRT_r_req_method(ctx)",
		VCL_MET_DELIVER | VCL_MET_HASH | VCL_MET_HIT | VCL_MET_MISS
		 | VCL_MET_PASS | VCL_MET_PIPE | VCL_MET_PURGE
		 | VCL_MET_RECV | VCL_MET_SYNTH,
	    "VRT_l_req_method(ctx, ",
		VCL_MET_DELIVER | VCL_MET_HASH | VCL_MET_HIT | VCL_MET_MISS
		 | VCL_MET_PASS | VCL_MET_PIPE | VCL_MET_PURGE
		 | VCL_MET_RECV | VCL_MET_SYNTH,
	},
	{ "req.proto", STRING, 9,
	    "VRT_r_req_proto(ctx)",
		VCL_MET_DELIVER | VCL_MET_HASH | VCL_MET_HIT | VCL_MET_MISS
		 | VCL_MET_PASS | VCL_MET_PIPE | VCL_MET_PURGE
		 | VCL_MET_RECV | VCL_MET_SYNTH,
	    "VRT_l_req_proto(ctx, ",
		VCL_MET_DELIVER | VCL_MET_HASH | VCL_MET_HIT | VCL_MET_MISS
		 | VCL_MET_PASS | VCL_MET_PIPE | VCL_MET_PURGE
		 | VCL_MET_RECV | VCL_MET_SYNTH,
	},
	{ "req.restarts", INT, 12,
	    "VRT_r_req_restarts(ctx)",
		VCL_MET_DELIVER | VCL_MET_HASH | VCL_MET_HIT | VCL_MET_MISS
		 | VCL_MET_PASS | VCL_MET_PIPE | VCL_MET_PURGE
		 | VCL_MET_RECV | VCL_MET_SYNTH,
	    NULL,	/* No writes allowed */
		0,
	},
	{ "req.ttl", DURATION, 7,
	    "VRT_r_req_ttl(ctx)",
		VCL_MET_DELIVER | VCL_MET_HASH | VCL_MET_HIT | VCL_MET_MISS
		 | VCL_MET_PASS | VCL_MET_PIPE | VCL_MET_PURGE
		 | VCL_MET_RECV | VCL_MET_SYNTH,
	    "VRT_l_req_ttl(ctx, ",
		VCL_MET_DELIVER | VCL_MET_HASH | VCL_MET_HIT | VCL_MET_MISS
		 | VCL_MET_PASS | VCL_MET_PIPE | VCL_MET_PURGE
		 | VCL_MET_RECV | VCL_MET_SYNTH,
	},
	{ "req.url", STRING, 7,
	    "VRT_r_req_url(ctx)",
		VCL_MET_DELIVER | VCL_MET_HASH | VCL_MET_HIT | VCL_MET_MISS
		 | VCL_MET_PASS | VCL_MET_PIPE | VCL_MET_PURGE
		 | VCL_MET_RECV | VCL_MET_SYNTH,
	    "VRT_l_req_url(ctx, ",
		VCL_MET_DELIVER | VCL_MET_HASH | VCL_MET_HIT | VCL_MET_MISS
		 | VCL_MET_PASS | VCL_MET_PIPE | VCL_MET_PURGE
		 | VCL_MET_RECV | VCL_MET_SYNTH,
	},
	{ "req.xid", STRING, 7,
	    "VRT_r_req_xid(ctx)",
		VCL_MET_DELIVER | VCL_MET_HASH | VCL_MET_HIT | VCL_MET_MISS
		 | VCL_MET_PASS | VCL_MET_PIPE | VCL_MET_PURGE
		 | VCL_MET_RECV | VCL_MET_SYNTH,
	    NULL,	/* No writes allowed */
		0,
	},
	{ "resp", HTTP, 4,
	    "VRT_r_resp(ctx)",
		VCL_MET_DELIVER | VCL_MET_SYNTH,
	    NULL,	/* No writes allowed */
		0,
	},
	{ "resp.http.", HEADER, 10,
	    "HDR_RESP",
		VCL_MET_DELIVER | VCL_MET_SYNTH,
	    "HDR_RESP",
		VCL_MET_DELIVER | VCL_MET_SYNTH,
	},
	{ "resp.proto", STRING, 10,
	    "VRT_r_resp_proto(ctx)",
		VCL_MET_DELIVER | VCL_MET_SYNTH,
	    "VRT_l_resp_proto(ctx, ",
		VCL_MET_DELIVER | VCL_MET_SYNTH,
	},
	{ "resp.reason", STRING, 11,
	    "VRT_r_resp_reason(ctx)",
		VCL_MET_DELIVER | VCL_MET_SYNTH,
	    "VRT_l_resp_reason(ctx, ",
		VCL_MET_DELIVER | VCL_MET_SYNTH,
	},
	{ "resp.status", INT, 11,
	    "VRT_r_resp_status(ctx)",
		VCL_MET_DELIVER | VCL_MET_SYNTH,
	    "VRT_l_resp_status(ctx, ",
		VCL_MET_DELIVER | VCL_MET_SYNTH,
	},
	{ "server.hostname", STRING, 15,
	    "VRT_r_server_hostname(ctx)",
		VCL_MET_BACKEND_ERROR | VCL_MET_BACKEND_FETCH
		 | VCL_MET_BACKEND_RESPONSE | VCL_MET_DELIVER | VCL_MET_FINI
		 | VCL_MET_HASH | VCL_MET_HIT | VCL_MET_INIT | VCL_MET_MISS
		 | VCL_MET_PASS | VCL_MET_PIPE | VCL_MET_PURGE
		 | VCL_MET_RECV | VCL_MET_SYNTH,
	    NULL,	/* No writes allowed */
		0,
	},
	{ "server.identity", STRING, 15,
	    "VRT_r_server_identity(ctx)",
		VCL_MET_BACKEND_ERROR | VCL_MET_BACKEND_FETCH
		 | VCL_MET_BACKEND_RESPONSE | VCL_MET_DELIVER | VCL_MET_FINI
		 | VCL_MET_HASH | VCL_MET_HIT | VCL_MET_INIT | VCL_MET_MISS
		 | VCL_MET_PASS | VCL_MET_PIPE | VCL_MET_PURGE
		 | VCL_MET_RECV | VCL_MET_SYNTH,
	    NULL,	/* No writes allowed */
		0,
	},
	{ "server.ip", IP, 9,
	    "VRT_r_server_ip(ctx)",
		VCL_MET_DELIVER | VCL_MET_HASH | VCL_MET_HIT | VCL_MET_MISS
		 | VCL_MET_PASS | VCL_MET_PIPE | VCL_MET_PURGE
		 | VCL_MET_RECV | VCL_MET_SYNTH,
	    NULL,	/* No writes allowed */
		0,
	},
	{ NULL }
};
