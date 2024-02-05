#include "common.h"

string minWindow(string s, string t) {
	if(t.size() > s.size() || t == "") return "";
	std::unordered_map<char, unsigned int> charCounts, windowCounts;
	const int MAXINT = 0x7fffffff;
	unsigned int charCount = 0, windowCount = 0;
	int curStart = 0, curEnd = 0, resultStart = 0, maxLen = MAXINT;

	// Count Characters in t
	for(char c: t)
	{
		charCounts[c]++;
		charCount++;
	}
	// Window
	for(int i = 0; i<s.size(); ++i)
	{
		char curChar = s[i];
		// If character is in t
		if(charCounts[curChar] > 0)
		{
			// Increment windowCount for that character
			windowCounts[curChar]++;
			// Increment the total windowCount unless this specific character already met its original count before this iteration
			windowCount += (windowCounts[curChar] <= charCounts[curChar]);
			curEnd = i;
		}
		// If the window count is satisfied reduce it from the front until it doesn't and continue
		while(windowCount == charCount)
		{
			// If the length of the window is smaller update the result
			int curLen = (curEnd-curStart)+1;
			if(curLen < maxLen)
			{
				resultStart = curStart;
				maxLen = curLen;
			}
			// Reduce
			char startChar = s[curStart];
			bool shouldReduce = charCounts[startChar]>0;
			windowCounts[startChar] -= shouldReduce;
			windowCount -= shouldReduce && (windowCounts[startChar] < charCounts[startChar]);
			curStart++;
		}
	}
	if(maxLen == MAXINT) return "";
	return s.substr(resultStart, maxLen); 
}