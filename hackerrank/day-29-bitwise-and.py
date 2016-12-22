#!/bin/python

#https://www.hackerrank.com/challenges/30-bitwise-and
"""
# Day 29: Bitwise AND
# 
# Objective 
# 
# Welcome to the last day! Today, we're discussing bitwise operations. Check out the Tutorial
# tab for learning materials and an instructional video!
# 
# Task 
# 
# Given set S = {1,2,3,...,N}. Find two integers, A and B (where A < B), from set S such that
# the value of A&B is the maximum possible and also less than a given integer, K. In this case,
# & represents the bitwise AND operator.
# 
# Input Format
# 
# The first line contains an integer, T, the number of test cases. 
# Each of the T subsequent lines defines a test case as 2 space-separated integers, N and K, respectively.
# 
# Constraints
# 
#     * 1 <= T <= 10**3
#     * 2 <= N <= 10**3
#     * 2 <= K <= N
# 
# Output Format
# 
# For each test case, print the maximum possible value of A&B on a new line.
# 
# Sample Input
# 
#     3
#     5 2
#     8 5
#     2 2
# 
# Sample Output
# 
#     1
#     4
#     0
# 
"""

#// ---------------------------- locked code below ------------------------------

#!/bin/python

import sys

###################################################################
print "to run: python ./day-29-bitwise-and.py < day-29-bitwise-and.txt"
###################################################################

ar=[]
maxn=0

t = int(raw_input().strip())
for a0 in xrange(t):
    n,k = raw_input().strip().split(' ')
    n,k = [int(n),int(k)]

#// ---------------------------- locked code above ------------------------------


    """ approach #1:  straightforward and brute-force (inefficient and time-out)
        #
    m = 0
    for i in xrange(1,n):
        for j in xrange(i+1,n+1):
            a = i&j
            if a<k and a>m: m=a
    print "#", m
    """

    """ approach #2:  cache all input and process once
    ar += [[n,k]]
    if n>maxn: maxn = n

# done with input
m = [ [0]*maxn for n in xrange(maxn) ]
for i in xrange(maxn):
    for j in xrange(i+1,maxn+1):
        m[i][j] = i&j

for n in xrange(len(ar)):
    n,k = ar[n]
    mx = 0
    for i in xrange(n):
        for j in xrange(i+1,n+1):
#            print "m[,",i,"][",j,"]=", m[i][j], "k=",k, "mx=",mx
            if m[i][j]<k and m[i][j]>mx: mx=m[i][j] 

    print mx
    """

    """ approach #3:  start with a reasonable number
        #
    m = 0
    for i in xrange(1,k+1):
        for j in xrange(i+1,n+1):
            a = i&j
            if a<k and a>m: m=a
    print "#", m
    """

    """ approach #4:  based on HackerRank discussion
        #
        # https://www.hackerrank.com/challenges/30-bitwise-and/forum/comments/157544
        # https://www.hackerrank.com/challenges/30-bitwise-and/forum/comments/144944
        #
    m = 0

    if (k%2)==1: m=(k-1)        # (k-1) can be derived by ((k-1) & k)
    else:
        # check if (k-1) is possible
        if (k | (k-1))<=n:
            # yes
            m=(k-1)             # (k-1) can be derived by ((k-1) & (k|(k-1)))
        else:
            m=(k-2)
    //"""
    """
        # https://www.hackerrank.com/challenges/30-bitwise-and/forum/comments/157544
        # condensed version
    if ((k-1)|k)<=n: m=k-1
    else: m=k-2
    """

#    print "#", m



#// ---------------------------- locked code below ------------------------------

