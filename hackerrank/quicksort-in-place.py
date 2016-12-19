#!/bin/python

#https://www.hackerrank.com/challenges/quicksort3

"""
# Challenge 
# 
# Create an in-place version of Quicksort. You need to follow Lomuto Partitioning method.
# 	// https://en.wikipedia.org/wiki/Quicksort#Algorithm
# 
# Guideline 
# 
# Instead of copying the array into multiple sub-arrays, use indices to keep track of the different
# sub-arrays. You can pass the indices to a modified partition method. The partition method should
# partition the sub-array and then return the index location where the pivot gets placed, so you
# can then call partition on each side of the pivot.
# 
# * Always select the last element in the 'sub-array' as a pivot.
# * Partition the left side and then the right side of the sub-array.
# * Print out the whole array at the end of every partitioning method.
# * An array of length 1 or less will be considered sorted, and there is no need to sort or to print them.
# 
# Since you cannot just create new sub-arrays for the elements, partition method will need to
# use another trick to keep track of which elements are greater and which are lower than the pivot.
# 
# The In-place Trick
# 
# * If an element is lower than the pivot, you should swap it with a larger element on the left-side of the sub-array.
# * Greater elements should remain where they are.
# * At the end of the partitioning method, the pivot should be swapped with the first element of
#   the right partition, consisting of all larger elements, of the sub-array.
# * To ensure that you don't swap a small element with another small element, use an index to
#   keep track of the small elements that have already been swapped into their "place".
# 
# 	http://upload.wikimedia.org/wikipedia/commons/8/84/Lomuto_animated.gif
# 
"""

# Enter your code here. Read input from STDIN. Print output to STDOUT


def prArray(ar):
    for i in xrange(len(ar)):
        print ar[i],
    print

def swap(ar, i, j):
    tmp = ar[i]
    ar[i] = ar[j]
    ar[j] = tmp

def partition(ar, lo, hi):

    # if (gDebug) cout << __FUNCTION__ << ": lo=" << lo << ", hi=" << hi << endl;

    swapCount = 0
    p = cur = lo
    while cur < hi:
        if ar[cur]<=ar[hi]:
            swap(ar, cur, p)
            swapCount += 1
            p += 1
        cur += 1
    # swap last element into pivot position
    swap(ar, p, hi)

    # if (gDebug) cout << __FUNCTION__ << ": swapCount=" << swapCount << endl
    # if (gDebug) cout << " >>>: "
    prArray(ar)

    return p          

def quicksort(ar, lo, hi):

    if (hi-lo) <= 0:
        # no sort needed/possible
        return

    p = partition(ar, lo, hi)
    # if (gDebug) cout << "parted: p=" << p << ", lo=" << lo << ", hi=" << hi << endl
    if (lo < p) : quicksort(ar, lo, p-1)
    if (p < hi) : quicksort(ar, p+1, hi)


###################################################################
print "to run: python ./day-24-more-linked-list.py < day-24-more-linked-list.txt"
###################################################################

count=int(raw_input())

# read in the unsorted array
ar=map(int, raw_input().strip().split())

if count==1:
    # corner case
    prArray(ar)
else:
    # if (gDebug) cout << "init: "; prArray(ar)
    quicksort(ar, 0, len(ar)-1)
    
