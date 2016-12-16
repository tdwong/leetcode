#!/bin/sh

#https://www.hackerrank.com/challenges/bash-tutorials---more-on-conditionals

# sanity check for bash
[ "X$BASH_VERSION" = "X" ] && echo "error: bash required" && exit

#  identify whether the triangle is Scalene, Isosceles, or Equilateral.

read a
read b
read c
if (( $a == $b && $b == $c )) ; then
    echo EQUILATERAL
elif (( $a == $b || $b == $c || $a == $c )) ; then
    echo ISOSCELES
else
    echo SCALENE
fi

