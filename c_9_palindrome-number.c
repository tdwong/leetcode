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
#include <math.h>

#define false	0
#define	true	!false
typedef	int	bool;

bool isPalindrome(int x) {
	if (x < 0) return false;
	if (x == 0) return true;

#ifdef	__math_pow__
/*
 * math operation (pow & double) are really slow
 *
	99ms for all test leetcode cases
	3.62% leetcode ranking
 */
    int g=0, z=x;
    while ( z >= 10 ) { z /= 10; g++; }
//    printf ("g=%d\n", g);
	int f = 0, b = g;
	while (f < b) {
		if ( ((x / (int)pow(10,f)) % 10) !=
		     ((x / (int)pow(10,b)) % 10) )
		{ return false; }
		f++; b--;
	}
    return true;
#endif	//__math_pow__

/*
	82ms for all test leetcode cases
	20.68% leetcode ranking
 */
	int z = x, rev = 0;
	while ( z >= 10 ) {
		int d = z % 10;
		rev = rev*10 + d;
		z /= 10;
	}
	rev = rev*10 + z;
    printf ("x=%d, rev=%d\n", x, rev);
	return (x==rev);
}

int main(int argc, char **argv)
{
	int ix;
	for (ix = 1; ix < argc; ix++) {
		printf("%s: %s\n", argv[ix], isPalindrome(atoi(argv[ix]))?"true":"false");
	}
}

