/*
 * NB:  This file is machine generated, DO NOT EDIT!
 *
 * Edit and run generate.py instead
 */

VCL_HTTP VRT_r_bereq(const struct vrt_ctx *);

VCL_BACKEND VRT_r_bereq_backend(const struct vrt_ctx *);
void VRT_l_bereq_backend(const struct vrt_ctx *, VCL_BACKEND);

VCL_DURATION VRT_r_bereq_between_bytes_timeout(const struct vrt_ctx *);
void VRT_l_bereq_between_bytes_timeout(const struct vrt_ctx *, VCL_DURATION);

VCL_DURATION VRT_r_bereq_connect_timeout(const struct vrt_ctx *);
void VRT_l_bereq_connect_timeout(const struct vrt_ctx *, VCL_DURATION);

VCL_DURATION VRT_r_bereq_first_byte_timeout(const struct vrt_ctx *);
void VRT_l_bereq_first_byte_timeout(const struct vrt_ctx *, VCL_DURATION);


VCL_STRING VRT_r_bereq_method(const struct vrt_ctx *);
void VRT_l_bereq_method(const struct vrt_ctx *, const char *, ...);

VCL_STRING VRT_r_bereq_proto(const struct vrt_ctx *);
void VRT_l_bereq_proto(const struct vrt_ctx *, const char *, ...);

VCL_INT VRT_r_bereq_retries(const struct vrt_ctx *);

VCL_BOOL VRT_r_bereq_uncacheable(const struct vrt_ctx *);
void VRT_l_bereq_uncacheable(const struct vrt_ctx *, VCL_BOOL);

VCL_STRING VRT_r_bereq_url(const struct vrt_ctx *);
void VRT_l_bereq_url(const struct vrt_ctx *, const char *, ...);

VCL_STRING VRT_r_bereq_xid(const struct vrt_ctx *);

VCL_HTTP VRT_r_beresp(const struct vrt_ctx *);

VCL_IP VRT_r_beresp_backend_ip(const struct vrt_ctx *);

VCL_STRING VRT_r_beresp_backend_name(const struct vrt_ctx *);

VCL_BOOL VRT_r_beresp_do_esi(const struct vrt_ctx *);
void VRT_l_beresp_do_esi(const struct vrt_ctx *, VCL_BOOL);

VCL_BOOL VRT_r_beresp_do_gunzip(const struct vrt_ctx *);
void VRT_l_beresp_do_gunzip(const struct vrt_ctx *, VCL_BOOL);

VCL_BOOL VRT_r_beresp_do_gzip(const struct vrt_ctx *);
void VRT_l_beresp_do_gzip(const struct vrt_ctx *, VCL_BOOL);

VCL_BOOL VRT_r_beresp_do_stream(const struct vrt_ctx *);
void VRT_l_beresp_do_stream(const struct vrt_ctx *, VCL_BOOL);

VCL_DURATION VRT_r_beresp_grace(const struct vrt_ctx *);
void VRT_l_beresp_grace(const struct vrt_ctx *, VCL_DURATION);


VCL_DURATION VRT_r_beresp_keep(const struct vrt_ctx *);
void VRT_l_beresp_keep(const struct vrt_ctx *, VCL_DURATION);

VCL_STRING VRT_r_beresp_proto(const struct vrt_ctx *);
void VRT_l_beresp_proto(const struct vrt_ctx *, const char *, ...);

VCL_STRING VRT_r_beresp_reason(const struct vrt_ctx *);
void VRT_l_beresp_reason(const struct vrt_ctx *, const char *, ...);

VCL_INT VRT_r_beresp_status(const struct vrt_ctx *);
void VRT_l_beresp_status(const struct vrt_ctx *, VCL_INT);

VCL_STRING VRT_r_beresp_storage_hint(const struct vrt_ctx *);
void VRT_l_beresp_storage_hint(const struct vrt_ctx *, const char *, ...);

VCL_DURATION VRT_r_beresp_ttl(const struct vrt_ctx *);
void VRT_l_beresp_ttl(const struct vrt_ctx *, VCL_DURATION);

VCL_BOOL VRT_r_beresp_uncacheable(const struct vrt_ctx *);
void VRT_l_beresp_uncacheable(const struct vrt_ctx *, VCL_BOOL);

VCL_STRING VRT_r_client_identity(const struct vrt_ctx *);
void VRT_l_client_identity(const struct vrt_ctx *, const char *, ...);

VCL_IP VRT_r_client_ip(const struct vrt_ctx *);

VCL_TIME VRT_r_now(const struct vrt_ctx *);

VCL_DURATION VRT_r_obj_grace(const struct vrt_ctx *);

VCL_INT VRT_r_obj_hits(const struct vrt_ctx *);


VCL_DURATION VRT_r_obj_keep(const struct vrt_ctx *);

VCL_STRING VRT_r_obj_proto(const struct vrt_ctx *);

VCL_STRING VRT_r_obj_reason(const struct vrt_ctx *);

VCL_INT VRT_r_obj_status(const struct vrt_ctx *);

VCL_DURATION VRT_r_obj_ttl(const struct vrt_ctx *);

VCL_BOOL VRT_r_obj_uncacheable(const struct vrt_ctx *);

VCL_HTTP VRT_r_req(const struct vrt_ctx *);

VCL_BACKEND VRT_r_req_backend_hint(const struct vrt_ctx *);
void VRT_l_req_backend_hint(const struct vrt_ctx *, VCL_BACKEND);

VCL_BOOL VRT_r_req_can_gzip(const struct vrt_ctx *);

VCL_BOOL VRT_r_req_esi(const struct vrt_ctx *);
void VRT_l_req_esi(const struct vrt_ctx *, VCL_BOOL);

VCL_INT VRT_r_req_esi_level(const struct vrt_ctx *);

VCL_BOOL VRT_r_req_hash_always_miss(const struct vrt_ctx *);
void VRT_l_req_hash_always_miss(const struct vrt_ctx *, VCL_BOOL);

VCL_BOOL VRT_r_req_hash_ignore_busy(const struct vrt_ctx *);
void VRT_l_req_hash_ignore_busy(const struct vrt_ctx *, VCL_BOOL);


VCL_STRING VRT_r_req_method(const struct vrt_ctx *);
void VRT_l_req_method(const struct vrt_ctx *, const char *, ...);

VCL_STRING VRT_r_req_proto(const struct vrt_ctx *);
void VRT_l_req_proto(const struct vrt_ctx *, const char *, ...);

VCL_INT VRT_r_req_restarts(const struct vrt_ctx *);

VCL_DURATION VRT_r_req_ttl(const struct vrt_ctx *);
void VRT_l_req_ttl(const struct vrt_ctx *, VCL_DURATION);

VCL_STRING VRT_r_req_url(const struct vrt_ctx *);
void VRT_l_req_url(const struct vrt_ctx *, const char *, ...);

VCL_STRING VRT_r_req_xid(const struct vrt_ctx *);

VCL_HTTP VRT_r_resp(const struct vrt_ctx *);


VCL_STRING VRT_r_resp_proto(const struct vrt_ctx *);
void VRT_l_resp_proto(const struct vrt_ctx *, const char *, ...);

VCL_STRING VRT_r_resp_reason(const struct vrt_ctx *);
void VRT_l_resp_reason(const struct vrt_ctx *, const char *, ...);

VCL_INT VRT_r_resp_status(const struct vrt_ctx *);
void VRT_l_resp_status(const struct vrt_ctx *, VCL_INT);

VCL_STRING VRT_r_server_hostname(const struct vrt_ctx *);

VCL_STRING VRT_r_server_identity(const struct vrt_ctx *);

VCL_IP VRT_r_server_ip(const struct vrt_ctx *);

double VRT_Stv_free_space(const char *);
double VRT_Stv_used_space(const char *);
unsigned VRT_Stv_happy(const char *);
