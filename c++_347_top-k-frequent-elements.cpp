//https://leetcode.com/problems/top-k-frequent-elements/
/*
#	347.. Top K Frequent Elements
#	
#	Given a non-empty array of integers, return the k most frequent elements.
#	
#	For example,
#	
#	Given [1,1,1,2,2,3] and k = 2, return [1,2].
#	
#	Note: 
#	- You may assume k is always valid, 1  k  number of unique elements.
#	- Your algorithm's time complexity must be better than O(n log n), where n is the array's size.
*/

#include <iostream>
#include <algorithm>	// std::sort
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

		vector<pair<int,int> > countedPairs;
		while (nums.size())
		{
			int value = *nums.begin();
			int count = 0;
			for (vector<int>::iterator it = nums.begin(); it != nums.end(); /**/)
			{
				if (*it == value) {
					count++;
					it = nums.erase(it);
				}
				else {
					it++;
				}
			}
			// option #2 keep value and count in a vector of pair
			countedPairs.push_back(make_pair(value, count));
		}
		/* option #2 vector contains <value,occurrence> pairs
		 */
		/* sort #1 sort the vector (based on second field)
		 */
		vector<pair<int,int> > sortedPairs, copiedPairs=countedPairs;
		vector<pair<int,int> >::iterator itmax = copiedPairs.begin();
		sortedPairs.clear();
		while (copiedPairs.size())
		{
			for (vector<pair<int,int> >::iterator it = copiedPairs.begin(); it != copiedPairs.end(); it++)
			{
				if (it->second > itmax->second) itmax = it;
			}
			sortedPairs.push_back(*itmax);
			copiedPairs.erase(itmax);
		}
		//
		int idx = 0;
		vector<int> retNums(k);
		for (idx = 0; idx < k; idx++)
		{
			retNums[idx] = sortedPairs[idx].first;
		}
		return retNums;

	}
};

		bool myComparison(const pair<int,int> &a,const pair<int,int> &b)
		{
			   return a.second<b.second;
		}

main()
{
	/* vector from an array
	 */
//	int myints[]= {10,20,30,40,50};
	int myints[]= {1,1,1,2,2,3,};
	vector<int> nums (myints, myints + sizeof(myints)/sizeof(int));
	vector<int> data = nums;
	cout << "begin: " << *data.begin() << endl;;
	cout << "end:   " << *data.end()   << endl;;
	for (vector<int>::iterator it = data.begin(); it != data.end(); /**/)
	{
		cout << "value: " << *it << endl;
		it++;
	}

	/* count occurrences (and record in a map)
	 */
	map <int,int> countedMap;		// <value,occurrence>
	vector<pair<int,int> > countedPairs;
	while (data.size())
	{
		int value = *data.begin();
		int count = 0;
		for (vector<int>::iterator it = data.begin(); it != data.end(); /**/)
		{
			if (*it == value) {
				count++;
				it = data.erase(it);
			}
			else {
				it++;
			}
		}
//		cout << "value: " << value << ", count=" << count << endl;
		// option #1 keep value and count in a map
		countedMap[value] = count;
		// option #2 keep value and count in a vector of pair
		countedPairs.push_back(make_pair(value, count));
	}
	/* option #1 map contains the value and its occurrence
	 */
	for (map<int,int>::iterator it = countedMap.begin(); it != countedMap.end(); it++)
	{
		cout << "countedMap[" << it->first << "]: " << it->second << endl;			// format#1
//		cout << "countedMap: [" << it->first << "," << it->second << "]" << endl;	// format#2 (same as countedPairs)
	}
	/* option #2 vector contains <value,occurrence> pairs
	 */
	for (vector<pair<int,int> >::iterator it = countedPairs.begin(); it != countedPairs.end(); it++)
	{
//		cout << "countedPairs[" << it->first << "]: " << it->second << endl;		// format#1 (same as countedMap)
		cout << "countedPairs: [" << it->first << "," << it->second << "]" << endl;	// format#2
	}
	/* sort #1 sort the vector (based on second field)
	 */
	vector<pair<int,int> > sortedPairs, copiedPairs=countedPairs;
			for (vector<pair<int,int> >::iterator it = copiedPairs.begin(); it != copiedPairs.end(); it++)
			{
				cout << "copiedPairs[" << it->first << "]: " << it->second << endl;			// format#1
			}
	vector<pair<int,int> >::iterator itmax = copiedPairs.begin();
	sortedPairs.clear();
	while (copiedPairs.size())
	{
		for (vector<pair<int,int> >::iterator it = copiedPairs.begin(); it != copiedPairs.end(); it++)
		{
			if (it->second > itmax->second) itmax = it;
		}
		sortedPairs.push_back(*itmax);
		copiedPairs.erase(itmax);
	}
	// print sorted
	int idx;
	idx = 0;
	for (vector<pair<int,int> >::iterator it = sortedPairs.begin(); it != sortedPairs.end(); it++, idx++)
	{
		cout << idx << ":sortedPairs: [" << it->first << "," << it->second << "]" << endl;	// format#2
	}
	/* sort #2 sort the vector (based on second field)
	 */
	sort(countedPairs.begin(), countedPairs.end(), myComparison);
	idx = 0;
	for (vector<pair<int,int> >::iterator it = countedPairs.begin(); it != countedPairs.end(); it++, idx++)
	{
		cout << idx << ":countedPairs.sorted: [" << it->first << "," << it->second << "]" << endl;	// format#2
	}

	//
	Solution s;
    vector<int> top = s.topKFrequent(nums, 2);
	for (vector<int>::iterator it = top.begin(); it != top.end(); it++)
	{
		cout << "top: " << *it << endl;
	}
}

