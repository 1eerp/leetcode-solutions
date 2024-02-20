#include "common.h"

int rob(vector<int>& nums) {
	const int n = nums.size();
	int t1 = nums[0], t2, t3;
	if(n == 1) return t1;
	t2 = max(t1, nums[1]);
	if(n == 2) return t2;

	for(int i = 2; i < n; i++)
		t3 = max(t2,t1 + nums[i]), t1 = t2, t2 = t3;
	
	return t3;
}