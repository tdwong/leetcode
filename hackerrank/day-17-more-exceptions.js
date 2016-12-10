//#https://www.hackerrank.com/challenges/30-more-exceptions
/*
# Day 17: More Exceptions
# 
# Objective 
# 
# Yesterday's challenge taught you to manage exceptional situations by using try and catch blocks. In
# today's challenge, you're going to practice throwing and propagating an exception. Check out
# the Tutorial tab for learning materials and an instructional video!
# 
# Task 
# 
# Write a Calculator class with a single method: int power(int,int). The power method takes
# two integers, n and p, as parameters and returns the integer result of n**p. If either n or
# p is negative, then the method must throw an exception with the message: "n and p should be
# non-negative".
# 
# Note: Do not use an access modifier (e.g.: public) in the declaration for your Calculator class.
# 
# Input Format
# 
# Input from stdin is handled for you by the locked stub code in your editor. The first line
# contains an integer, T, the number of test cases. Each of the T subsequent lines describes a
# test case in 2 space-separated integers denoting n and p, respectively.
# 
# Constraints
# 
# 	* No Test Case will result in overflow for correctly written code.
# 
# Output Format
# 
# Output to stdout is handled for you by the locked stub code in your editor. There are T lines
# of output, where each line contains the result of n**p as calculated by your Calculator class'
# power method.
# 
# Sample Input
# 
# 	4
# 	3 5
# 	2 4
# 	-1 -2
# 	-1 3
# 
# Sample Output
# 
# 	243
# 	16
# 	n and p should be non-negative
# 	n and p should be non-negative
# 
# Explanation
# 
# T = 4
# T0: 3 and 5 are positive, so power returns the result of 3**5, which is 243. 
# T1: 2 and 4 are positive, so power returns the result of 2**4=, which is 16. 
# T2: Both inputs (-1 and -2) are negative, so power throws an exception and "n and p should be non-negative" is printed. 
# T3: One of the inputs (-1) is negative, so power throws an exception and "n and p should be non-negative" is printed.
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


// ---------------------------- locked code above ------------------------------

//Write your code here

    //http://www.phpied.com/3-ways-to-define-a-javascript-class/
// use function to define a class
function Calculator() {
    // this.member...
	this.power = function(n, p) {
        if (n<0 || p<0) { throw "n and p should be non-negative"; }
        var value = 1;
        while (p > 0) {
            value *= n;
            p--;
        }
        return value;
    }
};

//###################################################################
console.log( "to run: nodejs ./day-17-more-exceptions.js < day-17-more-exceptions.txt" );
//###################################################################

// ---------------------------- locked code below ------------------------------

function main(){
    var myCalculator=new Calculator();
    var T=parseInt(readLine());
    while(T-->0){
        var num = (readLine().split(" "));
        try{
            var n=parseInt(num[0]);
            var p=parseInt(num[1]);
            var ans=myCalculator.power(n,p);
            console.log(ans);
        }
        catch(e){
            console.log(e);
        }

    }
}
