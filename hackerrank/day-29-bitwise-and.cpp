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

// ---------------------------- locked code below ------------------------------

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
cout << "to run: ./day-29-bitwise-and < day-29-bitwise-and.txt" << endl;
//###################################################################

    int t;
    cin >> t;

// ---------------------------- locked code above ------------------------------

    for(int a0 = 0; a0 < t; a0++){
        int n;
        int k;
        cin >> n >> k;

		int m = 0;
		for (int i=1; i<=n-1; i++) {
			for (int j=i+1; j<=n; j++) {
				int a=i&j;
				if ((a<k) && (a>m)) { m=a; }
			}
		}
		cout << m << endl;
    }

// ---------------------------- locked code below ------------------------------

    return 0;
}

