/*
 * NB:  This file is machine generated, DO NOT EDIT!
 *
 * Edit and run lib/libvcc/generate.py instead.
 */


#include "config.h"

#include "vcc_compile.h"

void
vcc_Var_Init(struct vcc *tl)
{
    struct symbol *sym;

	sym = VCC_MkSym(tl, "local.ip",  SYM_VAR, 0, 99);
	AN(sym);
	sym->type = IP;
	sym->eval = vcc_Eval_Var;
	sym->rname = "VRT_r_local_ip(ctx)";
	sym->r_methods =
		VCL_MET_BACKEND_ERROR | VCL_MET_BACKEND_FETCH
		 | VCL_MET_BACKEND_RESPONSE | VCL_MET_DELIVER | VCL_MET_HASH
		 | VCL_MET_HIT | VCL_MET_MISS | VCL_MET_PASS | VCL_MET_PIPE
		 | VCL_MET_PURGE | VCL_MET_RECV | VCL_MET_SYNTH;
	sym->w_methods =
		0;
	sym->u_methods =
		0;

	sym = VCC_MkSym(tl, "local.endpoint",  SYM_VAR, 41, 99);
	AN(sym);
	sym->type = STRING;
	sym->eval = vcc_Eval_Var;
	sym->rname = "VRT_r_local_endpoint(ctx)";
	sym->r_methods =
		VCL_MET_BACKEND_ERROR | VCL_MET_BACKEND_FETCH
		 | VCL_MET_BACKEND_RESPONSE | VCL_MET_DELIVER | VCL_MET_HASH
		 | VCL_MET_HIT | VCL_MET_MISS | VCL_MET_PASS | VCL_MET_PIPE
		 | VCL_MET_PURGE | VCL_MET_RECV | VCL_MET_SYNTH;
	sym->w_methods =
		0;
	sym->u_methods =
		0;

	sym = VCC_MkSym(tl, "local.socket",  SYM_VAR, 41, 99);
	AN(sym);
	sym->type = STRING;
	sym->eval = vcc_Eval_Var;
	sym->rname = "VRT_r_local_socket(ctx)";
	sym->r_methods =
		VCL_MET_BACKEND_ERROR | VCL_MET_BACKEND_FETCH
		 | VCL_MET_BACKEND_RESPONSE | VCL_MET_DELIVER | VCL_MET_HASH
		 | VCL_MET_HIT | VCL_MET_MISS | VCL_MET_PASS | VCL_MET_PIPE
		 | VCL_MET_PURGE | VCL_MET_RECV | VCL_MET_SYNTH;
	sym->w_methods =
		0;
	sym->u_methods =
		0;

	sym = VCC_MkSym(tl, "remote.ip",  SYM_VAR, 0, 99);
	AN(sym);
	sym->type = IP;
	sym->eval = vcc_Eval_Var;
	sym->rname = "VRT_r_remote_ip(ctx)";
	sym->r_methods =
		VCL_MET_BACKEND_ERROR | VCL_MET_BACKEND_FETCH
		 | VCL_MET_BACKEND_RESPONSE | VCL_MET_DELIVER | VCL_MET_HASH
		 | VCL_MET_HIT | VCL_MET_MISS | VCL_MET_PASS | VCL_MET_PIPE
		 | VCL_MET_PURGE | VCL_MET_RECV | VCL_MET_SYNTH;
	sym->w_methods =
		0;
	sym->u_methods =
		0;

	sym = VCC_MkSym(tl, "client.ip",  SYM_VAR, 0, 99);
	AN(sym);
	sym->type = IP;
	sym->eval = vcc_Eval_Var;
	sym->rname = "VRT_r_client_ip(ctx)";
	sym->r_methods =
		VCL_MET_BACKEND_ERROR | VCL_MET_BACKEND_FETCH
		 | VCL_MET_BACKEND_RESPONSE | VCL_MET_DELIVER | VCL_MET_HASH
		 | VCL_MET_HIT | VCL_MET_MISS | VCL_MET_PASS | VCL_MET_PIPE
		 | VCL_MET_PURGE | VCL_MET_RECV | VCL_MET_SYNTH;
	sym->w_methods =
		0;
	sym->u_methods =
		0;

	sym = VCC_MkSym(tl, "client.identity",  SYM_VAR, 0, 99);
	AN(sym);
	sym->type = STRING;
	sym->eval = vcc_Eval_Var;
	sym->rname = "VRT_r_client_identity(ctx)";
	sym->r_methods =
		VCL_MET_DELIVER | VCL_MET_HASH | VCL_MET_HIT | VCL_MET_MISS
		 | VCL_MET_PASS | VCL_MET_PIPE | VCL_MET_PURGE
		 | VCL_MET_RECV | VCL_MET_SYNTH;
	sym->lname = "VRT_l_client_identity(ctx, ";
	sym->w_methods =
		VCL_MET_DELIVER | VCL_MET_HASH | VCL_MET_HIT | VCL_MET_MISS
		 | VCL_MET_PASS | VCL_MET_PIPE | VCL_MET_PURGE
		 | VCL_MET_RECV | VCL_MET_SYNTH;
	sym->u_methods =
		0;

	sym = VCC_MkSym(tl, "server.ip",  SYM_VAR, 0, 99);
	AN(sym);
	sym->type = IP;
	sym->eval = vcc_Eval_Var;
	sym->rname = "VRT_r_server_ip(ctx)";
	sym->r_methods =
		VCL_MET_BACKEND_ERROR | VCL_MET_BACKEND_FETCH
		 | VCL_MET_BACKEND_RESPONSE | VCL_MET_DELIVER | VCL_MET_HASH
		 | VCL_MET_HIT | VCL_MET_MISS | VCL_MET_PASS | VCL_MET_PIPE
		 | VCL_MET_PURGE | VCL_MET_RECV | VCL_MET_SYNTH;
	sym->w_methods =
		0;
	sym->u_methods =
		0;

	sym = VCC_MkSym(tl, "server.hostname",  SYM_VAR, 0, 99);
	AN(sym);
	sym->type = STRING;
	sym->eval = vcc_Eval_Var;
	sym->rname = "VRT_r_server_hostname(ctx)";
	sym->r_methods =
		VCL_MET_BACKEND_ERROR | VCL_MET_BACKEND_FETCH
		 | VCL_MET_BACKEND_RESPONSE | VCL_MET_DELIVER | VCL_MET_FINI
		 | VCL_MET_HASH | VCL_MET_HIT | VCL_MET_INIT | VCL_MET_MISS
		 | VCL_MET_PASS | VCL_MET_PIPE | VCL_MET_PURGE
		 | VCL_MET_RECV | VCL_MET_SYNTH;
	sym->w_methods =
		0;
	sym->u_methods =
		0;

	sym = VCC_MkSym(tl, "server.identity",  SYM_VAR, 0, 99);
	AN(sym);
	sym->type = STRING;
	sym->eval = vcc_Eval_Var;
	sym->rname = "VRT_r_server_identity(ctx)";
	sym->r_methods =
		VCL_MET_BACKEND_ERROR | VCL_MET_BACKEND_FETCH
		 | VCL_MET_BACKEND_RESPONSE | VCL_MET_DELIVER | VCL_MET_FINI
		 | VCL_MET_HASH | VCL_MET_HIT | VCL_MET_INIT | VCL_MET_MISS
		 | VCL_MET_PASS | VCL_MET_PIPE | VCL_MET_PURGE
		 | VCL_MET_RECV | VCL_MET_SYNTH;
	sym->w_methods =
		0;
	sym->u_methods =
		0;

	sym = VCC_MkSym(tl, "req",  SYM_VAR, 0, 99);
	AN(sym);
	sym->type = HTTP;
	sym->eval = vcc_Eval_Var;
	sym->rname = "VRT_r_req(ctx)";
	sym->r_methods =
		VCL_MET_DELIVER | VCL_MET_HASH | VCL_MET_HIT | VCL_MET_MISS
		 | VCL_MET_PASS | VCL_MET_PIPE | VCL_MET_PURGE
		 | VCL_MET_RECV | VCL_MET_SYNTH;
	sym->w_methods =
		0;
	sym->u_methods =
		0;

	sym = VCC_MkSym(tl, "req.method",  SYM_VAR, 0, 99);
	AN(sym);
	sym->type = STRING;
	sym->eval = vcc_Eval_Var;
	sym->rname = "VRT_r_req_method(ctx)";
	sym->r_methods =
		VCL_MET_DELIVER | VCL_MET_HASH | VCL_MET_HIT | VCL_MET_MISS
		 | VCL_MET_PASS | VCL_MET_PIPE | VCL_MET_PURGE
		 | VCL_MET_RECV | VCL_MET_SYNTH;
	sym->lname = "VRT_l_req_method(ctx, ";
	sym->w_methods =
		VCL_MET_DELIVER | VCL_MET_HASH | VCL_MET_HIT | VCL_MET_MISS
		 | VCL_MET_PASS | VCL_MET_PIPE | VCL_MET_PURGE
		 | VCL_MET_RECV | VCL_MET_SYNTH;
	sym->u_methods =
		0;

	sym = VCC_MkSym(tl, "req.hash",  SYM_VAR, 0, 99);
	AN(sym);
	sym->type = BLOB;
	sym->eval = vcc_Eval_Var;
	sym->rname = "VRT_r_req_hash(ctx)";
	sym->r_methods =
		VCL_MET_DELIVER | VCL_MET_HIT | VCL_MET_MISS | VCL_MET_PASS
		 | VCL_MET_PURGE;
	sym->w_methods =
		0;
	sym->u_methods =
		0;

	sym = VCC_MkSym(tl, "req.url",  SYM_VAR, 0, 99);
	AN(sym);
	sym->type = STRING;
	sym->eval = vcc_Eval_Var;
	sym->rname = "VRT_r_req_url(ctx)";
	sym->r_methods =
		VCL_MET_DELIVER | VCL_MET_HASH | VCL_MET_HIT | VCL_MET_MISS
		 | VCL_MET_PASS | VCL_MET_PIPE | VCL_MET_PURGE
		 | VCL_MET_RECV | VCL_MET_SYNTH;
	sym->lname = "VRT_l_req_url(ctx, ";
	sym->w_methods =
		VCL_MET_DELIVER | VCL_MET_HASH | VCL_MET_HIT | VCL_MET_MISS
		 | VCL_MET_PASS | VCL_MET_PIPE | VCL_MET_PURGE
		 | VCL_MET_RECV | VCL_MET_SYNTH;
	sym->u_methods =
		0;

	sym = VCC_MkSym(tl, "req.proto",  SYM_VAR, 0, 40);
	AN(sym);
	sym->type = STRING;
	sym->eval = vcc_Eval_Var;
	sym->rname = "VRT_r_req_proto(ctx)";
	sym->r_methods =
		VCL_MET_DELIVER | VCL_MET_HASH | VCL_MET_HIT | VCL_MET_MISS
		 | VCL_MET_PASS | VCL_MET_PIPE | VCL_MET_PURGE
		 | VCL_MET_RECV | VCL_MET_SYNTH;
	sym->lname = "VRT_l_req_proto(ctx, ";
	sym->w_methods =
		VCL_MET_DELIVER | VCL_MET_HASH | VCL_MET_HIT | VCL_MET_MISS
		 | VCL_MET_PASS | VCL_MET_PIPE | VCL_MET_PURGE
		 | VCL_MET_RECV | VCL_MET_SYNTH;
	sym->u_methods =
		0;

	sym = VCC_MkSym(tl, "req.proto",  SYM_VAR, 41, 99);
	AN(sym);
	sym->type = STRING;
	sym->eval = vcc_Eval_Var;
	sym->rname = "VRT_r_req_proto(ctx)";
	sym->r_methods =
		VCL_MET_DELIVER | VCL_MET_HASH | VCL_MET_HIT | VCL_MET_MISS
		 | VCL_MET_PASS | VCL_MET_PIPE | VCL_MET_PURGE
		 | VCL_MET_RECV | VCL_MET_SYNTH;
	sym->w_methods =
		0;
	sym->u_methods =
		0;

	sym = VCC_MkSym(tl, "req.http.",  SYM_NONE, 0, 99);
	AN(sym);
	sym->wildcard = vcc_Var_Wildcard;
	AN(sym);
	sym->type = HEADER;
	sym->eval = vcc_Eval_Var;
	sym->rname = "HDR_REQ";
	sym->r_methods =
		VCL_MET_DELIVER | VCL_MET_HASH | VCL_MET_HIT | VCL_MET_MISS
		 | VCL_MET_PASS | VCL_MET_PIPE | VCL_MET_PURGE
		 | VCL_MET_RECV | VCL_MET_SYNTH;
	sym->lname = "HDR_REQ";
	sym->w_methods =
		VCL_MET_DELIVER | VCL_MET_HASH | VCL_MET_HIT | VCL_MET_MISS
		 | VCL_MET_PASS | VCL_MET_PIPE | VCL_MET_PURGE
		 | VCL_MET_RECV | VCL_MET_SYNTH;
	sym->uname = "VRT_u_req_http_(ctx)";
	sym->u_methods =
		VCL_MET_DELIVER | VCL_MET_HASH | VCL_MET_HIT | VCL_MET_MISS
		 | VCL_MET_PASS | VCL_MET_PIPE | VCL_MET_PURGE
		 | VCL_MET_RECV | VCL_MET_SYNTH;

	sym = VCC_MkSym(tl, "req.restarts",  SYM_VAR, 0, 99);
	AN(sym);
	sym->type = INT;
	sym->eval = vcc_Eval_Var;
	sym->rname = "VRT_r_req_restarts(ctx)";
	sym->r_methods =
		VCL_MET_DELIVER | VCL_MET_HASH | VCL_MET_HIT | VCL_MET_MISS
		 | VCL_MET_PASS | VCL_MET_PIPE | VCL_MET_PURGE
		 | VCL_MET_RECV | VCL_MET_SYNTH;
	sym->w_methods =
		0;
	sym->u_methods =
		0;

	sym = VCC_MkSym(tl, "req.storage",  SYM_VAR, 0, 99);
	AN(sym);
	sym->type = STEVEDORE;
	sym->eval = vcc_Eval_Var;
	sym->rname = "VRT_r_req_storage(ctx)";
	sym->r_methods =
		VCL_MET_DELIVER | VCL_MET_HASH | VCL_MET_HIT | VCL_MET_MISS
		 | VCL_MET_PASS | VCL_MET_PIPE | VCL_MET_PURGE
		 | VCL_MET_RECV | VCL_MET_SYNTH;
	sym->lname = "VRT_l_req_storage(ctx, ";
	sym->w_methods =
		VCL_MET_DELIVER | VCL_MET_HASH | VCL_MET_HIT | VCL_MET_MISS
		 | VCL_MET_PASS | VCL_MET_PIPE | VCL_MET_PURGE
		 | VCL_MET_RECV | VCL_MET_SYNTH;
	sym->u_methods =
		0;

	sym = VCC_MkSym(tl, "req.esi_level",  SYM_VAR, 0, 99);
	AN(sym);
	sym->type = INT;
	sym->eval = vcc_Eval_Var;
	sym->rname = "VRT_r_req_esi_level(ctx)";
	sym->r_methods =
		VCL_MET_DELIVER | VCL_MET_HASH | VCL_MET_HIT | VCL_MET_MISS
		 | VCL_MET_PASS | VCL_MET_PIPE | VCL_MET_PURGE
		 | VCL_MET_RECV | VCL_MET_SYNTH;
	sym->w_methods =
		0;
	sym->u_methods =
		0;

	sym = VCC_MkSym(tl, "req.ttl",  SYM_VAR, 0, 99);
	AN(sym);
	sym->type = DURATION;
	sym->eval = vcc_Eval_Var;
	sym->rname = "VRT_r_req_ttl(ctx)";
	sym->r_methods =
		VCL_MET_DELIVER | VCL_MET_HASH | VCL_MET_HIT | VCL_MET_MISS
		 | VCL_MET_PASS | VCL_MET_PIPE | VCL_MET_PURGE
		 | VCL_MET_RECV | VCL_MET_SYNTH;
	sym->lname = "VRT_l_req_ttl(ctx, ";
	sym->w_methods =
		VCL_MET_DELIVER | VCL_MET_HASH | VCL_MET_HIT | VCL_MET_MISS
		 | VCL_MET_PASS | VCL_MET_PIPE | VCL_MET_PURGE
		 | VCL_MET_RECV | VCL_MET_SYNTH;
	sym->u_methods =
		0;

	sym = VCC_MkSym(tl, "req.grace",  SYM_VAR, 0, 99);
	AN(sym);
	sym->type = DURATION;
	sym->eval = vcc_Eval_Var;
	sym->rname = "VRT_r_req_grace(ctx)";
	sym->r_methods =
		VCL_MET_DELIVER | VCL_MET_HASH | VCL_MET_HIT | VCL_MET_MISS
		 | VCL_MET_PASS | VCL_MET_PIPE | VCL_MET_PURGE
		 | VCL_MET_RECV | VCL_MET_SYNTH;
	sym->lname = "VRT_l_req_grace(ctx, ";
	sym->w_methods =
		VCL_MET_DELIVER | VCL_MET_HASH | VCL_MET_HIT | VCL_MET_MISS
		 | VCL_MET_PASS | VCL_MET_PIPE | VCL_MET_PURGE
		 | VCL_MET_RECV | VCL_MET_SYNTH;
	sym->u_methods =
		0;

	sym = VCC_MkSym(tl, "req.xid",  SYM_VAR, 0, 99);
	AN(sym);
	sym->type = STRING;
	sym->eval = vcc_Eval_Var;
	sym->rname = "VRT_r_req_xid(ctx)";
	sym->r_methods =
		VCL_MET_DELIVER | VCL_MET_HASH | VCL_MET_HIT | VCL_MET_MISS
		 | VCL_MET_PASS | VCL_MET_PIPE | VCL_MET_PURGE
		 | VCL_MET_RECV | VCL_MET_SYNTH;
	sym->w_methods =
		0;
	sym->u_methods =
		0;

	sym = VCC_MkSym(tl, "req.esi",  SYM_VAR, 0, 40);
	AN(sym);
	sym->type = BOOL;
	sym->eval = vcc_Eval_Var;
	sym->rname = "VRT_r_req_esi(ctx)";
	sym->r_methods =
		VCL_MET_DELIVER | VCL_MET_HASH | VCL_MET_HIT | VCL_MET_MISS
		 | VCL_MET_PASS | VCL_MET_PIPE | VCL_MET_PURGE
		 | VCL_MET_RECV | VCL_MET_SYNTH;
	sym->lname = "VRT_l_req_esi(ctx, ";
	sym->w_methods =
		VCL_MET_DELIVER | VCL_MET_HASH | VCL_MET_HIT | VCL_MET_MISS
		 | VCL_MET_PASS | VCL_MET_PIPE | VCL_MET_PURGE
		 | VCL_MET_RECV | VCL_MET_SYNTH;
	sym->u_methods =
		0;

	sym = VCC_MkSym(tl, "req.can_gzip",  SYM_VAR, 0, 99);
	AN(sym);
	sym->type = BOOL;
	sym->eval = vcc_Eval_Var;
	sym->rname = "VRT_r_req_can_gzip(ctx)";
	sym->r_methods =
		VCL_MET_DELIVER | VCL_MET_HASH | VCL_MET_HIT | VCL_MET_MISS
		 | VCL_MET_PASS | VCL_MET_PIPE | VCL_MET_PURGE
		 | VCL_MET_RECV | VCL_MET_SYNTH;
	sym->w_methods =
		0;
	sym->u_methods =
		0;

	sym = VCC_MkSym(tl, "req.backend_hint",  SYM_VAR, 0, 99);
	AN(sym);
	sym->type = BACKEND;
	sym->eval = vcc_Eval_Var;
	sym->rname = "VRT_r_req_backend_hint(ctx)";
	sym->r_methods =
		VCL_MET_DELIVER | VCL_MET_HASH | VCL_MET_HIT | VCL_MET_MISS
		 | VCL_MET_PASS | VCL_MET_PIPE | VCL_MET_PURGE
		 | VCL_MET_RECV | VCL_MET_SYNTH;
	sym->lname = "VRT_l_req_backend_hint(ctx, ";
	sym->w_methods =
		VCL_MET_DELIVER | VCL_MET_HASH | VCL_MET_HIT | VCL_MET_MISS
		 | VCL_MET_PASS | VCL_MET_PIPE | VCL_MET_PURGE
		 | VCL_MET_RECV | VCL_MET_SYNTH;
	sym->u_methods =
		0;

	sym = VCC_MkSym(tl, "req.hash_ignore_busy",  SYM_VAR, 0, 99);
	AN(sym);
	sym->type = BOOL;
	sym->eval = vcc_Eval_Var;
	sym->rname = "VRT_r_req_hash_ignore_busy(ctx)";
	sym->r_methods =
		VCL_MET_DELIVER | VCL_MET_HASH | VCL_MET_HIT | VCL_MET_MISS
		 | VCL_MET_PASS | VCL_MET_PIPE | VCL_MET_PURGE
		 | VCL_MET_RECV | VCL_MET_SYNTH;
	sym->lname = "VRT_l_req_hash_ignore_busy(ctx, ";
	sym->w_methods =
		VCL_MET_DELIVER | VCL_MET_HASH | VCL_MET_HIT | VCL_MET_MISS
		 | VCL_MET_PASS | VCL_MET_PIPE | VCL_MET_PURGE
		 | VCL_MET_RECV | VCL_MET_SYNTH;
	sym->u_methods =
		0;

	sym = VCC_MkSym(tl, "req.hash_always_miss",  SYM_VAR, 0, 99);
	AN(sym);
	sym->type = BOOL;
	sym->eval = vcc_Eval_Var;
	sym->rname = "VRT_r_req_hash_always_miss(ctx)";
	sym->r_methods =
		VCL_MET_DELIVER | VCL_MET_HASH | VCL_MET_HIT | VCL_MET_MISS
		 | VCL_MET_PASS | VCL_MET_PIPE | VCL_MET_PURGE
		 | VCL_MET_RECV | VCL_MET_SYNTH;
	sym->lname = "VRT_l_req_hash_always_miss(ctx, ";
	sym->w_methods =
		VCL_MET_DELIVER | VCL_MET_HASH | VCL_MET_HIT | VCL_MET_MISS
		 | VCL_MET_PASS | VCL_MET_PIPE | VCL_MET_PURGE
		 | VCL_MET_RECV | VCL_MET_SYNTH;
	sym->u_methods =
		0;

	sym = VCC_MkSym(tl, "req.is_hitmiss",  SYM_VAR, 0, 99);
	AN(sym);
	sym->type = BOOL;
	sym->eval = vcc_Eval_Var;
	sym->rname = "VRT_r_req_is_hitmiss(ctx)";
	sym->r_methods =
		VCL_MET_DELIVER | VCL_MET_HASH | VCL_MET_HIT | VCL_MET_MISS
		 | VCL_MET_PASS | VCL_MET_PIPE | VCL_MET_PURGE
		 | VCL_MET_RECV | VCL_MET_SYNTH;
	sym->w_methods =
		0;
	sym->u_methods =
		0;

	sym = VCC_MkSym(tl, "req.is_hitpass",  SYM_VAR, 0, 99);
	AN(sym);
	sym->type = BOOL;
	sym->eval = vcc_Eval_Var;
	sym->rname = "VRT_r_req_is_hitpass(ctx)";
	sym->r_methods =
		VCL_MET_DELIVER | VCL_MET_HASH | VCL_MET_HIT | VCL_MET_MISS
		 | VCL_MET_PASS | VCL_MET_PIPE | VCL_MET_PURGE
		 | VCL_MET_RECV | VCL_MET_SYNTH;
	sym->w_methods =
		0;
	sym->u_methods =
		0;

	sym = VCC_MkSym(tl, "req_top.method",  SYM_VAR, 0, 99);
	AN(sym);
	sym->type = STRING;
	sym->eval = vcc_Eval_Var;
	sym->rname = "VRT_r_req_top_method(ctx)";
	sym->r_methods =
		VCL_MET_DELIVER | VCL_MET_HASH | VCL_MET_HIT | VCL_MET_MISS
		 | VCL_MET_PASS | VCL_MET_PIPE | VCL_MET_PURGE
		 | VCL_MET_RECV | VCL_MET_SYNTH;
	sym->w_methods =
		0;
	sym->u_methods =
		0;

	sym = VCC_MkSym(tl, "req_top.url",  SYM_VAR, 0, 99);
	AN(sym);
	sym->type = STRING;
	sym->eval = vcc_Eval_Var;
	sym->rname = "VRT_r_req_top_url(ctx)";
	sym->r_methods =
		VCL_MET_DELIVER | VCL_MET_HASH | VCL_MET_HIT | VCL_MET_MISS
		 | VCL_MET_PASS | VCL_MET_PIPE | VCL_MET_PURGE
		 | VCL_MET_RECV | VCL_MET_SYNTH;
	sym->w_methods =
		0;
	sym->u_methods =
		0;

	sym = VCC_MkSym(tl, "req_top.http.",  SYM_NONE, 0, 99);
	AN(sym);
	sym->wildcard = vcc_Var_Wildcard;
	AN(sym);
	sym->type = HEADER;
	sym->eval = vcc_Eval_Var;
	sym->rname = "HDR_REQ_TOP";
	sym->r_methods =
		VCL_MET_DELIVER | VCL_MET_HASH | VCL_MET_HIT | VCL_MET_MISS
		 | VCL_MET_PASS | VCL_MET_PIPE | VCL_MET_PURGE
		 | VCL_MET_RECV | VCL_MET_SYNTH;
	sym->lname = "HDR_REQ_TOP";
	sym->w_methods =
		0;
	sym->u_methods =
		0;

	sym = VCC_MkSym(tl, "req_top.proto",  SYM_VAR, 0, 99);
	AN(sym);
	sym->type = STRING;
	sym->eval = vcc_Eval_Var;
	sym->rname = "VRT_r_req_top_proto(ctx)";
	sym->r_methods =
		VCL_MET_DELIVER | VCL_MET_HASH | VCL_MET_HIT | VCL_MET_MISS
		 | VCL_MET_PASS | VCL_MET_PIPE | VCL_MET_PURGE
		 | VCL_MET_RECV | VCL_MET_SYNTH;
	sym->w_methods =
		0;
	sym->u_methods =
		0;

	sym = VCC_MkSym(tl, "bereq",  SYM_VAR, 0, 99);
	AN(sym);
	sym->type = HTTP;
	sym->eval = vcc_Eval_Var;
	sym->rname = "VRT_r_bereq(ctx)";
	sym->r_methods =
		VCL_MET_BACKEND_ERROR | VCL_MET_BACKEND_FETCH
		 | VCL_MET_BACKEND_RESPONSE;
	sym->w_methods =
		0;
	sym->u_methods =
		0;

	sym = VCC_MkSym(tl, "bereq.xid",  SYM_VAR, 0, 99);
	AN(sym);
	sym->type = STRING;
	sym->eval = vcc_Eval_Var;
	sym->rname = "VRT_r_bereq_xid(ctx)";
	sym->r_methods =
		VCL_MET_BACKEND_ERROR | VCL_MET_BACKEND_FETCH
		 | VCL_MET_BACKEND_RESPONSE;
	sym->w_methods =
		0;
	sym->u_methods =
		0;

	sym = VCC_MkSym(tl, "bereq.retries",  SYM_VAR, 0, 99);
	AN(sym);
	sym->type = INT;
	sym->eval = vcc_Eval_Var;
	sym->rname = "VRT_r_bereq_retries(ctx)";
	sym->r_methods =
		VCL_MET_BACKEND_ERROR | VCL_MET_BACKEND_FETCH
		 | VCL_MET_BACKEND_RESPONSE;
	sym->w_methods =
		0;
	sym->u_methods =
		0;

	sym = VCC_MkSym(tl, "bereq.backend",  SYM_VAR, 0, 99);
	AN(sym);
	sym->type = BACKEND;
	sym->eval = vcc_Eval_Var;
	sym->rname = "VRT_r_bereq_backend(ctx)";
	sym->r_methods =
		VCL_MET_BACKEND_ERROR | VCL_MET_BACKEND_FETCH
		 | VCL_MET_BACKEND_RESPONSE | VCL_MET_PIPE;
	sym->lname = "VRT_l_bereq_backend(ctx, ";
	sym->w_methods =
		VCL_MET_BACKEND_ERROR | VCL_MET_BACKEND_FETCH
		 | VCL_MET_BACKEND_RESPONSE | VCL_MET_PIPE;
	sym->u_methods =
		0;

	sym = VCC_MkSym(tl, "bereq.body",  SYM_VAR, 0, 99);
	AN(sym);
	sym->type = BODY;
	sym->eval = vcc_Eval_Var;
	sym->r_methods =
		0;
	sym->w_methods =
		0;
	sym->uname = "VRT_u_bereq_body(ctx)";
	sym->u_methods =
		VCL_MET_BACKEND_FETCH;

	sym = VCC_MkSym(tl, "bereq.hash",  SYM_VAR, 0, 99);
	AN(sym);
	sym->type = BLOB;
	sym->eval = vcc_Eval_Var;
	sym->rname = "VRT_r_bereq_hash(ctx)";
	sym->r_methods =
		VCL_MET_BACKEND_ERROR | VCL_MET_BACKEND_FETCH
		 | VCL_MET_BACKEND_RESPONSE | VCL_MET_PIPE;
	sym->w_methods =
		0;
	sym->u_methods =
		0;

	sym = VCC_MkSym(tl, "bereq.method",  SYM_VAR, 0, 99);
	AN(sym);
	sym->type = STRING;
	sym->eval = vcc_Eval_Var;
	sym->rname = "VRT_r_bereq_method(ctx)";
	sym->r_methods =
		VCL_MET_BACKEND_ERROR | VCL_MET_BACKEND_FETCH
		 | VCL_MET_BACKEND_RESPONSE | VCL_MET_PIPE;
	sym->lname = "VRT_l_bereq_method(ctx, ";
	sym->w_methods =
		VCL_MET_BACKEND_ERROR | VCL_MET_BACKEND_FETCH
		 | VCL_MET_BACKEND_RESPONSE | VCL_MET_PIPE;
	sym->u_methods =
		0;

	sym = VCC_MkSym(tl, "bereq.url",  SYM_VAR, 0, 99);
	AN(sym);
	sym->type = STRING;
	sym->eval = vcc_Eval_Var;
	sym->rname = "VRT_r_bereq_url(ctx)";
	sym->r_methods =
		VCL_MET_BACKEND_ERROR | VCL_MET_BACKEND_FETCH
		 | VCL_MET_BACKEND_RESPONSE | VCL_MET_PIPE;
	sym->lname = "VRT_l_bereq_url(ctx, ";
	sym->w_methods =
		VCL_MET_BACKEND_ERROR | VCL_MET_BACKEND_FETCH
		 | VCL_MET_BACKEND_RESPONSE | VCL_MET_PIPE;
	sym->u_methods =
		0;

	sym = VCC_MkSym(tl, "bereq.proto",  SYM_VAR, 0, 40);
	AN(sym);
	sym->type = STRING;
	sym->eval = vcc_Eval_Var;
	sym->rname = "VRT_r_bereq_proto(ctx)";
	sym->r_methods =
		VCL_MET_BACKEND_ERROR | VCL_MET_BACKEND_FETCH
		 | VCL_MET_BACKEND_RESPONSE | VCL_MET_PIPE;
	sym->lname = "VRT_l_bereq_proto(ctx, ";
	sym->w_methods =
		VCL_MET_BACKEND_ERROR | VCL_MET_BACKEND_FETCH
		 | VCL_MET_BACKEND_RESPONSE | VCL_MET_PIPE;
	sym->u_methods =
		0;

	sym = VCC_MkSym(tl, "bereq.proto",  SYM_VAR, 41, 99);
	AN(sym);
	sym->type = STRING;
	sym->eval = vcc_Eval_Var;
	sym->rname = "VRT_r_bereq_proto(ctx)";
	sym->r_methods =
		VCL_MET_BACKEND_ERROR | VCL_MET_BACKEND_FETCH
		 | VCL_MET_BACKEND_RESPONSE | VCL_MET_PIPE;
	sym->w_methods =
		0;
	sym->u_methods =
		0;

	sym = VCC_MkSym(tl, "bereq.http.",  SYM_NONE, 0, 99);
	AN(sym);
	sym->wildcard = vcc_Var_Wildcard;
	AN(sym);
	sym->type = HEADER;
	sym->eval = vcc_Eval_Var;
	sym->rname = "HDR_BEREQ";
	sym->r_methods =
		VCL_MET_BACKEND_ERROR | VCL_MET_BACKEND_FETCH
		 | VCL_MET_BACKEND_RESPONSE | VCL_MET_PIPE;
	sym->lname = "HDR_BEREQ";
	sym->w_methods =
		VCL_MET_BACKEND_ERROR | VCL_MET_BACKEND_FETCH
		 | VCL_MET_BACKEND_RESPONSE | VCL_MET_PIPE;
	sym->uname = "VRT_u_bereq_http_(ctx)";
	sym->u_methods =
		VCL_MET_BACKEND_ERROR | VCL_MET_BACKEND_FETCH
		 | VCL_MET_BACKEND_RESPONSE | VCL_MET_PIPE;

	sym = VCC_MkSym(tl, "bereq.uncacheable",  SYM_VAR, 0, 99);
	AN(sym);
	sym->type = BOOL;
	sym->eval = vcc_Eval_Var;
	sym->rname = "VRT_r_bereq_uncacheable(ctx)";
	sym->r_methods =
		VCL_MET_BACKEND_ERROR | VCL_MET_BACKEND_FETCH
		 | VCL_MET_BACKEND_RESPONSE;
	sym->w_methods =
		0;
	sym->u_methods =
		0;

	sym = VCC_MkSym(tl, "bereq.connect_timeout",  SYM_VAR, 0, 99);
	AN(sym);
	sym->type = DURATION;
	sym->eval = vcc_Eval_Var;
	sym->rname = "VRT_r_bereq_connect_timeout(ctx)";
	sym->r_methods =
		VCL_MET_BACKEND_ERROR | VCL_MET_BACKEND_FETCH
		 | VCL_MET_BACKEND_RESPONSE | VCL_MET_PIPE;
	sym->lname = "VRT_l_bereq_connect_timeout(ctx, ";
	sym->w_methods =
		VCL_MET_BACKEND_ERROR | VCL_MET_BACKEND_FETCH
		 | VCL_MET_BACKEND_RESPONSE | VCL_MET_PIPE;
	sym->u_methods =
		0;

	sym = VCC_MkSym(tl, "bereq.first_byte_timeout",  SYM_VAR, 0, 99);
	AN(sym);
	sym->type = DURATION;
	sym->eval = vcc_Eval_Var;
	sym->rname = "VRT_r_bereq_first_byte_timeout(ctx)";
	sym->r_methods =
		VCL_MET_BACKEND_ERROR | VCL_MET_BACKEND_FETCH
		 | VCL_MET_BACKEND_RESPONSE;
	sym->lname = "VRT_l_bereq_first_byte_timeout(ctx, ";
	sym->w_methods =
		VCL_MET_BACKEND_ERROR | VCL_MET_BACKEND_FETCH
		 | VCL_MET_BACKEND_RESPONSE;
	sym->u_methods =
		0;

	sym = VCC_MkSym(tl, "bereq.between_bytes_timeout",  SYM_VAR, 0, 99);
	AN(sym);
	sym->type = DURATION;
	sym->eval = vcc_Eval_Var;
	sym->rname = "VRT_r_bereq_between_bytes_timeout(ctx)";
	sym->r_methods =
		VCL_MET_BACKEND_ERROR | VCL_MET_BACKEND_FETCH
		 | VCL_MET_BACKEND_RESPONSE;
	sym->lname = "VRT_l_bereq_between_bytes_timeout(ctx, ";
	sym->w_methods =
		VCL_MET_BACKEND_ERROR | VCL_MET_BACKEND_FETCH
		 | VCL_MET_BACKEND_RESPONSE;
	sym->u_methods =
		0;

	sym = VCC_MkSym(tl, "bereq.is_bgfetch",  SYM_VAR, 0, 99);
	AN(sym);
	sym->type = BOOL;
	sym->eval = vcc_Eval_Var;
	sym->rname = "VRT_r_bereq_is_bgfetch(ctx)";
	sym->r_methods =
		VCL_MET_BACKEND_ERROR | VCL_MET_BACKEND_FETCH
		 | VCL_MET_BACKEND_RESPONSE;
	sym->w_methods =
		0;
	sym->u_methods =
		0;

	sym = VCC_MkSym(tl, "beresp",  SYM_VAR, 0, 99);
	AN(sym);
	sym->type = HTTP;
	sym->eval = vcc_Eval_Var;
	sym->rname = "VRT_r_beresp(ctx)";
	sym->r_methods =
		VCL_MET_BACKEND_ERROR | VCL_MET_BACKEND_RESPONSE;
	sym->w_methods =
		0;
	sym->u_methods =
		0;

	sym = VCC_MkSym(tl, "beresp.body",  SYM_VAR, 0, 99);
	AN(sym);
	sym->type = BODY;
	sym->eval = vcc_Eval_Var;
	sym->r_methods =
		0;
	sym->lname = "VRT_l_beresp_body(ctx, ";
	sym->w_methods =
		VCL_MET_BACKEND_ERROR;
	sym->u_methods =
		0;

	sym = VCC_MkSym(tl, "beresp.proto",  SYM_VAR, 0, 40);
	AN(sym);
	sym->type = STRING;
	sym->eval = vcc_Eval_Var;
	sym->rname = "VRT_r_beresp_proto(ctx)";
	sym->r_methods =
		VCL_MET_BACKEND_ERROR | VCL_MET_BACKEND_RESPONSE;
	sym->lname = "VRT_l_beresp_proto(ctx, ";
	sym->w_methods =
		VCL_MET_BACKEND_ERROR | VCL_MET_BACKEND_RESPONSE;
	sym->u_methods =
		0;

	sym = VCC_MkSym(tl, "beresp.proto",  SYM_VAR, 41, 99);
	AN(sym);
	sym->type = STRING;
	sym->eval = vcc_Eval_Var;
	sym->rname = "VRT_r_beresp_proto(ctx)";
	sym->r_methods =
		VCL_MET_BACKEND_ERROR | VCL_MET_BACKEND_RESPONSE;
	sym->w_methods =
		0;
	sym->u_methods =
		0;

	sym = VCC_MkSym(tl, "beresp.status",  SYM_VAR, 0, 99);
	AN(sym);
	sym->type = INT;
	sym->eval = vcc_Eval_Var;
	sym->rname = "VRT_r_beresp_status(ctx)";
	sym->r_methods =
		VCL_MET_BACKEND_ERROR | VCL_MET_BACKEND_RESPONSE;
	sym->lname = "VRT_l_beresp_status(ctx, ";
	sym->w_methods =
		VCL_MET_BACKEND_ERROR | VCL_MET_BACKEND_RESPONSE;
	sym->u_methods =
		0;

	sym = VCC_MkSym(tl, "beresp.reason",  SYM_VAR, 0, 99);
	AN(sym);
	sym->type = STRING;
	sym->eval = vcc_Eval_Var;
	sym->rname = "VRT_r_beresp_reason(ctx)";
	sym->r_methods =
		VCL_MET_BACKEND_ERROR | VCL_MET_BACKEND_RESPONSE;
	sym->lname = "VRT_l_beresp_reason(ctx, ";
	sym->w_methods =
		VCL_MET_BACKEND_ERROR | VCL_MET_BACKEND_RESPONSE;
	sym->u_methods =
		0;

	sym = VCC_MkSym(tl, "beresp.http.",  SYM_NONE, 0, 99);
	AN(sym);
	sym->wildcard = vcc_Var_Wildcard;
	AN(sym);
	sym->type = HEADER;
	sym->eval = vcc_Eval_Var;
	sym->rname = "HDR_BERESP";
	sym->r_methods =
		VCL_MET_BACKEND_ERROR | VCL_MET_BACKEND_RESPONSE;
	sym->lname = "HDR_BERESP";
	sym->w_methods =
		VCL_MET_BACKEND_ERROR | VCL_MET_BACKEND_RESPONSE;
	sym->uname = "VRT_u_beresp_http_(ctx)";
	sym->u_methods =
		VCL_MET_BACKEND_ERROR | VCL_MET_BACKEND_RESPONSE;

	sym = VCC_MkSym(tl, "beresp.do_esi",  SYM_VAR, 0, 99);
	AN(sym);
	sym->type = BOOL;
	sym->eval = vcc_Eval_Var;
	sym->rname = "VRT_r_beresp_do_esi(ctx)";
	sym->r_methods =
		VCL_MET_BACKEND_ERROR | VCL_MET_BACKEND_RESPONSE;
	sym->lname = "VRT_l_beresp_do_esi(ctx, ";
	sym->w_methods =
		VCL_MET_BACKEND_ERROR | VCL_MET_BACKEND_RESPONSE;
	sym->u_methods =
		0;

	sym = VCC_MkSym(tl, "beresp.do_stream",  SYM_VAR, 0, 99);
	AN(sym);
	sym->type = BOOL;
	sym->eval = vcc_Eval_Var;
	sym->rname = "VRT_r_beresp_do_stream(ctx)";
	sym->r_methods =
		VCL_MET_BACKEND_ERROR | VCL_MET_BACKEND_RESPONSE;
	sym->lname = "VRT_l_beresp_do_stream(ctx, ";
	sym->w_methods =
		VCL_MET_BACKEND_ERROR | VCL_MET_BACKEND_RESPONSE;
	sym->u_methods =
		0;

	sym = VCC_MkSym(tl, "beresp.do_gzip",  SYM_VAR, 0, 99);
	AN(sym);
	sym->type = BOOL;
	sym->eval = vcc_Eval_Var;
	sym->rname = "VRT_r_beresp_do_gzip(ctx)";
	sym->r_methods =
		VCL_MET_BACKEND_ERROR | VCL_MET_BACKEND_RESPONSE;
	sym->lname = "VRT_l_beresp_do_gzip(ctx, ";
	sym->w_methods =
		VCL_MET_BACKEND_ERROR | VCL_MET_BACKEND_RESPONSE;
	sym->u_methods =
		0;

	sym = VCC_MkSym(tl, "beresp.do_gunzip",  SYM_VAR, 0, 99);
	AN(sym);
	sym->type = BOOL;
	sym->eval = vcc_Eval_Var;
	sym->rname = "VRT_r_beresp_do_gunzip(ctx)";
	sym->r_methods =
		VCL_MET_BACKEND_ERROR | VCL_MET_BACKEND_RESPONSE;
	sym->lname = "VRT_l_beresp_do_gunzip(ctx, ";
	sym->w_methods =
		VCL_MET_BACKEND_ERROR | VCL_MET_BACKEND_RESPONSE;
	sym->u_methods =
		0;

	sym = VCC_MkSym(tl, "beresp.was_304",  SYM_VAR, 0, 99);
	AN(sym);
	sym->type = BOOL;
	sym->eval = vcc_Eval_Var;
	sym->rname = "VRT_r_beresp_was_304(ctx)";
	sym->r_methods =
		VCL_MET_BACKEND_ERROR | VCL_MET_BACKEND_RESPONSE;
	sym->w_methods =
		0;
	sym->u_methods =
		0;

	sym = VCC_MkSym(tl, "beresp.uncacheable",  SYM_VAR, 0, 99);
	AN(sym);
	sym->type = BOOL;
	sym->eval = vcc_Eval_Var;
	sym->rname = "VRT_r_beresp_uncacheable(ctx)";
	sym->r_methods =
		VCL_MET_BACKEND_ERROR | VCL_MET_BACKEND_RESPONSE;
	sym->lname = "VRT_l_beresp_uncacheable(ctx, ";
	sym->w_methods =
		VCL_MET_BACKEND_ERROR | VCL_MET_BACKEND_RESPONSE;
	sym->u_methods =
		0;

	sym = VCC_MkSym(tl, "beresp.ttl",  SYM_VAR, 0, 99);
	AN(sym);
	sym->type = DURATION;
	sym->eval = vcc_Eval_Var;
	sym->rname = "VRT_r_beresp_ttl(ctx)";
	sym->r_methods =
		VCL_MET_BACKEND_ERROR | VCL_MET_BACKEND_RESPONSE;
	sym->lname = "VRT_l_beresp_ttl(ctx, ";
	sym->w_methods =
		VCL_MET_BACKEND_ERROR | VCL_MET_BACKEND_RESPONSE;
	sym->u_methods =
		0;

	sym = VCC_MkSym(tl, "beresp.age",  SYM_VAR, 0, 99);
	AN(sym);
	sym->type = DURATION;
	sym->eval = vcc_Eval_Var;
	sym->rname = "VRT_r_beresp_age(ctx)";
	sym->r_methods =
		VCL_MET_BACKEND_ERROR | VCL_MET_BACKEND_RESPONSE;
	sym->w_methods =
		0;
	sym->u_methods =
		0;

	sym = VCC_MkSym(tl, "beresp.grace",  SYM_VAR, 0, 99);
	AN(sym);
	sym->type = DURATION;
	sym->eval = vcc_Eval_Var;
	sym->rname = "VRT_r_beresp_grace(ctx)";
	sym->r_methods =
		VCL_MET_BACKEND_ERROR | VCL_MET_BACKEND_RESPONSE;
	sym->lname = "VRT_l_beresp_grace(ctx, ";
	sym->w_methods =
		VCL_MET_BACKEND_ERROR | VCL_MET_BACKEND_RESPONSE;
	sym->u_methods =
		0;

	sym = VCC_MkSym(tl, "beresp.keep",  SYM_VAR, 0, 99);
	AN(sym);
	sym->type = DURATION;
	sym->eval = vcc_Eval_Var;
	sym->rname = "VRT_r_beresp_keep(ctx)";
	sym->r_methods =
		VCL_MET_BACKEND_ERROR | VCL_MET_BACKEND_RESPONSE;
	sym->lname = "VRT_l_beresp_keep(ctx, ";
	sym->w_methods =
		VCL_MET_BACKEND_ERROR | VCL_MET_BACKEND_RESPONSE;
	sym->u_methods =
		0;

	sym = VCC_MkSym(tl, "beresp.backend",  SYM_VAR, 0, 99);
	AN(sym);
	sym->type = BACKEND;
	sym->eval = vcc_Eval_Var;
	sym->rname = "VRT_r_beresp_backend(ctx)";
	sym->r_methods =
		VCL_MET_BACKEND_ERROR | VCL_MET_BACKEND_RESPONSE;
	sym->w_methods =
		0;
	sym->u_methods =
		0;

	sym = VCC_MkSym(tl, "beresp.backend.name",  SYM_VAR, 0, 99);
	AN(sym);
	sym->type = STRING;
	sym->eval = vcc_Eval_Var;
	sym->rname = "VRT_r_beresp_backend_name(ctx)";
	sym->r_methods =
		VCL_MET_BACKEND_ERROR | VCL_MET_BACKEND_RESPONSE;
	sym->w_methods =
		0;
	sym->u_methods =
		0;

	sym = VCC_MkSym(tl, "beresp.backend.ip",  SYM_VAR, 0, 40);
	AN(sym);
	sym->type = IP;
	sym->eval = vcc_Eval_Var;
	sym->rname = "VRT_r_beresp_backend_ip(ctx)";
	sym->r_methods =
		VCL_MET_BACKEND_RESPONSE;
	sym->w_methods =
		0;
	sym->u_methods =
		0;

	sym = VCC_MkSym(tl, "beresp.storage",  SYM_VAR, 0, 99);
	AN(sym);
	sym->type = STEVEDORE;
	sym->eval = vcc_Eval_Var;
	sym->rname = "VRT_r_beresp_storage(ctx)";
	sym->r_methods =
		VCL_MET_BACKEND_ERROR | VCL_MET_BACKEND_RESPONSE;
	sym->lname = "VRT_l_beresp_storage(ctx, ";
	sym->w_methods =
		VCL_MET_BACKEND_ERROR | VCL_MET_BACKEND_RESPONSE;
	sym->u_methods =
		0;

	sym = VCC_MkSym(tl, "beresp.storage_hint",  SYM_VAR, 0, 40);
	AN(sym);
	sym->type = STRING;
	sym->eval = vcc_Eval_Var;
	sym->rname = "VRT_r_beresp_storage_hint(ctx)";
	sym->r_methods =
		VCL_MET_BACKEND_ERROR | VCL_MET_BACKEND_RESPONSE;
	sym->lname = "VRT_l_beresp_storage_hint(ctx, ";
	sym->w_methods =
		VCL_MET_BACKEND_ERROR | VCL_MET_BACKEND_RESPONSE;
	sym->u_methods =
		0;

	sym = VCC_MkSym(tl, "obj.proto",  SYM_VAR, 0, 99);
	AN(sym);
	sym->type = STRING;
	sym->eval = vcc_Eval_Var;
	sym->rname = "VRT_r_obj_proto(ctx)";
	sym->r_methods =
		VCL_MET_HIT;
	sym->w_methods =
		0;
	sym->u_methods =
		0;

	sym = VCC_MkSym(tl, "obj.status",  SYM_VAR, 0, 99);
	AN(sym);
	sym->type = INT;
	sym->eval = vcc_Eval_Var;
	sym->rname = "VRT_r_obj_status(ctx)";
	sym->r_methods =
		VCL_MET_HIT;
	sym->w_methods =
		0;
	sym->u_methods =
		0;

	sym = VCC_MkSym(tl, "obj.reason",  SYM_VAR, 0, 99);
	AN(sym);
	sym->type = STRING;
	sym->eval = vcc_Eval_Var;
	sym->rname = "VRT_r_obj_reason(ctx)";
	sym->r_methods =
		VCL_MET_HIT;
	sym->w_methods =
		0;
	sym->u_methods =
		0;

	sym = VCC_MkSym(tl, "obj.hits",  SYM_VAR, 0, 99);
	AN(sym);
	sym->type = INT;
	sym->eval = vcc_Eval_Var;
	sym->rname = "VRT_r_obj_hits(ctx)";
	sym->r_methods =
		VCL_MET_DELIVER | VCL_MET_HIT;
	sym->w_methods =
		0;
	sym->u_methods =
		0;

	sym = VCC_MkSym(tl, "obj.http.",  SYM_NONE, 0, 99);
	AN(sym);
	sym->wildcard = vcc_Var_Wildcard;
	AN(sym);
	sym->type = HEADER;
	sym->eval = vcc_Eval_Var;
	sym->rname = "HDR_OBJ";
	sym->r_methods =
		VCL_MET_HIT;
	sym->lname = "HDR_OBJ";
	sym->w_methods =
		0;
	sym->u_methods =
		0;

	sym = VCC_MkSym(tl, "obj.ttl",  SYM_VAR, 0, 99);
	AN(sym);
	sym->type = DURATION;
	sym->eval = vcc_Eval_Var;
	sym->rname = "VRT_r_obj_ttl(ctx)";
	sym->r_methods =
		VCL_MET_DELIVER | VCL_MET_HIT;
	sym->w_methods =
		0;
	sym->u_methods =
		0;

	sym = VCC_MkSym(tl, "obj.age",  SYM_VAR, 0, 99);
	AN(sym);
	sym->type = DURATION;
	sym->eval = vcc_Eval_Var;
	sym->rname = "VRT_r_obj_age(ctx)";
	sym->r_methods =
		VCL_MET_DELIVER | VCL_MET_HIT;
	sym->w_methods =
		0;
	sym->u_methods =
		0;

	sym = VCC_MkSym(tl, "obj.grace",  SYM_VAR, 0, 99);
	AN(sym);
	sym->type = DURATION;
	sym->eval = vcc_Eval_Var;
	sym->rname = "VRT_r_obj_grace(ctx)";
	sym->r_methods =
		VCL_MET_DELIVER | VCL_MET_HIT;
	sym->w_methods =
		0;
	sym->u_methods =
		0;

	sym = VCC_MkSym(tl, "obj.keep",  SYM_VAR, 0, 99);
	AN(sym);
	sym->type = DURATION;
	sym->eval = vcc_Eval_Var;
	sym->rname = "VRT_r_obj_keep(ctx)";
	sym->r_methods =
		VCL_MET_DELIVER | VCL_MET_HIT;
	sym->w_methods =
		0;
	sym->u_methods =
		0;

	sym = VCC_MkSym(tl, "obj.uncacheable",  SYM_VAR, 0, 99);
	AN(sym);
	sym->type = BOOL;
	sym->eval = vcc_Eval_Var;
	sym->rname = "VRT_r_obj_uncacheable(ctx)";
	sym->r_methods =
		VCL_MET_DELIVER;
	sym->w_methods =
		0;
	sym->u_methods =
		0;

	sym = VCC_MkSym(tl, "obj.storage",  SYM_VAR, 0, 99);
	AN(sym);
	sym->type = STEVEDORE;
	sym->eval = vcc_Eval_Var;
	sym->rname = "VRT_r_obj_storage(ctx)";
	sym->r_methods =
		VCL_MET_DELIVER | VCL_MET_HIT;
	sym->w_methods =
		0;
	sym->u_methods =
		0;

	sym = VCC_MkSym(tl, "resp",  SYM_VAR, 0, 99);
	AN(sym);
	sym->type = HTTP;
	sym->eval = vcc_Eval_Var;
	sym->rname = "VRT_r_resp(ctx)";
	sym->r_methods =
		VCL_MET_DELIVER | VCL_MET_SYNTH;
	sym->w_methods =
		0;
	sym->u_methods =
		0;

	sym = VCC_MkSym(tl, "resp.body",  SYM_VAR, 0, 99);
	AN(sym);
	sym->type = BODY;
	sym->eval = vcc_Eval_Var;
	sym->r_methods =
		0;
	sym->lname = "VRT_l_resp_body(ctx, ";
	sym->w_methods =
		VCL_MET_SYNTH;
	sym->u_methods =
		0;

	sym = VCC_MkSym(tl, "resp.proto",  SYM_VAR, 0, 40);
	AN(sym);
	sym->type = STRING;
	sym->eval = vcc_Eval_Var;
	sym->rname = "VRT_r_resp_proto(ctx)";
	sym->r_methods =
		VCL_MET_DELIVER | VCL_MET_SYNTH;
	sym->lname = "VRT_l_resp_proto(ctx, ";
	sym->w_methods =
		VCL_MET_DELIVER | VCL_MET_SYNTH;
	sym->u_methods =
		0;

	sym = VCC_MkSym(tl, "resp.proto",  SYM_VAR, 41, 99);
	AN(sym);
	sym->type = STRING;
	sym->eval = vcc_Eval_Var;
	sym->rname = "VRT_r_resp_proto(ctx)";
	sym->r_methods =
		VCL_MET_DELIVER | VCL_MET_SYNTH;
	sym->lname = "VRT_l_resp_proto(ctx, ";
	sym->w_methods =
		VCL_MET_DELIVER | VCL_MET_SYNTH;
	sym->u_methods =
		0;

	sym = VCC_MkSym(tl, "resp.status",  SYM_VAR, 0, 99);
	AN(sym);
	sym->type = INT;
	sym->eval = vcc_Eval_Var;
	sym->rname = "VRT_r_resp_status(ctx)";
	sym->r_methods =
		VCL_MET_DELIVER | VCL_MET_SYNTH;
	sym->lname = "VRT_l_resp_status(ctx, ";
	sym->w_methods =
		VCL_MET_DELIVER | VCL_MET_SYNTH;
	sym->u_methods =
		0;

	sym = VCC_MkSym(tl, "resp.reason",  SYM_VAR, 0, 99);
	AN(sym);
	sym->type = STRING;
	sym->eval = vcc_Eval_Var;
	sym->rname = "VRT_r_resp_reason(ctx)";
	sym->r_methods =
		VCL_MET_DELIVER | VCL_MET_SYNTH;
	sym->lname = "VRT_l_resp_reason(ctx, ";
	sym->w_methods =
		VCL_MET_DELIVER | VCL_MET_SYNTH;
	sym->u_methods =
		0;

	sym = VCC_MkSym(tl, "resp.http.",  SYM_NONE, 0, 99);
	AN(sym);
	sym->wildcard = vcc_Var_Wildcard;
	AN(sym);
	sym->type = HEADER;
	sym->eval = vcc_Eval_Var;
	sym->rname = "HDR_RESP";
	sym->r_methods =
		VCL_MET_DELIVER | VCL_MET_SYNTH;
	sym->lname = "HDR_RESP";
	sym->w_methods =
		VCL_MET_DELIVER | VCL_MET_SYNTH;
	sym->uname = "VRT_u_resp_http_(ctx)";
	sym->u_methods =
		VCL_MET_DELIVER | VCL_MET_SYNTH;

	sym = VCC_MkSym(tl, "resp.do_esi",  SYM_VAR, 41, 99);
	AN(sym);
	sym->type = BOOL;
	sym->eval = vcc_Eval_Var;
	sym->rname = "VRT_r_resp_do_esi(ctx)";
	sym->r_methods =
		VCL_MET_DELIVER | VCL_MET_SYNTH;
	sym->lname = "VRT_l_resp_do_esi(ctx, ";
	sym->w_methods =
		VCL_MET_DELIVER | VCL_MET_SYNTH;
	sym->u_methods =
		0;

	sym = VCC_MkSym(tl, "resp.is_streaming",  SYM_VAR, 0, 99);
	AN(sym);
	sym->type = BOOL;
	sym->eval = vcc_Eval_Var;
	sym->rname = "VRT_r_resp_is_streaming(ctx)";
	sym->r_methods =
		VCL_MET_DELIVER | VCL_MET_SYNTH;
	sym->w_methods =
		0;
	sym->u_methods =
		0;

	sym = VCC_MkSym(tl, "now",  SYM_VAR, 0, 99);
	AN(sym);
	sym->type = TIME;
	sym->eval = vcc_Eval_Var;
	sym->rname = "VRT_r_now(ctx)";
	sym->r_methods =
		VCL_MET_BACKEND_ERROR | VCL_MET_BACKEND_FETCH
		 | VCL_MET_BACKEND_RESPONSE | VCL_MET_DELIVER | VCL_MET_FINI
		 | VCL_MET_HASH | VCL_MET_HIT | VCL_MET_INIT | VCL_MET_MISS
		 | VCL_MET_PASS | VCL_MET_PIPE | VCL_MET_PURGE
		 | VCL_MET_RECV | VCL_MET_SYNTH;
	sym->w_methods =
		0;
	sym->u_methods =
		0;

	sym = VCC_MkSym(tl, "sess.xid",  SYM_VAR, 41, 99);
	AN(sym);
	sym->type = STRING;
	sym->eval = vcc_Eval_Var;
	sym->rname = "VRT_r_sess_xid(ctx)";
	sym->r_methods =
		VCL_MET_BACKEND_ERROR | VCL_MET_BACKEND_FETCH
		 | VCL_MET_BACKEND_RESPONSE | VCL_MET_DELIVER | VCL_MET_HASH
		 | VCL_MET_HIT | VCL_MET_MISS | VCL_MET_PASS | VCL_MET_PIPE
		 | VCL_MET_PURGE | VCL_MET_RECV | VCL_MET_SYNTH;
	sym->w_methods =
		0;
	sym->u_methods =
		0;

	sym = VCC_MkSym(tl, "sess.timeout_idle",  SYM_VAR, 0, 99);
	AN(sym);
	sym->type = DURATION;
	sym->eval = vcc_Eval_Var;
	sym->rname = "VRT_r_sess_timeout_idle(ctx)";
	sym->r_methods =
		VCL_MET_DELIVER | VCL_MET_HASH | VCL_MET_HIT | VCL_MET_MISS
		 | VCL_MET_PASS | VCL_MET_PIPE | VCL_MET_PURGE
		 | VCL_MET_RECV | VCL_MET_SYNTH;
	sym->lname = "VRT_l_sess_timeout_idle(ctx, ";
	sym->w_methods =
		VCL_MET_DELIVER | VCL_MET_HASH | VCL_MET_HIT | VCL_MET_MISS
		 | VCL_MET_PASS | VCL_MET_PIPE | VCL_MET_PURGE
		 | VCL_MET_RECV | VCL_MET_SYNTH;
	sym->u_methods =
		0;
}

/* VCL type identifiers */
const struct vrt_type VCL_TYPE_ACL[1] = { {
	.magic = VRT_TYPE_MAGIC,
	.lname = "acl",
	.uname = "ACL",
	.ctype = "const struct vrt_acl *",
	.szof = sizeof(VCL_ACL),
}};
const struct vrt_type VCL_TYPE_BACKEND[1] = { {
	.magic = VRT_TYPE_MAGIC,
	.lname = "backend",
	.uname = "BACKEND",
	.ctype = "const struct director *",
	.szof = sizeof(VCL_BACKEND),
}};
const struct vrt_type VCL_TYPE_BLOB[1] = { {
	.magic = VRT_TYPE_MAGIC,
	.lname = "blob",
	.uname = "BLOB",
	.ctype = "const struct vmod_priv *",
	.szof = sizeof(VCL_BLOB),
}};
const struct vrt_type VCL_TYPE_BODY[1] = { {
	.magic = VRT_TYPE_MAGIC,
	.lname = "body",
	.uname = "BODY",
	.ctype = "const char *",
	.szof = sizeof(VCL_BODY),
}};
const struct vrt_type VCL_TYPE_BOOL[1] = { {
	.magic = VRT_TYPE_MAGIC,
	.lname = "bool",
	.uname = "BOOL",
	.ctype = "unsigned",
	.szof = sizeof(VCL_BOOL),
}};
const struct vrt_type VCL_TYPE_BYTES[1] = { {
	.magic = VRT_TYPE_MAGIC,
	.lname = "bytes",
	.uname = "BYTES",
	.ctype = "int64_t",
	.szof = sizeof(VCL_BYTES),
}};
const struct vrt_type VCL_TYPE_DURATION[1] = { {
	.magic = VRT_TYPE_MAGIC,
	.lname = "duration",
	.uname = "DURATION",
	.ctype = "vtim_dur",
	.szof = sizeof(VCL_DURATION),
}};
const struct vrt_type VCL_TYPE_ENUM[1] = { {
	.magic = VRT_TYPE_MAGIC,
	.lname = "enum",
	.uname = "ENUM",
	.ctype = "const char *",
	.szof = sizeof(VCL_ENUM),
}};
const struct vrt_type VCL_TYPE_HEADER[1] = { {
	.magic = VRT_TYPE_MAGIC,
	.lname = "header",
	.uname = "HEADER",
	.ctype = "const struct gethdr_s *",
	.szof = sizeof(VCL_HEADER),
}};
const struct vrt_type VCL_TYPE_HTTP[1] = { {
	.magic = VRT_TYPE_MAGIC,
	.lname = "http",
	.uname = "HTTP",
	.ctype = "struct http *",
	.szof = sizeof(VCL_HTTP),
}};
const struct vrt_type VCL_TYPE_INSTANCE[1] = { {
	.magic = VRT_TYPE_MAGIC,
	.lname = "instance",
	.uname = "INSTANCE",
	.ctype = "void",
}};
const struct vrt_type VCL_TYPE_INT[1] = { {
	.magic = VRT_TYPE_MAGIC,
	.lname = "int",
	.uname = "INT",
	.ctype = "int64_t",
	.szof = sizeof(VCL_INT),
}};
const struct vrt_type VCL_TYPE_IP[1] = { {
	.magic = VRT_TYPE_MAGIC,
	.lname = "ip",
	.uname = "IP",
	.ctype = "const struct suckaddr *",
	.szof = sizeof(VCL_IP),
}};
const struct vrt_type VCL_TYPE_PROBE[1] = { {
	.magic = VRT_TYPE_MAGIC,
	.lname = "probe",
	.uname = "PROBE",
	.ctype = "const struct vrt_backend_probe *",
	.szof = sizeof(VCL_PROBE),
}};
const struct vrt_type VCL_TYPE_REAL[1] = { {
	.magic = VRT_TYPE_MAGIC,
	.lname = "real",
	.uname = "REAL",
	.ctype = "double",
	.szof = sizeof(VCL_REAL),
}};
const struct vrt_type VCL_TYPE_STEVEDORE[1] = { {
	.magic = VRT_TYPE_MAGIC,
	.lname = "stevedore",
	.uname = "STEVEDORE",
	.ctype = "const struct stevedore *",
	.szof = sizeof(VCL_STEVEDORE),
}};
const struct vrt_type VCL_TYPE_STRANDS[1] = { {
	.magic = VRT_TYPE_MAGIC,
	.lname = "strands",
	.uname = "STRANDS",
	.ctype = "const struct strands *",
	.szof = sizeof(VCL_STRANDS),
}};
const struct vrt_type VCL_TYPE_STRING[1] = { {
	.magic = VRT_TYPE_MAGIC,
	.lname = "string",
	.uname = "STRING",
	.ctype = "const char *",
	.szof = sizeof(VCL_STRING),
}};
const struct vrt_type VCL_TYPE_TIME[1] = { {
	.magic = VRT_TYPE_MAGIC,
	.lname = "time",
	.uname = "TIME",
	.ctype = "vtim_real",
	.szof = sizeof(VCL_TIME),
}};
const struct vrt_type VCL_TYPE_VCL[1] = { {
	.magic = VRT_TYPE_MAGIC,
	.lname = "vcl",
	.uname = "VCL",
	.ctype = "struct vcl *",
	.szof = sizeof(VCL_VCL),
}};
const struct vrt_type VCL_TYPE_VOID[1] = { {
	.magic = VRT_TYPE_MAGIC,
	.lname = "void",
	.uname = "VOID",
	.ctype = "void",
}};
