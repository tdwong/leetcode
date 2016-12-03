#!/bin/python

#https://www.hackerrank.com/challenges/30-binary-numbers
"""
# Day 10: Binary Numbers
# 
# Objective 
# 
# Today, we're working with binary numbers. Check out the Tutorial tab for learning materials and an instructional video!
# 
# Task 
# 
# Given a base-10 integer, n, convert it to binary (base-2). Then find and print the base-10
# integer denoting the maximum number of consecutive 1's in n's binary representation.
# 
# Input Format
# 
# 	A single integer, n.
# 
# Constraints
# 
# 	* 1 <= n <= 10**6
# 
# Output Format
# 
# 	Print a single base-10 integer denoting the maximum number of consecutive 1's in the binary representation of n.
# 
# Sample Input 1
# 
# 	5
# 
# Sample Output 1
# 
# 	1
# 
# Sample Input 2
# 
# 	13
# 
# Sample Output 2
# 
# 	2
# 
# Explanation
# 
# Sample Case 1: 
# The binary representation of 5 is 101, so the maximum number of consecutive 1's is 1.
# 
# Sample Case 2: 
# The binary representation of 13 is 1101 , so the maximum number of consecutive 1's is 2.
# 
"""

###################################################################
print "provide an integer n:",
###################################################################

import sys

def tobits(n):
	nar=[]
	while n>0:
		nar.append(n%2)
		n=n/2
#	nar.reverse()
	return nar

def count1s(ar):
	count=0
	for i in ar:
		if i==1:  count+=1
	return count

def countC1s(ar):
	count=0
	maxc=0
	for i in ar:
		if i==1:
			count+=1
		else:	# i==0
			if count>maxc: maxc=count
			count=0
		# "ternary" expressions -- i.e. condense oneline if-else
	return maxc if count<=maxc else count


n = int(raw_input().strip())

## print "tobits(%d): %s" % (n, tobits(n)),
## print count1s(tobits(n))
print countC1s(tobits(n))

