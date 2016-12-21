#!/bin/bash

#
# bash day-28-ht-regex-patterns.sh < day-28-ht-regex-patterns_3.txt
#

read n
cat - | grep '@gmail.com$' | sed -e 's/ .*gmail.com//' | sort
