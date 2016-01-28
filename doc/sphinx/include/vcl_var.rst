
bereq
~~~~~

bereq

	Type: HTTP

	Readable from: backend

	
	The entire backend request HTTP data structure
	

bereq.backend

	Type: BACKEND

	Readable from: vcl_pipe, backend

	Writable from: vcl_pipe, backend

	
	This is the backend or director we attempt to fetch from.
	

bereq.between_bytes_timeout

	Type: DURATION

	Readable from: backend

	Writable from: backend

	
	The time in seconds to wait between each received byte from the
	backend.  Not available in pipe mode.
	

bereq.connect_timeout

	Type: DURATION

	Readable from: vcl_pipe, backend

	Writable from: vcl_pipe, backend

	
	The time in seconds to wait for a backend connection.
	

bereq.first_byte_timeout

	Type: DURATION

	Readable from: backend

	Writable from: backend

	
	The time in seconds to wait for the first byte from
	the backend.  Not available in pipe mode.
	

bereq.http.

	Type: HEADER

	Readable from: vcl_pipe, backend

	Writable from: vcl_pipe, backend

	
	The corresponding HTTP header.
	

bereq.method

	Type: STRING

	Readable from: vcl_pipe, backend

	Writable from: vcl_pipe, backend

	
	The request type (e.g. "GET", "HEAD").
	

bereq.proto

	Type: STRING

	Readable from: vcl_pipe, backend

	Writable from: vcl_pipe, backend

	
	The HTTP protocol version used to talk to the server.
	

bereq.retries

	Type: INT

	Readable from: backend

	
	A count of how many times this request has been retried.
	

bereq.uncacheable

	Type: BOOL

	Readable from: backend

	
	Indicates whether this request is uncacheable due
	to a pass in the client side or a hit on an existing
	uncacheable object (aka hit-for-pass).
	

bereq.url

	Type: STRING

	Readable from: vcl_pipe, backend

	Writable from: vcl_pipe, backend

	
	The requested URL.
	

bereq.xid

	Type: STRING

	Readable from: backend

	
	Unique ID of this request.
	

beresp
~~~~~~

beresp

	Type: HTTP

	Readable from: vcl_backend_response, vcl_backend_error

	
	The entire backend response HTTP data structure
	

beresp.age

	Type: DURATION

	Readable from: vcl_backend_response, vcl_backend_error

	
	The age of the object.
	

beresp.backend

	Type: BACKEND

	Readable from: vcl_backend_response, vcl_backend_error

	
	This is the backend we fetched from.  If bereq.backend
	was set to a director, this will be the backend selected
	by the director.
	

beresp.backend.ip

	Type: IP

	Readable from: vcl_backend_response, vcl_backend_error

	
	IP of the backend this response was fetched from.
	

beresp.backend.name

	Type: STRING

	Readable from: vcl_backend_response, vcl_backend_error

	
	Name of the backend this response was fetched from.
	

beresp.do_esi

	Type: BOOL

	Readable from: vcl_backend_response, vcl_backend_error

	Writable from: vcl_backend_response, vcl_backend_error

	
	Boolean. ESI-process the object after fetching it.
	Defaults to false. Set it to true to parse the
	object for ESI directives. Will only be honored if
	req.esi is true.
	

beresp.do_gunzip

	Type: BOOL

	Readable from: vcl_backend_response, vcl_backend_error

	Writable from: vcl_backend_response, vcl_backend_error

	
	Boolean. Unzip the object before storing it in the
	cache.  Defaults to false.
	

beresp.do_gzip

	Type: BOOL

	Readable from: vcl_backend_response, vcl_backend_error

	Writable from: vcl_backend_response, vcl_backend_error

	
	Boolean. Gzip the object before storing it. Defaults
	to false. When http_gzip_support is on Varnish will
	request already compressed content from the backend
	and as such compression in Varnish is not needed.
	

beresp.do_stream

	Type: BOOL

	Readable from: vcl_backend_response, vcl_backend_error

	Writable from: vcl_backend_response, vcl_backend_error

	
	Deliver the object to the client directly without
	fetching the whole object into varnish. If this
	request is pass'ed it will not be stored in memory.
	

beresp.grace

	Type: DURATION

	Readable from: vcl_backend_response, vcl_backend_error

	Writable from: vcl_backend_response, vcl_backend_error

	
	Set to a period to enable grace.
	

beresp.http.

	Type: HEADER

	Readable from: vcl_backend_response, vcl_backend_error

	Writable from: vcl_backend_response, vcl_backend_error

	
	The corresponding HTTP header.
	

beresp.keep

	Type: DURATION

	Readable from: vcl_backend_response, vcl_backend_error

	Writable from: vcl_backend_response, vcl_backend_error

	
	Set to a period to enable conditional backend requests.
	
	The keep time is cache lifetime in addition to the ttl.
	
	Objects with ttl expired but with keep time left may be used
	to issue conditional (If-Modified-Since / If-None-Match)
	requests to the backend to refresh them.
	

beresp.proto

	Type: STRING

	Readable from: vcl_backend_response, vcl_backend_error

	Writable from: vcl_backend_response, vcl_backend_error

	
	The HTTP protocol version used the backend replied with.
	

beresp.reason

	Type: STRING

	Readable from: vcl_backend_response, vcl_backend_error

	Writable from: vcl_backend_response, vcl_backend_error

	
	The HTTP status message returned by the server.
	

beresp.status

	Type: INT

	Readable from: vcl_backend_response, vcl_backend_error

	Writable from: vcl_backend_response, vcl_backend_error

	
	The HTTP status code returned by the server.
	

beresp.storage_hint

	Type: STRING

	Readable from: vcl_backend_response, vcl_backend_error

	Writable from: vcl_backend_response, vcl_backend_error

	
	Hint to Varnish that you want to save this object to a
	particular storage backend.
	

beresp.ttl

	Type: DURATION

	Readable from: vcl_backend_response, vcl_backend_error

	Writable from: vcl_backend_response, vcl_backend_error

	
	The object's remaining time to live, in seconds.
	

beresp.uncacheable

	Type: BOOL

	Readable from: vcl_backend_response, vcl_backend_error

	Writable from: vcl_backend_response, vcl_backend_error

	
	Inherited from bereq.uncacheable, see there.
	
	Setting this variable makes the object uncacheable, which may
	get stored as a hit-for-pass object in the cache.
	
	Clearing the variable has no effect and will log the warning
	"Ignoring attempt to reset beresp.uncacheable".
	

beresp.was_304

	Type: BOOL

	Readable from: vcl_backend_response, vcl_backend_error

	
	Boolean. If this is a successful 304 response to a
	backend conditional request refreshing an existing
	cache object.
	

client
~~~~~~

client.identity

	Type: STRING

	Readable from: client

	Writable from: client

	
	Identification of the client, used to load balance
	in the client director.
	

client.ip

	Type: IP

	Readable from: client

	
	The client's IP address.
	

local
~~~~~

local.ip

	Type: IP

	Readable from: client

	
	The IP address of the local end of the TCP connection.
	

now
~~~

now

	Type: TIME

	Readable from: all

	
	The current time, in seconds since the epoch. When
	used in string context it returns a formatted string.
	

obj
~~~

obj.age

	Type: DURATION

	Readable from: vcl_hit

	
	The age of the object.
	

obj.grace

	Type: DURATION

	Readable from: vcl_hit

	
	The object's remaining grace period in seconds.
	

obj.hits

	Type: INT

	Readable from: vcl_hit, vcl_deliver

	
	The count of cache-hits on this object. A value of 0 indicates a
	cache miss.
	

obj.http.

	Type: HEADER

	Readable from: vcl_hit

	
	The corresponding HTTP header.
	

obj.keep

	Type: DURATION

	Readable from: vcl_hit

	
	The object's remaining keep period in seconds.
	

obj.proto

	Type: STRING

	Readable from: vcl_hit

	
	The HTTP protocol version used when the object was retrieved.
	

obj.reason

	Type: STRING

	Readable from: vcl_hit

	
	The HTTP status message returned by the server.
	

obj.status

	Type: INT

	Readable from: vcl_hit

	
	The HTTP status code returned by the server.
	

obj.ttl

	Type: DURATION

	Readable from: vcl_hit

	
	The object's remaining time to live, in seconds.
	

obj.uncacheable

	Type: BOOL

	Readable from: vcl_deliver

	
	Whether the object is uncacheable (pass or hit-for-pass).
	

remote
~~~~~~

remote.ip

	Type: IP

	Readable from: client

	
	The IP address of the other end of the TCP connection.
	This can either be the clients IP, or the outgoing IP
	of a proxy server.
	

req
~~~

req

	Type: HTTP

	Readable from: client

	
	The entire request HTTP data structure
	

req.backend_hint

	Type: BACKEND

	Readable from: client

	Writable from: client

	
	Set bereq.backend to this if we attempt to fetch.
	

req.can_gzip

	Type: BOOL

	Readable from: client

	
	Does the client accept the gzip transfer encoding.
	

req.esi

	Type: BOOL

	Readable from: client

	Writable from: client

	
	Boolean. Set to false to disable ESI processing
	regardless of any value in beresp.do_esi. Defaults
	to true. This variable is subject to change in
	future versions, you should avoid using it.
	

req.esi_level

	Type: INT

	Readable from: client

	
	A count of how many levels of ESI requests we're currently at.
	

req.hash_always_miss

	Type: BOOL

	Readable from: vcl_recv

	Writable from: vcl_recv

	
	Force a cache miss for this request. If set to true
	Varnish will disregard any existing objects and
	always (re)fetch from the backend.
	

req.hash_ignore_busy

	Type: BOOL

	Readable from: vcl_recv

	Writable from: vcl_recv

	
	Ignore any busy object during cache lookup. You
	would want to do this if you have two server looking
	up content from each other to avoid potential deadlocks.
	

req.http.

	Type: HEADER

	Readable from: client

	Writable from: client

	
	The corresponding HTTP header.
	

req.method

	Type: STRING

	Readable from: client

	Writable from: client

	
	The request type (e.g. "GET", "HEAD").
	

req.proto

	Type: STRING

	Readable from: client

	Writable from: client

	
	The HTTP protocol version used by the client.
	

req.restarts

	Type: INT

	Readable from: client

	
	A count of how many times this request has been restarted.
	

req.ttl

	Type: DURATION

	Readable from: client

	Writable from: client

	
	

req.url

	Type: STRING

	Readable from: client

	Writable from: client

	
	The requested URL.
	

req.xid

	Type: STRING

	Readable from: client

	
	Unique ID of this request.
	

req_top
~~~~~~~

req_top.http.

	Type: HEADER

	Readable from: client

	
	HTTP headers of the top-level request in a tree of ESI requests.
	Identical to req.http. in non-ESI requests.
	

req_top.method

	Type: STRING

	Readable from: client

	
	The request method of the top-level request in a tree
	of ESI requests. (e.g. "GET", "HEAD").
	Identical to req.method in non-ESI requests.
	

req_top.proto

	Type: STRING

	Readable from: client

	
	HTTP protocol version of the top-level request in a tree of
	ESI requests.
	Identical to req.proto in non-ESI requests.
	

req_top.url

	Type: STRING

	Readable from: client

	
	The requested URL of the top-level request in a tree
	of ESI requests.
	Identical to req.url in non-ESI requests.
	

resp
~~~~

resp

	Type: HTTP

	Readable from: vcl_deliver, vcl_synth

	
	The entire response HTTP data structure.
	

resp.http.

	Type: HEADER

	Readable from: vcl_deliver, vcl_synth

	Writable from: vcl_deliver, vcl_synth

	
	The corresponding HTTP header.
	

resp.is_streaming

	Type: BOOL

	Readable from: vcl_deliver, vcl_synth

	
	Returns true when the response will be streamed
	from the backend.
	

resp.proto

	Type: STRING

	Readable from: vcl_deliver, vcl_synth

	Writable from: vcl_deliver, vcl_synth

	
	The HTTP protocol version to use for the response.
	

resp.reason

	Type: STRING

	Readable from: vcl_deliver, vcl_synth

	Writable from: vcl_deliver, vcl_synth

	
	The HTTP status message that will be returned.
	

resp.status

	Type: INT

	Readable from: vcl_deliver, vcl_synth

	Writable from: vcl_deliver, vcl_synth

	
	The HTTP status code that will be returned.
	
	Assigning a HTTP standardized code to resp.status will also
	set resp.reason to the corresponding status message.
	

server
~~~~~~

server.hostname

	Type: STRING

	Readable from: all

	
	The host name of the server.
	

server.identity

	Type: STRING

	Readable from: all

	
	The identity of the server, as set by the -i
	parameter.  If the -i parameter is not passed to varnishd,
	server.identity will be set to the name of the instance, as
	specified by the -n parameter.
	

server.ip

	Type: IP

	Readable from: client

	
	The IP address of the socket on which the client
	connection was received.
	

storage
~~~~~~~

storage.<name>.free_space

	Type: BYTES

	Readable from: client, backend

	
	Free space available in the named stevedore. Only available for
	the malloc stevedore.
	

storage.<name>.used_space

	Type: BYTES

	Readable from: client, backend

	
	Used space in the named stevedore. Only available for the malloc
	stevedore.
	

storage.<name>.happy

	Type: BOOL

	Readable from: client, backend

	
	Health status for the named stevedore. Not available in any of the
	current stevedores.
	
