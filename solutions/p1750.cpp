#include "common.h"

int minimumLength(string s) {
	int l = 0, r = s.size()-1;
	while(l < r && s[l] == s[r])
	{
		for(int i = l+1; l+1 < r && s[l] == s[i]; i++)
			l++;
		
		for(int i = r-1; l+1 < r && s[r] == s[i]; i--)
			r--;
		
		l++, r--;
	}
	return (r-l)+1;
}