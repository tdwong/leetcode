//#https://www.hackerrank.com/challenges/30-exceptions-string-to-integer
/*
# Day 16: Exceptions - String to Integer
# 
# Objective 
# 
# Today, we're getting started with Exceptions by learning how to parse an integer from a string
# and print a custom error message. Check out the Tutorial tab for learning materials and an
# instructional video!
# 
# Task 
# 
# Read a string, S, and print its integer value; if S cannot be converted to an integer, print "Bad String".
# 
# Note: You must use the String-to-Integer and exception handling constructs built into your
# submission language. If you attempt to use loops/conditional statements, you will get a 0 score.
# 
# Input Format
# 
# 	A single string, S.
# 
# Constraints
# 
# 	* 1 <= |S| <= 6, where |S| is the length of string S.
# 	* S is composed of either lowercase letters (a-z) or decimal digits (0-9).
# 
# Output Format
# 
# 	Print the parsed integer value of S, or "Bad String" if S cannot be converted to an integer.
# 
# Sample Input 0
# 
# 	3
# 
# Sample Output 0
# 
# 	3
# 
# Sample Input 1
# 
# 	za
# 
# Sample Output 1
# 
# 	Bad String
# 
# Explanation
# 
# Sample Case 0 contains an integer, so it should not raise an exception when we attempt to
# convert it to an integer. Thus, we print the 3. 
# 
# Sample Case 1 does not contain any integers, so an attempt to convert it to an integer will
# raise an exception. Thus, our exception handler prints "Bad String".
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
console.log("provide a string to be converted: ");
//###################################################################

function main() {
    var S = readLine();

//** this approach uses if (isNaN) to throw exception
//**	the if statement will be detected by hackerrank solution checker and marked fail
	try {
		var n = (function(S) {
			var n = parseInt(S);
			if (isNaN(n)) { throw "Bad String"; }
			return n;
		}) (S);
		console.log(n);
	}
	catch (e) {
		console.log(e);
	}

//https://www.hackerrank.com/challenges/30-exceptions-string-to-integer/forum/comments/128001
//** this approach uses eval to throw exception
//**	the ternary ( ? : ) operation is broken into multiple strings to avoid from been detected
/*
	try {
		var str = 'isNaN(S) ? ';
		var str2= "null.throw : ";
		var answer = eval(str + str2 + S);
		//console.log("answer= "+answer)
	} catch (e) {
		answer = 'Bad String';
		//console.log("answer= "+answer)
	}
	process.stdout.write(answer.toString());
*/


//https://www.hackerrank.com/challenges/30-exceptions-string-to-integer/forum/comments/128001
//** this approach uses .toString() to throw exception
//**	... * 0 + 2) is needed as toString() takes 2.36 as optional radix
/*
	// Hacky way to generate an exception
	var i = 1;
	try {
		i.toString(parseInt(S) ) * 0 + 2); // Fails on NaN
		console.log(S);
	} catch (err) {
		console.log("Bad String");
	}
*/
   
//https://www.hackerrank.com/challenges/30-exceptions-string-to-integer/forum/comments/216625
//** this approach also uses .toString() to throw exception
/*
    try{
        var ans = parseInt(S) || ans.toString();
        console.log(parseInt(S));
    }
    catch(e) {
        console.log("Bad String");
    }
*/
    

}

