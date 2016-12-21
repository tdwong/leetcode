//#https://www.hackerrank.com/challenges/30-regex-patterns
/*
# Day 28: RegEx, Patterns, and Intro to Databases
# 
# Objective 
# 
# Today, we're working with regular expressions. Check out the Tutorial tab for learning materials
# and an instructional video!
# 
# Task 
# 
# Consider a database table, Emails, which has the attributes First Name and Email ID. Given N
# rows of data simulating the Emails table, print an alphabetically-ordered list of people whose
# email address ends in @gmail.com.
# 
# Input Format
# 
# The first line contains an integer, N, total number of rows in the table. 
# Each of the N subsequent lines contains 2 space-separated strings denoting a person's first name and email ID, respectively.
# 
# Constraints
# 
#     * 2 <= N <= 30
#     * Each of the first names consists of lower case letters [a-z] only.
#     * Each of the email IDs consists of lower case letters [a-z], @ and . only.
#     * The length of the first name is no longer than 20.
#     * The length of the email ID is no longer than 50.
# 
# Output Format
# 
# Print an alphabetically-ordered list of first names for every user with a gmail account. Each
# name must be printed on a new line.
# 
# Sample Input
# 
#     6
#     riya riya@gmail.com
#     julia julia@julia.me
#     julia sjulia@gmail.com
#     julia julia@gmail.com
#     samantha samantha@gmail.com
#     tanya tanya@gmail.com
# 
# Sample Output
# 
#     julia
#     julia
#     riya
#     samantha
#     tanya
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

///
#include <regex>
#include <string.h>

std::multiset<std::string> result;
///

using namespace std;


int main(){

// ---------------------------- locked code above ------------------------------

//###################################################################
cout << "to run: python ./day-28-regex-patterns.py < day-28-regex-patterns.txt" << endl;
//###################################################################

    int N;
    cin >> N;
    for(int a0 = 0; a0 < N; a0++){
        string firstName;
        string emailID;
        cin >> firstName >> emailID;

/* The correct solution is to use C++ regex  
 * 
 * however, regex doesNOT work with g++ 4..8.4 on bash for ubuntu for windows 10
 */
//		std::regex pattern ("@gmail.com$");
//		bool m = std::regex_search (emailID,pattern);

		char *pattern = (char*) "@gmail.com";
		bool m = (strstr(emailID.c_str(), pattern) != NULL);
		if (m == true) {
			// cout << "emailID: " << emailID << endl;
			result.insert(firstName);
		}
    }

	for (std::multiset<std::string>::iterator it = result.begin(); it != result.end(); it++)
	{
		cout << *it << endl;
	}


// ---------------------------- locked code below ------------------------------

    return 0;
}

