#include "common.h"

bool compare(string& s1, int n, string& s2)
{
	int end = s2.size();
	if(end % n) return false;
	int i = 0, j = 0;
	while(j < end)
	{
		if(s1[i] != s2[j++]) return false;
		i = (i + 1) % n;
	}
	return true;
}
string gcdOfStrings(string str1, string str2) {
	int m = str1.size(), n = str2.size();
	string& smaller = m < n ? str1: str2;
	string& bigger = m < n ? str2: str1;
	int size = smaller.size(), divisor = 2;
	while(size)
	{
		if(compare(smaller, size, smaller) && compare(smaller, size, bigger)) return smaller.substr(0, size);
		size = smaller.size() / divisor++;
	}

	return "";
}