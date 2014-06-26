Backend - Backend selected
	Logged when a connection is selected for handling a backend request.
	
	The format is::
	
		%d %s %s
		|  |  |
		|  |  +- Backend display name
		|  +---- VCL name
		+------- Connection file descriptor
	


BackendClose - Backend connection closed
	Logged when a backend connection is closed.
	
	The format is::
	
		%d %s [ %s ]
		|  |    |
		|  |    +- Optional reason
		|  +------ Backend display name
		+--------- Connection file descriptor
	


BackendOpen - Backend connection opened
	Logged when a new backend connection is opened.
	
	The format is::
	
		%d %s %s %s
		|  |  |  |
		|  |  |  +- Remote port
		|  |  +---- Remote address
		|  +------- Backend display name
		+---------- Connection file descriptor
	


BackendReuse - Backend connection put up for reuse
	Logged when a backend connection is put up for reuse by a later connection.
	
	The format is::
	
		%d %s
		|  |
		|  +- Backend display name
		+---- Connection file descriptor
	


Backend_health - Backend health check
	The result of a backend health probe.
	
	The format is::
	
		%s %s %s %u %u %u %f %f %s
		|  |  |  |  |  |  |  |  |
		|  |  |  |  |  |  |  |  +- Probe HTTP response
		|  |  |  |  |  |  |  +---- Average response time
		|  |  |  |  |  |  +------- Response time
		|  |  |  |  |  +---------- Probe window size
		|  |  |  |  +------------- Probe threshold level
		|  |  |  +---------------- Number of good probes in window
		|  |  +------------------- Probe window bits
		|  +---------------------- Status message
		+------------------------- Backend name
	


Begin - Marks the start of a VXID
	The first record of a VXID transaction.
	
	The format is::
	
		%s %d %s
		|  |  |
		|  |  +- Reason
		|  +---- Parent vxid
		+------- Type ("sess", "req" or "bereq")
	


BereqAcct - Backend request accounting
	Contains byte counters from backend request processing.
	
	The format is::
	
		%d %d %d %d %d %d
		|  |  |  |  |  |
		|  |  |  |  |  +- Total bytes received
		|  |  |  |  +---- Body bytes received
		|  |  |  +------- Header bytes received
		|  |  +---------- Total bytes transmitted
		|  +------------- Body bytes transmitted
		+---------------- Header bytes transmitted
	


BereqHeader - Backend request header
	HTTP header contents.
	
	The format is::
	
		%s: %s
		|   |
		|   +- Header value
		+----- Header name
	


BereqMethod - Backend request method
	The HTTP request method used.
	


BereqProtocol - Backend request protocol
	The HTTP protocol version information.
	


BereqURL - Backend request URL
	The HTTP request URL.
	


BerespHeader - Backend response header
	HTTP header contents.
	
	The format is::
	
		%s: %s
		|   |
		|   +- Header value
		+----- Header name
	


BerespProtocol - Backend response protocol
	The HTTP protocol version information.
	


BerespReason - Backend response response
	The HTTP response string received.
	


BerespStatus - Backend response status
	The HTTP status code received.
	


BogoHeader - Bogus HTTP received
	Contains the first 20 characters of received HTTP headers we could not make sense of.  Applies to both req.http and beresp.http.
	


CLI - CLI communication
	CLI communication between varnishd master and child process.
	


Debug - Debug messages
	Debug messages can normally be ignored, but are sometimes helpful during trouble-shooting.  Most debug messages must be explicitly enabled with parameters.
	


ESI_BodyBytes - ESI body fragment byte counter
	Contains the body byte count for this ESI body fragment. This number does not include any transfer encoding overhead.
	
	The format is::
	
		%d
		|
		+- Body bytes
	


ESI_xmlerror - ESI parser error or warning message
	An error or warning was generated during parsing of an ESI object. The log record describes the problem encountered.

End - Marks the end of a VXID
	The last record of a VXID transaction.
	


Error - Error messages
	Error messages are stuff you probably want to know.
	


ExpBan - Object evicted due to ban
	Logs the VXID when an object is banned.
	


ExpKill - Object expiry event
	Logs events related to object expiry. The events are:
	
	EXP_Rearm
		Logged when the expiry time of an object changes.
	
	EXP_Inbox
		Logged when the expiry thread picks an object from the inbox for processing.
	
	EXP_Kill
		Logged when the expiry thread kills an object from the inbox.
	
	EXP_When
		Logged when the expiry thread moves an object on the binheap.
	
	EXP_Expired
		Logged when the expiry thread expires an object.
	
	LRU_Cand
		Logged when an object is evaluated for LRU force expiry.
	
	LRU
		Logged when an object is force expired due to LRU.
	
	LRU_Fail
		Logged when no suitable candidate object is found for LRU force expiry.
	
	The format is::
	
		EXP_Rearm p=%p E=%f e=%f f=0x%x
		EXP_Inbox p=%p e=%f f=0x%x
		EXP_Kill p=%p e=%f f=0x%x
		EXP_When p=%p e=%f f=0x%x
		EXP_Expired x=%u t=%f
		LRU_Cand p=%p f=0x%x r=%d
		LRU x=%u
		LRU_Fail
		
		Legend:
		p=%p         Objcore pointer
		t=%f         Remaining TTL (s)
		e=%f         Expiry time (unix epoch)
		E=%f         Old expiry time (unix epoch)
		f=0x%x       Objcore flags
		r=%d         Objcore refcount
		x=%u         Object VXID
	


FetchError - Error while fetching object
	Logs the error message of a failed fetch operation.
	


Fetch_Body - Body fetched from backend
	Ready to fetch body from backend.
	
	The format is::
	
		%d (%s) %s
		|   |    |
		|   |    +---- 'stream' or '-'
		|   +--------- Text description of body fetch mode
		+------------- Body fetch mode
	


Gzip - G(un)zip performed on object
	A Gzip record is emitted for each instance of gzip or gunzip work performed. Worst case, an ESI transaction stored in gzip'ed objects but delivered gunziped, will run into many of these.
	
	The format is::
	
		%c %c %c %d %d %d %d %d
		|  |  |  |  |  |  |  |
		|  |  |  |  |  |  |  +- Bit length of compressed data
		|  |  |  |  |  |  +---- Bit location of 'last' bit
		|  |  |  |  |  +------- Bit location of first deflate block
		|  |  |  |  +---------- Bytes output
		|  |  |  +------------- Bytes input
		|  |  +---------------- 'E': ESI, '-': Plain object
		|  +------------------- 'F': Fetch, 'D': Deliver
		+---------------------- 'G': Gzip, 'U': Gunzip, 'u': Gunzip-test
	
	Examples::
	
		U F E 182 159 80 80 1392
		G F E 159 173 80 1304 1314
	


Hash - Value added to hash
	This value was added to the object lookup hash.
	
	NB: This log record is masked by default.
	


Hit - Hit object in cache
	Object looked up in cache. Shows the VXID of the object.
	


HitPass - Hit for pass object in cache.
	Hit-for-pass object looked up in cache. Shows the VXID of the hit-for-pass object.
	


HttpGarbage - Unparseable HTTP request
	Logs the content of unparseable HTTP requests.
	


Length - Size of object body
	Logs the size of a fetch object body.
	


Link - Links to a child VXID
	Links this VXID to any child VXID it initiates.
	
	The format is::
	
		%s %d %s
		|  |  |
		|  |  +- Reason
		|  +---- Child vxid
		+------- Child type ("req" or "bereq")
	


LostHeader - Failed attempt to set HTTP header
	Logs the header name of a failed HTTP header operation due to resource exhaustion or configured limits.
	


ObjHeader - Object  header
	HTTP header contents.
	
	The format is::
	
		%s: %s
		|   |
		|   +- Header value
		+----- Header name
	


ObjProtocol - Object  protocol
	The HTTP protocol version information.
	


ObjReason - Object  response
	The HTTP response string received.
	


ObjStatus - Object  status
	The HTTP status code received.
	


PipeAcct - Pipe byte counts
	Contains byte counters for pipe sessions.
	
	The format is::
	
		%d %d %d %d
		|  |  |  |
		|  |  |  +------- Piped bytes to client
		|  |  +---------- Piped bytes from client
		|  +------------- Backend request headers
		+---------------- Client request headers
	


ReqAcct - Request handling byte counts
	Contains byte counts for the request handling. This record is not logged for ESI sub-requests, but the sub-requests' response body count is added to the main request.
	
	The format is::
	
		%d %d %d %d %d %d
		|  |  |  |  |  |
		|  |  |  |  |  +- Total bytes transmitted
		|  |  |  |  +---- Body bytes transmitted
		|  |  |  +------- Header bytes transmitted
		|  |  +---------- Total bytes received
		|  +------------- Body bytes received
		+---------------- Header bytes received
	


ReqHeader - Client request header
	HTTP header contents.
	
	The format is::
	
		%s: %s
		|   |
		|   +- Header value
		+----- Header name
	


ReqMethod - Client request method
	The HTTP request method used.
	


ReqProtocol - Client request protocol
	The HTTP protocol version information.
	


ReqStart - Client request start
	Start of request processing. Logs the client IP address and port number.
	
	The format is::
	
		%s %s
		|  |
		|  +- Port number
		+---- IP address
	


ReqURL - Client request URL
	The HTTP request URL.
	


RespHeader - Client response header
	HTTP header contents.
	
	The format is::
	
		%s: %s
		|   |
		|   +- Header value
		+----- Header name
	


RespProtocol - Client response protocol
	The HTTP protocol version information.
	


RespReason - Client response response
	The HTTP response string received.
	


RespStatus - Client response status
	The HTTP status code received.
	


SessClose - Client connection closed
	SessionClose is the last record for any client connection.
	
	The format is::
	
		%s %f
		|  |
		|  +- How long the session was open
		+---- Why the connection closed
	


SessOpen - Client connection opened
	The first record for a client connection, with the socket-endpoints of the connection.
	
	The format is::
	
		%s %d %s %s %s %d
		|  |  |  |  |  |
		|  |  |  |  |  +- File descriptor number
		|  |  |  |  +---- Local TCP port ('-' if !$log_local_addr)
		|  |  |  +------- Local IPv4/6 address ('-' if !$log_local_addr)
		|  |  +---------- Listen socket
		|  +------------- Client TCP socket
		+---------------- Client IPv4/6 address
	


Storage - Where object is stored
	Type and name of the storage backend the object is stored in.
	
	The format is::
	
		%s %s
		|  |
		|  +- Name of storage backend
		+---- Type ("malloc", "file", "persistent" etc.)
	


TTL - TTL set on object
	A TTL record is emitted whenever the ttl, grace or keep values for an object is set.
	
	The format is::
	
		%s %d %d %d %d %d [ %d %u %u ]
		|  |  |  |  |  |    |  |  |
		|  |  |  |  |  |    |  |  +- Max-Age from Cache-Control header
		|  |  |  |  |  |    |  +---- Expires header
		|  |  |  |  |  |    +------- Date header
		|  |  |  |  |  +------------ Age (incl Age: header value)
		|  |  |  |  +--------------- Reference time for TTL
		|  |  |  +------------------ Keep
		|  |  +--------------------- Grace
		|  +------------------------ TTL
		+--------------------------- "RFC" or "VCL"
	
	The last four fields are only present in "RFC" headers.
	
	Examples::
	
		RFC 19 -1 -1 1312966109 4 0 0 23
		VCL 10 -1 -1 1312966109 4
		VCL 7 -1 -1 1312966111 6
		VCL 7 120 -1 1312966111 6
		VCL 7 120 3600 1312966111 6
		VCL 12 120 3600 1312966113 8
	


Timestamp - Timing information
	Contains timing information for the Varnish worker threads.
	
	Time stamps are issued by Varnish on certain events, and show the absolute time of the event, the time spent since the start of the work unit, and the time spent since the last timestamp was logged. See vsl(7) for information about the individual timestamps.
	
	The format is::
	
		%s: %f %f %f
		|   |  |  |
		|   |  |  +- Time since last timestamp
		|   |  +---- Time since start of work unit
		|   +------- Absolute time of event
		+----------- Event label
	


VCL_Error - VCL execution error message
	Logs error messages generated during VCL execution.
	


VCL_Log - Log statement from VCL
	User generated log messages insert from VCL through std.log()

VCL_acl - VSL ACL check results
	Logs VCL ACL evaluation results.
	


VCL_call - VCL method called
	Logs the VCL method name when a VCL method is called.
	


VCL_return - VCL method return value
	Logs the VCL method terminating statement.
	


VCL_trace - VCL trace data
	Logs VCL execution trace data.
	
	The format is::
	
		%u %u.%u
		|  |  |
		|  |  +- VCL program line position
		|  +---- VCL program line number
		+------- VCL trace point index
	
	NB: This log record is masked by default.
	


VSL - VSL API warnings and error message
	Warnings and error messages genererated by the VSL API while reading the shared memory log.
	


WorkThread - Logs thread start/stop events
	Logs worker thread creation and termination events.
	
	The format is::
	
		%p %s
		|  |
		|  +- [start|end]
		+---- Worker struct pointer
	
	NB: This log record is masked by default.
	


