.. _ref_cli_auth <response>:

auth <response>
~~~~~~~~~~~~~~~
  Authenticate.

.. _ref_cli_backend.list [-j] [-p] [<backend_pattern>]:

backend.list [-j] [-p] [<backend_pattern>]
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  List backends.  -p also shows probe status.

``-j`` specifies JSON output.

.. _ref_cli_backend.set_health <backend_pattern> [auto|healthy|sick]:

backend.set_health <backend_pattern> [auto|healthy|sick]
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  Set health status on the backends.

.. _ref_cli_ban <field> <operator> <arg> [&& <field> <oper> <arg> ...]:

ban <field> <operator> <arg> [&& <field> <oper> <arg> ...]
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  Mark obsolete all objects where all the conditions match.

See :ref:`vcl(7)_ban` for details

.. _ref_cli_ban.list [-j]:

ban.list [-j]
~~~~~~~~~~~~~
  List the active bans.

 Unless ``-j`` is specified (for JSON output),  the output format is:

  * Time the ban was issued.

  * Objects referencing this ban.

  * ``C`` if ban is completed = no further testing against it.

  * if ``lurker`` debugging is enabled:

    * ``R`` for req.* tests

    * ``O`` for obj.* tests

    * Pointer to ban object

  * Ban specification

.. _ref_cli_banner:

banner
~~~~~~
  Print welcome banner.

.. _ref_cli_help [-j] [<command>]:

help [-j] [<command>]
~~~~~~~~~~~~~~~~~~~~~
  Show command/protocol help.

``-j`` specifies JSON output.

.. _ref_cli_panic.clear [-z]:

panic.clear [-z]
~~~~~~~~~~~~~~~~
  Clear the last panic, if any, -z will clear related varnishstat counter(s)

.. _ref_cli_panic.show [-j]:

panic.show [-j]
~~~~~~~~~~~~~~~
  Return the last panic, if any.

``-j`` specifies JSON output -- the panic message is returned as an unstructured JSON string.

.. _ref_cli_param.reset <param>:

param.reset <param>
~~~~~~~~~~~~~~~~~~~
  Reset parameter to default value.

.. _ref_cli_param.set <param> <value>:

param.set <param> <value>
~~~~~~~~~~~~~~~~~~~~~~~~~
  Set parameter value.

.. _ref_cli_param.show [-l|-j] [<param>|changed]:

param.show [-l|-j] [<param>|changed]
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  Show parameters and their values.

The long form with ``-l`` shows additional information, including documentation and minimum, maximum and default values, if defined for the parameter. JSON output is specified with ``-j``, in which the information for the long form is included; only one of ``-l`` or ``-j`` is permitted. If a parameter is specified with ``<param>``, show only that parameter. If ``changed`` is specified, show only those parameters whose values differ from their defaults.

.. _ref_cli_pid [-j]:

pid [-j]
~~~~~~~~
  Show the pid of the master process, and the worker if it's running.

  ``-j`` specifies JSON output.

.. _ref_cli_ping [-j] [<timestamp>]:

ping [-j] [<timestamp>]
~~~~~~~~~~~~~~~~~~~~~~~
  Keep connection alive.

The response is formatted as JSON if ``-j`` is specified.

.. _ref_cli_quit:

quit
~~~~
  Close connection.

.. _ref_cli_start:

start
~~~~~
  Start the Varnish cache process.

.. _ref_cli_status [-j]:

status [-j]
~~~~~~~~~~~
  Check status of Varnish cache process.

``-j`` specifies JSON output.

.. _ref_cli_stop:

stop
~~~~
  Stop the Varnish cache process.

.. _ref_cli_storage.list [-j]:

storage.list [-j]
~~~~~~~~~~~~~~~~~
  List storage devices.

``-j`` specifies JSON output.

.. _ref_cli_vcl.discard <configname|label>:

vcl.discard <configname|label>
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  Unload the named configuration (when possible).

.. _ref_cli_vcl.inline <configname> <quoted_VCLstring> [auto|cold|warm]:

vcl.inline <configname> <quoted_VCLstring> [auto|cold|warm]
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  Compile and load the VCL data under the name provided.

  Multi-line VCL can be input using the here document :ref:`ref_syntax`.

.. _ref_cli_vcl.label <label> <configname>:

vcl.label <label> <configname>
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  Apply label to configuration.

.. _ref_cli_vcl.list [-j]:

vcl.list [-j]
~~~~~~~~~~~~~
  List all loaded configuration.

``-j`` specifies JSON output.

.. _ref_cli_vcl.load <configname> <filename> [auto|cold|warm]:

vcl.load <configname> <filename> [auto|cold|warm]
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  Compile and load the VCL file under the name provided.

.. _ref_cli_vcl.show [-v] <configname>:

vcl.show [-v] <configname>
~~~~~~~~~~~~~~~~~~~~~~~~~~
  Display the source code for the specified configuration.

.. _ref_cli_vcl.state <configname> [auto|cold|warm]:

vcl.state <configname> [auto|cold|warm]
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  Force the state of the named configuration.

.. _ref_cli_vcl.use <configname|label>:

vcl.use <configname|label>
~~~~~~~~~~~~~~~~~~~~~~~~~~
  Switch to the named configuration immediately.

