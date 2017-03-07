//https://www.hackerrank.com/challenges/30-review-loop
/*
# Day 6: Let's Review
# 
# Objective 
# 
# Today we're expanding our knowledge of Strings and combining it with what we've already learned
# about loops. Check out the Tutorial tab for learning materials and an instructional video!
# 
# Task 
# 
# Given a string, S, of length N that is indexed from 0 to N-1, print its even-indexed and
# odd-indexed characters as 2 space-separated strings on a single line (see the Sample below for
# more detail).
# 
# Note: 0 is considered to be an even index.
# 
# Input Format
# 
# The first line contains an integer, T (the number of test cases). 
# Each line i of the T subsequent lines contain a String, S.
# 
# Constraints
# 
# 	* 1 <= T <= 10
# 	* 2 <= length of S <= 10000
# 
# Output Format
# 
# For each String Sj (where 0 <= j <= T-1), print Sj's even-indexed characters, followed by a
# space, followed by Sj's odd-indexed characters.
# 
# Sample Input
# 
# 	2
# 	Hacker
# 	Rank
# 
# Sample Output
# 
# 	Hce akr
# 	Rn ak
# 	Explanation
# 
# Test Case 0:  S = "Hacker"
# 	 
# 	S[0] = "H" 
# 	S[1] = "a" 
# 	S[2] = "c" 
# 	S[3] = "k" 
# 	S[4] = "e" 
# 	S[5] = "r" 
# 	 
# 	The even indices are 0, 2, and 6 and the odd indices are 1, 3, and 5. We then print a
# 	single line of 2 space-separated strings; the first string contains the ordered characters
# 	from S's even indices (Hce), and the second string contains the ordered characters from
# 	S's odd indices (akr).
# 
# Test Case 1:  S = "Rank"
# 	 
# 	S[0] = "R"
# 	S[1] = "a"
# 	S[2] = "n"
# 	S[3] = "k"
# 	 
# 	The even indices are 0 and 2, and the odd indices are 1 and 3. We then print a single
# 	line of 2 space-separated strings; the first string contains the ordered characters
# 	from S's even indices (Rn), and the second string contains the ordered characters from
# 	S's odd indices (ak).
# 
*/

package main
import (
	"fmt"
	//"os"
	//"bufio"
	"runtime"
)

func main() {
 //Enter your code here. Read input from STDIN. Print output to STDOUT
	var T int
	fmt.Scanf("%v\n", &T)
	//fmt.Println(T)
	//reader := bufio.NewReader(os.Stdin)
	for i:=0; i<T; i++ {
		//str,_ := reader.ReadString('\n');
		var str string
			// NOTE: parse address of str to fmt.Scanf()
		fmt.Scanf("%s", &str)
//
//https://play.golang.org/p/SfMA3srmVI
//
			// convert string into a []byte slice
			//
		bytes := make([]byte, len(str))
		copy(bytes, str)
			// or string to array
			////	var arr [len(str)]byte
			////	copy(arr[:], str)
		//fmt.Println(bytes)
	/*---
		for j:=0; j<len(str); j++ {
			fmt.Printf("%c.", bytes[j]);
		}
		fmt.Println()
	---*/
		for j:=0; j<len(str); j+=2 {
			fmt.Printf("%c", bytes[j]);
		}
		fmt.Printf(" ");
		for j:=1; j<len(str); j+=2 {
			fmt.Printf("%c", bytes[j]);
		}
		fmt.Println()

		// only for Windows environment
		// eat up the final new line (\n\r)
		if runtime.GOOS == "windows" {
			var z string
			fmt.Scanln(&z)
		}


	}	// for i:=0; i<T; i++
}

