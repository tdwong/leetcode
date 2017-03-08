//#https://www.hackerrank.com/challenges/30-bitwise-and
/*
# Day 29: Bitwise AND
# 
# Objective 
# 
# Welcome to the last day! Today, we're discussing bitwise operations. Check out the Tutorial
# tab for learning materials and an instructional video!
# 
# Task 
# 
# Given set S = {1,2,3,...,N}. Find two integers, A and B (where A < B), from set S such that
# the value of A&B is the maximum possible and also less than a given integer, K. In this case,
# & represents the bitwise AND operator.
# 
# Input Format
# 
# The first line contains an integer, T, the number of test cases. 
# Each of the T subsequent lines defines a test case as 2 space-separated integers, N and K, respectively.
# 
# Constraints
# 
#     * 1 <= T <= 10**3
#     * 2 <= N <= 10**3
#     * 2 <= K <= N
# 
# Output Format
# 
# For each test case, print the maximum possible value of A&B on a new line.
# 
# Sample Input
# 
#     3
#     5 2
#     8 5
#     2 2
# 
# Sample Output
# 
#     1
#     4
#     0
# 
*/


package main
import "fmt"

func main() {
 //Enter your code here. Read input from STDIN. Print output to STDOUT

	var t int
	fmt.Scanf("%v\n", &t)

	for ix:=0;ix<t;ix++ {

		var n,k int
		fmt.Scanf("%v %v\n", &n, &k)

		//
		m := 0
		// dataset runs from {1,2,...n}
		for a:=1;a<n;a++ {
			// b>a is one of the requirements
			for b:=a+1;b<=n;b++ {
				ai := a&b
				// (a&b)<k is one of the requirements
				if ai<k && ai>m { m=ai }
			}
		}

		fmt.Println(m)

	}

}


