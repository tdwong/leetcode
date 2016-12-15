//#https://www.hackerrank.com/challenges/mini-max-sum
/*
# 
# Given five positive integers, find the minimum and maximum values that can be calculated by
# summing exactly four of the five integers. Then print the respective minimum and maximum values
# as a single line of two space-separated long integers.
# 
# Input Format
# 
# A single line of five space-separated integers.
# 
# Constraints
# 
# 	* Each integer is in the inclusive range [1, 10**9].
# 
# Output Format
# 
# Print two space-separated long integers denoting the respective minimum and maximum values that
# can be calculated by summing exactly four of the five integers. (The output can be greater than
# 32 bit integer.)
# 
# Sample Input
# 
# 	1 2 3 4 5
# 
# Sample Output
# 
# 	10 14
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

//########################################################
    console.log( "please enter 5 numbers separated with space: " );
//########################################################

function main() {
    var a_temp = readLine().split(' ');
    var a = parseInt(a_temp[0]);
    var b = parseInt(a_temp[1]);
    var c = parseInt(a_temp[2]);
    var d = parseInt(a_temp[3]);
    var e = parseInt(a_temp[4]);

    var ar=[a,b,c,d,e];
    var sar=ar.sort();
    var min=max=0;
    for (var i=0;i<4;i++) { min+=sar[i]; }
    for (var i=(sar.length-1);i>(sar.length-5);i--) { max+=sar[i]; }
    console.log(min+" "+max);
}

