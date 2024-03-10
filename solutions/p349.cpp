#include "common.h"

vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
	int has[1001] = {0};
	std::vector<int> result; result.reserve(1000);
	for(int i: nums1) has[i] = 1;
	for(int i: nums2) if(has[i]-- > 0) result.push_back(i);
	return result; 
}