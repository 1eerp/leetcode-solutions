#include "common.h"

int numSubarrayProductLessThanK(vector<int>& nums, int k) {
	if(k < 2) return 0;
	const int n = nums.size();
	int l = 0, r = 0, result = 0;
	long int prod = 1;
	while(r < n)
	{
		if(prod < k)
		{
			prod *= nums[r];
			result += (prod < k) * (r - l + 1);
			r++;
		}
		else
		{
			while(prod >= k)
				prod /= nums[l++];
			result += (r - l);
		}
	}
	bool needed = prod >= k;
	while(prod >= k)
		prod /= nums[l++];
	result += needed * (r - l);

	return result;
}