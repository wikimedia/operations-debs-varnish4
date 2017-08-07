
COUNTER LEVELS
==============

INFO – Informational counters
	Counters giving runtime information

DIAG – Diagnostic counters
	Counters giving diagnostic information

DEBUG – Debug counters
	Counters giving Varnish internals debug information


MAIN COUNTERS (MAIN.*)
======================

uptime – Child process uptime (INFO)
	How long the child process has been running.

sess_conn – Sessions accepted (INFO)
	Count of sessions successfully accepted

sess_drop – Sessions dropped (INFO)
	Count of sessions silently dropped due to lack of worker thread.

sess_fail – Session accept failures (INFO)
	Count of failures to accept TCP connection. Either the client changed its mind, or the kernel ran out of some resource like file descriptors.

client_req_400 – Client requests received, subject to 400 errors (INFO)
	400 means we couldn't make sense of the request, it was malformed in some drastic way.

client_req_417 – Client requests received, subject to 417 errors (INFO)
	417 means that something went wrong with an Expect: header.

client_req – Good client requests received (INFO)
	The count of parseable client requests seen.

cache_hit – Cache hits (INFO)
	Count of cache hits.  A cache hit indicates that an object has been delivered to a client without fetching it from a backend server.

cache_hitpass – Cache hits for pass. (INFO)
	Count of hits for pass. A cache hit for pass indicates that Varnish is going to pass the request to the backend and this decision has been cached in it self. This counts how many times the cached decision is being used.

cache_hitmiss – Cache hits for miss. (INFO)
	Count of hits for miss. A cache hit for miss indicates that Varnish is going to proceed as for a cache miss without request coalescing, and this decision has been cached. This counts how many times the cached decision is being used.

cache_miss – Cache misses (INFO)
	Count of misses. A cache miss indicates the object was fetched from the backend before delivering it to the client.

backend_conn – Backend conn. success (INFO)
	How many backend connections have successfully been established.

backend_unhealthy – Backend conn. not attempted (INFO)
	

backend_busy – Backend conn. too many (INFO)
	

backend_fail – Backend conn. failures (INFO)
	

backend_reuse – Backend conn. reuses (INFO)
	Count of backend connection reuses. This counter is increased whenever we reuse a recycled connection.

backend_recycle – Backend conn. recycles (INFO)
	Count of backend connection recycles. This counter is increased whenever we have a keep-alive connection that is put back into the pool of connections. It has not yet been used, but it might be, unless the backend closes it.

backend_retry – Backend conn. retry (INFO)
	

fetch_head – Fetch no body (HEAD) (INFO)
	beresp with no body because the request is HEAD.

fetch_length – Fetch with Length (INFO)
	beresp.body with Content-Length.

fetch_chunked – Fetch chunked (INFO)
	beresp.body with Chunked.

fetch_eof – Fetch EOF (INFO)
	beresp.body with EOF.

fetch_bad – Fetch bad T-E (INFO)
	beresp.body length/fetch could not be determined.

fetch_none – Fetch no body (INFO)
	beresp.body empty

fetch_1xx – Fetch no body (1xx) (INFO)
	beresp with no body because of 1XX response.

fetch_204 – Fetch no body (204) (INFO)
	beresp with no body because of 204 response.

fetch_304 – Fetch no body (304) (INFO)
	beresp with no body because of 304 response.

fetch_failed – Fetch failed (all causes) (INFO)
	beresp fetch failed.

fetch_no_thread – Fetch failed (no thread) (INFO)
	beresp fetch failed, no thread available.

pools – Number of thread pools (INFO)
	Number of thread pools. See also parameter thread_pools. NB: Presently pools cannot be removed once created.

threads – Total number of threads (INFO)
	Number of threads in all pools. See also parameters thread_pools, thread_pool_min and thread_pool_max.

threads_limited – Threads hit max (INFO)
	Number of times more threads were needed, but limit was reached in a thread pool. See also parameter thread_pool_max.

threads_created – Threads created (INFO)
	Total number of threads created in all pools.

threads_destroyed – Threads destroyed (INFO)
	Total number of threads destroyed in all pools.

threads_failed – Thread creation failed (INFO)
	Number of times creating a thread failed. See VSL::Debug for diagnostics. See also parameter thread_fail_delay.

thread_queue_len – Length of session queue (INFO)
	Length of session queue waiting for threads. NB: Only updates once per second. See also parameter thread_queue_limit.

busy_sleep – Number of requests sent to sleep on busy objhdr (INFO)
	Number of requests sent to sleep without a worker thread because they found a busy object.

busy_wakeup – Number of requests woken after sleep on busy objhdr (INFO)
	Number of requests taken off the busy object sleep list and rescheduled.

busy_killed – Number of requests killed after sleep on busy objhdr (INFO)
	Number of requests killed from the busy object sleep list due to lack of resources.

sess_queued – Sessions queued for thread (INFO)
	Number of times session was queued waiting for a thread. See also parameter thread_queue_limit.

sess_dropped – Sessions dropped for thread (INFO)
	Number of times session was dropped because the queue were too long already. See also parameter thread_queue_limit.

n_object – object structs made (INFO)
	Approximate number of HTTP objects (headers + body, if present) in the cache.

n_vampireobject – unresurrected objects (DIAG)
	Number of unresurrected objects

n_objectcore – objectcore structs made (INFO)
	Approximate number of object metadata elements in the cache. Each object needs an objectcore, extra objectcores are for hit-for-miss, hit-for-pass and busy objects.

n_objecthead – objecthead structs made (INFO)
	Approximate number of different hash entries in the cache.

n_backend – Number of backends (INFO)
	Number of backends known to us.

n_expired – Number of expired objects (INFO)
	Number of objects that expired from cache because of old age.

n_lru_nuked – Number of LRU nuked objects (INFO)
	How many objects have been forcefully evicted from storage to make room for a new object.

n_lru_moved – Number of LRU moved objects (DIAG)
	Number of move operations done on the LRU list.

losthdr – HTTP header overflows (INFO)
	

s_sess – Total sessions seen (INFO)
	

s_req – Total requests seen (INFO)
	

s_pipe – Total pipe sessions seen (INFO)
	

s_pass – Total pass-ed requests seen (INFO)
	

s_fetch – Total backend fetches initiated (INFO)
	

s_synth – Total synthethic responses made (INFO)
	

s_req_hdrbytes – Request header bytes (INFO)
	Total request header bytes received

s_req_bodybytes – Request body bytes (INFO)
	Total request body bytes received

s_resp_hdrbytes – Response header bytes (INFO)
	Total response header bytes transmitted

s_resp_bodybytes – Response body bytes (INFO)
	Total response body bytes transmitted

s_pipe_hdrbytes – Pipe request header bytes (INFO)
	Total request bytes received for piped sessions

s_pipe_in – Piped bytes from client (INFO)
	Total number of bytes forwarded from clients in pipe sessions

s_pipe_out – Piped bytes to client (INFO)
	Total number of bytes forwarded to clients in pipe sessions

sess_closed – Session Closed (INFO)
	

sess_closed_err – Session Closed with error (INFO)
	Total number of sessions closed with errors. See sc_* diag counters for detailed breakdown

sess_readahead – Session Read Ahead (INFO)
	

sess_herd – Session herd (DIAG)
	Number of times the timeout_linger triggered

sc_rem_close – Session OK  REM_CLOSE (DIAG)
	Number of session closes with REM_CLOSE (Client Closed)

sc_req_close – Session OK  REQ_CLOSE (DIAG)
	Number of session closes with REQ_CLOSE (Client requested close)

sc_req_http10 – Session Err REQ_HTTP10 (DIAG)
	Number of session closes with Error REQ_HTTP10 (Proto < HTTP/1.1)

sc_rx_bad – Session Err RX_BAD (DIAG)
	Number of session closes with Error RX_BAD (Received bad req/resp)

sc_rx_body – Session Err RX_BODY (DIAG)
	Number of session closes with Error RX_BODY (Failure receiving req.body)

sc_rx_junk – Session Err RX_JUNK (DIAG)
	Number of session closes with Error RX_JUNK (Received junk data)

sc_rx_overflow – Session Err RX_OVERFLOW (DIAG)
	Number of session closes with Error RX_OVERFLOW (Received buffer overflow)

sc_rx_timeout – Session Err RX_TIMEOUT (DIAG)
	Number of session closes with Error RX_TIMEOUT (Receive timeout)

sc_tx_pipe – Session OK  TX_PIPE (DIAG)
	Number of session closes with TX_PIPE (Piped transaction)

sc_tx_error – Session Err TX_ERROR (DIAG)
	Number of session closes with Error TX_ERROR (Error transaction)

sc_tx_eof – Session OK  TX_EOF (DIAG)
	Number of session closes with TX_EOF (EOF transmission)

sc_resp_close – Session OK  RESP_CLOSE (DIAG)
	Number of session closes with RESP_CLOSE (Backend/VCL requested close)

sc_overload – Session Err OVERLOAD (DIAG)
	Number of session closes with Error OVERLOAD (Out of some resource)

sc_pipe_overflow – Session Err PIPE_OVERFLOW (DIAG)
	Number of session closes with Error PIPE_OVERFLOW (Session pipe overflow)

sc_range_short – Session Err RANGE_SHORT (DIAG)
	Number of session closes with Error RANGE_SHORT (Insufficient data for range)

sc_req_http20 – Session Err REQ_HTTP20 (DIAG)
	Number of session closes with Error REQ_HTTP20 (HTTP2 not accepted)

sc_vcl_failure – Session Err VCL_FAILURE (DIAG)
	Number of session closes with Error VCL_FAILURE (VCL failure)

shm_records – SHM records (DIAG)
	

shm_writes – SHM writes (DIAG)
	

shm_flushes – SHM flushes due to overflow (DIAG)
	

shm_cont – SHM MTX contention (DIAG)
	

shm_cycles – SHM cycles through buffer (DIAG)
	

backend_req – Backend requests made (INFO)
	

n_vcl – Number of loaded VCLs in total (INFO)
	

n_vcl_avail – Number of VCLs available (DIAG)
	

n_vcl_discard – Number of discarded VCLs (DIAG)
	

vcl_fail – VCL failures (INFO)
	Count of failures which prevented VCL from completing.

bans – Count of bans (INFO)
	Number of all bans in system, including bans superseded by newer bans and bans already checked by the ban-lurker.

bans_completed – Number of bans marked 'completed' (DIAG)
	Number of bans which are no longer active, either because they got checked by the ban-lurker or superseded by newer identical bans.

bans_obj – Number of bans using obj.* (DIAG)
	Number of bans which use obj.* variables.  These bans can possibly be washed by the ban-lurker.

bans_req – Number of bans using req.* (DIAG)
	Number of bans which use req.* variables.  These bans can not be washed by the ban-lurker.

bans_added – Bans added (DIAG)
	Counter of bans added to ban list.

bans_deleted – Bans deleted (DIAG)
	Counter of bans deleted from ban list.

bans_tested – Bans tested against objects (lookup) (DIAG)
	Count of how many bans and objects have been tested against each other during hash lookup.

bans_obj_killed – Objects killed by bans (lookup) (DIAG)
	Number of objects killed by bans during object lookup.

bans_lurker_tested – Bans tested against objects (lurker) (DIAG)
	Count of how many bans and objects have been tested against each other by the ban-lurker.

bans_tests_tested – Ban tests tested against objects (lookup) (DIAG)
	Count of how many tests and objects have been tested against each other during lookup. 'ban req.url == foo && req.http.host == bar' counts as one in 'bans_tested' and as two in 'bans_tests_tested'

bans_lurker_tests_tested – Ban tests tested against objects (lurker) (DIAG)
	Count of how many tests and objects have been tested against each other by the ban-lurker. 'ban req.url == foo && req.http.host == bar' counts as one in 'bans_tested' and as two in 'bans_tests_tested'

bans_lurker_obj_killed – Objects killed by bans (lurker) (DIAG)
	Number of objects killed by the ban-lurker.

bans_lurker_obj_killed_cutoff – Objects killed by bans for cutoff (lurker) (DIAG)
	Number of objects killed by the ban-lurker to keep the number of bans below ban_cutoff.

bans_dups – Bans superseded by other bans (DIAG)
	Count of bans replaced by later identical bans.

bans_lurker_contention – Lurker gave way for lookup (DIAG)
	Number of times the ban-lurker had to wait for lookups.

bans_persisted_bytes – Bytes used by the persisted ban lists (DIAG)
	Number of bytes used by the persisted ban lists.

bans_persisted_fragmentation – Extra bytes in persisted ban lists due to fragmentation (DIAG)
	Number of extra bytes accumulated through dropped and completed bans in the persistent ban lists.

n_purges – Number of purge operations executed (INFO)
	

n_obj_purged – Number of purged objects (INFO)
	

exp_mailed – Number of objects mailed to expiry thread (DIAG)
	Number of objects mailed to expiry thread for handling.

exp_received – Number of objects received by expiry thread (DIAG)
	Number of objects received by expiry thread for handling.

hcb_nolock – HCB Lookups without lock (DEBUG)
	

hcb_lock – HCB Lookups with lock (DEBUG)
	

hcb_insert – HCB Inserts (DEBUG)
	

esi_errors – ESI parse errors (unlock) (DIAG)
	

esi_warnings – ESI parse warnings (unlock) (DIAG)
	

vmods – Loaded VMODs (INFO)
	

n_gzip – Gzip operations (INFO)
	

n_gunzip – Gunzip operations (INFO)
	

n_test_gunzip – Test gunzip operations (INFO)
	Those operations occur when Varnish receives a compressed object from a backend. They are done to verify the gzip stream while it's inserted in storage.

vsm_free – Free VSM space (DIAG)
	Number of bytes free in the shared memory used to communicate with tools like varnishstat, varnishlog etc.

vsm_used – Used VSM space (DIAG)
	Number of bytes used in the shared memory used to communicate with tools like varnishstat, varnishlog etc.

vsm_cooling – Cooling VSM space (DEBUG)
	Number of bytes which will soon (max 1 minute) be freed in the shared memory used to communicate with tools like varnishstat, varnishlog etc.

vsm_overflow – Overflow VSM space (DIAG)
	Number of bytes which does not fit in the shared memory used to communicate with tools like varnishstat, varnishlog etc. If this counter is not zero, consider increasing the runtime variable vsm_space.

vsm_overflowed – Overflowed VSM space (DIAG)
	Total number of bytes which did not fit in the shared memory used to communicate with tools like varnishstat, varnishlog etc. If this counter is not zero, consider increasing the runtime variable vsm_space.


MANAGEMENT PROCESS COUNTERS (MGT.*)
===================================

uptime – Management process uptime (INFO)
	Uptime in seconds of the management process

child_start – Child process started (DIAG)
	Number of times the child process has been started

child_exit – Child process normal exit (DIAG)
	Number of times the child process has been cleanly stopped

child_stop – Child process unexpected exit (DIAG)
	Number of times the child process has exited with an unexpected return code

child_died – Child process died (signal) (DIAG)
	Number of times the child process has died due to signals

child_dump – Child process core dumped (DIAG)
	Number of times the child process has produced core dumps

child_panic – Child process panic (DIAG)
	Number of times the management process has caught a child panic


MEMORY POOL COUNTERS (MEMPOOL.*)
================================

live – In use (DEBUG)
	

pool – In Pool (DEBUG)
	

sz_wanted – Size requested (DEBUG)
	

sz_actual – Size allocated (DEBUG)
	

allocs – Allocations (DEBUG)
	

frees – Frees (DEBUG)
	

recycle – Recycled from pool (DEBUG)
	

timeout – Timed out from pool (DEBUG)
	

toosmall – Too small to recycle (DEBUG)
	

surplus – Too many for pool (DEBUG)
	

randry – Pool ran dry (DEBUG)
	


MALLOC STORAGE COUNTERS (SMA.*)
===============================

c_req – Allocator requests (INFO)
	Number of times the storage has been asked to provide a storage segment.

c_fail – Allocator failures (INFO)
	Number of times the storage has failed to provide a storage segment.

c_bytes – Bytes allocated (INFO)
	Number of total bytes allocated by this storage.

c_freed – Bytes freed (INFO)
	Number of total bytes returned to this storage.

g_alloc – Allocations outstanding (INFO)
	Number of storage allocations outstanding.

g_bytes – Bytes outstanding (INFO)
	Number of bytes allocated from the storage.

g_space – Bytes available (INFO)
	Number of bytes left in the storage.


FILE STORAGE COUNTERS (SMF.*)
=============================

c_req – Allocator requests (INFO)
	Number of times the storage has been asked to provide a storage segment.

c_fail – Allocator failures (INFO)
	Number of times the storage has failed to provide a storage segment.

c_bytes – Bytes allocated (INFO)
	Number of total bytes allocated by this storage.

c_freed – Bytes freed (INFO)
	Number of total bytes returned to this storage.

g_alloc – Allocations outstanding (INFO)
	Number of storage allocations outstanding.

g_bytes – Bytes outstanding (INFO)
	Number of bytes allocated from the storage.

g_space – Bytes available (INFO)
	Number of bytes left in the storage.

g_smf – N struct smf (INFO)
	

g_smf_frag – N small free smf (INFO)
	

g_smf_large – N large free smf (INFO)
	


BACKEND COUNTERS (VBE.*)
========================

happy – Happy health probes (INFO)
	

bereq_hdrbytes – Request header bytes (INFO)
	Total backend request header bytes sent

bereq_bodybytes – Request body bytes (INFO)
	Total backend request body bytes sent

beresp_hdrbytes – Response header bytes (INFO)
	Total backend response header bytes received

beresp_bodybytes – Response body bytes (INFO)
	Total backend response body bytes received

pipe_hdrbytes – Pipe request header bytes (INFO)
	Total request bytes sent for piped sessions

pipe_out – Piped bytes to backend (INFO)
	Total number of bytes forwarded to backend in pipe sessions

pipe_in – Piped bytes from backend (INFO)
	Total number of bytes forwarded from backend in pipe sessions

conn – Concurrent connections to backend (INFO)
	

req – Backend requests sent (INFO)
	


LOCK COUNTERS (LCK.*)
=====================

creat – Created locks (DEBUG)
	

destroy – Destroyed locks (DEBUG)
	

locks – Lock Operations (DEBUG)
	

