#include "common.h"

long long largestPerimeter(vector<int>& nums) {
	const int n1 = nums.size() - 1;
	// Sort Ascending
	std::sort(nums.begin(), nums.end());

	// Get a sum excluding the last element
	long long sum = 0;
	for(int i = 0; i < n1; i++)
		sum += nums[i];
	
	for(int i = n1; i > 1; i--)
	{
		if(nums[i] < sum) return sum + nums[i];
		sum -= nums[i-1];
	}

	return -1;        
}