#include "common.h"

int findDuplicate(vector<int>& nums) {
	vector<int> dups(nums.size()+1, 0);
	for(int i : nums)
		if(dups[i]++) return i;
	
	return 0;
}