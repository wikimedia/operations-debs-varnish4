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

uptime – How long the child process has been running. (INFO)
	Child process uptime

sess_conn – Count of sessions successfully accepted (INFO)
	Sessions accepted

sess_drop – Count of sessions silently dropped due to lack of worker thread. (INFO)
	Sessions dropped

sess_fail – Count of failures to accept TCP connection.  Either the client changed its mind, or the kernel ran out of some resource like file descriptors. (INFO)
	Session accept failures

client_req_400 – 400 means we couldn't make sense of the request, it was malformed in some drastic way. (INFO)
	Client requests received, subject to 400 errors

client_req_417 – 417 means that something went wrong with an Expect: header. (INFO)
	Client requests received, subject to 417 errors

client_req – The count of parseable client requests seen. (INFO)
	Good client requests received

cache_hit – Count of cache hits.   A cache hit indicates that an object has been delivered to a  client without fetching it from a backend server. (INFO)
	Cache hits

cache_hitpass – Count of hits for pass  A cache hit for pass indicates that Varnish is going to  pass the request to the backend and this decision has been   cached in it self. This counts how many times the cached   decision is being used. (INFO)
	Cache hits for pass

cache_miss – Count of misses  A cache miss indicates the object was fetched from the  backend before delivering it to the backend. (INFO)
	Cache misses

backend_conn – How many backend connections have successfully been established. (INFO)
	Backend conn. success

backend_unhealthy –  (INFO)
	Backend conn. not attempted

backend_busy –  (INFO)
	Backend conn. too many

backend_fail –  (INFO)
	Backend conn. failures

backend_reuse – Count of backend connection reuses  This counter is increased whenever we reuse a recycled connection. (INFO)
	Backend conn. reuses

backend_recycle – Count of backend connection recycles  This counter is increased whenever we have a keep-alive  connection that is put back into the pool of connections.  It has not yet been used, but it might be, unless the backend  closes it. (INFO)
	Backend conn. recycles

backend_retry –  (INFO)
	Backend conn. retry

fetch_head – beresp with no body because the request is HEAD. (INFO)
	Fetch no body (HEAD)

fetch_length – beresp.body with Content-Length. (INFO)
	Fetch with Length

fetch_chunked – beresp.body with Chunked. (INFO)
	Fetch chunked

fetch_eof – beresp.body with EOF. (INFO)
	Fetch EOF

fetch_bad – beresp.body length/fetch could not be determined. (INFO)
	Fetch bad T-E

fetch_none – beresp.body empty (INFO)
	Fetch no body

fetch_1xx – beresp with no body because of 1XX response. (INFO)
	Fetch no body (1xx)

fetch_204 – beresp with no body because of 204 response. (INFO)
	Fetch no body (204)

fetch_304 – beresp with no body because of 304 response. (INFO)
	Fetch no body (304)

fetch_failed – beresp fetch failed. (INFO)
	Fetch failed (all causes)

fetch_no_thread – beresp fetch failed, no thread available. (INFO)
	Fetch failed (no thread)

pools – Number of thread pools.  See also parameter thread_pools.  NB: Presently pools cannot be removed once created. (INFO)
	Number of thread pools

threads – Number of threads in all pools.  See also parameters thread_pools, thread_pool_min and thread_pool_max. (INFO)
	Total number of threads

threads_limited – Number of times more threads were needed, but limit was reached in a thread pool.  See also parameter thread_pool_max. (INFO)
	Threads hit max

threads_created – Total number of threads created in all pools. (INFO)
	Threads created

threads_destroyed – Total number of threads destroyed in all pools. (INFO)
	Threads destroyed

threads_failed – Number of times creating a thread failed.  See VSL::Debug for diagnostics.  See also parameter thread_fail_delay. (INFO)
	Thread creation failed

thread_queue_len – Length of session queue waiting for threads.  NB: Only updates once per second.  See also parameter queue_max. (INFO)
	Length of session queue

busy_sleep – Number of requests sent to sleep without a worker thread because they found a busy object. (INFO)
	Number of requests sent to sleep on busy objhdr

busy_wakeup – Number of requests taken of the busy object sleep list and and rescheduled. (INFO)
	Number of requests woken after sleep on busy objhdr

busy_killed – Number of requests killed from the busy object sleep list due to lack of resources. (INFO)
	Number of requests killed after sleep on busy objhdr

sess_queued – Number of times session was queued waiting for a thread.  See also parameter queue_max. (INFO)
	Sessions queued for thread

sess_dropped – Number of times session was dropped because the queue were too long already. See also parameter queue_max. (INFO)
	Sessions dropped for thread

n_object – Number of object structs made (INFO)
	object structs made

n_vampireobject – Number of unresurrected objects (DIAG)
	unresurrected objects

n_objectcore – Number of objectcore structs made (INFO)
	objectcore structs made

n_objecthead – Number of objecthead structs made (INFO)
	objecthead structs made

n_waitinglist – Number of waitinglist structs made (DEBUG)
	waitinglist structs made

n_backend – Number of backends known to us. (INFO)
	Number of backends

n_expired – Number of objects that expired from cache because of old age. (INFO)
	Number of expired objects

n_lru_nuked – How many objects have been forcefully evicted from storage to make room for a new object. (INFO)
	Number of LRU nuked objects

n_lru_moved – Number of move operations done on the LRU list. (DIAG)
	Number of LRU moved objects

losthdr –  (INFO)
	HTTP header overflows

s_sess –  (INFO)
	Total sessions seen

s_req –  (INFO)
	Total requests seen

s_pipe –  (INFO)
	Total pipe sessions seen

s_pass –  (INFO)
	Total pass-ed requests seen

s_fetch –  (INFO)
	Total backend fetches initiated

s_synth –  (INFO)
	Total synthethic responses made

s_req_hdrbytes – Total request header bytes received (INFO)
	Request header bytes

s_req_bodybytes – Total request body bytes received (INFO)
	Request body bytes

s_resp_hdrbytes – Total response header bytes transmitted (INFO)
	Response header bytes

s_resp_bodybytes – Total response body bytes transmitted (INFO)
	Response body bytes

s_pipe_hdrbytes – Total request bytes received for piped sessions (INFO)
	Pipe request header bytes

s_pipe_in – Total number of bytes forwarded from clients in pipe sessions (INFO)
	Piped bytes from client

s_pipe_out – Total number of bytes forwarded to clients in pipe sessions (INFO)
	Piped bytes to client

sess_closed –  (INFO)
	Session Closed

sess_closed_err – Total number of sessions closed with errors. See sc_* diag counters for detailed breakdown (INFO)
	Session Closed with error

sess_readahead –  (INFO)
	Session Read Ahead

sess_herd –  (DIAG)
	Session herd

sc_rem_close – Number of session closes with REM_CLOSE (Client Closed) (DIAG)
	Session OK  REM_CLOSE

sc_req_close – Number of session closes with REQ_CLOSE (Client requested close) (DIAG)
	Session OK  REQ_CLOSE

sc_req_http10 – Number of session closes with Error REQ_HTTP10 (Proto < HTTP/1.1) (DIAG)
	Session Err REQ_HTTP10

sc_rx_bad – Number of session closes with Error RX_BAD (Received bad req/resp) (DIAG)
	Session Err RX_BAD

sc_rx_body – Number of session closes with Error RX_BODY (Failure receiving req.body) (DIAG)
	Session Err RX_BODY

sc_rx_junk – Number of session closes with Error RX_JUNK (Received junk data) (DIAG)
	Session Err RX_JUNK

sc_rx_overflow – Number of session closes with Error RX_OVERFLOW (Received buffer overflow) (DIAG)
	Session Err RX_OVERFLOW

sc_rx_timeout – Number of session closes with Error RX_TIMEOUT (Receive timeout) (DIAG)
	Session Err RX_TIMEOUT

sc_tx_pipe – Number of session closes with TX_PIPE (Piped transaction) (DIAG)
	Session OK  TX_PIPE

sc_tx_error – Number of session closes with Error TX_ERROR (Error transaction) (DIAG)
	Session Err TX_ERROR

sc_tx_eof – Number of session closes with TX_EOF (EOF transmission) (DIAG)
	Session OK  TX_EOF

sc_resp_close – Number of session closes with RESP_CLOSE (Backend/VCL requested close) (DIAG)
	Session OK  RESP_CLOSE

sc_overload – Number of session closes with Error OVERLOAD (Out of some resource) (DIAG)
	Session Err OVERLOAD

sc_pipe_overflow – Number of session closes with Error PIPE_OVERFLOW (Session pipe overflow) (DIAG)
	Session Err PIPE_OVERFLOW

sc_range_short – Number of session closes with Error RANGE_SHORT (Insufficient data for range) (DIAG)
	Session Err RANGE_SHORT

shm_records –  (DIAG)
	SHM records

shm_writes –  (DIAG)
	SHM writes

shm_flushes –  (DIAG)
	SHM flushes due to overflow

shm_cont –  (DIAG)
	SHM MTX contention

shm_cycles –  (DIAG)
	SHM cycles through buffer

backend_req –  (INFO)
	Backend requests made

n_vcl –  (INFO)
	Number of loaded VCLs in total

n_vcl_avail –  (DIAG)
	Number of VCLs available

n_vcl_discard –  (DIAG)
	Number of discarded VCLs

bans – Number of all bans in system, including bans superseded by newer bans and bans already checked by the ban-lurker. (INFO)
	Count of bans

bans_completed – Number of bans which are no longer active, either because they got checked by the ban-lurker or superseded by newer identical bans. (DIAG)
	Number of bans marked 'completed'

bans_obj – Number of bans which use obj.* variables.  These bans can possibly be washed by the ban-lurker. (DIAG)
	Number of bans using obj.*

bans_req – Number of bans which use req.* variables.  These bans can not be washed by the ban-lurker. (DIAG)
	Number of bans using req.*

bans_added – Counter of bans added to ban list. (DIAG)
	Bans added

bans_deleted – Counter of bans deleted from ban list. (DIAG)
	Bans deleted

bans_tested – Count of how many bans and objects have been tested against each other during hash lookup. (DIAG)
	Bans tested against objects (lookup)

bans_obj_killed – Number of objects killed by bans during object lookup. (DIAG)
	Objects killed by bans (lookup)

bans_lurker_tested – Count of how many bans and objects have been tested against each other by the ban-lurker. (DIAG)
	Bans tested against objects (lurker)

bans_tests_tested – Count of how many tests and objects have been tested against each other during lookup.  'ban req.url == foo && req.http.host == bar' counts as one in 'bans_tested' and as two in 'bans_tests_tested' (DIAG)
	Ban tests tested against objects (lookup)

bans_lurker_tests_tested – Count of how many tests and objects have been tested against each other by the ban-lurker.  'ban req.url == foo && req.http.host == bar' counts as one in 'bans_tested' and as two in 'bans_tests_tested' (DIAG)
	Ban tests tested against objects (lurker)

bans_lurker_obj_killed – Number of objects killed by ban-lurker. (DIAG)
	Objects killed by bans (lurker)

bans_dups – Count of bans replaced by later identical bans. (DIAG)
	Bans superseded by other bans

bans_lurker_contention – Number of times the ban-lurker had to wait for lookups. (DIAG)
	Lurker gave way for lookup

bans_persisted_bytes – Number of bytes used by the persisted ban lists. (DIAG)
	Bytes used by the persisted ban lists

bans_persisted_fragmentation – Number of extra bytes accumulated through dropped and completed bans in the persistent ban lists. (DIAG)
	Extra bytes in persisted ban lists due to fragmentation

n_purges –  (INFO)
	Number of purge operations executed

n_obj_purged –  (INFO)
	Number of purged objects

exp_mailed – Number of objects mailed to expiry thread for handling. (DIAG)
	Number of objects mailed to expiry thread

exp_received – Number of objects received by expiry thread for handling. (DIAG)
	Number of objects received by expiry thread

hcb_nolock –  (DEBUG)
	HCB Lookups without lock

hcb_lock –  (DEBUG)
	HCB Lookups with lock

hcb_insert –  (DEBUG)
	HCB Inserts

esi_errors –  (DIAG)
	ESI parse errors (unlock)

esi_warnings –  (DIAG)
	ESI parse warnings (unlock)

vmods –  (INFO)
	Loaded VMODs

n_gzip –  (INFO)
	Gzip operations

n_gunzip –  (INFO)
	Gunzip operations

vsm_free – Number of bytes free in the shared memory used to communicate with tools like varnishstat, varnishlog etc. (DIAG)
	Free VSM space

vsm_used – Number of bytes used in the shared memory used to communicate with tools like varnishstat, varnishlog etc. (DIAG)
	Used VSM space

vsm_cooling – Number of bytes which will soon (max 1 minute) be freed in the shared memory used to communicate with tools like varnishstat, varnishlog etc. (DEBUG)
	Cooling VSM space

vsm_overflow – Number of bytes which does not fit in the shared memory used to communicate with tools like varnishstat, varnishlog etc. (DIAG)
	Overflow VSM space

vsm_overflowed – Total number of bytes which did not fit in the shared memory used to communicate with tools like varnishstat, varnishlog etc. (DIAG)
	Overflowed VSM space

MANAGEMENT PROCESS COUNTERS (MGT.*)
===================================

uptime – Uptime in seconds of the management process (INFO)
	Management process uptime

child_start – Number of times the child process has been started (DIAG)
	Child process started

child_exit – Number of times the child process has been cleanly stopped (DIAG)
	Child process normal exit

child_stop – Number of times the child process has exited with an unexpected return code (DIAG)
	Child process unexpected exit

child_died – Number of times the child process has died due to signals (DIAG)
	Child process died (signal)

child_dump – Number of times the child process has produced core dumps (DIAG)
	Child process core dumped

child_panic – Number of times the management process has caught a child panic (DIAG)
	Child process panic


PER MEMORY POOL COUNTERS (MEMPOOL.*)
====================================

live –  (DEBUG)
	In use

pool –  (DEBUG)
	In Pool

sz_wanted –  (DEBUG)
	Size requested

sz_actual –  (DEBUG)
	Size allocated

allocs –  (DEBUG)
	Allocations

frees –  (DEBUG)
	Frees

recycle –  (DEBUG)
	Recycled from pool

timeout –  (DEBUG)
	Timed out from pool

toosmall –  (DEBUG)
	Too small to recycle

surplus –  (DEBUG)
	Too many for pool

randry –  (DEBUG)
	Pool ran dry


PER MALLOC STORAGE COUNTERS (SMA.*)
===================================

c_req – Number of times the storage has been asked to provide a storage segment. (INFO)
	Allocator requests

c_fail – Number of times the storage has failed to provide a storage segment. (INFO)
	Allocator failures

c_bytes – Number of total bytes allocated by this storage. (INFO)
	Bytes allocated

c_freed – Number of total bytes returned to this storage. (INFO)
	Bytes freed

g_alloc – Number of storage allocations outstanding. (INFO)
	Allocations outstanding

g_bytes – Number of bytes allocated from the storage. (INFO)
	Bytes outstanding

g_space – Number of bytes left in the storage. (INFO)
	Bytes available


PER FILE STORAGE COUNTERS (SMF.*)
=================================

c_req – Number of times the storage has been asked to provide a storage segment. (INFO)
	Allocator requests

c_fail – Number of times the storage has failed to provide a storage segment. (INFO)
	Allocator failures

c_bytes – Number of total bytes allocated by this storage. (INFO)
	Bytes allocated

c_freed – Number of total bytes returned to this storage. (INFO)
	Bytes freed

g_alloc – Number of storage allocations outstanding. (INFO)
	Allocations outstanding

g_bytes – Number of bytes allocated from the storage. (INFO)
	Bytes outstanding

g_space – Number of bytes left in the storage. (INFO)
	Bytes available

g_smf –  (INFO)
	N struct smf

g_smf_frag –  (INFO)
	N small free smf

g_smf_large –  (INFO)
	N large free smf


PER BACKEND COUNTERS (VBE.*)
============================

happy –  (INFO)
	Happy health probes

bereq_hdrbytes – Total backend request header bytes sent (INFO)
	Request header bytes

bereq_bodybytes – Total backend request body bytes sent (INFO)
	Request body bytes

beresp_hdrbytes – Total backend response header bytes received (INFO)
	Response header bytes

beresp_bodybytes – Total backend response body bytes received (INFO)
	Response body bytes

pipe_hdrbytes – Total request bytes sent for piped sessions (INFO)
	Pipe request header bytes

pipe_out – Total number of bytes forwarded to backend in pipe sessions (INFO)
	Piped bytes to backend

pipe_in – Total number of bytes forwarded from backend in pipe sessions (INFO)
	Piped bytes from backend

conn –  (INFO)
	Concurrent connections to backend

req –  (INFO)
	Backend requests sent


LOCK COUNTERS (LCK.*)
=====================

creat –  (DEBUG)
	Created locks

destroy –  (DEBUG)
	Destroyed locks

locks –  (DEBUG)
	Lock Operations

