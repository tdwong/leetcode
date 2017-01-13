//#https://www.hackerrank.com/contests/w28/challenges/the-great-xor
/*
# All Contests >> Week of Code 28 >> The Great XOR 
# 
# The Great XOR
# 
# Given a long integer, x, count the number of values of a satisfying the following conditions:
# 
#     * a XOR x > x
#     * 0 < a < x
# 
# where a and x are long integers and XOR is the bitwise XOR operator. 
# 
# You are given q queries, and each query is in the form of a long integer denoting x. For each
# query, print the total number of values of a satisfying the conditions above on a new line.
# 
# Input Format
# 
# The first line contains an integer, q, denoting the number of queries. 
# Each of the q subsequent lines contains a long integer describing the value of x for a query. 
# 
# Constraints
# 
#     * 1 <= q <= 10**5
#     * 1 <= x <= 10**10
# 
# Subtasks
# 
#     For 50% of the maximum score:
# 
#     * 1 <= q <= 10**3
#     * 1 <= x <= 10**4
# 
# Output Format
# 
# For each query, print the number of values of a satisfying the given conditions on a new line.
# 
# Sample Input 0
# 
#     2
#     2
#     10
# 
# Sample Output 0
# 
#     1
#     5
# 
*/

#include <stdio.h>
#include <stdlib.h>		// atoi

void the_great_xor_brute_force(int num)
{
	int count = 0;
	printf("%d :", num);
	for (int ix=0; ix<num; ix++) {
		if ((ix^num) > num) {
			count++;
			printf(" %d,",ix);
		}
	}
	printf(">> count=%d\n", count);
}

void the_great_xor(int num)
{
	int count=0;

	int b = (num >> 1);		// exclude bit-0 (LSB)
	int posCount = 2;		// bit-1 (2**1)

	while (b > 0) {
		int c = b&1;
        // toggle a bit==0 will create an XOR value greater than x
		if (c==0) { count += posCount;	}
		b >>= 1;
		posCount *= 2;
	}

	if ((num%2)==0) { count++; /* LSB */ }
	printf("%s: >> count=%d\n", __FUNCTION__, count);
}

int main(int argc, char **argv)
{
	int ix;
	for (ix = 1; ix < argc; ix++) {
		the_great_xor_brute_force(atoi(argv[ix]));
		the_great_xor(atoi(argv[ix]));
	}
	return 0;
}

