#include "common.h"

int maxSubarrayLength(vector<int>& nums, int k) {
	const int n = nums.size();
	int l = 0, r = 0, maxLen;
	unordered_map<int,int> freq;
	while(r < n)
	{
		if(freq[nums[r]] < k)
		{
			freq[nums[r++]]++;
			maxLen = max(maxLen, r-l);
		}
		else
		{
			while(freq[nums[r]] == k)
				freq[nums[l++]]--;
		}
	}

	return maxLen;
}