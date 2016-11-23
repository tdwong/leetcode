//https://www.hackerrank.com/challenges/a-very-big-sum?utm_campaign=challenge-recommendation&utm_medium=email&utm_source=24-hour-campaign
/*
#
# Problem:
#
# A Very Big Sum
#	
#	You are given an array of integers of size . You need to print the sum of the elements in the array,
#	keeping in mind that some of those integers may be quite large.
#	
# Input Format
#	The first line of the input consists of an integer . The next line contains  space-separated integers contained in the array.
#	
#	Output Format
#	Print a single value equal to the sum of the elements in the array.
#	
# Constraints 
#	1 <= N <= 10
#	0 <= A[i] <= 10**10 
#	
# Sample Input
#	
#	5
#	1000000001 1000000002 1000000003 1000000004 1000000005
#
# Output
#	
#	5000000015
#
# Note:
#	
#	The range of the 32-bit integer is ((-2)**31) to ((2)**31 -1) or [-2147483648,2147483647].
#
#	When we add several integer values, the resulting sum might exceed the above range. You might need to use
#	long long int in C/C++ or long data type in Java to store such sums.
#	
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main(){
    int n;
    unsigned long long sum = 0LL;
    cin >> n;
    vector<int> arr(n);
    for(int arr_i = 0;arr_i < n;arr_i++){
       cin >> arr[arr_i];
       sum += arr[arr_i];
    }
    cout << sum << endl;
    return 0;
}
