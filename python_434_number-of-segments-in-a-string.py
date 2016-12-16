"""
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
"""

import re

class Solution(object):
	""" 
		32 for all test leetcode cases
		100% leetcode ranking
	"""
    def countSegments(self, s):
        """
        :type s: str
        :rtype: int
        """
        if len(s)==0 or len(s.strip())==0:  return 0
        return len(re.split('\s+', s.strip()))


def checkSolution(s, expected):
	print "s='%s'" % s,
	n = Solution().countSegments(s)
	if expected!=None:
		print "ret:", n, "expected:", expected, "ok" if n==expected else "<-- wrong"
	else:
		print "ret:", n, "expected:", "TBD"


checkSolution("Hello, my name is John", 5)
checkSolution("   leading spaces line", 3)
checkSolution("trailing spaces line  ", 3)
checkSolution("  spaces on both ends ", 4)
checkSolution("extra  spaces in between  words  ", 5)
checkSolution("  combination  in word   spacing ", 4)
checkSolution("", 0)
checkSolution("                       ", 0)

