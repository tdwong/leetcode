//https://www.hackerrank.com/challenges/30-arrays
/*
# Day 7: Arrays
# 
# Objective 
# 
# Today, we're learning about the Array data structure. Check out the Tutorial tab for learning
# materials and an instructional video!
# 
# Task 
# 
# Given an array, A, of N integers, print A's elements in reverse order as a single line of space-separated numbers.
# 
# Input Format
# 
# The first line contains an integer, N (the size of our array). 
# The second line contains N space-separated integers describing array A's elements.
# 
# Constraints
# 
# 	* 1 <= N <= 1000
# 	* 1 <= A[i] <= 10000, where A is the i-th integer in the array.
# 
# Output Format
# 
# Print the elements of array A in reverse order as a single line of space-separated numbers.
# 
# Sample Input
# 
# 	4
# 	1 4 3 2
# 
# Sample Output
# 
# 	2 3 4 1
# 
*/

package main
import (
	"fmt"
	"runtime"
)

func main() {
 //Enter your code here. Read input from STDIN. Print output to STDOUT

	var n int
	fmt.Scanf("%d\n", &n)

	ar := make([]int, n)
	for i:=0;i<n;i++ {
		fmt.Scanf("%v", &ar[i])
	}
	for i:=(n-1);i>=0;i-- {
		fmt.Printf("%v ", ar[i])
	}
	fmt.Println()

	chop()

}

func chop() {
		// only for Windows environment
		// eat up the final new line (\n\r)
		if runtime.GOOS == "windows" {
			var z string
			fmt.Scanln(&z)
		}
}

