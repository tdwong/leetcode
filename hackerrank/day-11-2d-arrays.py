#!/bin/python

#https://www.hackerrank.com/challenges/30-2d-arrays
"""
# Day 11: 2D Arrays
# 
# Objective 
# 
# Today, we're building on our knowledge of Arrays by adding another dimension. Check out the
# Tutorial tab for learning materials and an instructional video!
# 
# Context 
# 
# Given a 6x6 2D Array, A:
# 
# 	1 1 1 0 0 0
# 	0 1 0 0 0 0
# 	1 1 1 0 0 0
# 	0 0 0 0 0 0
# 	0 0 0 0 0 0
# 	0 0 0 0 0 0
# 
# We define an hourglass in A to be a subset of values with indices falling in this pattern in A's graphical
# representation:
# 
# 	a b c
# 	  d
# 	e f g
# 
# There are 16 hourglasses in A, and an hourglass sum is the sum of an hourglass' values.
# 
# Task 
# 
# Calculate the hourglass sum for every hourglass in A, then print the maximum hourglass sum.
# 
# Input Format
# 
# There are 6 lines of input, where each line contains 6 space-separated integers describing 2D
# Array A; every value in A will be in the inclusive range of 9 to -9.
# 
# Constraints
# 
# 	* -9 <= A[i][j] <= 9
# 	* 0 <= i,j <= 5
# 
# Output Format
# 
# Print the largest (maximum) hourglass sum found in A.
# 
# Sample Input
# 
# 	1 1 1 0 0 0
# 	0 1 0 0 0 0
# 	1 1 1 0 0 0
# 	0 0 2 4 4 0
# 	0 0 0 2 0 0
# 	0 0 1 2 4 0
# 
# Sample Output
# 
# 	19
# 
# Explanation
# 
# A contains the following hourglasses:
# 
# 	1 1 1   1 1 0   1 0 0   0 0 0
# 	  1       0       0       0
# 	1 1 1   1 1 0   1 0 0   0 0 0
# 
# 	0 1 0   1 0 0   0 0 0   0 0 0
# 	  1       1       0       0
# 	0 0 2   0 2 4   2 4 4   4 4 0
# 
# 	1 1 1   1 1 0   1 0 0   0 0 0
# 	  0       2       4       4
# 	0 0 0   0 0 2   0 2 0   2 0 0
# 
# 	0 0 2   0 2 4   2 4 4   4 4 0
# 	  0       0       2       0
# 	0 0 1   0 1 2   1 2 4   2 4 0
# 
# The hourglass with the maximum sum (19) is:
# 
# 	2 4 4
# 	  2
# 	1 2 4
# 
"""

###################################################################
from sys import argv
if len(argv) > 1:
	print "to run: python day-11-2d-arrays.py < day-11-2d-arrays.txt"
	quit()
###################################################################

import sys


arr = []
for arr_i in xrange(6):
   arr_temp = map(int,raw_input().strip().split(' '))
   arr.append(arr_temp)

#print type(arr)
#print "arr=",len(arr), arr
for i in xrange(len(arr)):
	r = arr[i]
#	print type(r), r
	for j in xrange(len(r)):
		print "%d" % (r[j]),
	print

sum = 0
for i in xrange(len(arr)-2):
	for j in xrange((len(arr[i])-2)):
#		print "i=",i,"j=",j,
#		print (arr[i][j] , arr[i][j+1] , arr[i][j+2] 
#				, arr[i+1][j] , arr[i+1][j+1] , arr[i+1][j+2] 
#				, arr[i+2][j] , arr[i+2][j+1] , arr[i+2][j+2] )
		sum = (
				+ arr[i][j] + arr[i][j+1] + arr[i][j+2] 
				+ arr[i+1][j+1]  
				+ arr[i+2][j] + arr[i+2][j+1] + arr[i+2][j+2] )
		try:
			if sum > largestS: largestS = sum
		except:
			largestS = sum
#		print "sum=",sum,"largestS=",largestS
		sum = 0
print "largestS=", largestS
#print largestS

