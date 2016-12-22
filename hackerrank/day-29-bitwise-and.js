//#https://www.hackerrank.com/challenges/30-bitwise-and
/*
# Day 29: Bitwise AND
# 
# Objective 
# 
# Welcome to the last day! Today, we're discussing bitwise operations. Check out the Tutorial
# tab for learning materials and an instructional video!
# 
# Task 
# 
# Given set S = {1,2,3,...,N}. Find two integers, A and B (where A < B), from set S such that
# the value of A&B is the maximum possible and also less than a given integer, K. In this case,
# & represents the bitwise AND operator.
# 
# Input Format
# 
# The first line contains an integer, T, the number of test cases. 
# Each of the T subsequent lines defines a test case as 2 space-separated integers, N and K, respectively.
# 
# Constraints
# 
#     * 1 <= T <= 10**3
#     * 2 <= N <= 10**3
#     * 2 <= K <= N
# 
# Output Format
# 
# For each test case, print the maximum possible value of A&B on a new line.
# 
# Sample Input
# 
#     3
#     5 2
#     8 5
#     2 2
# 
# Sample Output
# 
#     1
#     4
#     0
# 
*/

// ---------------------------- locked code below ------------------------------

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

//###################################################################
console.log( "to run: nodejs ./day-29-bitwise-and.js < day-29-bitwise-and.txt" );
//###################################################################

    var t = parseInt(readLine());
    for(var a0 = 0; a0 < t; a0++){
        var n_temp = readLine().split(' ');
        var n = parseInt(n_temp[0]);
        var k = parseInt(n_temp[1]);

// ---------------------------- locked code above ------------------------------

		var m = 0;
		for (var i=1; i<=n-1; i++) {
			for (var j=i+1; j<=n; j++) {
				var a=i&j;
				if ((a<k) && (a>m)) { m=a; }
			}
		}
		console.log(m);

// ---------------------------- locked code below ------------------------------

    }

}

