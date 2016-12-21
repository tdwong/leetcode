#!/bin/python

#https://www.hackerrank.com/challenges/30-regex-patterns
"""
# Day 28: RegEx, Patterns, and Intro to Databases
# 
# Objective 
# 
# Today, we're working with regular expressions. Check out the Tutorial tab for learning materials
# and an instructional video!
# 
# Task 
# 
# Consider a database table, Emails, which has the attributes First Name and Email ID. Given N
# rows of data simulating the Emails table, print an alphabetically-ordered list of people whose
# email address ends in @gmail.com.
# 
# Input Format
# 
# The first line contains an integer, N, total number of rows in the table. 
# Each of the N subsequent lines contains 2 space-separated strings denoting a person's first name and email ID, respectively.
# 
# Constraints
# 
#     * 2 <= N <= 30
#     * Each of the first names consists of lower case letters [a-z] only.
#     * Each of the email IDs consists of lower case letters [a-z], @ and . only.
#     * The length of the first name is no longer than 20.
#     * The length of the email ID is no longer than 50.
# 
# Output Format
# 
# Print an alphabetically-ordered list of first names for every user with a gmail account. Each
# name must be printed on a new line.
# 
# Sample Input
# 
#     6
#     riya riya@gmail.com
#     julia julia@julia.me
#     julia sjulia@gmail.com
#     julia julia@gmail.com
#     samantha samantha@gmail.com
#     tanya tanya@gmail.com
# 
# Sample Output
# 
#     julia
#     julia
#     riya
#     samantha
#     tanya
# 
"""

#// ---------------------------- locked code below ------------------------------

#!/bin/python

import sys

###
import re

###################################################################
print "to run: python ./day-28-regex-patterns.py < day-28-regex-patterns.txt"
###################################################################

m=[]
###

N = int(raw_input().strip())
for a0 in xrange(N):
    firstName,emailID = raw_input().strip().split(' ')
    firstName,emailID = [str(firstName),str(emailID)]

#// ---------------------------- locked code above ------------------------------


    if re.search('@gmail.com$',emailID)!=None:
        m += [firstName]

m.sort()
for e in xrange(len(m)):
    print m[e]

#// ---------------------------- locked code below ------------------------------

