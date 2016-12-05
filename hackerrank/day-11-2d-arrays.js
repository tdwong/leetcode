//https://www.hackerrank.com/challenges/30-2d-arrays
/*
# Day 11: 2D Arrays
# 
# Objective 
# 
# Today, we're building on our knowledge of Arrays by adding another dimension. Check out the
# Tutorial tab for learning materials and an instructional video!
# 
# Context 
# 
# Given a 6x6 2D Array, A:
# 
# 	1 1 1 0 0 0
# 	0 1 0 0 0 0
# 	1 1 1 0 0 0
# 	0 0 0 0 0 0
# 	0 0 0 0 0 0
# 	0 0 0 0 0 0
# 
# We define an hourglass in A to be a subset of values with indices falling in this pattern in A's graphical
# representation:
# 
# 	a b c
# 	  d
# 	e f g
# 
# There are 16 hourglasses in A, and an hourglass sum is the sum of an hourglass' values.
# 
# Task 
# 
# Calculate the hourglass sum for every hourglass in A, then print the maximum hourglass sum.
# 
# Input Format
# 
# There are 6 lines of input, where each line contains 6 space-separated integers describing 2D
# Array A; every value in A will be in the inclusive range of 9 to -9.
# 
# Constraints
# 
# 	* -9 <= A[i][j] <= 9
# 	* 0 <= i,j <= 5
# 
# Output Format
# 
# Print the largest (maximum) hourglass sum found in A.
# 
# Sample Input
# 
# 	1 1 1 0 0 0
# 	0 1 0 0 0 0
# 	1 1 1 0 0 0
# 	0 0 2 4 4 0
# 	0 0 0 2 0 0
# 	0 0 1 2 4 0
# 
# Sample Output
# 
# 	19
# 
# Explanation
# 
# A contains the following hourglasses:
# 
# 	1 1 1   1 1 0   1 0 0   0 0 0
# 	  1       0       0       0
# 	1 1 1   1 1 0   1 0 0   0 0 0
# 
# 	0 1 0   1 0 0   0 0 0   0 0 0
# 	  1       1       0       0
# 	0 0 2   0 2 4   2 4 4   4 4 0
# 
# 	1 1 1   1 1 0   1 0 0   0 0 0
# 	  0       2       4       4
# 	0 0 0   0 0 2   0 2 0   2 0 0
# 
# 	0 0 2   0 2 4   2 4 4   4 4 0
# 	  0       0       2       0
# 	0 0 1   0 1 2   1 2 4   2 4 0
# 
# The hourglass with the maximum sum (19) is:
# 
# 	2 4 4
# 	  2
# 	1 2 4
# 
*/

//###################################################################
	console.log("to run: nodejs day-11-2d-arrays.js < day-11-2d-arrays.txt");
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
    var arr = [];
    for(arr_i = 0; arr_i < 6; arr_i++){
       arr[arr_i] = readLine().split(' ');
       arr[arr_i] = arr[arr_i].map(Number);
    }

	var sum = 0;
	var largestSum = undefined;
	for(var ix = 0; ix < arr.length; ix++) {
		console.log(arr[ix]);
	}
	for(var ix = 0; ix < arr.length-2; ix++)
	{
		for(var iy = 0; iy < arr[ix].length-2; iy++) {
			sum = 
				arr[ix][iy]+arr[ix][iy+1]+arr[ix][iy+2]+
				arr[ix+1][iy+1]+
				arr[ix+2][iy]+arr[ix+2][iy+1]+arr[ix+2][iy+2]; 
			if (largestSum == undefined) {
				largestSum = sum;
			}
			else {
				if (sum > largestSum) { largestSum = sum; }
			}
//			console.log(arr[ix][iy]+" "+arr[ix][iy+1]+" "+arr[ix][iy+2]); 
//			console.log(arr[ix+1][iy]+" "+arr[ix+1][iy+1]+" "+arr[ix+1][iy+2]); 
//			console.log(arr[ix+2][iy]+" "+arr[ix+2][iy+1]+" "+arr[ix+2][iy+2]); 
		}
	}
	console.log(largestSum);

}

