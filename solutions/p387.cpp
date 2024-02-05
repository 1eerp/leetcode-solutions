#include "common.h"

int firstUniqChar(string s) {
	int n = s.size(), i = 0;
	int arr[26] = {0};
	// Count how many times a character shows up in the string
	for(; i < n; ++i)
		arr[s[i] - 'a']++;
	
	// Return the index if the character has a count of 1
	for(i = 0; i < n; ++i)
		if(arr[s[i]-'a'] == 1) return i;

	// No unique characters found
	return -1;
}