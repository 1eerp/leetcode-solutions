#include "common.h"

vector<int> findDuplicates(vector<int>& nums) {
	bitset<100001> exists;
	vector<int> result; result.reserve((nums.size() >> 1)+1);
	for(int num : nums)
	{
		if(exists.test(num)) result.push_back(num);
		else exists.set(num);
	}
	return result;
}