//https://www.hackerrank.com/challenges/30-operators
/*
# Day 2: Operators
# 
# Objective 
# 
# In this challenge, you'll work with arithmetic operators. Check out the Tutorial 
# (https://www.hackerrank.com/challenges/30-operators/tutorial) tab for learning materials and an instructional video!
# 
# Task 
# 
# Given the meal price (base cost of a meal), tip percent (the percentage of the meal price being added as tip), 
# and tax percent (the percentage of the meal price being added as tax) for a meal, find and print the meal's 
# total cost.
# 
# Note: Be sure to use precise values for your calculations, or you may end up with an incorrectly rounded result!
# 
# Input Format
# 
# 	There are 3 lines of numeric input: 
# 	The first line has a double, mealCost (the cost of the meal before tax and tip). 
# 	The second line has an integer, tipPercent (the percentage of  being added as tip). 
# 	The third line has an integer, taxPercent (the percentage of  being added as tax).
# 
# Output Format
# 
# 	Print "The total meal cost is totalCost dollars.", where totalCost is the rounded integer result of the entire bill 
# 	(mealCost with added tax and tip).
# 
# Sample Input
# 
# 	12.00
# 	20
# 	8
# 	
# Sample Output
# 
# 	The total meal cost is 15 dollars.
# 
# Explanation
# 
# Given: 
# 	mealCost = 12, tipPercent = 20, taxPercent = 8 
# 
# Calculations: 
# 
# 	tip = 12 x (20/100) = 2.4
# 	tax = 12 x (8/100) = 0.96
# 	totalCost = mealCost + tip + tax = 12 + 2.4 + 0.96 = 15.36
# 	round(totalCost) = 15
# 
# We round totalCost to the nearest dollar (integer) and then print our result:
# 
# 	The total meal cost is 15 dollars.
# 	
*/

/// for LOCAL TEST only
console.log("enter 3 lines of data... <ctrl-D> to end");
/// for LOCAL TEST only

var readline = require('readline');
var rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
  terminal: false
});

var gCost, gTip, gTax;

rl.on('line', function(line){
//    console.log(line);
    line = line.replace(/[\r\n]$/,"");      // trim \n at the end
    if (gCost == null)     { gCost = parseFloat(line); }
    else if (gTip == null) { gTip = parseInt(line); }
    else if (gTax == null) { gTax = parseInt(line); }
})

rl.on('close', function(line){
//    console.log("gCost="+gCost+", gTip="+gTip+", gTax="+gTax);
    console.log("The total meal cost is " + Math.round(gCost*(100+gTip+gTax)/100) + " dollars.");
//    console.log('done with readline');
})

