#include "common.h"

// Initial Solution - Not O(n) auxiliary space
int firstMissingPositive(vector<int>& nums) {
	const int n = nums.size();
	bitset<100001> exists;

	for(int num : nums)
		if(num <= n && num > 0) exists.set(num);
	
	for(int i = 1; i <= n; i++)
		if(!exists.test(i)) return i;
	
	return n+1;
}

// Solution using cyclic sort - O(n) auxiliary space
int firstMissingPositive(vector<int>& nums) {
	const int n = nums.size();
	int i = 0;
	while(i < n)
	{
		if(nums[i] <= n && nums[i] > 0 && nums[i] != nums[nums[i] -  1]) 
			swap(nums[i], nums[nums[i] -  1]);
		else
			i++;
	}
	
	for(i = 0; i < n; i++)
		if(nums[i] != i+1) return i+1;
	
	return n+1;
}