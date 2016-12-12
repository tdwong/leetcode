//#https://www.hackerrank.com/challenges/30-interfaces
/*
# Day 19: Interfaces
# 
# Objective 
# 
# Today, we're learning about Interfaces. Check out the Tutorial tab for learning materials and an instructional video!
# 
# Task 
# 
# The AdvancedArithmetic interface and the method declaration for the abstract int divisorSum(int n) method are provided
# for you in the editor below. Write the Calculator class, which implements the AdvancedArithmetic interface. The
# implementation for the divisorSum method must be public and take an integer parameter, n, and return the sum of
# all its divisors.
# 
# Note: Because we are writing multiple classes in the same file, do not use an access modifier (e.g.: public) in your
# class declaration (or your code will not compile); however, you must use the public access modifier before your method
# declaration for it to be accessible by the other classes in the file.
# 
# Input Format
# 
# 	A single line containing an integer, n.
# 
# Constraints
# 
# 	* 1 <= n <= 1000
# 
# Output Format
# 
# 	You are not responsible for printing anything to stdout. The locked Solution class in the editor below will call your
# 	code and print the necessary output.
# 
# Sample Input
# 
# 	6
# 
# Sample Output
# 
# 	I implemented: AdvancedArithmetic
# 	12
# 
# Explanation
# 
# The integer 6 is evenly divisible by 1, 2, 3, and 6. Our divisorSum method should return the sum of these numbers, which
# is 1 + 2 + 3 + 6 = 12. The Solution class then prints "I implemented: AdvancedArithmetic" on the first line, followed by
# the sum returned by divisorSum (which is 12) on the second line.
# 
*/


// ---------------------------- locked code below ------------------------------
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
class AdvancedArithmetic{
    public:
        virtual int divisorSum(int n)=0;
};
// ---------------------------- locked code above ------------------------------

int gDebug = 1;
//Write your code here
class Calculator : public AdvancedArithmetic {
	public:
        int divisorSum(int n) {
///			int sum = 1;
///			if (n != 1) { sum += n; }
			if (n==1) { return 1; }
			int sum = 0;
			if (gDebug) cout << "2.." << (int)(sqrt((float)n)) << endl;
			for (int ix = 1; ix <= (int)(sqrt((float)n)); ix++) {
				if (gDebug) cout << "ix= " << ix << ", sum= " << sum << endl;
				if ((n%ix) == 0) {
					sum += ix;
					int dividor = (n/ix);
					if (dividor != ix) {
						sum += (n/ix);
					}
					if (gDebug) cout << "ix= " << ix << ", (n/ix)=" << (n/ix) << ", sum= " << sum << endl;
				}
			}
			return sum;
		}
};

/* testcases
 * 
	6		-> 1x6, 2x3			-> 1+6+2+3 = 12
	1		-> 1
	20		-> 1x20, 2x10, 4x5	-> 1+20+2+10+4+5 = 42
	9		-> 1x9, 3x3			-> 1+9+3+3 = 13
	16		-> 1x16, 2x8, 4x4	-> 1+16+2+8+4= 31
 *
 */

// ---------------------------- locked code below ------------------------------

int main() {

//###################################################################
cout << "provide any integer value for AdvancedArithmetic calculation: ";
//###################################################################

    int n;
    cin >> n;
    AdvancedArithmetic *myCalculator = new Calculator(); 
    int sum = myCalculator->divisorSum(n);
    cout << "I implemented: AdvancedArithmetic\n" << sum;

//
	cout << endl;
//

    return 0;
}

