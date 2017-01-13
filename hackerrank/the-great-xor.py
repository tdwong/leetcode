#!/bin/python

#https://www.hackerrank.com/contests/w28/challenges/the-great-xor
"""
# All Contests >> Week of Code 28 >> The Great XOR 
# 
# The Great XOR
# 
# Given a long integer, x, count the number of values of a satisfying the following conditions:
# 
#     * a XOR x > x
#     * 0 < a < x
# 
# where a and x are long integers and XOR is the bitwise XOR operator. 
# 
# You are given q queries, and each query is in the form of a long integer denoting x. For each
# query, print the total number of values of a satisfying the conditions above on a new line.
# 
# Input Format
# 
# The first line contains an integer, q, denoting the number of queries. 
# Each of the q subsequent lines contains a long integer describing the value of x for a query. 
# 
# Constraints
# 
#     * 1 <= q <= 10**5
#     * 1 <= x <= 10**10
# 
# Subtasks
# 
#     For 50% of the maximum score:
# 
#     * 1 <= q <= 10**3
#     * 1 <= x <= 10**4
# 
# Output Format
# 
# For each query, print the number of values of a satisfying the given conditions on a new line.
# 
# Sample Input 0
# 
#     2
#     2
#     10
# 
# Sample Output 0
# 
#     1
#     5
# 
"""


#!/bin/python

import sys

q = int(raw_input().strip())
for a0 in xrange(q):
    x = long(raw_input().strip())
    # your code goes here
    
    b=x        # use b to traverse all bits
    count=0
    b=b>>1     # shift out LSB
    posCount=2 # LSB+1 (2**1)
    while b:
        # 
        c=b&1
        """ toggle a bit==0 will create an XOR value greater than x
        """
        if c==0: count += posCount
        b=b>>1
        posCount *= 2
        
    if x%2==0: count += 1       # LSB
    print count 

