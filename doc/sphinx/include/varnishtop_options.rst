-1

	Instead of a continously updated display, print the statistics once and exit. Implies ``-d``.

-b

	Only display transactions and log records coming from backend communication.

-c

	Only display transactions and log records coming from client communication.

-C

	Do all regular expression and string matching caseless.

-d

	Start processing log records at the head of the log instead of the tail.

-f

	Sort and group only on the first field of each log entry. This is useful when displaying e.g. stataddr entries, where the first field is the client IP address.

-g <session|request|vxid|raw>

	The grouping of the log records. The default is to group by vxid.

-h

	Print program usage and exit

-i taglist

	Include log records of these tags in output. Taglist is a comma-separated list of tag globs. Multiple -i options may be given.
	
	If a tag include option is the first of any tag selection options, all tags are first marked excluded.

-I <[taglist:]regex>

	Include by regex matching. Output only records matching taglist and regular expression. Applies to any tag if taglist is absent.
	
	If a tag include option is the first of any tag selection options, all tags are first marked excluded.

-L limit

	Sets the upper limit of incomplete transactions kept before the oldest transaction is force completed. A warning record is synthesized when this happens. This setting keeps an upper bound on the memory usage of running queries. Defaults to 1000 transactions.

-n name

	Specify the name of the varnishd instance to get logs from. If -n is not specified, the host name is used.

-N filename

	Specify the filename of a stale VSM instance. When using this option the abandonment checking is disabled.

-p period

	Specified the number of seconds to measure over, the default is 60 seconds. The first number in the list is the average number of requests seen over this time period.

-q query

	Specifies the VSL query to use.

-r filename

	Read log in binary file format from this file.

-T seconds

	Sets the transaction timeout in seconds. This defines the maximum number of seconds elapsed between a Begin tag and the End tag. If the timeout expires, a warning record is synthesized and the transaction is force completed. Defaults to 120 seconds.

-x taglist

	Exclude log records of these tags in output. Taglist is a comma-separated list of tag globs. Multiple -x options may be given.


-X <[taglist:]regex>

	Exclude by regex matching. Do not output records matching taglist and regular expression. Applies to any tag if taglist is absent.

-V

	Print version information and exit.

