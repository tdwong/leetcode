//https://www.hackerrank.com/challenges/30-arrays
/*
# Day 7: Arrays
# 
# Objective 
# 
# Today, we're learning about the Array data structure. Check out the Tutorial tab for learning
# materials and an instructional video!
# 
# Task 
# 
# Given an array, A, of N integers, print A's elements in reverse order as a single line of space-separated numbers.
# 
# Input Format
# 
# The first line contains an integer, N (the size of our array). 
# The second line contains N space-separated integers describing array A's elements.
# 
# Constraints
# 
# 	* 1 <= N <= 1000
# 	* 1 <= A[i] <= 10000, where A is the i-th integer in the array.
# 
# Output Format
# 
# Print the elements of array A in reverse order as a single line of space-separated numbers.
# 
# Sample Input
# 
# 	4
# 	1 4 3 2
# 
# Sample Output
# 
# 	2 3 4 1
# 
*/

//###################################################################
console.log( "provide # of array element(s), and list of elements in 2nd line:" );

//###################################################################

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
    var n = parseInt(readLine());
    arr = readLine().split(' ');
    arr = arr.map(Number);
	console.log( arr.reverse().join(' ') );
}

