#include "common.h"

int maxVowels(string s, int k) {
	const int n = s.size();
	// Mark characters that are vowels as true
	bool focusChars[128] = {false}; 
	focusChars['a'] = 1, focusChars['e'] = 1, focusChars['i'] = 1, focusChars['o'] = 1, focusChars['u'] = 1;

	// Mark characters in s that are vowels as true
	vector<bool> isVowel; isVowel.reserve(s.size());
	for(char c : s) isVowel.push_back(focusChars[c]);

	// Get the max of the first substring
	int sum = 0, i = 0, result;
	for(;i < k; i++) sum += isVowel[i];
	result = sum;

	// Slide window through the string
	for(;i < n && result != k; i++)
	{
		sum += isVowel[i] - isVowel[i-k];
		result = max(result, sum);
	}
	return result;
}