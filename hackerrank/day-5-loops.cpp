//https://www.hackerrank.com/challenges/30-loops
/*
# Day 5: Loops
# 
# Objective 
# 
# In this challenge, we're going to use loops to help us do some simple math. Check out the Tutorial tab to learn more.
# 
# Task 
# 
# Given an integer, n, print its first 10 multiples. Each multiple n x i (where 1 <= i <= 10) should be printed on a new line
# in the form: n x i = result.
# 
# Input Format
# 
# 	A single integer, n.
# 
# Constraints
# 
# 	* 2 <= n <= 20
# 
# Output Format
# 
# 	Print 10 lines of output; each line i (where 1 <= i <= 10) contains the result of n x i in the form: 
# 	n x i = result.
# 
# Sample Input
# 
# 	2
# 
# Sample Output
# 
# 	2 x 1 = 2
# 	2 x 2 = 4
# 	2 x 3 = 6
# 	2 x 4 = 8
# 	2 x 5 = 10
# 	2 x 6 = 12
# 	2 x 7 = 14
# 	2 x 8 = 16
# 	2 x 9 = 18
# 	2 x 10 = 20
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
    int n;
    cin >> n;

	for (int ix = 1; ix <= 10; ix++) { cout << n << " x " << ix << " = " << n*ix << endl; }
    return 0;
}
