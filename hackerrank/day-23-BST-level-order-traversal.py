#!/bin/python

#https://www.hackerrank.com/challenges/30-binary-trees
"""
# Day 23: BST Level-Order Traversal
# 
# Objective 
# 
# Today, we're going further with Binary Search Trees. Check out the Tutorial tab for learning
# materials and an instructional video!
# 
# Task 
# 
# A level-order traversal, also known as a breadth-first search, visits each level of a tree's
# nodes from left to right, top to bottom. You are given a pointer, root, pointing to the root
# of a binary search tree. Complete the levelOrder function provided in your editor so that it
# prints the level-order traversal of the binary search tree.
# 
# Hint: You'll find a queue helpful in completing this challenge.
# 
# Input Format
# 
# The locked stub code in your editor reads the following inputs and assembles them into a BST: 
# The first line contains an integer, T (the number of test cases). 
# The T subsequent lines each contain an integer, data, denoting the value of an element that must be added to the BST.
# 
# Output Format
# 
# Print the data value of each node in the tree's level-order traversal as a single line of N space-separated integers.
# 
# Sample Input
# 
#     6
#     3
#     5
#     4
#     7
#     2
#     1
# 
# Sample Output
# 
#     3 2 5 1 4 7 
# 
# Explanation
# 
# The input forms the following binary search tree: 
# 
#     https://s3.amazonaws.com/hr-challenge-images/17176/1461696188-8eddd12300-BST.png
# 
# We traverse each level of the tree from the root downward, and we process the nodes at each
# level from left to right. The resulting level-order traversal is 3 -> 2 -> 5 -> 1 -> 4 -> 7,
# and we print these data values as a single line of space-separated integers.
# 
#  
"""

#// ---------------------------- locked code below ------------------------------

import sys

class Node:
    def __init__(self,data):
        self.right=self.left=None
        self.data = data
class Solution:
    def insert(self,root,data):
        if root==None:
            return Node(data)
        else:
            if data<=root.data:
                cur=self.insert(root.left,data)
                root.left=cur
            else:
                cur=self.insert(root.right,data)
                root.right=cur
        return root

#// ---------------------------- locked code above ------------------------------

    def bst_traverse(self,ar,far):
        if len(ar)!=0:
            node = ar.pop(0)
            print node.data,
#            far.append(node)
            if node.left!=None: ar.append(node.left)
            if node.right!=None: ar.append(node.right)
            self.bst_traverse(ar, far)

    def levelOrder(self,root):
        #Write your code here
        ar=[root]
        far=[]
        self.bst_traverse(ar,far)
        print
#        for i in xrange(len(far)):
#            print far[i].data, "..",
#        print


###################################################################
print "to run: python ./day-23-BST-level-order-traversal.py < day-23-BST-level-order-traversal.txt"
###################################################################

#// ---------------------------- locked code below ------------------------------

T=int(raw_input())
myTree=Solution()
root=None
for i in range(T):
    data=int(raw_input())
    root=myTree.insert(root,data)
myTree.levelOrder(root)