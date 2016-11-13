//https://leetcode.com/problems/add-two-numbers/ 
/*
#	2. Add Two Numbers
#	
#	You are given two linked lists representing two non-negative numbers. The digits are stored in
#	reverse order and each of their nodes contain a single digit. Add the two numbers and return it
#	as a linked list.
#	
#	Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
#	
#	Output: 7 -> 0 -> 8
#	
*/

enum {
	_leetcode_test_case_,
	_case1_,
	_case2_,
	_case3_,
	_case4_,
	_case5_,
} eTestcase;

#include <stdio.h>
#include <stdlib.h>

struct ListNode {
   int val;
   struct ListNode *next;
};

struct ListNode *reverseList(struct ListNode *ptr);
struct ListNode* addLists(struct ListNode* l1, struct ListNode* l2);


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
//	return addLists(reverseList(l1), reverseList(l2));
	return addLists(l1, l2);
}

void printList(struct ListNode *ptr)
{
	while (ptr) {
		printf("[%d] ", ptr->val);
		ptr = ptr->next;
	}
	printf("\n");
}

struct ListNode *reverseList(struct ListNode *ptr)
{
	struct ListNode *nptr = ptr, *tptr = NULL;
	while (ptr) {
		struct ListNode *cptr = ptr;
	#if 0
		if (cptr->next) { nptr = cptr->next; }
		//
		ptr = cptr->next;
		cptr->next = tptr;
		tptr = cptr;

	#else
		if (cptr->next) {
			nptr = cptr->next;
			cptr->next = tptr;
		}
		else {
			cptr->next = tptr;
			break;
		}
		tptr = cptr;
		ptr = nptr;
	#endif
	}
	return nptr;
}

struct ListNode* addLists(struct ListNode* l1, struct ListNode* l2)
{
//	printf("\n");
//	printf("l1: "); printList(l1);
//	printf("l2: "); printList(l2);

	int sum, carryOver = 0;
	struct ListNode *sumptr = NULL, *pptr = NULL;
	while (l1 || l2) {
		if (l1 && l2) {
			sum = l1->val + l2->val + carryOver;
		}
		else if (l1 == NULL) {
			sum = l2->val + carryOver;
		}
		else if (l2 == NULL) {
			sum = l1->val + carryOver;
		}
		else {
			break;
		}

		//
			if (sum > 9) {
				carryOver = 1;
				sum -= 10;
			}
			else { carryOver = 0; }

		// create the elememt
		struct ListNode *ptr;
			/// TODO: resource clean-up
			ptr = malloc(sizeof(struct ListNode));
			ptr->val = sum;
			ptr->next = NULL;
			//
			if (sumptr == NULL) { sumptr = ptr; }
			if (pptr   != NULL) { pptr->next = ptr; }
			pptr = ptr;

		//
		if (l1) { l1 = l1->next; }
		if (l2) { l2 = l2->next; }
	}
	// border condition - handle last carryOver
	if (carryOver)
	{
		// create the elememt
		struct ListNode *ptr;
			/// TODO: resource clean-up
			ptr = malloc(sizeof(struct ListNode));
			ptr->val = carryOver;
			ptr->next = NULL;
			//
			if (pptr   != NULL) { pptr->next = ptr; }
	}
	//
	return sumptr;
}

struct ListNode *build_list(int *nums, int len)
{
	int ix;
	struct ListNode *nodep = NULL, *ptr;
	for (ix = (len-1); ix >= 0; ix--)
	{
/// TODO: resource clean-up
		ptr = malloc(sizeof(struct ListNode));
		ptr->val = nums[ix];
		ptr->next = nodep;
		nodep = ptr;
	}
	return nodep;
}

struct ListNode *build_n1(int testcase)
{
/// TODO: resource clean-up
	struct ListNode *nodep, *ptr, *nptr;
	// build initial lists
	if (testcase == _leetcode_test_case_) {
		nodep = ptr = malloc(sizeof(struct ListNode));
		ptr->val = 2;
		ptr->next = malloc(sizeof(struct ListNode));
		//
		ptr = ptr->next;
		ptr->val = 4;
		ptr->next = malloc(sizeof(struct ListNode));
		//
		ptr = ptr->next;
		ptr->val = 3;
		ptr->next = NULL;
	}	//_leetcode_test_case_

	else if (testcase == _case1_) {
		nodep = ptr = malloc(sizeof(struct ListNode));
		ptr->val = 0;
		ptr->next = NULL;
	}	//_case1_

	else if (testcase == _case2_) {
		nodep = ptr = malloc(sizeof(struct ListNode));
		ptr->val = 5;
		ptr->next = NULL;
	}	//_case2_

	else if (testcase == _case3_) {
		nodep = ptr = malloc(sizeof(struct ListNode));
		ptr->val = 1;
		ptr->next = malloc(sizeof(struct ListNode));
		//
		ptr = ptr->next;
		ptr->val = 8;
		ptr->next = NULL;
	}	//_case3_

	else if (testcase == _case4_) {
		nodep = ptr = malloc(sizeof(struct ListNode));
		ptr->val = 9;
		ptr->next = malloc(sizeof(struct ListNode));
		//
		ptr = ptr->next;
		ptr->val = 8;
		ptr->next = NULL;
	}	//_case4_

	if (testcase == _case5_) {
		nodep = ptr = malloc(sizeof(struct ListNode));
		ptr->val = 9;
		ptr->next = malloc(sizeof(struct ListNode));
		//
		ptr = ptr->next;
		ptr->val = 9;
		ptr->next = NULL;
	}	//_case5_

	//
	return nodep;
}
struct ListNode *build_n2(int testcase)
{
/// TODO: resource clean-up
	struct ListNode *nodep, *ptr, *nptr;
	// build initial lists
	if (testcase == _leetcode_test_case_) {
		nodep = ptr = malloc(sizeof(struct ListNode));
		ptr->val = 5;
		ptr->next = malloc(sizeof(struct ListNode));
		//
		ptr = ptr->next;
		ptr->val = 6;
		ptr->next = malloc(sizeof(struct ListNode));
		//
		ptr = ptr->next;
		ptr->val = 4;
		ptr->next = NULL;
	}	//_leetcode_test_case_

	if (testcase == _case1_ || testcase == _case3_) {
		nodep = ptr = malloc(sizeof(struct ListNode));
		ptr->val = 0;
		ptr->next = NULL;
	}	//_case1_||_case3_

	if (testcase ==	_case2_) {
		nodep = ptr = malloc(sizeof(struct ListNode));
		ptr->val = 5;
		ptr->next = NULL;
	}	//_case2_

	if (testcase == _case4_ || testcase == _case5_) {
		nodep = ptr = malloc(sizeof(struct ListNode));
		ptr->val = 1;
		ptr->next = NULL;
	}	//_case4_||_case5_

	//
	return nodep;
}

int main()
{
	struct ListNode *n1, *n2;

#ifdef	_REVERSE_
//
	printf("n1: "); printList(n1=build_n1());
	printf("n2: "); printList(n2=build_n2());
//
	struct ListNode *rn1, *rn2;
	printf("rev n1: "); printList(rn1 = reverseList(n1));
	printf("rev n2: "); printList(rn2 = reverseList(n2));
//
	printf("n1: "); printList(n1);
	printf("n2: "); printList(n2);
//
	printf("add rev n1 & rev n2: "); printList(addLists(rn1, rn2));
#endif	//_REVERSE_

//
	printf("n1: "); printList(n1=build_n1(_leetcode_test_case_));
	printf("n2: "); printList(n2=build_n2(_leetcode_test_case_));
	printf("add n1 & n2: "); printList(addLists(n1, n2));
	printf("addTwoNumbers: "); printList(addTwoNumbers(n1,n2));

//
	int listL1[]={2,4,3,}; n1=build_list(listL1,3);
	int listL2[]={5,6,4,}; n2=build_list(listL2,3);
	printf("addTwoNumbers: "); printList(addTwoNumbers(n1,n2));

//
	printf("n1: "); printList(n1=build_n1(_case5_));
	printf("n2: "); printList(n2=build_n2(_case5_));
	printf("add n1 & n2: "); printList(addLists(n1, n2));
	printf("addTwoNumbers: "); printList(addTwoNumbers(n1,n2));

//
	int list51[]={9,9,}; n1=build_list(list51,2);
	int list52[]={1,};   n2=build_list(list52,1);
	printf("addTwoNumbers: "); printList(addTwoNumbers(n1,n2));

	return 0;
}
