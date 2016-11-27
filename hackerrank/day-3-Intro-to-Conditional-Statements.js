//https://www.hackerrank.com/challenges/30-conditional-statements
/*
# Day 3: Intro to Conditional Statements
# 
# Objective 
# 
# In this challenge, we're getting started with conditional statements. Check out the Tutorial tab for learning materials and an instructional video!
# 
# Task 
# 
# Given an integer, n, perform the following conditional actions:
# 
# If n is odd, print "Weird"
# If n is even and in the inclusive range of 2 to 5, print "Not Weird"
# If n is even and in the inclusive range of 6 to 20, print "Weird"
# If n is even and greater than 20, print "Not Weird"
# 
# Complete the stub code provided in your editor to print whether or not n is weird.
# 
# Input Format
# 
# 	A single line containing a positive integer, n.
# 
# Constraints
# 
# 	1 <= n <= 100
# 
# Output Format
# 
# 	Print "Weird" if the number is weird; otherwise, print "Not Weird".
# 
# Sample Input 0
# 
# 	3
# 	
# Sample Output 0
# 
# 	Weird
# 	
# Sample Input 1
# 
# 	24
# 	
# Sample Output 1
# 
# 	Not Weird
# 
# Explanation
# 
# Sample Case 0:  n = 3
# 
# 	n is odd and odd numbers are weird, so we print "Weird".
# 
# Sample Case 1:  n = 24
# 	n > 20 and n is even, so it isn't weird. Thus, we print "Not Weird".
#  
*/

process.stdin.resume();
process.stdin.setEncoding('ascii');

var input_stdin = "";
var input_stdin_array = "";
var input_currentline = 0;

process.stdin.on('data', function (data) {
    input_stdin += data;
});

process.stdin.on('end', function () {
    input_stdin_array = input_stdin.split("\n");
    main();    
});

function readLine() {
    return input_stdin_array[input_currentline++];
}

/////////////// ignore above this line ////////////////////

function main() {
    var N = parseInt(readLine());

	//**** IDENTICAL CODE as in cpp solution except using console.log (instead of printf)

	if (N%2) {
		console.log("Weird");
	}
	else {
		if (2 <= N && N <= 5) console.log("Not Weird");
		else if (6 <= N && N <= 20) console.log("Weird");
		else console.log("Not Weird");
	}
}

