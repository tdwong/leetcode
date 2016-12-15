#!/bin/python

#https://www.hackerrank.com/challenges/30-binary-search-trees
"""
# Day 22: Binary Search Trees
# 
# Objective 
# 
# Today, we're working with Binary Search Trees (BSTs). Check out the Tutorial tab for learning
# materials and an instructional video!
# 
# Task 
# 
# The height of a binary search tree is the number of edges between the tree's root and its furthest
# leaf. You are given a pointer, root, pointing to the root of a binary search tree. Complete the
# getHeight function provided in your editor so that it returns the height of the binary search
# tree.
# 
# Input Format
# 
# The locked stub code in your editor reads the following inputs and assembles them into a binary search tree: 
# 
# The first line contains an integer, n, denoting the number of nodes in the tree. 
# Each of the n subsequent lines contains an integer, data, denoting the value of an element that must be added to the BST.
# 
# Output Format
# 
# The locked stub code in your editor will print the integer returned by your getHeight function denoting the height of the BST.
# 
# Sample Input
# 
#     7
#     3
#     5
#     2
#     1
#     4
#     6
#     7
# 
# Sample Output
# 
#     3
# 
# Explanation
# 
# The input forms the following BST:
# 
#     https://s3.amazonaws.com/hr-challenge-images/17175/1459894869-6bb53ce6eb-BST.png
# 
# The longest root-to-leaf path is shown below:
# 
#     https://s3.amazonaws.com/hr-challenge-images/17175/1459895368-4955f9ce74-LongestRTL.png
# 
# There are 4 nodes in this path that are connected by 3 edges, meaning our BST's height = 3. Thus, we print 3 as our answer.
#  
"""

#// ---------------------------- locked code below ------------------------------

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


    def getHeight(self,root):
        #Write your code here
#        print "data=", root.data
        if root.left == None and root.right == None: return 0
        rheight = lheight = 1
        if root.right != None:
            rheight += self.getHeight(root.right)
#            print "root.right=",  root.right, "rheight=", rheight
        if root.left != None:
            lheight += self.getHeight(root.left)
#            print "root.left=",  root.left, "lheight=", lheight
        return lheight if lheight>rheight else rheight


###################################################################
print "to run: python ./day-22-binary-search-trees.py < day-22-binary-search-trees.txt"
###################################################################

#// ---------------------------- locked code below ------------------------------

T=int(raw_input())
myTree=Solution()
root=None
for i in range(T):
    data=int(raw_input())
    root=myTree.insert(root,data)
height=myTree.getHeight(root)
print height

