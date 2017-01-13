#!/bin/python

#https://www.hackerrank.com/challenges/pangrams
"""
# 
# Roy wanted to increase his typing speed for programming contests. So, his friend advised him
# to type the sentence "The quick brown fox jumps over the lazy dog" repeatedly, because it is a
# pangram. (Pangrams are sentences constructed by using every letter of the alphabet at least once.)
# 
# After typing the sentence several times, Roy became bored with it. So he started to look for other pangrams.
# 
# Given a sentence s, tell Roy if it is a pangram or not.
# 
# Input Format
# 
# Input consists of a string s.
# 
# Constraints 
# 
#     * Length of s can be at most 10**3 (1 <= |s| <= 10**3) and it may contain spaces, lower case and
#      upper case letters. Lower-case and upper-case instances of a letter are considered the same.
# 
# Output Format
# 
# Output a line containing "pangram" if s is a pangram, otherwise output "not pangram".
# 
# Sample Input
# 
# Input #1
# 
#     We promptly judged antique ivory buckles for the next prize    
# 
# Input #2
# 
#     We promptly judged antique ivory buckles for the prize    
# 
# Sample Output
# 
# Output #1
# 
#     pangram
# 
# Output #2
# 
#     not pangram
# 
# Explanation
# 
# In the first test case, the answer is pangram because the sentence contains all the letters of the English alphabet.
# 
"""

# Enter your code here. Read input from STDIN. Print output to STDOUT

import string
import itertools

s=raw_input().strip().lower()

pangram=False
l=list(s)
g=list(itertools.groupby(l))

zs=[]
# create the zs
for e in g:
    #print "e[0]=",e[0]
    if e[0] not in zs:
        zs += [e[0]]

#print "zs=",zs
zs.sort()
#print "zs.sorted=",zs

# check all characters are covered
u=' '+string.ascii_lowercase
"""
for a in u:
    if a not in zs:
        pangram=False
        break
#
if pangram==True:
    print "pangram"
else:
    print "not pangram"
"""

if u=="".join(zs):
    print "pangram"
else:
    print "not pangram"

