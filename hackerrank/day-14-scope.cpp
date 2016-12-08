//https://www.hackerrank.com/challenges/30-scope
/*
# Day 14: Scope
# 
# Objective 
# 
# Today we're discussing scope. Check out the Tutorial tab for learning materials and an instructional video!
# 
# The absolute difference between two integers, a and b, is written as |a-b|. The maximum absolute
# difference between two integers in a set of positive integers, elements, is the largest absolute
# difference between any two integers in elements.
# 
# The Difference class is started for you in the editor. It has a private integer array (elements)
# for storing N non-negative integers, and a public integer (maximumDifference) for storing the
# maximum absolute difference.
# 
# Task 
# 
# Complete the Difference class by writing the following:
# 
# 	* A class constructor that takes an array of integers as a parameter and saves it to the elements instance variable.
# 
# 	* A computeDifference method that finds the maximum absolute difference between any 2 numbers in N and stores it in the maximumDifference instance variable.
# 
# Input Format
# 
# You are not responsible for reading any input from stdin. The locked Solution class in your editor reads in 2 lines of input; the first line contains N, and the second line describes the elements array.
# 
# Constraints
# 
# 	* 1 <= N <= 10
# 	* 1 <= elements[i] <= 100, where 0 <= i <= N-1
# 
# Output Format
# 
# You are not responsible for printing any output; the Solution class will print the value of
# the maximumDifference instance variable.
# 
# Sample Input
# 
# 	3
# 	1 2 5
# 
# Sample Output
# 
# 	4
# 
# Explanation
# 
# The scope of the elements array and maximumDifference integer is the entire class instance. The
# class constructor saves the argument passed to the constructor as the elements instance variable
# (where the computeDifference method can access it).
# 
# To find the maximum difference, computeDifference checks each element in the array and finds the maximum difference between any 2 elements:  
# 
# 	|1 - 2| = 1
# 	|1 - 5| = 4
# 	|2 - 5| = 3
# 
# The maximum of these differences is 4, so it saves the value 4 as the maximumDifference instance
# variable. The locked stub code in the editor then prints the value stored as maximumDifference,
# which is 4.
# 
*/


// ---------------------------- locked code below ------------------------------
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Difference {
    private:
    vector<int> elements;
  
    public:
    int maximumDifference;
// ---------------------------- locked code above ------------------------------

    // Add your code here
    Difference(vector<int> elements) : elements(elements) {}

    void computeDifference() {
        int max = 0, min = 0;
        for (vector<int>::iterator it = elements.begin(); it < elements.end(); it++)
        {
            if (max == 0) { max = *it; }
            else {
                if (*it>max) { max = *it; }
            }
            if (min == 0) { min = *it; }
            else {
                if (*it<min) { min = *it; }
            }
        }
        maximumDifference = max - min;
    }


// ---------------------------- locked code below ------------------------------
}; // End of Difference class

int main() {

//###################################################################
cout << "to run: ./day-14-scope < day-14-scope.txt" << endl;
//###################################################################

    int N;
    cin >> N;
    
    vector<int> a;
    
    for (int i = 0; i < N; i++) {
        int e;
        cin >> e;
        
        a.push_back(e);
    }
    
    Difference d(a);
    
    d.computeDifference();
    
    cout << d.maximumDifference;
    
    return 0;
}

