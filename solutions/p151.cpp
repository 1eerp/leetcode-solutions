#include "common.h"

std::pair<int,int> strip(string& s)
{
	int start = 0, end = s.size()-1;
	for(int i = 0; i <= end; i++)
		if(isspace(s[i])) start++; else break;
	
	for(int i = end; i >= 0 && start < end; i--)
		if(isspace(s[i])) end--; else break;
	
	return {start, end};
}

string reverseWords(string s) {
	auto [start, end] = strip(s);
	vector<string> words;
	string word; word.reserve(s.size());
	for(int i = start; i <= end; i++)
	{
		bool isSpace = isspace(s[i]);
		if(!isSpace)
		{
			word.push_back(s[i]);
		}
		else if (isspace(s[i]) && word.size())
		{
			words.emplace_back(word);
			word.clear();
		}
	}
	words.emplace_back(word);
	word.clear();

	stringstream ss;
	ss << *(words.rbegin());
	for(auto it = words.rbegin()+1; it != words.rend(); it++)
		ss << ' ' <<  *it;
	
	return ss.str();
}