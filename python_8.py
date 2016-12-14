#//https://leetcode.com/problems/string-to-integer-atoi/
"""
# 
# 8. String to Integer (atoi)   Add to List QuestionEditorial Solution  My Submissions
# 
# 	Implement atoi to convert a string to an integer.
# 
# 	Hint: Carefully consider all possible input cases. If you want a challenge, please do
# 	not see below and ask yourself what are the possible input cases.
# 
# 	Notes: It is intended for this problem to be specified vaguely (ie, no given input
# 	specs). You are responsible to gather all the input requirements up front.
# 
# Update (2015-02-10):
# 	The signature of the C++ function had been updated. If you still see your function
# 	signature accepts a const char * argument, please click the reload button  to reset
# 	your code definition.
# 
# spoilers alert... click to show requirements for atoi.
# 
# Requirements for atoi:
# 
# 	The function first discards as many whitespace characters as necessary until the
# 	first non-whitespace character is found. Then, starting from this character, takes an
# 	optional initial plus or minus sign followed by as many numerical digits as possible,
# 	and interprets them as a numerical value.
# 
# 	The string can contain additional characters after those that form the integral number,
# 	which are ignored and have no effect on the behavior of this function.
# 
# 	If the first sequence of non-whitespace characters in str is not a valid integral number,
# 	or if no such sequence exists because either str is empty or it contains only whitespace
# 	characters, no conversion is performed.
# 
# 	If no valid conversion could be performed, a zero value is returned. If the correct
# 	value is out of the range of representable values, INT_MAX (2147483647) or INT_MIN
# 	(-2147483648) is returned.
# 
"""

class Solution(object):
	""" 
		82ms for all test leetcode cases
		32.45% leetcode ranking
	"""
    def myAtoi(self, str):
        """
        :type str: str
        :rtype: in
        """
        
        # initialization
        INT_MAX=2147483647
        INT_MIN=-2147483648
        digits='0123456789'
        ret = 0;
        str = str.strip()
        
        # corner case
        if len(str)==0: return 0
        
        # check leading sign if exists
        negative = False
        if str[0]=='+': cstr = str[1:]
        elif str[0]=='-':
            negative = True
            cstr = str[1:]
        else:
            cstr = str[:]
            
        for i in xrange(len(cstr)):
            if cstr[i] not in digits: return ret
            if negative==True:
                # Python always does the "floor division" for both negative numbers division and positive numbers division
                # print "ret=", float(ret), "cstr[i]=", cstr[i], "cmp=", (INT_MIN+int(cstr[i]))/10.
                if float(ret) < (INT_MIN+int(cstr[i]))/10.: return INT_MIN
                ret = ret * 10 - int(cstr[i])
            else:
                if ret > ((INT_MAX-int(cstr[i]))/10): return INT_MAX
                ret = ret * 10 + int(cstr[i])
        
        return ret


# ----------------------------------------------------------------------

cases=[
	"213" ,
	"-213" ,
	"+213" ,
	"-1" ,
	"+1" ,
	"" ,
	"      " ,
	"2147483647" ,
	"2147483648" ,
	"+2147483647" ,
	"-2147483648" ,
	"-2147483649" ,
	"      -11919730356x" ,
]

for x in cases:
	print "x=", x

	s = Solution()
	print "Solution:  ", s.myAtoi(x)

