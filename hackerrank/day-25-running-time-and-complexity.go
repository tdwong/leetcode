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

package main
import (
	"fmt"
	"math"
)

	//** declare primes as a global variable - slice of int
var primes []int

func main() {
 //Enter your code here. Read input from STDIN. Print output to STDOUT

		//** initialize primes - slice of int
	primes = []int {2}

	var T int;
	fmt.Scanf("%v\n", &T)

	for i:=0;i<T;i++ {
		var n int;
		fmt.Scanf("%v\n", &n)

		if (IsPrime(n)) {
			fmt.Println("Prime")
		} else {
			fmt.Println("Not prime")
		}
	}
}

func IsPrime(n int) bool {

	// see IsPrime(n) function in day-25-running-time-and-complexity.py for all variants
	//
	// only the smartest approach is implemented here

	// corner cases
	if n==1 { return false; }
	if n==2 { return true; }

	// even number
	if (n%2)==0 { return false; }

	// 4. with even more smart (requires the global primes[], reuse established primes[])

	var startValue int
		// determine which value to start (for IsPrime checking)
		if len(primes)==1 {
			startValue = 3
		} else {
			// primes[] contains more than just initial values
			// we can start from largest known prime
			startValue = primes[len(primes)-1];
		}

	// now check up to sqrt(n) for any prime value(s)
		// step every 2 number to skip all even numbers
	upper := int(math.Sqrt(float64(n)))
	for ix:=startValue;ix<(upper+1);ix+=2 {
		if (IsPrime(ix) == true) {
			// add to our primes[]
			primes = append(primes, ix)
		}
	}
	//fmt.Println("primes:",primes)

	// now compare the given value with known (collected) prime numbers
	for ix:=0;ix<len(primes);ix++ {
		if (n%primes[ix]) == 0 { return false }
	}
	return true

}
