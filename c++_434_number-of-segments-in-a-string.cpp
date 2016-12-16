/*
//https://leetcode.com/contest/leetcode-weekly-contest-11/problems/number-of-segments-in-a-string/
#
# 434. Number of Segments in a String
#
#	Count the number of segments in a string, where a segment is defined to be a contiguous sequence of non-space characters.
#	
#	Please note that the string does not contain any non-printable characters.
#	
#	Example:
#	
#		Input: "Hello, my name is John"
#	
#		Output: 5
#
*/

#include <iostream>
//#include <string>

//using namespace std;

/*
    0 for all test leetcode cases
    38.46% leetcode ranking
 */
class Solution {
public:
    int countSegments(std::string s) {
        int count = 0;
        int cip = 0;
        for (int ix = 0; ix < s.size(); ix++) {
            if (!isspace(s[ix])) {
                if (cip == 0) {
                    cip++;
                    count++;
                }
            }
            else { cip = 0; }
        }
        //std::cout << count << std::endl;
        return count;
    }
};

void checkSolution(std::string s, int expected)
{
	Solution solution;
	int ret = solution.countSegments(s);
	std::string retstr = (ret == expected) ? "ok" : "<-- wrong";
	std::cout << "s='" << s << "', ret: " << ret << ", expected: " << expected << "\t" << retstr << std::endl;
}

int main()
{
	checkSolution("Hello, my name is John", 5);
	checkSolution("   leading spaces line", 3);
	checkSolution("trailing spaces line  ", 3);
	checkSolution("  spaces on both ends ", 4);
	checkSolution("extra  spaces in between  words  ", 5);
	checkSolution("  combination  in word   spacing ", 4);
	checkSolution("", 0);
	checkSolution("                       ", 0);
	//
	return 0;
}

