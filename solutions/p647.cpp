#include "common.h"

int countPalindromesFromCenter(const string& t, int l, int r)
{
	int result = 0;
	while(l >= 0 && r <= t.size())
	{
		if(t[l--] == t[r++]) result++;
		else break;
	}
	return result;
}

	int countSubstrings(string s) {
	int n = s.size(), result = 0;
	for(int i = 0; i < n; ++i)
		result += countPalindromesFromCenter(s, i-1, i+1) + countPalindromesFromCenter(s, i,i+1) + 1;

	return result;
}