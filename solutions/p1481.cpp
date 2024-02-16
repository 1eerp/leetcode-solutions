#include "common.h"

int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
	unordered_map<int, int> mp;

	// Count the amount of times a number shows up
	for(int a: arr)
		mp[a]++;

	// Get an array of the counts and sort it
	vector<int> counts;
	int n = mp.size();
	counts.reserve(n);
	for(auto& kvp: mp)
		counts.emplace_back(kvp.second);

	sort(counts.begin(), counts.end());

	// Find result by reducing k by the counts, until k is negative       
	int i = 0;
	for(; i < n; i++)
	{
		k -= counts[i];
		if(k < 0) break;
	}

	return n - i;
}