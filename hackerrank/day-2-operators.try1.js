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

//process.stdin.setEncoding('utf8');
//process.stdin.resume();

/*
//	var gCost, gTip, gTax;
//	process.stdin.on('data', function() {
//	  var chunk = process.stdin.read();
//	    process.stdout.write("1stdin.read:"+chunk+"\n");
//	  if ((chunk !== null) && (chunk != undefined)) {
//	        chunk = chunk.replace(/\n$/,"");                // trim \n at the end
//	    process.stdout.write("2stdin.read:"+chunk+"\n");
//	//        gchunk = chunk;
//	//    process.stdout.write("stdin.read:"+gchunk+"\n");
//	        if (gCost == null) { gCost = chunk; }
//	        else if (gTip == null) { gTip = chunk; }
//	        else if (gTax == null) { gTax = chunk; }
//	  }
//	});
//	
//	process.stdin.on('end', function() {
//	    console.log("gCost="+gCost+", gTip="+gTip+", gTax="+gTax+"\n");
//	    var totalCost = gCost * (100+gTip+gTax) / 100;
//	    console.log("The total meal cost is " + Math.round(totalCost) + " dollars.");
//	});
*/

// if reading for utf8
process.stdin.setEncoding('utf8');

var gCost, gTip, gTax;
//var gvar = "global";

process.stdin.on('readable', function() {
  var chunk = process.stdin.read();
  if (chunk !== null) {
  	chunk = chunk.replace(/\n$/,"");		// trim \n at the end
//    process.stdout.write("stdin.read:"+chunk+"\n");
//	gchunk = chunk;
//    process.stdout.write("stdin.read:"+gchunk+"\n");
	if (gCost == null) { gCost = chunk; }
	else if (gTip == null) { gTip = chunk; }
	else if (gTax == null) { gTax = chunk; }
  }
});

process.stdin.on('end', function() {
    //process.stdout.write("stdout gchunk:"+gchunk+",gvar="+gvar+"\n");
	//console.log("console.log gchunk: "+gchunk+",gvar="+gvar+"\n");
//	console.log("gCost="+gCost+", gTip="+gTip+", gTax="+gTax+"\n");
	gCost=parseFloat(gCost);
	gTip =parseInt(gTip);
	gTax =parseInt(gTax);
    var totalCost = (gCost * (100+gTip+gTax)) / 100;
//	var a=12.00, b=20, c=8;
//	console.log("a="+a+", b="+b+", c="+c+"\n");
//    var z = Math.round(a*(100+b+c)/100);
//	console.log("z="+z+"\n");
    console.log("The total meal cost is " + Math.round(gCost*(100+gTip+gTax)/100) + " dollars.");
	process.exit();
});
