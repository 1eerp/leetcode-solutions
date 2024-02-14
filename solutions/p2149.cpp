#include "common.h"

vector<int> rearrangeArray(vector<int>& nums) {
	int indices[2] = {0, 1};
	const int n = nums.size();

	std::vector<int> result(n); 
	for(int i = 0; i < n; i++)
	{
		int* indexP = indices + (nums[i] < 0);
		result[*indexP] = nums[i];
		*indexP += 2;
	}
	return result;
}