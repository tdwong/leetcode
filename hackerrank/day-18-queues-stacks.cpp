//#https://www.hackerrank.com/challenges/30-queues-stacks
/*
# Day 18: Queues and Stacks
# 
# Objective 
# 
# Welcome to Day 18! Today we're learning about Stacks and Queues. Check out the Tutorial tab
# for learning materials and an instructional video!
# 
# A palindrome is a word, phrase, number, or other sequence of characters which reads the same
# backwards and forwards. Can you determine if a given string, s, is a palindrome?
# 
# To solve this challenge, we must first take each character in s, enqueue it in a queue, and also
# push that same character onto a stack. Once that's done, we must dequeue the first character
# from the queue and pop the top character off the stack, then compare the two characters to see
# if they are the same; as long as the characters match, we continue dequeueing, popping, and
# comparing each character until our containers are empty (a non-match means s isn't a palindrome).
# 
# Write the following declarations and implementations:
# 
#     1. Two instance variables: one for your stack, and one for your queue.
#     2. A void pushCharacter(char ch) method that pushes a character onto a stack.
#     3. A void enqueueCharacter(char ch) method that enqueues a character in the queue instance variable.
#     4. A char popCharacter() method that pops and returns the character at the top of the stack instance variable.
#     5. A char dequeueCharacter() method that dequeues and returns the first character in the queue instance variable.
# 
# Input Format
# 
# You do not need to read anything from stdin. The locked stub code in your editor reads a single
# line containing string s. It then calls the methods specified above to pass each character to
# your instance variables.
# 
# Constraints
# 
#     * s is composed of lowercase English letters.
# 
# Output Format
# 
# You are not responsible for printing any output to stdout. 
# If your code is correctly written and s is a palindrome, the locked stub code will print "The
# word, s, is a palindrome."; otherwise, it will print "The word, s, is a palindrome." 
# 
# Sample Input
# 
#     racecar
# 
# Sample Output
# 
#     The word, racecar, is a palindrome.
# 
*/


/* testcases:
 *
	racecar
	yes
 *
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
    //Write your code here
		vector<char> myStack, myQueue;
	public:
		Solution() { myStack.clear(); myQueue.clear(); }
		
		void pushCharacter(char item)    { myStack.insert(myStack.begin(), item); }
		void enqueueCharacter(char item) { myQueue.push_back(item); }
		
		char popCharacter(void) {
			// char item = *myStack.begin();
			vector<char>::iterator it = myStack.begin();
			char item = *it;
			myStack.erase(myStack.begin());
			return item;
		}
		char dequeueCharacter(void) {
			// char item = *myQueue.begin();
			vector<char>::iterator it = myQueue.begin();
			char item = *it;
			myQueue.erase(myQueue.begin());
			return item;
		}
		
		void printContent(void) {
			vector<char>::iterator it;
			cout << "myStack: [ ";
			for (it = myStack.begin(); it != myStack.end(); it++) {
				cout << *it << " ";
			}
			cout << "]" << endl;
			cout << "myQueue: [ ";
			for (it = myQueue.begin(); it != myQueue.end(); it++) {
				cout << *it << " ";
			}
			cout << "]" << endl;

		}
};


// ---------------------------- locked code below ------------------------------

int main() {

//###################################################################
cout << "provide any string for palindrome check: ";
//###################################################################

    // read the string s.
    string s;
    getline(cin, s);
    
  // create the Solution class object p.
    Solution obj;
    
    // push/enqueue all the characters of string s to stack.
    for (int i = 0; i < s.length(); i++) {
        obj.pushCharacter(s[i]);
        obj.enqueueCharacter(s[i]);
    }
    
//
	obj.printContent();
//

    bool isPalindrome = true;
    
    // pop the top character from stack.
    // dequeue the first character from queue.
    // compare both the characters.
    for (int i = 0; i < s.length() / 2; i++) {
        if (obj.popCharacter() != obj.dequeueCharacter()) {
            isPalindrome = false;
            
            break;
        }
    }
    
    // finally print whether string s is palindrome or not.
    if (isPalindrome) {
        cout << "The word, " << s << ", is a palindrome.";
    } else {
        cout << "The word, " << s << ", is not a palindrome.";
    }
    
//
	cout << endl;
//
    return 0;
}

