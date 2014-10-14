-a

	When writing output to a file, append to it rather than overwrite it.

-b

	Only display transactions and log records coming from backend communication.

-B

	Output binary data suitable for reading with -r.

-c

	Only display transactions and log records coming from client communication.

-C

	Do all regular expression and string matching caseless.

-d

	Start processing log records at the head of the log instead of the tail.

-D

	Daemonize.

-g <session|request|vxid|raw>

	The grouping of the log records. The default is to group by vxid.

-h

	Print program usage and exit

-i taglist

	Include log records of these tags in output. Taglist is a comma-separated list of tag globs. Multiple -i options may be given.
	
	If a tag include option is the first of any tag selection options, all tags are first marked excluded.

-k num

	Process this number of matching log transactions before exiting.

-I <[taglist:]regex>

	Include by regex matching. Output only records matching taglist and regular expression. Applies to any tag if taglist is absent.
	
	If a tag include option is the first of any tag selection options, all tags are first marked excluded.

-L limit

	Sets the upper limit of incomplete transactions kept before the oldest transaction is force completed. A warning record is synthesized when this happens. This setting keeps an upper bound on the memory usage of running queries. Defaults to 1000 transactions.

-n name

	Specify the name of the varnishd instance to get logs from. If -n is not specified, the host name is used.

-N filename

	Specify the filename of a stale VSM instance. When using this option the abandonment checking is disabled.

-P file

	Write the process' PID to the specified file.

-q query

	Specifies the VSL query to use.

-r filename

	Read log in binary file format from this file.

-T seconds

	Sets the transaction timeout in seconds. This defines the maximum number of seconds elapsed between a Begin tag and the End tag. If the timeout expires, a warning record is synthesized and the transaction is force completed. Defaults to 120 seconds.

-v

	Use verbose output on record set printing, giving the VXID on every log line. Without this option, the VXID will only be given on the header of that transaction.

-V

	Print version information and exit.

-w filename

	Redirect output to file. The file will be overwritten unless the -a option was specified. If the application receives a SIGHUP the file will be reopened allowing the old one to be rotated away.

-x taglist

	Exclude log records of these tags in output. Taglist is a comma-separated list of tag globs. Multiple -x options may be given.


-X <[taglist:]regex>

	Exclude by regex matching. Do not output records matching taglist and regular expression. Applies to any tag if taglist is absent.

