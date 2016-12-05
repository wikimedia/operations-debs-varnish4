.. _ref_cli_auth <response>:

auth <response>
~~~~~~~~~~~~~~~
  Authenticate.

.. _ref_cli_backend.list [-p] [<backend_pattern>]:

backend.list [-p] [<backend_pattern>]
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  List backends.  -p also shows probe status.

.. _ref_cli_backend.set_health <backend_pattern> [auto|healthy|sick]:

backend.set_health <backend_pattern> [auto|healthy|sick]
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  Set health status on the backends.

.. _ref_cli_ban <field> <operator> <arg> [&& <field> <oper> <arg> ...]:

ban <field> <operator> <arg> [&& <field> <oper> <arg> ...]
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  Mark obsolete all objects where all the conditions match.

See :ref:`vcl(7)_ban` for details

.. _ref_cli_ban.list:

ban.list
~~~~~~~~
  List the active bans.

  The output format is:

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

.. _ref_cli_help [<command>]:

help [<command>]
~~~~~~~~~~~~~~~~
  Show command/protocol help.

.. _ref_cli_panic.clear [-z]:

panic.clear [-z]
~~~~~~~~~~~~~~~~
  Clear the last panic, if any, -z will clear related varnishstat counter(s)

.. _ref_cli_panic.show:

panic.show
~~~~~~~~~~
  Return the last panic, if any.

.. _ref_cli_param.set <param> <value>:

param.set <param> <value>
~~~~~~~~~~~~~~~~~~~~~~~~~
  Set parameter value.

.. _ref_cli_param.show [-l] [<param>]:

param.show [-l] [<param>]
~~~~~~~~~~~~~~~~~~~~~~~~~
  Show parameters and their values.

.. _ref_cli_ping [<timestamp>]:

ping [<timestamp>]
~~~~~~~~~~~~~~~~~~
  Keep connection alive.

.. _ref_cli_quit:

quit
~~~~
  Close connection.

.. _ref_cli_start:

start
~~~~~
  Start the Varnish cache process.

.. _ref_cli_status:

status
~~~~~~
  Check status of Varnish cache process.

.. _ref_cli_stop:

stop
~~~~
  Stop the Varnish cache process.

.. _ref_cli_storage.list:

storage.list
~~~~~~~~~~~~
  List storage devices.

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

.. _ref_cli_vcl.list:

vcl.list
~~~~~~~~
  List all loaded configuration.

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

