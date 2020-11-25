..
.. NB:  This file is machine generated, DO NOT EDIT!
..
.. Edit ./vmod_cookie.vcc and run make instead
..


:tocdepth: 1

.. _vmod_cookie(3):

===================================
VMOD cookie - Varnish Cookie Module
===================================

SYNOPSIS
========

.. parsed-literal::

  import cookie [as name] [from "path"]
  
  :ref:`cookie.clean()`
   
  :ref:`cookie.delete()`
   
  :ref:`cookie.filter()`
   
  :ref:`cookie.filter_re()`
   
  :ref:`cookie.keep()`
   
  :ref:`cookie.keep_re()`
   
  :ref:`cookie.format_rfc1123()`
   
  :ref:`cookie.get()`
   
  :ref:`cookie.get_re()`
   
  :ref:`cookie.get_string()`
   
  :ref:`cookie.isset()`
   
  :ref:`cookie.parse()`
   
  :ref:`cookie.set()`
   
DESCRIPTION
===========

Handle HTTP cookies more easily in Varnish VCL.

Parses a cookie header into an internal data store, where per-cookie
get/set/delete functions are available. A keep() function removes all
but a set comma-separated list of cookies. A filter() function removes a comma-
separated list of cookies.

Regular expressions can be used for either selecting cookies, deleting matching
cookies and deleting non-matching cookie names.

A convenience function for formatting the Set-Cookie Expires date field
is also included.

The state loaded with cookie.parse() has a lifetime of the current request
or backend request context. To pass variables to the backend request, store
the contents as fake bereq headers.

Filtering example::

	import cookie;

	sub vcl_recv {
	    if (req.http.cookie) {
	        cookie.parse(req.http.cookie);
	        # Either delete the ones you want to get rid of:
	        cookie.delete("cookie2");
	        # or delete all but a few:
	        cookie.keep("SESSIONID,PHPSESSID");

	        # Store it back into req so it will be passed to the backend.
	        set req.http.cookie = cookie.get_string();

	        # If empty, unset so the builtin VCL can consider it for caching.
	        if (req.http.cookie == "") {
	            unset req.http.cookie;
	        }
	    }
	}


.. _cookie.clean():

VOID clean()
------------

Clean up previously parsed cookies. It is not necessary to run clean()
in normal operations.

Example::

	sub vcl_recv {
	    cookie.clean();
	}

.. _cookie.delete():

VOID delete(STRING cookiename)
------------------------------

Delete ``cookiename`` from internal vmod storage if it exists.

Example::

	sub vcl_recv {
	    cookie.parse("cookie1: value1; cookie2: value2;");
	    cookie.delete("cookie2");
	    # get_string() will now yield "cookie1: value1";
	}

.. _cookie.filter():

VOID filter(STRING filterstring)
--------------------------------

Delete all cookies from internal vmod storage that are in the
comma-separated argument cookienames.

Example::

	sub vcl_recv {
	    cookie.parse("cookie1: value1; cookie2: value2; cookie3: value3");
	    cookie.filter("cookie1,cookie2");
	    # get_string() will now yield
	    # "cookie3: value3";
	}

.. _cookie.filter_re():

VOID filter_re(STRING expression)
---------------------------------

Delete all cookies from internal vmod storage that matches the
regular expression ``expression``.

Example::

	sub vcl_recv {
	    cookie.parse("cookie1: value1; cookie2: value2; cookie3: value3");
	    cookie.filter_re("^cookie[12]$");
	    # get_string() will now yield
	    # "cookie3: value3";
	}

.. _cookie.keep():

VOID keep(STRING filterstring)
------------------------------

Delete all cookies from internal vmod storage that is not in the
comma-separated argument cookienames.

Example::

	sub vcl_recv {
	    cookie.parse("cookie1: value1; cookie2: value2; cookie3: value3");
	    cookie.keep("cookie1,cookie2");
	    # get_string() will now yield
	    # "cookie1: value1; cookie2: value2;";
	}

.. _cookie.keep_re():

VOID keep_re(STRING expression)
-------------------------------

Delete all cookies from internal vmod storage that does not match
expression ``expression``.

Example::

	sub vcl_recv {
	    cookie.parse("cookie1: value1; cookie2: value2; cookie3: value3");
	    cookie.keep_re("^cookie1,cookie2");
	    # get_string() will now yield
	    # "cookie1: value1; cookie2: value2;";
	}

.. _cookie.format_rfc1123():

STRING format_rfc1123(TIME now, DURATION timedelta)
---------------------------------------------------

Get a RFC1123 formatted date string suitable for inclusion in a
Set-Cookie response header.

Care should be taken if the response has multiple Set-Cookie headers.
In that case the header vmod should be used.

Example::

	sub vcl_deliver {
	    # Set a userid cookie on the client that lives for 5 minutes.
	    set resp.http.Set-Cookie = "userid=" + req.http.userid +
	        "; Expires=" + cookie.format_rfc1123(now, 5m) + "; httpOnly";
	}

.. _cookie.get():

STRING get(STRING cookiename)
-----------------------------

Get the value of ``cookiename``, as stored in internal vmod storage. If
``cookiename`` does not exist an empty string is returned.

Example::

	import std;
	sub vcl_recv {
	    cookie.parse("cookie1: value1; cookie2: value2;");
	    std.log("cookie1 value is: " + cookie.get("cookie1"));
	}

.. _cookie.get_re():

STRING get_re(STRING expression)
--------------------------------

Get the value of the first cookie in internal vmod storage that matches
regular expression ``expression``. If nothing matches, an empty string
is returned.

Example::

	import std;
	sub vcl_recv {
	    cookie.parse("cookie1: value1; cookie2: value2;");
	    std.log("cookie1 value is: " + cookie.get_re("^cookie1$"));
	}

.. _cookie.get_string():

STRING get_string()
-------------------

Get a Cookie string value with all cookies in internal vmod storage. Does
not modify internal storage.

Example::

	sub vcl_recv {
	    cookie.parse(req.http.cookie);
	    cookie.keep("SESSIONID,PHPSESSID");
	    set req.http.cookie = cookie.get_string();
	}

.. _cookie.isset():

BOOL isset(STRING cookiename)
-----------------------------

Check if ``cookiename`` is set in the internal vmod storage.

Example::

	import std;
	sub vcl_recv {
	    cookie.parse("cookie1: value1; cookie2: value2;");
	    if (cookie.isset("cookie2")) {
	        std.log("cookie2 is set.");
	    }
	}

.. _cookie.parse():

VOID parse(STRING cookieheader)
-------------------------------

Parse the cookie string in ``cookieheader``. If state already exists,
``clean()`` will be run first.

Example::

	sub vcl_recv {
	    cookie.parse(req.http.Cookie);
	}

.. _cookie.set():

VOID set(STRING cookiename, STRING value)
-----------------------------------------

Set the internal vmod storage for ``cookiename`` to ``value``.

Example::

	sub vcl_recv {
	    cookie.set("cookie1", "value1");
	    std.log("cookie1 value is: " + cookie.get("cookie1"));
	}
