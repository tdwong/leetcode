#!/bin/python

#https://www.hackerrank.com/challenges/30-running-time-and-complexity
"""
# Day 25: Running Time and Complexity
# 
# Objective 
# 
# Today we're learning about running time! Check out the Tutorial tab for learning materials and an instructional video!
# 
# Task 
# 
# A prime is a natural number greater than 1 that has no positive divisors other than 1 and
# itself. Given a number, n, determine and print whether it's "Prime" or "Not prime".
# 
# Note: If possible, try to come up with a O(sqrt(n)) primality algorithm, or see what sort of
# optimizations you come up with for an O(n) algorithm. Be sure to check out the Editorial after
# submitting your code!
# 
# Input Format
# 
# The first line contains an integer, T, the number of test cases. 
# Each of the T subsequent lines contains an integer, n, to be tested for primality.
# 
# Constraints
# 
#     * 1 <= T <= 30
#     * 1 <= n <= 2 x 10**9
# 
# Output Format
# 
# For each test case, print whether n is "Prime" or "Not prime" on a new line.
# 
# Sample Input
# 
#     3
#     12
#     5
#     7
# 
# Sample Output
# 
#     Not prime
#     Prime
#     Prime
# 
# Explanation
# 
# Test Case 0: n = 12. 
# 12 is divisible by numbers other than 1 and itself (i.e.: 2, 3, 6), so we print "No prime" on a new line.
# 
# Test Case 1: n = 5. 
# 5 is only divisible 1 and itself, so we print "Prime" on a new line.
# 
# Test Case 2: n = 7. 
# 7 is only divisible 1 and itself, so we print "Prime" on a new line.
#  
"""

#// ---------------------------- locked code below ------------------------------

#// ---------------------------- locked code above ------------------------------

###################################################################
print "to run: python ./day-24-more-linked-list.py < day-24-more-linked-list.txt"
###################################################################

# Enter your code here. Read input from STDIN. Print output to STDOUT

from math import sqrt,ceil

primes=[2]

def IsPrime(n):
    # corner case:
    if n==1: return False
    if n==2: return True
    # 1. brute-force
    """
    for f in xrange(2, int(sqrt(n))+1):
        if n%f == 0: return False
    return True
    """
    # 2. with some smart
    """
#    print "int(sqrt(",n,")):", int(sqrt(n))
    if n%2 == 0: return False
    for f in xrange(3, int(sqrt(n)+1), 2):
        if n%f == 0: return False
    return True
    """
    # 3. with more smart (requires the global primes[])
    """
    global primes
#    print "int(sqrt(",n,")):", int(sqrt(n))
    if n%2 == 0: return False
    for f in xrange(3, int(sqrt(n)+1), 2):
        # fine all primes smaller than sqrt(n)
        if IsPrime(f): primes += [f]
#    print "primes:", primes
    for p in primes:
        if n%p == 0: return False
    return True
    """
    # 4. with even more smart (requires the global primes[], reuse established primes[])
#    """
    global primes
#    print "int(sqrt(",n,")):", int(sqrt(n)), "primes=", primes
    if n%2 == 0: return False
    startValue = (primes[len(primes)-1], 3) [ len(primes)==1 ]       # (FalseVale,TrueValue) [ expression ]
        #~ if len(primes)==1: startValue=3
        #~ else: startValue = primes[len(primes)-1]
    for f in xrange(startValue, int(sqrt(n)+1), 2):
#        print "startValue=", startValue, "f=", f
        # fine all primes smaller than sqrt(n)
        if IsPrime(f): primes += [f]
#    print "primes:", primes
    for p in primes:
        if n%p == 0: return False
    return True
#    """


T=int(input())
for i in xrange(T):
    n=int(input())
    #
#    print "primes:", primes
#    print "len(primes)", len(primes)
    if IsPrime(n)==True: print "Prime"
    else: print "Not prime"


#// ---------------------------- locked code below ------------------------------

