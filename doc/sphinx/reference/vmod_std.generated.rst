..
.. NB:  This file is machine generated, DO NOT EDIT!
..
.. Edit vmod.vcc and run make instead
..

.. role:: ref(emphasis)

.. _vmod_std(3):

========
vmod_std
========

-----------------------
Varnish Standard Module
-----------------------

:Manual section: 3

SYNOPSIS
========

import std [from "path"] ;


DESCRIPTION
===========

`vmod_std` contains basic functions which are part and parcel of Varnish,
but which for reasons of architecture fit better in a VMOD.

One particular class of functions in vmod_std is the conversions functions
which all have the form::

	TYPE type(STRING, TYPE)

These functions attempt to convert STRING to the TYPE, and if that fails,
they return the second argument, which must have the given TYPE.

CONTENTS
========

* :ref:`func_cache_req_body`
* :ref:`func_collect`
* :ref:`func_duration`
* :ref:`func_fileread`
* :ref:`func_getenv`
* :ref:`func_healthy`
* :ref:`func_integer`
* :ref:`func_ip`
* :ref:`func_late_100_continue`
* :ref:`func_log`
* :ref:`func_port`
* :ref:`func_querysort`
* :ref:`func_random`
* :ref:`func_real`
* :ref:`func_real2integer`
* :ref:`func_real2time`
* :ref:`func_rollback`
* :ref:`func_set_ip_tos`
* :ref:`func_strstr`
* :ref:`func_syslog`
* :ref:`func_time`
* :ref:`func_time2integer`
* :ref:`func_time2real`
* :ref:`func_timestamp`
* :ref:`func_tolower`
* :ref:`func_toupper`

.. _func_toupper:

toupper
-------

::

	STRING toupper(STRING s)

Description
	Converts the string *s* to uppercase.
Example
	set beresp.http.scream = std.toupper("yes!");

.. _func_tolower:

tolower
-------

::

	STRING tolower(STRING s)

Description
	Converts the string *s* to lowercase.
Example
	set beresp.http.nice = std.tolower("VerY");

.. _func_set_ip_tos:

set_ip_tos
----------

::

	VOID set_ip_tos(INT tos)

Description
	Sets the IP type-of-service (TOS) field for the current session
	to *tos*.
	Please note that the TOS field is not removed by the end of the
	request so probably want to set it on every request should you
	utilize it.
Example
	| if (req.url ~ "^/slow/") {
	|	std.set_ip_tos(0);
	| }

.. _func_random:

random
------

::

	REAL random(REAL lo, REAL hi)

Description
	Returns a random real number between *lo* and *hi*.
	This function uses the "testable" random generator in varnishd
	which enables determinstic tests to be run (See m00002.vtc).
	This function should not be used for cryptographic applications.
Example
	set beresp.http.random-number = std.random(1, 100);

.. _func_log:

log
---

::

	VOID log(STRING s)

Description
	Logs the string *s* to the shared memory log, using VSL tag
	*SLT_VCL_Log*.
Example
	std.log("Something fishy is going on with the vhost " + req.http.host);

.. _func_syslog:

syslog
------

::

	VOID syslog(INT priority, STRING s)

Description
	Logs the string *s* to syslog tagged with *priority*. *priority*
	is formed by ORing the facility and level values. See your
	system's syslog.h file for possible values.
Example
	std.syslog(9, "Something is wrong");

	This will send a message to syslog using LOG_USER | LOG_ALERT.

.. _func_fileread:

fileread
--------

::

	STRING fileread(PRIV_CALL, STRING)

Description
	Reads a file and returns a string with the content. Please
	note that it is not recommended to send variables to this
	function the caching in the function doesn't take this into
	account. Also, files are not re-read.
Example
	set beresp.http.served-by = std.fileread("/etc/hostname");

.. _func_collect:

collect
-------

::

	VOID collect(HEADER hdr, STRING sep=", ")

Description
	Collapses multiple *hdr* headers into one long header. The
	default separator *sep* is the standard comma separator to
	use when collapsing headers, with an additional  whitespace
	for pretty printing.

	Care should be taken when collapsing headers. In particular
	collapsing Set-Cookie will lead to unexpected results on the
	browser side.
Examples
	| std.collect(req.http.accept);
	| std.collect(req.http.cookie, "; ");

.. _func_duration:

duration
--------

::

	DURATION duration(STRING s, DURATION fallback)

Description
	Converts the string *s* to seconds. *s* must be quantified
	with ms (milliseconds), s (seconds), m (minutes), h (hours),
	d (days), w (weeks) or y (years) units. If conversion fails,
	*fallback* will be returned.
Example
	set beresp.ttl = std.duration("1w", 3600s);

.. _func_integer:

integer
-------

::

	INT integer(STRING s, INT fallback)

Description
	Converts the string *s* to an integer. If conversion fails,
	*fallback* will be returned.
Example
	| if (std.integer(req.http.foo, 0) > 5) {
	|	...
	| }

.. _func_ip:

ip
--

::

	IP ip(STRING s, IP fallback)

Description
	Converts the string *s* to the first IP number returned by
	the system library function getaddrinfo(3). If conversion
	fails, *fallback* will be returned.
Example
	| if (std.ip(req.http.X-forwarded-for, "0.0.0.0") ~ my_acl) {
	|	...
	| }

.. _func_real:

real
----

::

	REAL real(STRING s, REAL fallback)

Description
	Converts the string *s* to a real. If conversion fails,
	*fallback* will be returned.
Example
	| if (std.real(req.http.foo, 0.0) > 5.5) {
	|	...
	| }

.. _func_real2integer:

real2integer
------------

::

	INT real2integer(REAL r, INT fallback)

Description
	Converts the real *r* to an integer. If conversion fails,
	*fallback* will be returned.
Example
	set req.http.integer = std.real2integer(1140618699.00, 0);

.. _func_real2time:

real2time
---------

::

	TIME real2time(REAL r, TIME fallback)

Description
	Converts the real *r* to a time. If conversion fails,
	*fallback* will be returned.
Example
	set req.http.time = std.real2time(1140618699.00, now);

.. _func_time2integer:

time2integer
------------

::

	INT time2integer(TIME t, INT fallback)

Description
	Converts the time *t* to a integer. If conversion fails,
	*fallback* will be returned.
Example
	set req.http.int = std.time2integer(now, 0);

.. _func_time2real:

time2real
---------

::

	REAL time2real(TIME t, REAL fallback)

Description
	Converts the time *t* to a real. If conversion fails,
	*fallback* will be returned.
Example
	set req.http.real = std.time2real(now, 1.0);

.. _func_healthy:

healthy
-------

::

	BOOL healthy(BACKEND be)

Description
	Returns `true` if the backend *be* is healthy.

.. _func_port:

port
----

::

	INT port(IP ip)

Description
	Returns the port number of the IP address *ip*.

.. _func_rollback:

rollback
--------

::

	VOID rollback(HTTP h)

Description
	Restores the *h* HTTP headers to their original state.
Example
	std.rollback(bereq);

.. _func_timestamp:

timestamp
---------

::

	VOID timestamp(STRING s)

Description
	Introduces a timestamp in the log with the current time, using
	the string *s* as the label. This is useful to time the execution
	of lengthy VCL procedures, and makes the timestamps inserted
	automatically by Varnish more accurate.
Example
	std.timestamp("curl-request");

.. _func_querysort:

querysort
---------

::

	STRING querysort(STRING)

Description
	Sorts the query string for cache normalization purposes.
Example
	set req.url = std.querysort(req.url);

.. _func_cache_req_body:

cache_req_body
--------------

::

	BOOL cache_req_body(BYTES size)

Description
	Caches the request body if it is smaller than *size*.  Returns
	`true` if the body was cached, `false` otherwise.

	Normally the request body is not available after sending it to
	the backend.  By caching it is possible to retry pass operations,
	e.g. POST and PUT.
Example
	| if (std.cache_req_body(1KB)) {
	|	...
	| }

.. _func_strstr:

strstr
------

::

	STRING strstr(STRING s1, STRING s2)

Description
	Returns a string beginning at the first occurrence of the string
	*s2* in the string *s1*, or an empty string if *s2* is not found.

	Note that the comparison is case sensitive.
Example
	| if (std.strstr(req.url, req.http.restrict)) {
	|	...
	| }

	This will check if the content of req.http.restrict occurs
	anywhere in req.url.

.. _func_time:

time
----

::

	TIME time(STRING s, TIME fallback)

Description
	Converts the string *s* to a time. If conversion fails,
	*fallback* will be returned.

	Supported formats:

	| "Sun, 06 Nov 1994 08:49:37 GMT"
	| "Sunday, 06-Nov-94 08:49:37 GMT"
	| "Sun Nov  6 08:49:37 1994"
	| "1994-11-06T08:49:37"
	| "784111777.00"
	| "784111777"
Example
	| if (std.time(resp.http.last-modified, now) < now - 1w) {
	|	...
	| }

.. _func_getenv:

getenv
------

::

	STRING getenv(STRING name)

Description
	Return environment variable *name* or the empty string.

	See getenv(3)
Example
	| set req.http.My-Env = std.getenv("MY_ENV");

.. _func_late_100_continue:

late_100_continue
-----------------

::

	VOID late_100_continue(BOOL late)

Description
	Controls when varnish reacts to an `Expect: 100-continue` client
	request header.

	Varnish always generates a `100 Continue` response if
	requested by the client trough the `Expect: 100-continue`
	header when waiting for request body data.

	But, by default, the `100 Continue` response is already
	generated immediately after `vcl_recv` returns to reduce
	latencies under the assumption that the request body will be
	read eventually.

	Calling `std.late_100_continue(true)` in `vcl_recv` will cause
	the `100 Continue` response to only be sent when needed. This
	may cause additional latencies for processing request bodies,
	but is the correct behavior by strict interpretation of
	RFC7231.

	This function has no effect outside `vcl_recv` and after
	calling `std.cache_req_body()` or any other function consuming
	the request body.

Example
	| vcl_recv {
	|	std.late_100_continue(true);
	|
	|	if (req.method == "POST") {
	|		std.late_100_continue(false);
	|		return (pass);
	|	}
	|	...
	| }

SEE ALSO
========

* :ref:`varnishd(1)`
* :ref:`vsl(7)`

COPYRIGHT
=========

::

  Copyright (c) 2010-2017 Varnish Software AS
  All rights reserved.
 
  Author: Poul-Henning Kamp <phk@FreeBSD.org>
 
  Redistribution and use in source and binary forms, with or without
  modification, are permitted provided that the following conditions
  are met:
  1. Redistributions of source code must retain the above copyright
     notice, this list of conditions and the following disclaimer.
  2. Redistributions in binary form must reproduce the above copyright
     notice, this list of conditions and the following disclaimer in the
     documentation and/or other materials provided with the distribution.
 
  THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND
  ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
  ARE DISCLAIMED.  IN NO EVENT SHALL AUTHOR OR CONTRIBUTORS BE LIABLE
  FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
  DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
  OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
  HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
  LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
  OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
  SUCH DAMAGE.

