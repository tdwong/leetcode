#!/bin/bash

#https://www.hackerrank.com/challenges/lonely-integer-2

# There are N integers in an array A. All but one integer occur in pairs. Your task is to find
# the number that occurs only once.

#
# Input Format
#
# The first line of the input contains an integer N, indicating the number of integers. The
# next line contains N space-separated integers that form the array A.
#

read cnt
read numbers
# split numbers into an array
IFS=' ' read -r -a array <<< "$numbers"

#
# iterate array
declare -A dict
for num in "${array[@]}";
do
#    echo num=$num
    if [ -z ${dict[$num]} ]; then
#        echo 'init $num'
        let dict[$num]=1
    else
#        echo 'incr $num'
        let dict[$num]+=1
    fi
#    echo "\${dict[$num]}=${dict[$num]}"
done

#
# iterate associative array
for k in "${!dict[@]}"
do
#    echo key=$k, value=${dict[$k]}
    if [ ${dict[$k]} -ne 2 ]; then
        echo $k
        break
    fi
done

