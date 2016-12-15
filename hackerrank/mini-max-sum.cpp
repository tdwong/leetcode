//#https://www.hackerrank.com/challenges/mini-max-sum
/*
# 
# Given five positive integers, find the minimum and maximum values that can be calculated by
# summing exactly four of the five integers. Then print the respective minimum and maximum values
# as a single line of two space-separated long integers.
# 
# Input Format
# 
# A single line of five space-separated integers.
# 
# Constraints
# 
# 	* Each integer is in the inclusive range [1, 10**9].
# 
# Output Format
# 
# Print two space-separated long integers denoting the respective minimum and maximum values that
# can be calculated by summing exactly four of the five integers. (The output can be greater than
# 32 bit integer.)
# 
# Sample Input
# 
# 	1 2 3 4 5
# 
# Sample Output
# 
# 	10 14
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

bool fncomp (long int lhs, long int rhs) {return lhs<rhs;}

int main(){

//########################################################
    cout << "please enter 5 numbers separated with space: ";
//########################################################

    long int a;
    long int b;
    long int c;
    long int d;
    long int e;
    cin >> a >> b >> c >> d >> e;
    
	bool(*fn_pt)(long int,long int) = fncomp;
    multiset<long int,bool(*)(long int,long int)> ns (fn_pt);
	ns.insert(a);
	ns.insert(b);
	ns.insert(c);
	ns.insert(d);
	ns.insert(e);
    
    long int min,max;
    min = max = 0;
	multiset<long int>::iterator it = ns.begin();
	int min_end = 4;
	int max_start = ns.size()-4;
    for (int ix=0; ix<ns.size(); ix++) {
		if (ix < min_end) min += *it;
		if (ix >= max_start) max += *it;
		it++;
	} 
    
    cout << min << " " << max << endl;
    return 0;
}
