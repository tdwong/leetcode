#!/bin/sh

###
###	bash requires the file format in UNIX format
###
### :set fileformat=unix
###	:echo &fileformat
### unix
###

#//https://www.hackerrank.com/challenges/30-sorting
#/*
# Day 20: Sorting
# 
# Objective 
# 
# Today, we're discussing a simple sorting algorithm called Bubble Sort. Check out the Tutorial
# tab for learning materials and an instructional video!
# 
# Consider the following version of Bubble Sort:
# 
#     for (int i = 0; i < n; i++) {
#         // Track number of elements swapped during a single array traversal
#         int numberOfSwaps = 0;
#         
#         for (int j = 0; j < n - 1; j++) {
#             // Swap adjacent elements if they are in decreasing order
#             if (a[j] > a[j + 1]) {
#                 swap(a[j], a[j + 1]);
#                 numberOfSwaps++;
#             }
#         }
#         
#         // If no elements were swapped during a traversal, array is sorted
#         if (numberOfSwaps == 0) {
#             break;
#         }
#     }
# 
# Task 
# 
# Given an array, a, of size n containing distinct elements a[0], a[1],..., a[n-1], sort array a in
# ascending order using the Bubble Sort algorithm above. Once sorted, print the following 3 lines:
# 
# 1. Array is sorted in numSwaps swaps 
# where numSwaps is the number of swaps that took place.
#  
# 2. First Element: firstElement
# where firstElement is the first element in the sorted array.
#  
# 3. Last Element: lastElement
# where lastElement is the last element in the sorted array.
# 
# Hint: To complete this challenge, you will need to add a variable that keeps a running tally
# of all swaps that occur during execution.
# 
# Input Format
# 
# The first line contains an integer, n, denoting the number of elements in array a. 
# The second line contains n space-separated integers describing a, where the i-th integer is a[i], all i are in [0, n-1] range.
# 
# Constraints
# 
#     * 2 <=n <= 600
#     * 1 <= a[i] <= 2 x 10**6 , all i are in [0, n-1]  range
# 
# Output Format
# 
# There should be 3 lines of output:
# 
# 1. Array is sorted in numSwaps swaps.
# where numSwaps is the number of swaps that took place.
#  
# 2. First Element: firstElement
# where firstElement is the first element in the sorted array.
#  
# 3. Last Element: lastElement
# where lastElement is the last element in the sorted array.
# 
# Sample Input 0
# 
#     3
#     1 2 3
# 
# Sample Output 0
# 
#     Array is sorted in 0 swaps.
#     First Element: 1
#     Last Element: 3
# 
# Sample Input 1
# 
#     3
#     3 2 1
# 
# Sample Output 1
# 
#     Array is sorted in 3 swaps.
#     First Element: 1
#     Last Element: 3
# 
# Explanation
# 
# Sample Case 1: 
# 
# The array is already sorted, so 0 swaps take place and we print the necessary 3 lines of output shown above.
# 
# Sample Case 2: 
# 
# The array is not sorted, and its initial values are: {3, 2, 1}. The following 3 swaps take place:
# 
#     1. {3, 2, 1} -> { 2, 3, 1}
#     2. {2, 3, 1} -> { 2, 1, 3}
#     3. {2, 1, 3} -> { 1, 2, 3}
# 
# At this point the array is sorted and we print the necessary 3 lines of output shown above.
#  
#*/


###################################################################
echo "to run: bash ./day-20-sorting.sh < day-20-sorting.txt"
###################################################################

# read array size
read n
# read entire array
read s
	# break into bash array
read -r -a p <<< $s

#
let ts=0
let sc=0
while true; do

	# for loop to walk from first to last elements in the array

	#	echo "#arr= ${#p[*]} ,,, arr= ${p[@]}"
	let arrsize=${#p[*]}

	#-	let i=0
	#-#x	while (( $i < ${#p[*]} ));			# takes too much time
	#-	while (( $i < $arrsize ));

	# see http://technicalworldforyou.blogspot.com/2012/03/shell-script-to-sort-number-in-array.html for using for(;;)
	for (( i=0 ; i < $arrsize ; i++ ))

	do

		# use i and ni to access two consective elements
		let ni=$i+1
#		echo "i=$i,,, ni=$ni,,, #p[*]=${#p[*]}"
		# cannot go beyond last element
#x		[ $ni -ge ${#p[*]} ] && break
		(( $ni >= ${#p[*]} )) && break			# use bash internal command to speed up
#		echo "i=" ${p[$i]} ",ni=" ${p[$ni]}

		# comparison
#x		if [ ${p[$i]} -gt ${p[$ni]} ];
		if (( ${p[$i]} > ${p[$ni]} ));			# use bash internal command to speed up
		then
#			echo "swapping i=" ${p[$i]} ",ni=" ${p[$ni]}
			# do swap
			let sc=$sc+1
			let ts=$ts+1
			#
			tmp=${p[$i]}
			p[$i]=${p[$ni]}
			p[$ni]=$tmp
		fi
	#-		let i=$i+1
	#-#		echo "next i = $i"
	done

	# check swap count of this iteration
#x	[ $sc -eq 0 ] && break
	(( $sc == 0 )) && break			# use bash internal command to speed up
	let sc=0
	let arrsize=$arrsize-1
done

echo "Array is sorted in $ts swaps."
echo "First Element: ${p[0]}"
echo "Last Element: ${p[-1]}"
##let z=${#p[*]}-1
##echo "Last Element: ${p[$z]}"

