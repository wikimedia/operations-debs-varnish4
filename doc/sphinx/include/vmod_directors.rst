==============
vmod_directors
==============

-------------------------
Backend traffic directors
-------------------------

:Manual section: 3

SYNOPSIS
========

import directors [from "path"] ;


DESCRIPTION
===========

Vmod_directors enables load balancing in Varnish. The module serves
as an example on how one could extend the load balancing capabilities
of Varnish.

To enable load balancing you must import this vmod (directors) in your
VCL:::

  import directors;

Then you define your backends. Once you have the backends declared you
can add them to a director. This happens in executed VCL code. If you
want to emulate the previous behavior of Varnish 3.0 you can just
initialize the directors in vcl_init, like this:::

    sub vcl_init {
        new bar = directors.round_robin();
        bar.add_backend(server1);
        bar.add_backend(server2);
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
* :ref:`obj_hash`
* :ref:`func_hash.add_backend`
* :ref:`func_hash.backend`
* :ref:`obj_random`
* :ref:`func_random.add_backend`
* :ref:`func_random.backend`
* :ref:`obj_round_robin`
* :ref:`func_round_robin.add_backend`
* :ref:`func_round_robin.backend`

.. _obj_round_robin:

Object round_robin
==================


Description
       Create a round robin director. This director will pick backends
       in a round robin fashion.
Example
       new bar = directors.round_robin();

.. _func_round_robin.add_backend:

VOID round_robin.add_backend(BACKEND)
-------------------------------------

Prototype
	VOID round_robin.add_backend(BACKEND)

Description
       Adds a backend to the director.
Example
       rrdir.add_backend(backend1);

.. _func_round_robin.backend:

BACKEND round_robin.backend()
-----------------------------

Prototype
	BACKEND round_robin.backend()

Description
       Picks a backend from the director.
Example
       set req.backend_hint = rrdir.backend();

.. _obj_fallback:

Object fallback
===============


Description
        Creates a fallback director.

#	XXX: Add description of fallback director.

Example
        new foo = directors.fallback();

.. _func_fallback.add_backend:

VOID fallback.add_backend(BACKEND)
----------------------------------

Prototype
	VOID fallback.add_backend(BACKEND)

Description
       Adds a backend to the director.
Example
       bar.add_backend(backend1);

.. _func_fallback.backend:

BACKEND fallback.backend()
--------------------------

Prototype
	BACKEND fallback.backend()

Description
       Picks a backend from the director.
Example
       set req.backend_hint = rrdir.backend();

.. _obj_random:

Object random
=============


Description
       Adds a random director. This director chooses backend based on
       a random number. As you add backends to the director each
       backends gets a weight, which is used to when requests are
       being distributed. So, a backend with a weight of 1 would get
       more or less 1% of the traffic of a backend in the same
       director with a weight of 100.
Example
       new rand_dir = directors.random();

.. _func_random.add_backend:

VOID random.add_backend(BACKEND, REAL)
--------------------------------------

Prototype
	VOID random.add_backend(BACKEND, REAL)

Description
       Adds a backend to the director with weight.
Example
       bar.add_backend(backend1, 3.14);

.. _func_random.backend:

BACKEND random.backend()
------------------------

Prototype
	BACKEND random.backend()

Description
       Picks a backend from the director.
Example
       set req.backend_hint = rrdir.backend();

.. _obj_hash:

Object hash
===========


Description
       Creates a hash director. The hash director chooses the backend
       based on hashing an arbitrary string. If you provide it with a
       session cookie, you'll have the client connecting to the same
       backend every time.
Example
       new hdir = directors.hash();

.. _func_hash.add_backend:

VOID hash.add_backend(BACKEND, REAL)
------------------------------------

Prototype
	VOID hash.add_backend(BACKEND, REAL)

Description
	Adds a backend to the director with a certain weight.

	Weight is used as in the round_robin director. Recommended value is
	1.0 unless you have special needs.

Example
       hdir.add_backend(backend1, 1.0);

.. _func_hash.backend:

BACKEND hash.backend(STRING_LIST)
---------------------------------

Prototype
	BACKEND hash.backend(STRING_LIST)

Description
       Picks a backend from the director. Use the string or list of
       strings provided to pick the backend.
Example
       # pick a backend based on the cookie header from the client
       set req.backend_hint = hdir.backend(req.http.cookie);

