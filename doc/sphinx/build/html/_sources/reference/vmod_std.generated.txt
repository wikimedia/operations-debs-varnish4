..
.. NB:  This file is machine generated, DO NOT EDIT!
..
.. Edit vmod.vcc and run make instead
..

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

Vmod_std contains basic functions which are part and parcel of Varnish,
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
* :ref:`func_healthy`
* :ref:`func_integer`
* :ref:`func_ip`
* :ref:`func_log`
* :ref:`func_port`
* :ref:`func_querysort`
* :ref:`func_random`
* :ref:`func_real`
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

STRING toupper(STRING_LIST)
---------------------------

Prototype
	STRING toupper(STRING_LIST s)

Description
	Converts the string *s* to uppercase.
Example
	set beresp.http.x-scream = std.toupper("yes!");

.. _func_tolower:

STRING tolower(STRING_LIST)
---------------------------

Prototype
	STRING tolower(STRING_LIST s)

Description
	Converts the string *s* to lowercase.
Example
	set beresp.http.x-nice = std.tolower("VerY");

.. _func_set_ip_tos:

VOID set_ip_tos(INT)
--------------------

Prototype
	VOID set_ip_tos(INT tos)

Description
	Sets the IP type-of-service (TOS) field for the current session to *tos*.
	Please note that the TOS field is not removed by the end of the
	request so probably want to set it on every request should you
	utilize it.
Example
	| if (req.url ~ ^/slow/) {
	|    std.set_ip_tos(0x0);
	| }

.. _func_random:

REAL random(REAL, REAL)
-----------------------

Prototype
	REAL random(REAL lo, REAL hi)

Description
	Returns a random real number between *lo* and *hi*.
Example
	set beresp.http.x-random-number = std.random(1, 100);

.. _func_log:

VOID log(STRING_LIST)
---------------------

Prototype
	VOID log(STRING_LIST s)

Description
	Logs the string *s* to the shared memory log, using VSL tag *SLT_VCL_Log*.
Example
	std.log("Something fishy is going on with the vhost " + req.host);

.. _func_syslog:

VOID syslog(INT, STRING_LIST)
-----------------------------

Prototype
	VOID syslog(INT priority, STRING_LIST s)

Description
	Logs the string *s* to syslog marked with *priority*.  See your
	system's syslog.h file for the legal values of *priority*.
Example
	std.syslog(8 + 1, "Something is wrong");

.. _func_fileread:

STRING fileread(PRIV_CALL, STRING)
----------------------------------

Prototype
	STRING fileread(PRIV_CALL, STRING)

Description
	Reads a file and returns a string with the content. Please
	note that it is not recommended to send variables to this
	function the caching in the function doesn't take this into
	account. Also, files are not re-read.
Example
	set beresp.http.x-served-by = std.fileread("/etc/hostname");

.. _func_collect:

VOID collect(HEADER)
--------------------

Prototype
	VOID collect(HEADER hdr)

Description
	Collapses the header *hdr*, joining them into one.
Example
	std.collect(req.http.cookie);

	This will collapse several Cookie: headers into one, long
	cookie header.

.. _func_duration:

DURATION duration(STRING, DURATION)
-----------------------------------

Prototype
	DURATION duration(STRING s, DURATION fallback)

Description
	Converts the string *s* to seconds. *s* must be quantified
	with ms (milliseconds), s (seconds), m (minutes), h (hours),
	d (days), w (weeks) or y (years) units. If conversion fails,
	*fallback* will be returned.
Example
	set beresp.ttl = std.duration("1w", 3600s);

.. _func_integer:

INT integer(STRING, INT)
------------------------

Prototype
	INT integer(STRING s, INT fallback)

Description
	Converts the string *s* to an integer.	If conversion fails,
	*fallback* will be returned.
Example
	| if (std.integer(beresp.http.x-foo, 0) > 5) {
	| 	...
	| }

.. _func_ip:

IP ip(STRING, IP)
-----------------

Prototype
	IP ip(STRING s, IP fallback)

Description
	Converts the string *s* to the first IP number returned by
	the system library function getaddrinfo(3).  If conversion
	fails, *fallback* will be returned.
Example
	| if (std.ip(req.http.X-forwarded-for, "0.0.0.0") ~ my_acl) {
	| 	...
	| }

.. _func_real:

REAL real(STRING, REAL)
-----------------------

Prototype
	REAL real(STRING s, REAL fallback)

Description
	Converts the string *s* to a real.  If conversion fails,
	*fallback* will be returned.
Example
	set req.http.x-real = std.real(req.http.x-foo, 0.0);

.. _func_real2time:

TIME real2time(REAL)
--------------------

Prototype
	TIME real2time(REAL r)

Description
	Converts the real *r* to a time.
Example
	set req.http.x-time = std.real2time(1140618699.00);

.. _func_time2integer:

INT time2integer(TIME)
----------------------

Prototype
	INT time2integer(TIME t)

Description
	Converts the time *t* to a integer.
Example
	set req.http.x-int = std.time2integer(now);

.. _func_time2real:

REAL time2real(TIME)
--------------------

Prototype
	REAL time2real(TIME t)

Description
	Converts the time *t* to a real.
Example
	set req.http.x-real = std.time2real(now);

.. _func_healthy:

BOOL healthy(BACKEND)
---------------------

Prototype
	BOOL healthy(BACKEND be)

Description
	Returns `true` if the backend *be* is healthy.

.. _func_port:

INT port(IP)
------------

Prototype
	INT port(IP ip)

Description
	Returns the port number of the IP address *ip*.

.. _func_rollback:

VOID rollback(HTTP)
-------------------

Prototype
	VOID rollback(HTTP h)

Description
	Restores the *h* HTTP headers to their original state.
Example
	std.rollback(bereq);

.. _func_timestamp:

VOID timestamp(STRING)
----------------------

Prototype
	VOID timestamp(STRING s)

Description
	Introduces a timestamp in the log with the current time, using
	the string *s* as the label. This is useful to time the execution
	of lengthy VCL procedures, and makes the timestamps inserted
	automatically by Varnish more accurate.
Example
	std.timestamp("curl-request");

.. _func_querysort:

STRING querysort(STRING)
------------------------

Prototype
	STRING querysort(STRING)

Description
	Sorts the query string for cache normalization purposes.
Example
        set req.url = std.querysort(req.url);

.. _func_cache_req_body:

VOID cache_req_body(BYTES)
--------------------------

Prototype
	VOID cache_req_body(BYTES size)

Description
	Cache the req.body if it is smaller than *size*.

	Caching the req.body makes it possible to retry pass
	operations (POST, PUT).
Example
	std.cache_req_body(1KB);

	This will cache the req.body if its size is smaller than 1KB.

.. _func_strstr:

STRING strstr(STRING, STRING)
-----------------------------

Prototype
	STRING strstr(STRING s1, STRING s2)

Description
	Returns the first occurrence of the string *s2* in the string
	*s1*, or an empty string if not found.

	Note that the comparison is case sensitive.
Example
	| if (std.strstr(req.url, req.http.x-restrict)) {
	| 	...
	| }

.. _func_time:

TIME time(STRING, TIME)
-----------------------

Prototype
	TIME time(STRING s, TIME fallback)

Description
	Converts the string *s* to a time.  If conversion fails,
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
	| 	...
	| }


SEE ALSO
========

* vcl(7)
* varnishd(1)

HISTORY
=======

The Varnish standard module was released along with Varnish Cache 3.0.
This manual page was written by Per Buer with help from Martin Blix
Grydeland.

COPYRIGHT
=========

This document is licensed under the same licence as Varnish
itself. See LICENCE for details.

