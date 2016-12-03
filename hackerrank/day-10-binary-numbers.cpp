//https://www.hackerrank.com/challenges/30-binary-numbers
/*
# Day 10: Binary Numbers
# 
# Objective 
# 
# Today, we're working with binary numbers. Check out the Tutorial tab for learning materials and an instructional video!
# 
# Task 
# 
# Given a base-10 integer, n, convert it to binary (base-2). Then find and print the base-10
# integer denoting the maximum number of consecutive 1's in n's binary representation.
# 
# Input Format
# 
# 	A single integer, n.
# 
# Constraints
# 
# 	* 1 <= n <= 10**6
# 
# Output Format
# 
# 	Print a single base-10 integer denoting the maximum number of consecutive 1's in the binary representation of n.
# 
# Sample Input 1
# 
# 	5
# 
# Sample Output 1
# 
# 	1
# 
# Sample Input 2
# 
# 	13
# 
# Sample Output 2
# 
# 	2
# 
# Explanation
# 
# Sample Case 1: 
# The binary representation of 5 is 101, so the maximum number of consecutive 1's is 1.
# 
# Sample Case 2: 
# The binary representation of 13 is 1101 , so the maximum number of consecutive 1's is 2.
# 
*/


#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

int main(){

//###################################################################
printf("provide an integer n: ");
//###################################################################

    int n;
    cin >> n;

	int curCount = 0, maxCount = 0;

	while (n>0) {
		if ((n&1)==1) { curCount++; }
		else {
			if (curCount > maxCount) { maxCount = curCount; }
			curCount = 0;
		}
		n >>= 1;
	}
	// printf("%d\n", (curCount>maxCount)?curCount:maxCount);
	cout << ((curCount>maxCount)?curCount:maxCount) << endl;

    return 0;
}

