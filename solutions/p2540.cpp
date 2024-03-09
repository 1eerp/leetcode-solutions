#include "common.h"

int getCommon(vector<int>& nums1, vector<int>& nums2) {
	const int m = nums1.size(), n = nums2.size(); 
	int i = 0, j = 0;
	while(i < m && j < n)
	{
		if(nums1[i] == nums2[j]) return nums1[i];
		else if (nums1[i] < nums2[j]) i++;
		else j++;
	}
	return -1;
}