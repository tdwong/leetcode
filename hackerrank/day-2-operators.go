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

package main

import (
	"fmt"
	//"io"
	//"bufio"
	"math"
)

func main() {

	var mealCost float64
	var tipPercent,taxPercent uint

	_,_ = fmt.Scanln(&mealCost)
	_,_ = fmt.Scanln(&tipPercent)
	_,_ = fmt.Scanln(&taxPercent)

    totalCost := Round( mealCost * float64(100+tipPercent+taxPercent) / 100. , 0);

	fmt.Println("The total meal cost is", totalCost, "dollars.")

}

//https://play.golang.org/p/MlSteRZVX3
//
// Round return rounded version of x with prec precision.
//
// Special cases are:
//		Round(0) = 0
//		Round(Inf) = Inf
//		Round(NaN) = NaN
func Round(x float64, prec int) float64 {
	var rounder float64
	pow := math.Pow(10, float64(prec))
	intermed := x * pow
	_, frac := math.Modf(intermed)
	if frac >= 0.5 {
		rounder = math.Ceil(intermed)
	} else {
		rounder = math.Floor(intermed)
	}
	return rounder / pow
}


