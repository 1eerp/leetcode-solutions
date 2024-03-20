#include "common.h"

int compress(vector<char>& chars) {
	stringstream resultS; 
	int i = 1, curCount = 1;
	char lastChar = chars[0];
	while(i < chars.size())
	{
		if(chars[i] == lastChar) curCount++;
		else
		{

			resultS << lastChar;
			if(curCount > 1) resultS << to_string(curCount);
			curCount = 1;
			lastChar = chars[i];
		}
		i++;
	}
	resultS << lastChar;
	if(curCount > 1) resultS << to_string(curCount);

	string s = resultS.str();
	for(int i = 0; i < s.size(); i++)
		chars[i] = s[i];
	
	return s.size();
}