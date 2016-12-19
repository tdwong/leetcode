//#https://www.hackerrank.com/challenges/30-running-time-and-complexity
/*
# Day 25: Running Time and Complexity
# 
# Objective 
# 
# Today we're learning about running time! Check out the Tutorial tab for learning materials and an instructional video!
# 
# Task 
# 
# A prime is a natural number greater than 1 that has no positive divisors other than 1 and
# itself. Given a number, n, determine and print whether it's "Prime" or "Not prime".
# 
# Note: If possible, try to come up with a O(sqrt(n)) primality algorithm, or see what sort of
# optimizations you come up with for an O(n) algorithm. Be sure to check out the Editorial after
# submitting your code!
# 
# Input Format
# 
# The first line contains an integer, T, the number of test cases. 
# Each of the T subsequent lines contains an integer, n, to be tested for primality.
# 
# Constraints
# 
#     * 1 <= T <= 30
#     * 1 <= n <= 2 x 10**9
# 
# Output Format
# 
# For each test case, print whether n is "Prime" or "Not prime" on a new line.
# 
# Sample Input
# 
#     3
#     12
#     5
#     7
# 
# Sample Output
# 
#     Not prime
#     Prime
#     Prime
# 
# Explanation
# 
# Test Case 0: n = 12. 
# 12 is divisible by numbers other than 1 and itself (i.e.: 2, 3, 6), so we print "No prime" on a new line.
# 
# Test Case 1: n = 5. 
# 5 is only divisible 1 and itself, so we print "Prime" on a new line.
# 
# Test Case 2: n = 7. 
# 7 is only divisible 1 and itself, so we print "Prime" on a new line.
#  
*/

#// ---------------------------- locked code below ------------------------------

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


#// ---------------------------- locked code above ------------------------------

// initialize with one prime
//
vector<int> primes(1, 2);		// one int with 2 : the first primary

bool IsPrime(int n)
{
	// see IsPrime(n) function in day-25-running-time-and-complexity.py for all variants
	//
	// only the smartest approach is implemented here

	// corner case:
	if (n==1) { return false; }
	if (n==2) { return true; }

	// 4. with even more smart (requires the global primes[], reuse established primes[])
//#	print "int(sqrt(",n,")):", int(sqrt(n)), "primes=", primes
//	cout << "int(sqrt("<<n<<")):"<< int(sqrt(n)) <<endl;//<< "primes="<< primes

	if (n%2 == 0) { return false; }

	// determine which value to start (with IsPrime checking)
	int startValue = 3;
	if (primes.size()!=1) {
		// primes[] contains more than just initial value
		startValue = primes[primes.size()-1];
		// the last value is gauranteed to be non-even
	}
	else { startValue = 3; }

	// now check up to sqrt(n) for any prime value(s)
		// step every 2 number to skip all even numbers
	for (int ix=startValue; ix < ((int)sqrt(n)+1); ix+=2) {
//#		print "startValue=", startValue, "f=", f
//		cout  << "startValue=" << startValue << ", ix=" << ix << endl;
		if (IsPrime(ix) == true) {
			// add to our primes[]
			primes.push_back(ix);
		}
	}
//#	print "primes:", primes

	// now compare the given value with known (collected) prime numbers
	for (int ix=0; ix < primes.size(); ix++) {
		if ((n%primes[ix]) == 0) { return false; }
	}
	//
	return true;
}

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   

//###################################################################
cout << "to run: ./day-24-more-linked-list < day-24-more-linked-list.txt" << endl;
//###################################################################

#if 1
	int T; cin >> T;

	int n;
	while (T-->0) {
		cin >> n;
		//cout << "input: " << n << endl;
		if (IsPrime(n)) { cout << "Prime" << endl; }
		else { cout << "Not prime" << endl; }
	}
#else
	int T,data;
	cin>>T;
	while(T-->0){
		cin>>data;
		/*
		if (IsPrime(data)) { cout << "Prime" << endl; }
		else { cout << "Not prime" << endl; }
		*/
		cout << (IsPrime(data)?"Prime":"Not prime") << endl;
	}
#endif

#// ---------------------------- locked code below ------------------------------

    return 0;
}

