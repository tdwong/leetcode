/*
# 
# Roy wanted to increase his typing speed for programming contests. So, his friend advised him
# to type the sentence "The quick brown fox jumps over the lazy dog" repeatedly, because it is a
# pangram. (Pangrams are sentences constructed by using every letter of the alphabet at least once.)
# 
# After typing the sentence several times, Roy became bored with it. So he started to look for other pangrams.
# 
# Given a sentence s, tell Roy if it is a pangram or not.
# 
# Input Format
# 
# Input consists of a string s.
# 
# Constraints 
# 
#     * Length of s can be at most 10**3 (1 <= |s| <= 10**3) and it may contain spaces, lower case and
#      upper case letters. Lower-case and upper-case instances of a letter are considered the same.
# 
# Output Format
# 
# Output a line containing "pangram" if s is a pangram, otherwise output "not pangram".
# 
# Sample Input
# 
# Input #1
# 
#     We promptly judged antique ivory buckles for the next prize    
# 
# Input #2
# 
#     We promptly judged antique ivory buckles for the prize    
# 
# Sample Output
# 
# Output #1
# 
#     pangram
# 
# Output #2
# 
#     not pangram
# 
# Explanation
# 
# In the first test case, the answer is pangram because the sentence contains all the letters of the English alphabet.
# 
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

static int gDebug = 1;
void prVectorChar(vector<unsigned char> v)
{
	if (gDebug==0) return;
	cout << "[";
	for (int ix = 0; ix < v.size(); ix++)
		cout << v[ix] << ",";
	cout << "]" << endl;
}

bool ucharCmp(unsigned char a, unsigned char b) { return (a==b); }

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    string s;
		// read stdin with spaces
		//http://stackoverflow.com/a/5838803/663485
	std::getline(std::cin, s);
		//http://blog.fourthwoods.com/2013/12/10/convert-c-string-to-lower-case-or-upper-case/
	std::transform(s.begin(), s.end(), s.begin(), ::tolower);
    
    vector<unsigned char> v(s.begin(),s.end());
    sort(v.begin(),v.end());

	prVectorChar(v);

#define _not_using_unique_ 0
#ifdef _not_using_unique_
	vector<unsigned char> uv;
	int ix;
	unsigned char next = (unsigned char) 0;
	for (ix = 0; ix < v.size(); ix++) {
		if (v[ix] != next) {
			uv.push_back(v[ix]);
			next = v[ix];
		}
	}
#else
	vector<unsigned char> uv = v;
	vector<unsigned char>::iterator it = std::unique (uv.begin(), uv.end());
	uv.resize( std::distance( uv.begin(), it ) );
#endif	//_not_using_unique_

	prVectorChar(uv);
    
	//
	string u = " abcdefghijklmnopqrstuvwxyz";
	string uz = string(uv.begin(),uv.end());

	if (uz==u) cout << "pangram" << endl;
	else cout << "not pangram" << endl;

    return 0;
}
