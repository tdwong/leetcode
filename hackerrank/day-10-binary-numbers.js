//https://www.hackerrank.com/challenges/30-binary-numbers
/*
# Day 10: Binary Numbers
# 
# Objective 
# 
# Today, we're working with binary numbers. Check out the Tutorial tab for learning materials and an instructional video!
# 
# Task 
# 
# Given a base-10 integer, n, convert it to binary (base-2). Then find and print the base-10
# integer denoting the maximum number of consecutive 1's in n's binary representation.
# 
# Input Format
# 
# 	A single integer, n.
# 
# Constraints
# 
# 	* 1 <= n <= 10**6
# 
# Output Format
# 
# 	Print a single base-10 integer denoting the maximum number of consecutive 1's in the binary representation of n.
# 
# Sample Input 1
# 
# 	5
# 
# Sample Output 1
# 
# 	1
# 
# Sample Input 2
# 
# 	13
# 
# Sample Output 2
# 
# 	2
# 
# Explanation
# 
# Sample Case 1: 
# The binary representation of 5 is 101, so the maximum number of consecutive 1's is 1.
# 
# Sample Case 2: 
# The binary representation of 13 is 1101 , so the maximum number of consecutive 1's is 2.
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

//###################################################################
console.log("provide an integer n: ");
//###################################################################

function main() {
    var n = parseInt(readLine());

	// identical (exactly same) as cpp implementation
	var curCount = 0, maxCount = 0;
	while (n>0) {
		if ((n&1)==1) { curCount++; }
		else {
			if (curCount > maxCount) { maxCount = curCount; }
			curCount = 0;
		}
		n >>= 1;
	}
	console.log((curCount>maxCount)?curCount:maxCount);
}

