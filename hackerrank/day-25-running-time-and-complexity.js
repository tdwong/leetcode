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

// ---------------------------- locked code below ------------------------------

// ---------------------------- locked code above ------------------------------

//###################################################################
console.log( "to run: ./day-24-more-linked-list < day-24-more-linked-list.txt" );
//###################################################################


// initialize with one prime
//
var primes=[2];

function processData(input) {
    //Enter your code here
//	console.log( "input=" + input );
	input_lines = input.split('\n');
	//
	for (var ix=1; ix<=parseInt(input_lines[0]); ix++) {
		var isPrime = function (n) {
				// see IsPrime(n) function in day-25-running-time-and-complexity.py for all variants
				//
				// only the smartest approach is implemented here

			// corner cases
			if (n==1) { return false; }
			if (n==2) { return true;  }
			if ((n%2)==0) { return false;  }

//			console.log( "isPrime(n)=" + n );

			// first find all primes up to sqrt(n)
			var startValue = (primes.length==1) ? 3 : primes[primes.length-1];
			for (var ip=startValue; ip < (Math.round(Math.sqrt(n))+1); ip+=2)	// step-up 2 number a time to skip even numbers
			{
				if (isPrime(ip) == true) { primes.push(ip); }
			}
			// check n against all primes[]
			for (var ip = 0; ip < primes.length; ip++) {
				if ((n%primes[ip])==0) { return false; }
			}
			return true;	
		};

		if (isPrime(parseInt(input_lines[ix])) == true) {
			process.stdout.write("Prime");
		} else {
			process.stdout.write("Not prime");
		}
		process.stdout.write("\n");

	}
} 


// ---------------------------- locked code below ------------------------------

process.stdin.resume();
process.stdin.setEncoding("ascii");
_input = "";
process.stdin.on("data", function (input) {
    _input += input;
});

process.stdin.on("end", function () {
   processData(_input);
});


