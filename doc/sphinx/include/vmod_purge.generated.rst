..
.. NB:  This file is machine generated, DO NOT EDIT!
..
.. Edit vmod.vcc and run make instead
..

.. role:: ref(emphasis)

.. _vmod_purge(3):

==========
vmod_purge
==========

--------------------
Varnish Purge Module
--------------------

:Manual section: 3

SYNOPSIS
========


::

   import purge [from "path"] ;
   
   INT hard()
  
   INT soft(DURATION ttl, DURATION grace, DURATION keep)
  




CONTENTS
========

* :ref:`func_hard`
* :ref:`func_soft`



DESCRIPTION
===========

`vmod_purge` contains functions that offer a finer-grained control than the
``purge`` transition in ``vcl_recv``. The functions can only be called from
``vcl_hit`` or ``vcl_miss`` and they should in general be used in both to
ensure that all variants of a same object are taken care of.

EXAMPLE
=======

::

    sub vcl_recv {
	if (req.method == "PURGE") {
	    if (client.ip !~ purge_acl) {
		return (synth(405));
	    }
	    return (hash);
	}
    }

    sub my_purge {
	set req.http.purged = purge.hard();
	if (req.http.purged == "0") {
	    return (synth(404));
	}
	else {
	    return (synth(200));
	}
    }

    sub vcl_hit {
	if (req.method == "PURGE") {
	    call my_purge;
	}
    }

    sub vcl_miss {
	if (req.method == "PURGE") {
	    call my_purge;
	}
    }

    sub vcl_synth {
	if (req.method == "PURGE") {
	    if (req.http.purged) {
		set resp.http.purged = req.http.purged;
	    }
	    return (deliver);
	}
    }


.. _func_hard:

INT hard()
----------

Description
	This is equivalent to ``return(purge)`` but explicitly called from
	``vcl_hit`` and ``vcl_miss``. It returns the number of purged objects.
Example
	set req.http.purged = purge.hard();


.. _func_soft:

INT soft(DURATION ttl, DURATION grace, DURATION keep)
-----------------------------------------------------

::

   INT soft(DURATION ttl=0, DURATION grace=-1, DURATION keep=-1)

Description
	Sets the TTL, grace and keep. By default, TTL is set to 0 with grace
	and keep periods left untouched. Setting a negative value for grace or
	keep periods leaves them untouched. Setting all three parameters to
	0 is equivalent to a hard purge. It can only be called from ``vcl_hit``
	or ``vcl_miss``. It returns the number of soft-purged objects.

SEE ALSO
========

* :ref:`vcl(7)`


COPYRIGHT
=========

::

  Copyright (c) 2017 Varnish Software AS
  All rights reserved.
 
  Author: Dridi Boukelmoune <dridi.boukelmoune@gmail.com>
 
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
