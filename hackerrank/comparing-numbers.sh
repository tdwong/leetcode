#!/bin/bash

#https://www.hackerrank.com/challenges/bash-tutorials---comparing-numbers

# sanity check for bash
[ "X$BASH_VERSION" = "X" ] && echo "error: bash required" && exit

echo "provide two numbers in separate lines: "

read x
read y
if (( $x < $y )); then
#- X is less than Y 
    echo X is less than Y 
elif (( $x == $y )); then
#- X is equal to Y
    echo X is equal to Y
else
#- X is greater than Y 
    echo X is greater than Y 
fi
