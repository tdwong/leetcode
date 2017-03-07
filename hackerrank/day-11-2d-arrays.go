//https://www.hackerrank.com/challenges/30-2d-arrays
/*
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
*/

package main
import "fmt"

func main() {
 //Enter your code here. Read input from STDIN. Print output to STDOUT

	var ar [6][6]int

	for i:=0;i<6;i++ {
		for j:=0;j<6;j++ {
			//var n int
			fmt.Scanf("%v",&ar[i][j])
		}
	}

	fmt.Println(ar)

	sum := 0
	largestSum := 0
	for i:=0;i<4;i++ {
		for j:=0;j<4;j++ {
			sum = ar[i][j]+ar[i][j+1]+ar[i][j+2] +
					ar[i+1][j+1] +	
					ar[i+2][j]+ar[i+2][j+1]+ar[i+2][j+2]
			// i==0 && j==0 : always assign largestSum in the very first iteration
			if i==0 && j==0 { largestSum = sum }
			if sum>largestSum { largestSum = sum }
		}
	}
	if sum>largestSum { largestSum = sum }

	fmt.Println(largestSum)

}

