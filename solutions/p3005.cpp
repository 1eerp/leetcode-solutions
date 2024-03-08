#include "common.h"

int maxFrequencyElements(vector<int>& nums) {
	std::unordered_map<int, int> freq, freqFreq;
	// Store Freq
	for(int num : nums) freq[num]++;

	int m = INT_MIN;
	for(auto kvp : freq)
	{
		freqFreq[kvp.second] += kvp.second;
		m = max(m, kvp.second);
	}

	return freqFreq[m];
}