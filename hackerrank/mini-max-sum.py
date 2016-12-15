#!/bin/python

#https://www.hackerrank.com/challenges/mini-max-sum
"""
# 
# Given five positive integers, find the minimum and maximum values that can be calculated by
# summing exactly four of the five integers. Then print the respective minimum and maximum values
# as a single line of two space-separated long integers.
# 
# Input Format
# 
# A single line of five space-separated integers.
# 
# Constraints
# 
# 	* Each integer is in the inclusive range [1, 10**9].
# 
# Output Format
# 
# Print two space-separated long integers denoting the respective minimum and maximum values that
# can be calculated by summing exactly four of the five integers. (The output can be greater than
# 32 bit integer.)
# 
# Sample Input
# 
# 	1 2 3 4 5
# 
# Sample Output
# 
# 	10 14
# 
"""

import sys

########################################################
print "please enter 5 numbers separated with space: ",
########################################################

a,b,c,d,e = raw_input().strip().split(' ')
a,b,c,d,e = [int(a),int(b),int(c),int(d),int(e)]

sar = [a,b,c,d,e]
sar.sort()
min = max = 0
for i in xrange(4):
    min += sar[i]
for i in xrange(len(sar)-1,len(sar)-5,-1):
    max += sar[i]

print min, max

