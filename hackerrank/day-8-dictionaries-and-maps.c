//https://www.hackerrank.com/challenges/30-dictionaries-and-maps
/*
# Day 8: Dictionaries and Maps
# 
# Objective 
# 
# Today, we're learning about Key-Value pair mappings using a Map or Dictionary data structure. Check
# out the Tutorial tab for learning materials and an instructional video!
# 
# Task 
# 
# Given n names and phone numbers, assemble a phone book that maps friends' names to their
# respective phone numbers. You will then be given an unknown number of names to query your phone
# book for. For each name queried, print the associated entry from your phone book on a new line
# in the form "name=phoneNumber"; if an entry for name is not found, print "Not found" instead.
# 
# Note: Your phone book should be a Dictionary/Map/HashMap data structure.
# 
# Input Format
# 
# The first line contains an integer, n, denoting the number of entries in the phone book. 
# Each of the n subsequent lines describes an entry in the form of 2 space-separated values on a
# single line. The first value is a friend's name, and the second value is an 8-digit phone number.
# 
# After the n lines of phone book entries, there are an unknown number of lines of queries. Each
# line (query) contains a name to look up, and you must continue reading lines until there is no
# more input.
# 
# Note: Names consist of lowercase English alphabetic letters and are first names only.
# 
# Constraints
# 
# 	* 1 <= n <= 10**5
# 	* 1 <= queries <= 10**5
# 
# Output Format
# 
# On a new line for each query, print "Not found" if the name has no corresponding entry in the
# phone book; otherwise, print the full name and phone Number in the format "name=phoneNumber".
# 
# Sample Input
# 
# 	3
# 	sam 99912222
# 	tom 11122222
# 	harry 12299933
# 	sam
# 	edward
# 	harry
# 
# Sample Output
# 
# 	sam=99912222
# 	Not found
# 	harry=12299933
# 
# Explanation
# 
# We add the following n = 3 (Key,Value) pairs to our map so it looks like this:
# 
# 	phoneBooks = { (sam,99912222), (tom,11122222), (harry,12299933) }
# 
# We then process each query and print "key=value" if the queried key is found in the map; otherwise, we print "Not found".
# 
# Query 0: sam 
# 	Sam is one of the keys in our dictionary, so we print "sam=99912222".
# 
# Query 1: edward 
# 	Edward is not one of the keys in our dictionary, so we print "Not found".
# 
# Query 2: harry 
# 	Harry is one of the keys in our dictionary, so we print "harry=12299933".
# 
*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

extern char *strdup(const char *s);

struct phoneEntry {
	char *name;
	char *number;
};

	static int
	comparePhoneEntry(const void *p1, const void *p2)
	{
		/* The actual arguments to this function are "pointers to
		   pointers to char", but strcmp(3) arguments are "pointers
		   to char", hence the following cast plus dereference */

		struct phoneEntry *pe1 = (struct phoneEntry *)p1;
		struct phoneEntry *pe2 = (struct phoneEntry *)p2;

		return strcmp(pe1->name, pe2->name);
	}

	static int mybsearch(struct phoneEntry arr[], int bix, int eix, char *target)
	{
		// cannt proceed
		if (bix > eix) { return -1; }
		//
		// find center point
		int ix = (eix+bix) / 2;
		if (strcmp(target, arr[ix].name) < 0) {
			return mybsearch(arr, bix, ix-1, target);
		}
		else if (strcmp(target, arr[ix].name) > 0) {
			return mybsearch(arr, ix+1, eix, target);
		}
		else /*(arr[ix] == target)*/
			return ix;
	}

int main()
{

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    

	// read # of phonebook entries
	int n;
	scanf("%d\n", &n);

	// built phonebooks
	struct phoneEntry *phoneBooks = calloc(n*sizeof(struct phoneEntry), 1);
	if ( phoneBooks == NULL ) {
		return -1;
	}
	//
	char name[32], number[16];
	struct phoneEntry *ptr = phoneBooks;
	for (int ix = 0; ix < n; ix++) {
		int rc = scanf("%s %s\n", name, number);
		ptr[ix].name = strdup(name);
		ptr[ix].number = strdup(number);
	}

	//*** sort phone book for better search performance
	qsort(phoneBooks, n, sizeof(struct phoneEntry), comparePhoneEntry);

	// continously read from stdin
	while (1) {
		int rc = scanf("%s\n", name);
		if (rc != 1) { break; }
		// search phoneBooks

		int iy = -1;
	#ifdef	_sequential_search_
		ptr = phoneBooks;
		for (iy = 0; iy < n; iy++) {
			if (strcmp(name, ptr[iy].name) == 0) { break; }
		}
		// not found (iy == n)
	#endif	//_sequential_search_

		iy = mybsearch(phoneBooks, 0, n-1, name);
		// not found (iy == -1)

		if (iy == -1) {
			printf("Not found\n");
		}
		else {
			printf("%s=%s\n", ptr[iy].name, ptr[iy].number);
		}
	}	// while (1)

	// release resource
	for (int ix = 0; ix < n; ix++) {
		free(ptr[ix].name);
		free(ptr[ix].number);
	}
	free(phoneBooks);

    return 0;
}
