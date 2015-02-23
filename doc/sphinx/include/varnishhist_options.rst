-C

	Do all regular expression and string matching caseless.

-d

	Start processing log records at the head of the log instead of the tail.

-g <request|vxid>

	The grouping of the log records. The default is to group by vxid.

-h

	Print program usage and exit

-L limit

	Sets the upper limit of incomplete transactions kept before the oldest transaction is force completed. A warning record is synthesized when this happens. This setting keeps an upper bound on the memory usage of running queries. Defaults to 1000 transactions.

-n name

	Specify the name of the varnishd instance to get logs from. If -n is not specified, the host name is used.

-N filename

	Specify the filename of a stale VSM instance. When using this option the abandonment checking is disabled.

-p period

	Specified the number of seconds between screen refreshes. Default is 1 second, and can be changed at runtime by pressing the [1-9] keys.

-P <size|responsetime|tag:field_num:min:max>

	Either specify "size" or "responsetime" profile or create a new one. Define the tag we'll look for, and the field number of the value we are interested in. min and max are the boundaries of the graph (these are power of tens).

-q query

	Specifies the VSL query to use.

-r filename

	Read log in binary file format from this file.

-T seconds

	Sets the transaction timeout in seconds. This defines the maximum number of seconds elapsed between a Begin tag and the End tag. If the timeout expires, a warning record is synthesized and the transaction is force completed. Defaults to 120 seconds.

-V

	Print version information and exit.

