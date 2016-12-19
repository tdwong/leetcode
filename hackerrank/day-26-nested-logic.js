//#https://www.hackerrank.com/challenges/30-nested-logic
/*
# Day 26: Nested Logic
# 
# Objective 
# 
Today's challenge puts your understanding of nested conditional statements to the test. You
# already have the knowledge to complete this challenge, but check out the Tutorial tab for a
# video on testing!
# 
# Task 
# 
# Your local library needs your help! Given the expected and actual return dates for a library
# book, create a program that calculates the fine (if any). The fee structure is as follows:
# 
# 1. If the book is returned on or before the expected return date, no fine will be charged (i.e.: fine = 0).
# 2. If the book is returned after the expected return day but still within the same calendar
#    month and year as the expected return date, fine = 15 Hackos x (the number of days late).
# 3. If the book is returned after the expected return month but still within the same calendar
#    year as the expected return date, the fine = 500 Hackos x (the number of months late).
# 4. If the book is returned after the calendar year in which it was expected, there is a fixed fine of 10000 Hackos..
# 
# Input Format
# 
# The first line contains 3 space-separated integers denoting the respective day, month, and year
# on which the book was actually returned.
# The second line contains 3 space-separated integers denoting the respective day, month, and year
# on which the book was expected to be returned (due date).
# 
# Constraints
# 
#     * 1 <= D <= 31
#     * 1 <= M <= 12
#     * 1 <= Y <= 3000
#     * It is guaranteed that the dates will be valid Gregorian calendar dates.
# 
# Output Format
# 
# Print a single integer denoting the library fine for the book received as input.
# 
# Sample Input
# 
#     9 6 2015
#     6 6 2015
# 
# Sample Output
# 
#     45
# 
# Explanation
# 
# Given the following return dates: 
# 
# Actual:   D(a) = 9, M(a) = 6, Y(a) = 2015
# Expected: D(e) = 6, M(e) = 6, Y(e) = 2015
# 
# Because Y(e)===Y(a), we know it is less than a year late. 
# Because M(e)===M(a), we know it's less than a month late. 
# Because D(e) < D(a), we know that it was returned late (but still within the same month and year).
# 
# Per the library's fee structure, we know that our fine will be 15 Hackos x (# days late). We
# then print the result of 15 x (D(a) - D(e)) = 15 x (9 - 6) = 45 as our output.
# 
# 
*/

// ---------------------------- locked code below ------------------------------

function processData(input) {

// ---------------------------- locked code above ------------------------------

//###################################################################
console.log( "to run: python ./day-26-nested-logic.py < day-26-nested-logic.txt" );
//###################################################################

//console.log( "input.length="+input.length+", input="+input);

    //Enter your code here

// getting input values
	var lines = input.split('\n');
	var A = lines[0].split(' ');
	var Da=parseInt(A[0]), Ma=parseInt(A[1]), Ya=parseInt(A[2]);
	var E = lines[1].split(' ');
	var De=parseInt(E[0]), Me=parseInt(E[1]), Ye=parseInt(E[2]);

//console.log( "A:"+A+",E:"+E );

	var fine = 0;

	// exact SAME CODE as in day-26-nested-logic.cpp
//console.log("Ya=",Ya,",Ye=",Ye,"Ya>Ye?",(Ya>Ye));
	if (Ya>Ye) {
		fine=10000;
	}
	else if (Ya==Ye) {
		//# check month
//console.log("Ma=",Ma,",Me=",Me,"Ma>Me?",(Ma>Me));
		if (Ma>Me) {
			fine=500*(Ma-Me);
		}
		else if (Ma==Me) {
			//# check day
//console.log("Da=",Da,",De=",De,"Da>De?",(Da>De));
			if (Da>De) {
				fine=15*(Da-De);
			}
		}
	}

	process.stdout.write(fine+"\n");


// ---------------------------- locked code below ------------------------------

} 

process.stdin.resume();
process.stdin.setEncoding("ascii");
_input = "";
process.stdin.on("data", function (input) {
    _input += input;
});

process.stdin.on("end", function () {
   processData(_input);
});

