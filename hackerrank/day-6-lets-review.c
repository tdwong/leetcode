//https://www.hackerrank.com/challenges/30-review-loop
/*
# Day 5: Let's Review
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

#include <stdio.h>
#include <string.h>		// strlen
#include <stdlib.h>		// calloc


int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
	int n;
	scanf("%d\n", &n);
	char str[10001];
	for (int ix=0; ix<n; ix++) {
		scanf("%s\n", str);
		char *es = calloc(strlen(str), 1);
		for (int iz=0, iy=0; iz<strlen(str); iz+=2, iy++) {
			// printf("iz=%d, str[iz]=%c\n", iz, str[iz]);
			es[iy] = str[iz];
		}
		// printf("es=%s\n", es);
		char *os = calloc(strlen(str), 1);
		if (strlen(str) > 1) {
			for (int iz=1, iy=0; iz<strlen(str); iz+=2, iy++) {
				// printf("iz=%d, str[iz]=%c\n", iz, str[iz]);
				os[iy] = str[iz];
			}
			// printf("os=%s\n", os);
		}
		printf("%s %s\n", es, os);
		free(es); free(os);
	}
    return 0;
}

