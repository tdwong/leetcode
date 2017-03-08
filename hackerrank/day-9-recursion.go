//https://www.hackerrank.com/challenges/30-recursion
/*
# Day 9: Recursion
# 
# Task 
# 
# Write a factorial function that takes a positive integer, N as a parameter and prints the result of N! (N factorial).
# 
# Note: If you fail to use recursion or fail to name your recursive function factorial or Factorial, you will get a score of 0.
# 
# Input Format
# 
# A single integer, N (the argument to pass to factorial).
# 
# Constraints
# 
# 	* 2 <= N <= 12
# 
# Your submission must contain a recursive function named factorial.
# 
# Output Format
# 
# Print a single integer denoting .
# 
# Sample Input
# 
# 	3
# 
# Sample Output
# 
# 	6
# 
*/

package main

import "fmt"

func main() {

	var n int
	fmt.Scanf("%v\n", &n)

	fmt.Printf("%v\n", factorial(n))

}

func factorial(n int) int {
	if n==1 {
		return 1
	} else {
		return n*factorial(n-1)
	}
}
