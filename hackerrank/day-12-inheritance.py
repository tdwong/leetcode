#!/bin/python

#https://www.hackerrank.com/challenges/30-inheritance
"""
# Day 12: Inheritance
# 
# Objective 
# 
# Today, we're delving into Inheritance. Check out the Tutorial tab for learning materials and an instructional video!
# 
# Task 
# 
# You are given two classes, Person and Student, where Person is the base class and Student is
# the derived class. Completed code for Person and a declaration for Student are provided for
# you in the editor. Observe that Student inherits all the properties of Person.
# 
# Complete the Student class by writing the following:
# 
# 	* A Student class constructor, which has  parameters:
# 		A string, firstName.
# 		A string, lastName.
# 		An integer, id.
# 		An integer array (or vector) of test scores, scores.
# 
# 	* A char calculate() method that calculates a Student object's average and returns the grade
# 	character representative of their calculated average:
# 
# 		// Grading.png
# 		   Grading Scale
# 		-------------------
# 		Letter	Average(a)
# 		-------------------
# 		  O   90 <= a <= 100
# 		  E   80 <= a <  90
# 		  A   70 <= a <  80
# 		  P   55 <= a <  70
# 		  D   40 <= a <  55
# 		  T         a <  40
# 
# Input Format
# 
# The locked stub code in your editor calls your Student class constructor and passes it the
# necessary arguments. It also calls the calculate method (which takes no arguments).
# 
# You are not responsible for reading the following input from stdin: 
# 
# The first line contains firstName, lastName, and id, respectively. The second line contains
# the number of test scores. The third line of space-separated integers describes scores.
# 
# Constraints
# 
# 	* 4 <= |firstName|,|lastName| <= 10
# 	* |id| === 7
# 	* 0 <= score,average <= 100
# 
# Output Format
# 
# This is handled by the locked stub code in your editor. Your output will be correct if your
# Student class constructor and calculate() method are properly implemented.
# 
# Sample Input
# 
# 	Heraldo Memelli 8135627
# 	2
# 	100 80
# 
# Sample Output
# 
# 	Name: Memelli, Heraldo
# 	ID: 8135627
# 	Grade: O
# 
# Explanation
# 
# 	This student had 2 scores to average: 100 and 80. The student's average grade is (100+80)/2 =
# 	90. An average grade of 90 corresponds to the letter grade O, so our calculate() method should
# 	return the character 'O'.
# 
"""


#// ---------------------------- locked code below ------------------------------
class Person:
    def __init__(self, firstName, lastName, idNumber):
        self.firstName = firstName
        self.lastName = lastName
        self.idNumber = idNumber

    def printPerson(self):
        print "Name:", self.lastName + ",", self.firstName
        print "ID:", self.idNumber
#// ---------------------------- locked code above ------------------------------


class Student(Person):
    def __init__(self, firstName, lastName, id, scores):
        self.person = Person(firstName, lastName, id)
        self.scores = scores

    def printPerson(self):
        self.person.printPerson()

    def calculate(self):
        sum = 0
        for score in self.scores: sum += score
        average = sum / len(self.scores)
        if 90 <= average: return 'O'
        elif 80 <= average and average < 90: return 'E'
        elif 70 <= average and average < 80: return 'A'
        elif 55 <= average and average < 70: return 'P'
        elif 40 <= average and average < 55: return 'D'
        else: return 'T'


#// ---------------------------- locked code below ------------------------------

###################################################################
	print "to run: python ./day-12-inheritance.py < day-12-inheritance.txt"
###################################################################

line = raw_input().split()
firstName = line[0]
lastName = line[1]
idNum = line[2]
numScores = int(raw_input()) # not needed for Python
scores = map(int, raw_input().split())
s = Student(firstName, lastName, idNum, scores)
s.printPerson()
print "Grade:", s.calculate()

