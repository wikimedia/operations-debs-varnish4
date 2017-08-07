..
.. NB:  This file is machine generated, DO NOT EDIT!
..
.. Edit vmod.vcc and run make instead
..

.. role:: ref(emphasis)

.. _vmod_directors(3):

==============
vmod_directors
==============

------------------------
Varnish Directors Module
------------------------

:Manual section: 3

SYNOPSIS
========

import directors [from "path"] ;


DESCRIPTION
===========

`vmod_directors` enables backend load balancing in Varnish.

The module implements load balancing techniques, and also serves as an
example on how one could extend the load balancing capabilities of
Varnish.

To enable load balancing you must import this vmod (directors).

Then you define your backends. Once you have the backends declared you
can add them to a director. This happens in executed VCL code. If you
want to emulate the previous behavior of Varnish 3.0 you can just
initialize the directors in vcl_init, like this::

    sub vcl_init {
	new vdir = directors.round_robin();
	vdir.add_backend(backend1);
	vdir.add_backend(backend2);
    }

As you can see there is nothing keeping you from manipulating the
directors elsewhere in VCL. So, you could have VCL code that would
add more backends to a director when a certain URL is called.

Note that directors can use other directors as backends.

CONTENTS
========

* :ref:`obj_fallback`
* :ref:`func_fallback.add_backend`
* :ref:`func_fallback.backend`
* :ref:`func_fallback.remove_backend`
* :ref:`obj_hash`
* :ref:`func_hash.add_backend`
* :ref:`func_hash.backend`
* :ref:`func_hash.remove_backend`
* :ref:`obj_random`
* :ref:`func_random.add_backend`
* :ref:`func_random.backend`
* :ref:`func_random.remove_backend`
* :ref:`obj_round_robin`
* :ref:`func_round_robin.add_backend`
* :ref:`func_round_robin.backend`
* :ref:`func_round_robin.remove_backend`
* :ref:`obj_shard`
* :ref:`func_shard.add_backend`
* :ref:`func_shard.backend`
* :ref:`func_shard.clear`
* :ref:`func_shard.debug`
* :ref:`func_shard.key`
* :ref:`func_shard.reconfigure`
* :ref:`func_shard.remove_backend`
* :ref:`func_shard.set_rampup`
* :ref:`func_shard.set_warmup`

.. _obj_round_robin:

round_robin
-----------

::

	new OBJ = round_robin()

Description
	Create a round robin director.

	This director will pick backends in a round robin fashion.
Example
	new vdir = directors.round_robin();

.. _func_round_robin.add_backend:

round_robin.add_backend
-----------------------

::

	VOID round_robin.add_backend(BACKEND)

Description
	Add a backend to the round-robin director.
Example
	vdir.add_backend(backend1);
	vdir.add_backend(backend2);

.. _func_round_robin.remove_backend:

round_robin.remove_backend
--------------------------

::

	VOID round_robin.remove_backend(BACKEND)

Description
	Remove a backend from the round-robin director.
Example
	vdir.remove_backend(backend1);
	vdir.remove_backend(backend2);

.. _func_round_robin.backend:

round_robin.backend
-------------------

::

	BACKEND round_robin.backend()

Description
	Pick a backend from the director.
Example
	set req.backend_hint = vdir.backend();


.. _obj_fallback:

fallback
--------

::

	new OBJ = fallback(BOOL sticky=0)

Description
	Create a fallback director.

	A fallback director will try each of the added backends in turn,
	and return the first one that is healthy.

	If ``sticky`` is set to true, the director will keep using the healthy
	backend, even if a higher-priority backend becomes available. Once the
	whole backend list is exhausted, it'll start over at the beginning.

Example
	new vdir = directors.fallback();

.. _func_fallback.add_backend:

fallback.add_backend
--------------------

::

	VOID fallback.add_backend(BACKEND)

Description
	Add a backend to the director.

	Note that the order in which this is done matters for the fallback
	director.

Example
	vdir.add_backend(backend1);
	vdir.add_backend(backend2);

.. _func_fallback.remove_backend:

fallback.remove_backend
-----------------------

::

	VOID fallback.remove_backend(BACKEND)

Description
	Remove a backend from the director.
Example
	vdir.remove_backend(backend1);
	vdir.remove_backend(backend2);

.. _func_fallback.backend:

fallback.backend
----------------

::

	BACKEND fallback.backend()

Description
	Pick a backend from the director.
Example
	set req.backend_hint = vdir.backend();


.. _obj_random:

random
------

::

	new OBJ = random()

Description
	Create a random backend director.

	The random director distributes load over the backends using
	a weighted random probability distribution.
	The "testable" random generator in varnishd is used, which
	enables deterministic tests to be run (See: d00004.vtc).

Example
	new vdir = directors.random();

.. _func_random.add_backend:

random.add_backend
------------------

::

	VOID random.add_backend(BACKEND, REAL)

Description
	Add a backend to the director with a given weight.

	Each backend backend will receive approximately
	100 * (weight / (sum(all_added_weights))) per cent of the traffic sent
	to this director.

Example
	# 2/3 to backend1, 1/3 to backend2.
	vdir.add_backend(backend1, 10.0);
	vdir.add_backend(backend2, 5.0);

.. _func_random.remove_backend:

random.remove_backend
---------------------

::

	VOID random.remove_backend(BACKEND)

Description
	Remove a backend from the director.
Example
	vdir.remove_backend(backend1);
	vdir.remove_backend(backend2);

.. _func_random.backend:

random.backend
--------------

::

	BACKEND random.backend()

Description
	Pick a backend from the director.
Example
	set req.backend_hint = vdir.backend();

.. _obj_hash:

hash
----

::

	new OBJ = hash()

Description
	Create a hashing backend director.

	The director chooses the backend server by computing a hash/digest
	of the string given to .backend().

	Commonly used with ``client.ip`` or a session cookie to get
	sticky sessions.

Example
	new vdir = directors.hash();

.. _func_hash.add_backend:

hash.add_backend
----------------

::

	VOID hash.add_backend(BACKEND, REAL)

Description
	Add a backend to the director with a certain weight.

	Weight is used as in the random director. Recommended value is
	1.0 unless you have special needs.

Example
	vdir.add_backend(backend1, 1.0);
	vdir.add_backend(backend2, 1.0);

.. _func_hash.remove_backend:

hash.remove_backend
-------------------

::

	VOID hash.remove_backend(BACKEND)

Description
	Remove a backend from the director.
Example
	vdir.remove_backend(backend1);
	vdir.remove_backend(backend2);

.. _func_hash.backend:

hash.backend
------------

::

	BACKEND hash.backend(STRING)

Description
	Pick a backend from the backend director.

	Use the string or list of strings provided to pick the backend.
Example
	# pick a backend based on the cookie header from the client
	set req.backend_hint = vdir.backend(req.http.cookie);

.. _obj_shard:

shard
-----

::

	new OBJ = shard()

Create a shard director.

Note that the shard director needs to be configured using at least one
``shard.add_backend()`` call(s) **followed by a**
``shard.reconfigure()`` **call** before it can hand out backends.

Introduction
````````````

The shard director selects backends by a key, which can be provided
directly or derived from strings. For the same key, the shard director
will always return the same backend, unless the backend configuration
or health state changes. Conversely, for differing keys, the shard
director will likely choose different backends. In the default
configuration, unhealthy backends are not selected.

The shard director resembles the hash director, but its main advantage
is that, when the backend configuration or health states change, the
association of keys to backends remains as stable as possible.

In addition, the rampup and warmup features can help to further
improve user-perceived response times.

Sharding
````````

This basic technique allows for numerous applications like optimizing
backend server cache efficiency, Varnish clustering or persisting
sessions to servers without keeping any state, and, in particular,
without the need to synchronize state between nodes of a cluster of
Varnish servers:

* Many applications use caches for data objects, so, in a cluster of
  application servers, requesting similar objects from the same server
  may help to optimize efficiency of such caches.

  For example, sharding by URL or some `id` component of the url has
  been shown to drastically improve the efficiency of many content
  management systems.

* As special case of the previous example, in clusters of Varnish
  servers without additional request distribution logic, each cache
  will need store all hot objects, so the effective cache size is
  approximately the smallest cache size of any server in the cluster.

  Sharding allows to segregate objects within the cluster such that
  each object is only cached on one of the servers (or on one primary
  and one backup, on a primary for long and others for short
  etc...). Effectively, this will lead to a cache size in the order of
  the sum of all individual caches, with the potential to drastically
  increase efficiency (scales by the number of servers).

* Another application is to implement persistence of backend requests,
  such that all requests sharing a certain criterion (such as an IP
  address or session ID) get forwarded to the same backend server.

When used with clusters of varnish servers, the shard director will,
if otherwise configured equally, make the same decision on all
servers. In other words, requests sharing a common criterion used as
the shard key will be balanced onto the same backend server(s) no
matter which Varnish server handles the request.

The drawbacks are:

* the distribution of requests depends on the number of requests per
  key and the uniformity of the distribution of key values. In short,
  while this technique may lead to much better efficiency overall, it
  may also lead to less good load balancing for specific cases.

* When a backend server becomes unavailable, every persistence
  technique has to reselect a new backend server, but this technique
  will also switch back to the preferred server once it becomes
  healthy again, so when used for persistence, it is generally less
  stable compared to stateful techniques (which would continue to use
  a selected server for as long as possible (or dictated by a TTL)).

Method
``````

When ``.reconfigure()`` is called, a consistent hashing circular data
structure gets built from hash values of "ident%d" (default ident
being the backend name) for each backend and for a running number from
1 to n (n is the number of `replicas`). Hashing creates the seemingly
random order for placement of backends on the consistent hashing ring.

When ``.backend()`` is called, a load balancing key gets generated
unless provided. The smallest hash value in the circle is looked up
that is larger than the key (searching clockwise and wrapping around
as necessary). The backend for this hash value is the preferred
backend for the given key.

If a healthy backend is requested, the search is continued linearly on
the ring as long as backends found are unhealthy or all backends have
been checked. The order of these "alternative backends" on the ring
is likely to differ for different keys. Alternative backends can also
be selected explicitly.

On consistent hashing see:

* http://www8.org/w8-papers/2a-webserver/caching/paper2.html
* http://www.audioscrobbler.net/development/ketama/
* svn://svn.audioscrobbler.net/misc/ketama
* http://en.wikipedia.org/wiki/Consistent_hashing

Error Reporting
```````````````

Failing methods should report errors to VSL with the Error tag, so
when configuring the shard director, you are advised to check::

	varnishlog -I Error:^shard

.. _func_shard.set_warmup:

shard.set_warmup
----------------

::

	VOID shard.set_warmup(REAL probability=0.0)

Set the default warmup probability. See the `warmup` parameter of
``shard.backend()``.

Default: 0.0 (no warmup)

.. _func_shard.set_rampup:

shard.set_rampup
----------------

::

	VOID shard.set_rampup(DURATION duration=0)

Set the default rampup duration. See `rampup` parameter of
`shard.backend()`.

Default: 0s (no rampup)

.. _func_shard.add_backend:

shard.add_backend
-----------------

::

	BOOL shard.add_backend(PRIV_TASK, BACKEND backend, STRING ident=0, DURATION rampup=973279260)

Add a backend `backend` to the director.

`ident`: Optionally specify an identification string for this backend,
which will be hashed by `shard.reconfigure()` to construct the
consistent hashing ring. The identification string defaults to the
backend name.

`ident` allows to add multiple instances of the same backend.

`rampup`: Optionally specify a specific rampup time for this
backend. The magic default value of `973279260s` instructs the shard
director to use the default rampup time (see :ref:`func_shard.set_rampup`).

NOTE: Backend changes need to be finalized with `shard.reconfigure()`
and are only supported on one shard director at a time.

.. _func_shard.remove_backend:

shard.remove_backend
--------------------

::

	BOOL shard.remove_backend(PRIV_TASK, BACKEND backend=0, STRING ident=0)

Remove backend(s) from the director. Either `backend` or `ident` must
be specified. `ident` removes a specific instance. If `backend` is
given without `ident`, all instances of this backend are removed.

NOTE: Backend changes need to be finalized with `shard.reconfigure()`
and are only supported on one shard director at a time.

.. _func_shard.clear:

shard.clear
-----------

::

	BOOL shard.clear(PRIV_TASK)

Remove all backends from the director.

NOTE: Backend changes need to be finalized with `shard.reconfigure()`
and are only supported on one shard director at a time.

.. _func_shard.reconfigure:

shard.reconfigure
-----------------

::

	BOOL shard.reconfigure(PRIV_TASK, INT replicas=67, ENUM {CRC32,SHA256,RS} alg="SHA256")

Reconfigure the consistent hashing ring to reflect backend changes.

This method must be called at least once before the director can be
used.

.. _func_shard.key:

shard.key
---------

::

	INT shard.key(STRING string, ENUM {CRC32,SHA256,RS} alg="SHA256")

Utility method to generate a sharding key for use with the
``shard.backend()`` method by hashing `string` with hash algorithm
`alg`.

.. _func_shard.backend:

shard.backend
-------------

::

	BACKEND shard.backend(ENUM {HASH,URL,KEY,BLOB} by="HASH", INT key=0, BLOB key_blob=0, INT alt=0, REAL warmup=-1, BOOL rampup=1, ENUM {CHOSEN,IGNORE,ALL} healthy="CHOSEN")


Lookup a backend on the consistent hashing ring.

This documentation uses the notion of an order of backends for a
particular shard key. This order is deterministic but seemingly random
as determined by the consistent hashing algorithm and is likely to
differ for different keys, depending on the number of backends and the
number of replicas. In particular, the backend order referred to here
is _not_ the order given when backends are added.

* `by` how to determine the sharding key

  default: `HASH`

  * `HASH`:

    * when called in backend context: Use the varnish hash value as
      set by `vcl_hash`

    * when called in client content: hash `req.url`

  * `URL`: hash req.url / bereq.url

  * `KEY`: use the `key` argument

  * `BLOB`: use the `key_blob` argument

  * `key` lookup key with `by=KEY`

    the `shard.key()` function may come handy to generate a sharding
    key from custom strings.

  * `key_blob` lookup key with `by=BLOB`

    Currently, this uses the first 4 bytes from the given blob in
    network byte order (big endian), left-padded with zeros for blobs
    smaller than 4 bytes.

* `alt` alternative backend selection

  default: `0`

  Select the `alt`-th alternative backend for the given `key`.

  This is particularly useful for retries / restarts due to backend
  errors: By setting `alt=req.restarts` or `alt=bereq.retries` with
  healthy=ALL, another server gets selected.

  The rampup and warmup features are only active for `alt==0`

* `rampup` slow start for servers which just went healthy

  default: `true`

  If `alt==0` and the chosen backend is in its rampup period, with a
  probability proportional to the fraction of time since the backup
  became healthy to the rampup period, return the next alternative
  backend, unless this is also in its rampup period.

  The default rampup interval can be set per shard director using the
  `set_rampup()` method or specifically per backend with the
  `set_backend()` method.

* `warmup` probabilistic alternative server selection

  possible values: -1, 0..1

  default: `-1`

  `-1`: use the warmup probability from the director definition

  Only used for `alt==0`: Sets the ratio of requests (0.0 to 1.0) that
  goes to the next alternate backend to warm it up when the preferred
  backend is healthy. Not active if any of the preferred or
  alternative backend are in rampup.

  `warmup=0.5` is a convenient way to spread the load for each key
  over two backends under normal operating conditions.

* `healthy`

  default: `CHOSEN`

  * CHOSEN: Return a healthy backend if possible.

    For `alt==0`, return the first healthy backend or none.

    For `alt > 0`, ignore the health state of backends skipped for
    alternative backend selection, then return the next healthy
    backend. If this does not exist, return the last healthy backend
    of those skipped or none.

  * IGNORE: Completely ignore backend health state

    Just return the first or `alt`-th alternative backend, ignoring
    health state. Ignore `rampup` and `warmup`.

  * ALL: Check health state also for alternative backend selection

    For `alt > 0`, return the `alt`-th alternative backend of all
    those healthy, the last healthy backend found or none.

.. _func_shard.debug:

shard.debug
-----------

::

	VOID shard.debug(INT)

`intentionally undocumented`

ACKNOWLEDGEMENTS
================

Development of a previous version of the shard director was partly sponsored
by Deutsche Telekom AG - Products & Innovation.

Development of this version of the shard director was partly sponsored
by BILD GmbH & Co KG.

COPYRIGHT
=========

::

  This document is licensed under the same licence as Varnish
  itself. See LICENCE for details.
 
  Copyright (c) 2013-2015 Varnish Software AS
  Copyright 2009-2016 UPLEX - Nils Goroll Systemoptimierung
  All rights reserved.
 
  Authors: Poul-Henning Kamp <phk@FreeBSD.org>
 	   Julian Wiesener <jw@uplex.de>
 	   Nils Goroll <slink@uplex.de>
 	   Geoffrey Simmons <geoff@uplex.de>
 
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

