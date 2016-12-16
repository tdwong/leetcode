//https://leetcode.com/problems/string-to-integer-atoi/
/*
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
*/

/* testcase
 *
	"213"
	"-213"
	"+213"
	"-1" 
	"+1" 
	""
	"      " 
	"2147483647"
	"2147483648"
	"+2147483647"
	"-2147483648" 
	"-2147483649" 
	"      -11919730356x" 
 *
 */

#include <ctypes.h>

/*
    6ms for all test leetcode cases
    31.44% leetcode ranking
 */
char *sameStrPalindromic_v2(char *str)
int myAtoi(char* str) {
    int ret = 0;
    int radix = 10;
    int neg = 0;
    
    // ignore leading whitespace
    while (isspace(*str)) { str++; }
    
    // handle positive & minus sign
    if (*str == '+') { str++; }
    else if (*str == '-') { neg=1; str++; }
    
    /*--
    // handle different radix
    if (*str == '0') {
        if ((*(str+1) == 'x') || (*(str+1) == 'X')) {
            radix = 16;
            str += 2;
        }
        else {
            radix = 8;
            str++;
        }
    }
    --*/
    
    while (*str) {
        switch (radix) {
            case 8:
                if (('0' <= *str) && (*str <= '7')) {
                    ret = (ret*radix) + (*str) - '0';
                }
                else {
                    // invalid char
                    return 0;
                }
                break;
            case 16:
                if (('0' <= *str) && (*str <= '9')) {
                    ret = (ret*radix) + (*str) - '0';
                }
                else if (('A' <= *str) && (*str <= 'F')) {
                    ret = (ret*radix) + (*str) - 'A' + 10;
                }
                else if (('a' <= *str) && (*str <= 'f')) {
                    ret = (ret*radix) + (*str) - 'a' + 10;
                }
                else {
                    // invalid char
                    return 0;
                }
                break;
            default:
                if (('0' <= *str) && (*str <= '9')) {
                    if (neg==0) {
                        // make sure we won't go beyond INT_MAX
                        if (ret > ((INT_MAX-(*str-'0'))/10)) {
                            // cannot go beyond INT_MAX
                            return INT_MAX;
                        }
                        ret = (ret*radix) + (*str) - '0';
                    }
                    else {
                        // make sure we won't go below INT_MAX
                        if (ret < ((INT_MIN+(*str-'0'))/10)) {
                            // cannot go below INT_MIN
                            return INT_MIN;
                        }
                        ret = (ret*radix) - ((*str) - '0');
                    }
                }
                else {
                    // not a valid numeric char.  return what we have
                    return ret;
                }
                break;
        }
        str++;
    }
    return ret;
}

