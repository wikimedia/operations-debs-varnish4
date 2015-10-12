-a

	When writing output to a file, append to it rather than overwrite it.

-C

	Do all regular expression and string matching caseless.

-d

	Start processing log records at the head of the log instead of the tail.

-D

	Daemonize.

-F format

	Set the output log format string.

-g <request|vxid>

	The grouping of the log records. The default is to group by vxid.

-h

	Print program usage and exit

-n name

	Specify the name of the varnishd instance to get logs from. If -n is not specified, the host name is used.

-N filename

	Specify the filename of a stale VSM instance. When using this option the abandonment checking is disabled.

-P file

	Write the process' PID to the specified file.

-q query

	Specifies the VSL query to use.

-r filename

	Read log in binary file format from this file. The file can be created with ``varnishlog -w filename``.

-t <seconds|off>

	Timeout before returning error on initial VSM connection. If set the VSM connection is retried every 0.5 seconds for this many seconds. If zero the connection is attempted only once and will fail immediately if unsuccessful. If set to "off", the connection will not fail, allowing the utility to start and wait indefinetely for the Varnish instance to appear.  Defaults to 5 seconds.

-V

	Print version information and exit.

-w filename

	Redirect output to file. The file will be overwritten unless the -a option was specified. If the application receives a SIGHUP the file will be reopened allowing the old one to be rotated away.

