//#https://www.hackerrank.com/challenges/30-regex-patterns
/*
# Day 28: RegEx, Patterns, and Intro to Databases
# 
# Objective 
# 
# Today, we're working with regular expressions. Check out the Tutorial tab for learning materials
# and an instructional video!
# 
# Task 
# 
# Consider a database table, Emails, which has the attributes First Name and Email ID. Given N
# rows of data simulating the Emails table, print an alphabetically-ordered list of people whose
# email address ends in @gmail.com.
# 
# Input Format
# 
# The first line contains an integer, N, total number of rows in the table. 
# Each of the N subsequent lines contains 2 space-separated strings denoting a person's first name and email ID, respectively.
# 
# Constraints
# 
#     * 2 <= N <= 30
#     * Each of the first names consists of lower case letters [a-z] only.
#     * Each of the email IDs consists of lower case letters [a-z], @ and . only.
#     * The length of the first name is no longer than 20.
#     * The length of the email ID is no longer than 50.
# 
# Output Format
# 
# Print an alphabetically-ordered list of first names for every user with a gmail account. Each
# name must be printed on a new line.
# 
# Sample Input
# 
#     6
#     riya riya@gmail.com
#     julia julia@julia.me
#     julia sjulia@gmail.com
#     julia julia@gmail.com
#     samantha samantha@gmail.com
#     tanya tanya@gmail.com
# 
# Sample Output
# 
#     julia
#     julia
#     riya
#     samantha
#     tanya
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

// ---------------------------- locked code above ------------------------------

//###################################################################
console.log( "to run: nodejs ./day-28-regex-patterns.js < day-28-regex-patterns.txt" );
//###################################################################

function main() {
	var results=[];
    var N = parseInt(readLine());
    for(var a0 = 0; a0 < N; a0++){
        var firstName_temp = readLine().split(' ');
        var firstName = firstName_temp[0];
        var emailID = firstName_temp[1];

		// search returns index into the string
		if (emailID.search(/@gmail.com$/)>0) {
			results.push(firstName);
		}
    }

	// process.stdout.write(results.sort()+"\n");
	results.sort();
	for (var i=0; i<results.length; i++) {
		process.stdout.write(results[i]+"\n");
	}


// ---------------------------- locked code below ------------------------------

}

