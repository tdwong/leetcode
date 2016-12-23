#!/bin/python

#https://www.hackerrank.com/challenges/30-testing
"""
# Day 27: Testing
# 
# Objective 
# 
# This challenge is very different from the others we've completed because it requires you to
# generate a valid test case for a problem instead of solving the problem. There is no input to
# read, you simply have to generate and print test values for the problem that satisfy both the
# problem's Input Format and the criteria laid out in the Task section. Check out the Tutorial
# tab for an instructional video on testing!
# 
# Consider the following problem (but do not solve it):
# 
# ||  Problem Statement
# ||  
# ||  A Discrete Mathematics professor has a class of N students. Frustrated with their lack of
# ||  discipline, the professor decides to cancel class if fewer than k students are present when
# ||  class starts. Given the arrival time of each student, determine if the class is canceled.

# ||  
# ||  Input Format
# ||  
# ||  The first line of input contains t, the number of lectures.
# ||  The information for each lecture spans two lines. The first line has two space-separated
# ||  integers, n (the number of students in the class) and k (the cancelation threshold). The second
# ||  line contains n space-separated integers describing the array of students' arrival times (A =
# ||  a(0),a(1),...,a(N-1)).
# ||  
# ||  Note: Non-positive arrival times (a(i) <= 0) indicate the student arrived early or on time;
# ||  positive arrival times (a(i) > 0) indicate the student arrived a(i) minutes late. If a student
# ||  arrives exactly on time (a(i) = 0), the student is considered to have entered before the class
# ||  started.
# ||  
# ||  Output Format
# ||  
# ||  For each test case, print the word YES if the class is canceled or NO if it is not.
# ||  
# ||  Example
# ||  
# ||  When properly solved, this input:
# ||  
# ||      2
# ||      4 3
# ||      -1 -3 4 2
# ||      4 2
# ||      0 -1 2 1
# ||  
# ||  Produces this output:
# ||  
# ||      YES
# ||      NO
# ||  
# ||  For the first test case, k=3. The professor wants at least 3 students in attendance, but only
# ||  2 arrive on time (-3 and -1). Thus, the class is canceled.
# ||  
# ||  For the second test case, k=2. The professor wants at least 2 students in attendance, and 2 do
# ||  arrive on time (0 and -1). Thus, the class is not canceled.
# ||  
# 
# Task
# 
# Create and print a test case for the problem above that meet the following criteria:
# 
#     * t <= 5
#     * 1 <= n <= 200
#     * 1 <= k <= n
#     * -10**3 <= a(i) <= 10**3, where i is in range (1,n) inclusive
#     * The value of n must be distinct across all the test cases.
#     * Array A must have at least 1 zero, 1 positive integer, and 1 negative integer.
# 
# Scoring
# 
# If you submit x correct test cases, you will earn (20*x)% of the maximum score. You must submit
# 5 test cases to earn the maximum possible score.
# 
# Input Format
# 
# You are not responsible for reading anything from stdin.
# 
# Output Format
# 
# Print 11 lines of output that can be read by the Professor challenge as valid input. Your test
# case must result in the following output when fed as input to the Professor challenge's solution:
# 
#     YES
#     NO
#     YES
#     NO
#     YES
# 
# Explanation
# 
# Your code must print lines of output that follow the Input Format in the Professor challenge
# above. For example, this partial solution to this challenge:
# 
#     print('2')
#     print('4 3')
#     print('-1 -3 4 2')
#     print('5 2')
#     print('0 -1 2 1 4')
# 
# prints the following output that can be used as valid input for the Professor challenge:
# 
#     2
#     4 3
#     -1 -3 4 2
#     5 2
#     0 -1 2 1 4
# 
# When read by a valid solution to the Professor challenge, it produces the following output:
# 
#     YES
#     NO
# 
# You must do something similar to this, except that the test case you develop must meet the
# constraints set in the Task section above.
# 
"""

#// ---------------------------- locked code below ------------------------------

#// ---------------------------- locked code above ------------------------------



"""
# #of_testcases
print 5

# each test case    (YES: cancelled)
    # #of_student, threadhold
print 10, 5
    # student_arrival_time
print 0,0,0,7,5,-9, 1,3, 4, 2

# each test case    (NO: not cancelled)
    # #of_student, threadhold
print 10, 4
    # student_arrival_time
print 0,0,0,0,0,9, -1, -1, 2, 1

# each test case    (YES: cancelled)
    # #of_student, threadhold
print 10, 10
    # student_arrival_time
print 0,0,0,0,0,9, -1,3, 4, 2

# each test case    (NO: not cancelled)
    # #of_student, threadhold
print 10, 9
    # student_arrival_time
print 0,0,0,0,0,-9, -1,3, -4, -2

# each test case    (YES: cancelled)
    # #of_student, threadhold
print 10, 3
    # student_arrival_time
print 0,5,12,5,7,9, -1,-3, 4, 2
"""


testcases = [
	[ 10, 5, [ 0,0,0,7,5,-9, 1,3, 4, 2 ] ],          # (YES: cancelled)
	[ 10, 4, [ 0,0,0,0,0,9, -1, -1, 2, 1 ] ],            # (NO: not cancelled)
	[ 10, 10, [ 0,0,0,0,0,9, -1,3, 4, 2 ] ],             # (YES: cancelled)
	[ 10, 9, [ 0,0,0,0,0,-9, -1,3, -4, -2 ] ],           # (NO: not cancelled)
	[ 10, 3, [ 0,5,12,5,7,9, -1,-3, 4, 2 ] ],            # (YES: cancelled)
]

# #of_testcases
print len(testcases)

# print each test case
for i in xrange(len(testcases)):
    n,k,artime=testcases[i]
    print n,k
    print reduce(lambda x,y: str(x)+' '+str(y), artime)

#// ---------------------------- locked code below ------------------------------

