#include "common.h"

string longestPalindrome(string s) {
	const int n = s.size();
	int curMax = 0;
	string result; result.reserve(n);
	
	for(int i = 0; i < n; i++)
	{
		int l = i, r = i;
		while(r < n && l >= 0 && s[l] == s[r++])
		{
			int temp = r - l--;
			if(temp > curMax)
			{
				result = s.substr(l+1, temp);
				curMax = temp;
			}
		}

		l = i, r = i+1;
		while(r < n && l >= 0 && s[l] == s[r++])
		{
			int temp = r - l--;
			if(temp > curMax)
			{
				result = s.substr(l+1, temp);
				curMax = temp;
			}
		}
	}
	return result;
}