//https://leetcode.com/problems/palindrome-number/
/*
#
# 9. Palindrome Number
#
#	Determine whether an integer is a palindrome. Do this without extra space.
#
#	palindrome
#	A word, phrase, or sequence that reads the same backward as forward, e.g., madam or nurses run
#
*/

#include <stdio.h>
#include <stdlib.h>

/*
	65ms for all test leetcode cases
	97.65% leetcode ranking
 */
class Solution {
public:
	bool isPalindrome(int x) {
		/*
		 *	IDENTICAL implementation as in c_9.c
		 *
		 *	However, leetocde C implementation ranks at 20.68% (82ms)
		 *	but, leetocde C++ implementation ranks at 97.65% (65ms)
		 */
		if (x < 0) return false;
		if (x == 0) return true;
		int z = x, rev = 0;
		while ( z >= 10 ) {
			int d = z % 10;
			rev = rev*10 + d;
			z /= 10;
		}
		rev = rev*10 + z;
		return (x==rev);
	}
};

/* recursive solution */
/*
	72ms for all test leetcode cases
	79.29% leetcode ranking
 */
class SolutionR {
public:
	int reverse(int val, int rev) {
		//printf("val=%d, rev=%d\n", val, rev);
		if (val < 10) {
			//printf("return: %d\n", (rev*10) + val);
			return (rev*10) + val;
		}
		//printf("call reverse(%d, %d)\n", (val/10), (rev*10)+(val%10) );
		return reverse( (val/10), (rev*10)+(val%10) );
	}
	bool isPalindrome(int x) {
		if (x < 0) return false;
		if (x == 0) return true;
		return (x == reverse(x, 0));
	}
};

int main(int argc, char **argv)
{
	Solution  s;
	SolutionR sr;
	for (int ix = 1; ix < argc; ix++) {
		int value = atoi(argv[ix]);
		printf("Solution  %s: %s\n", argv[ix], s.isPalindrome(value)?"true":"false");
		printf("SolutionR %s: %s\n", argv[ix], sr.isPalindrome(value)?"true":"false");
	}
}

