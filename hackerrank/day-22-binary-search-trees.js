//#https://www.hackerrank.com/challenges/30-binary-search-trees
/*
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
*/

// ---------------------------- locked code below ------------------------------

// Start of function Node
function Node(data) {
    this.data = data;
    this.left = null;
    this.right = null;
}; // End of function Node

// Start of function BinarySearchTree
function BinarySearchTree() {
    this.insert = function(root, data) {
        if (root === null) {
            this.root = new Node(data);
            
            return this.root;
        }
        
        if (data <= root.data) {
            if (root.left) {
                this.insert(root.left, data);
            } else {
                root.left = new Node(data);
            }
        } else {
            if (root.right) {
                this.insert(root.right, data);
            } else {
                root.right = new Node(data);
            }
        }
        
        return this.root;
    };
    
    // Start of function getHeight
    this.getHeight = function(root) {

// ---------------------------- locked code above ------------------------------

        // Add your code here
		var rheight=1, lheight=1;

//		console.log( "root.data=" + root.data );
		if ((root.right == null) && (root.left == null)) { return 0; }

		if (root.right != null) {
			rheight += this.getHeight(root.right);
//			console.log( "data=" + root.data + ", rheight=" + rheight );
		}
		if (root.left != null) {
			lheight += this.getHeight(root.left);
//			console.log( "data=" + root.data + ", lheight=" + lheight );
		}

		return (rheight>lheight) ? rheight : lheight ;

// ---------------------------- locked code below ------------------------------

    }; // End of function getHeight


///
	this.traverse = function(root) {
		if ((root.right == null) && (root.left == null)) {
			console.log( "data: " + root.data );
			return;
		}
		if (root.right) { this.traverse(root.right); }
		if (root.left) { this.traverse(root.left); }
		console.log( "data: " + root.data );
	}
///

}; // End of function BinarySearchTree


//###################################################################
console.log( "to run: nodejs ./day-22-binary-search-trees.js < day-22-binary-search-trees.txt" );
//###################################################################


process.stdin.resume();
process.stdin.setEncoding('ascii');

var _input = "";

process.stdin.on('data', function (data) {
    _input += data;
});

process.stdin.on('end', function () {
    var tree = new BinarySearchTree();
    var root = null;
    
    var values = _input.split('\n').map(Number);
    
//console.log("values="+values+", len=",parseInt(values[0]));
    //*-will-read-extra-data-afterward-*// for (var i = 1; i < values.length; i++) {
    for (var i = 1; i <= parseInt(values[0]); i++) {
        root = tree.insert(root, values[i]);
    }
    
    console.log(tree.getHeight(root));

///
	tree.traverse(root);
///
});

