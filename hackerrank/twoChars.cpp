//#https://www.hackerrank.com/challenges/two-characters
/*
#
# String t always consists of two distinct alternating characters. For example, if string t's
# two distinct characters are x and y, then t could be xyxyx or yxyxy but not xxyy or xyyx.
# 
# You can convert some string s to string t by deleting characters from s. When you delete a
# character from s, you must delete all occurrences of it in s. For example, if s = abaacdabd
# and you delete the character a, then the string becomes bcdbd.
# 
# Given s, convert it to the longest possible string t. Then print the length of string t on a
# new line; if no string t can be formed from s, print 0 instead.
# 
# Input Format
# 
# The first line contains a single integer denoting the length of s. 
# The second line contains string s.
# 
# Constraints
# 
#     * 1 <= |s| <= 1000
#     * s only contains lowercase English alphabetic letters (i.e., a to z).
# 
# Output Format
# 
# Print a single integer denoting the maximum length of t for the given s; if it is not possible
# to form string t, print 0 instead.
# 
# Sample Input
# 
#     10
#     beabeefeab
# 
# Sample Output
# 
#     5
# 
# Explanation
# 
# The characters present in s are a, b, e, and f. This means that t must consist of two of those characters.
# 
# If we delete e and f, the resulting string is babab. This is a valid t as there are only two
# distinct characters (a and b), and they are alternating within the string.
# 
# If we delete a and f, the resulting string is bebeeeb. This is not a valid string t because
# there are three consecutive e's present.
# 
# If we delete only e, the resulting string is babfab. This is not a valid string t because it
# contains three distinct characters.
# 
# Thus, we print the length of babab, which is 5, as our answer.
#
*/

//
#include <iostream>
#include <utility>
#include <vector>
#include <set>

using namespace std;

static int gDebug = 0;

//
// utility functions
//
void prString(const string s)
{
	if (gDebug==0) return;
	cout << ">>>  string:" << endl;
	for (int ix = 0; ix < s.length(); ix++)
		cout << "[" << ix << "]:" << s[ix] << endl;
	return;
}
//
void prUCharSet(const set<unsigned char> uniqSet)
{
	if (gDebug==0) return;
	cout << ">>>  uniqSet:" << endl;
	int jx=0;
	for (set<unsigned char>::iterator it = uniqSet.begin(); it != uniqSet.end(); it++, jx++)
		cout << "[" << jx << "]:" << *it << endl;
}
//
void prUCharVector(vector<unsigned char> ucVector)
{
	if (gDebug==0) return;
	cout << ">>>  ucVector:" << endl;
	int jx=0;
	for (vector<unsigned char>::iterator it = ucVector.begin(); it != ucVector.end(); it++, jx++)
		cout << "[" << jx << "]:" << *it << endl;
}
//
void prPairSet(const set<pair<unsigned char,unsigned char> > pairSet)
{
	if (gDebug==0) return;
	cout << ">>>  pairSet:" << endl;
	int jx=0;
	for (set<pair<unsigned char,unsigned char> >::iterator it = pairSet.begin(); it != pairSet.end(); it++, jx++)
		cout << "[" << jx << "]: (" << (*it).first << "," << (*it).second << ")" << endl;
}

// build all possible combinations 
//
void combinations(vector<unsigned char> vchars, set<pair<unsigned char, unsigned char> > &scombi)
{
	//* assumption: vchars contains NO duplicate characters
	//
	
	// end-conditions
	if (vchars.size() == 1) {
		// no more combination to be created
		return;
	}
	if (vchars.size() == 2) {
		// only one combination can be created
		scombi.insert(make_pair(vchars[0], vchars[1]));
		return;
	}
	
	// subset exclude first element
	std::vector<unsigned char> vrest (vchars.begin()+1, vchars.end());

	// add possible combination to vchars[0] & vrest(...)
	for (int ix = 0; ix < vrest.size(); ix++) {
		scombi.insert(make_pair(vchars[0], vrest[ix]));
	}
	
	// recursive
	combinations(vrest, scombi);
}


// find all possible combinations of any 2 characters from the string s
void buildCombi(const string s, set<pair<unsigned char,unsigned char> > &combiSet)
{
	// string -> set (unique unsigned char)
	set<unsigned char> uniqSet;
	for (int ix = 0; ix < s.length(); ix++)
		uniqSet.insert(s[ix]);
	//
	prUCharSet(uniqSet);

	// set -> vector
	vector<unsigned char> ucVector;
	for (set<unsigned char>::iterator it = uniqSet.begin(); it != uniqSet.end(); it++)
		ucVector.push_back(*it);
	//
	prUCharVector(ucVector);

	//* set<pair<unsigned char,unsigned char> > combiSet;
	combinations(ucVector, combiSet);
	//
	prPairSet(combiSet);

	return;
}

// find longest string with any 2 characters from the string s
int twoChars(string s)
{
	unsigned int longest = 0;

	//
	set<pair<unsigned char,unsigned char> > combiSet;
	buildCombi(s, combiSet);

	//
	for (set<pair<unsigned char,unsigned char> >::iterator it = combiSet.begin(); it != combiSet.end(); it++) {
		// loop thru string and pick only characters in pair<>
		vector<unsigned char> zVector;
		for (int ix = 0; ix < s.length(); ix++) {
			if ((s[ix] == (*it).first) || (s[ix] == (*it).second))
				zVector.push_back(s[ix]);
		}
		// validate the zVector
		bool validStr = true;
		for (int ix = 0; ix < (zVector.size()-1); ix++) {
			if (zVector[ix]==zVector[ix+1]) {
				validStr = false;
				break;
			}
		}
		if (validStr == true) {
			if (zVector.size() > longest)
				longest = zVector.size();
		}
	}

	return longest;
}

// main
int main()
{
    string s0="beabeefeab";
    cout << "expected: 5" << endl;
    cout << twoChars(s0) << endl;

    cout << "expected: 6" << endl;
    cout << twoChars("muqqzbcjmyknwlmlcfqjujabwtekovkwsfjrwmswqfurtpahkdyqdttizqbkrsmfpxchbjrbvcunogcvragjxivasdykamtkinxpgasmwz") << endl;

    cout << "expected: 0" << endl;
    cout << twoChars("clmgakmobtdtdvqttrpgzkjmhcwnflzuazzobixbnyzxbgoszbneqfshlzqspjxtbxhyybxklcqiheeqmkjfpgcjzgzlsanhikvprhedxbvyyksppxkcywwobeakjuvmzzdjptjkzvvovbmakdhabbwrvnztzxoptsytwjgglfdgyhpffwrtqbjgcarmnmuvniwvozocwukpdmaktuqqsufxdqazjppqkolcxsjonluxkhqnwsyudlyvmtgblbzqmjifqpgibndldpdkdsqeesikxwmnrzepefbveihjeacodnljfxjdniribcumqrcnwexjbahwuct") << endl;

	string s;
	cout << "a string please; ";
	cin >> s;
    cout << twoChars(s) << endl;

	return 0;
}
