#!/bin/bash

# solution to Robert's problem:

	# a has the ultimate value
a=100
	# c reference to a
c=a

# best solution (works only on bash)
#	see http://stackoverflow.com/a/1921337/663485
#
[ "X$BASH_VERSION" != "X" ] && echo "bash solution: " ${!c}

# alternative solution
#	see http://stackoverflow.com/a/1921376/663485
#
eval "q=\$$c"; echo "sh solution: " $q

