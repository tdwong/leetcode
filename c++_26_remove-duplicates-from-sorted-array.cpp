//https://leetcode.com/problems/remove-duplicates-from-sorted-array/
/*
#
# 26. Remove Duplicates from Sorted Array
#
#	Given a sorted array, remove the duplicates in place such that each element appear only once and return the new length.
#	
#	Do not allocate extra space for another array, you must do this in place with constant memory.
#	
#	For example,
#	Given input array nums = [1,1,2],
#	
#	Your function should return length = 2, with the first two elements of nums being 1 and 2 respectively.
#	It doesn't matter what you leave beyond the new length.
#
*/

#include <stdio.h>
#include <vector>

using namespace std;

/*
    39ms for all test leetcode cases
    23.76% leetcode ranking
 */
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int len = nums.size();
        if (len == 0) {  return 0; }
        int x = 0, y = 1;
        while (y < len) {
            if (nums[x] != nums[y]) {
                nums[x+1] = nums[y];
                x++; y++;
            }
            else {
                y++;
            }
        }
        return x+1;
    }
};

/*
 * apparently, using STL method to manipulate vector is slower
    49ms9ms for all test leetcode cases
    9.69% leetcode ranking
 */
class Solution1 {
public:
    int removeDuplicates(vector<int>& nums) {
        int len = nums.size();
        if (len == 0) {  return 0; }
        int x = 0, y = 1;
        while (nums.begin()+y != nums.end()) {
            if (nums[x] < nums[y]) {
                x++; y++;
            }
            else {
                nums.erase(nums.begin()+y);
            }
        }
        return nums.size();
    }
};

// testcases
int testcase[] = 
//  {};
//  {1, 1, 2};
//  {1, 2, 3, 4, 5};
//  {1, 1};
//  {1, 1, 1, 2, 3, 4, 5};
//  {1, 2, 3, 3, 3, 4, 5};
  {1, 1, 1, 2, 3, 3, 4, 5};

void printVector( const std::vector<int> & tcase )
{
    printf("[");
#if __cplusplus >= 199711L
    for (int val : tcase) { printf(" %d", val); }
#endif
    printf(" ]\n");
}

int main(int argc, char **argv)
{
    Solution  s;
    Solution1 s1;

    std::vector<int> tcase (testcase, testcase + sizeof(testcase)/sizeof(int));
    printf("init: "); printVector(tcase);

    printf("Solution: %d: ", s.removeDuplicates(tcase));
    printVector(tcase);

    printf("Solution: %d: ", s1.removeDuplicates(tcase));
    printVector(tcase);

}

