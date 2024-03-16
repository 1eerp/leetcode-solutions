#include "common.h"

int findMaxLength(vector<int>& nums) {
	int result = 0, sum = 0;
	unordered_map<int,int> prefix;
	prefix[0] = -1;

	for(int i = 0; i < nums.size(); i++)
	{
		sum += nums[i] - !nums[i];
		if(prefix.find(sum) != prefix.end())
			result = max(result, i - prefix[sum]);
		else
			prefix[sum] = i;
	}
	return result;
}