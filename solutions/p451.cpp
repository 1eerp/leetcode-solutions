#include "common.h"

string frequencySort(string s) {
	int n = s.size();
	// If size is 1 return string
	if(n == 1) return s;
	int counts[75] = {0};
	// Count how many times a char shows up
	for(int i = 0; i < n; ++i)
		counts[s[i] - '0']++;

	// Sort
	std::vector<std::vector<char>> stringLists(n+1, std::vector<char>(0));
	for(int i = 0; i < 75; ++i)
	{
		int count = counts[i];
		if(!count) continue;
		stringLists[count].push_back('0' + i);
	}
	// If the stringLists[n] has any element that means a character was used n times in the string and n is the length of the string
	if(stringLists[n].size()) return s;
	// Crate Output string
	string result; result.reserve(n);
	for(int i = n; i > 0; --i)
	{
		// If no character has been used i times, then continue
		if(!stringLists[i].size()) continue;
		for(char c: stringLists[i])
			result.append(string(i, c));
	}
	return result;
    }