#include "common.h"

// HELPER FUNCTION
string sortString(const string& s)
{
	char arr[26] = {0};
	for(int i = 0; i < s.size(); ++i)
		arr[s[i]-'a']++;

	string r;
	for(int i = 0; i < 26; ++i)
	{
		if(arr[i] == 0)
			continue;
		r.push_back('a'+i);
		// arr[i] will always be at least less than 100 so it can be represented in 1 byte
		r.push_back(arr[i]);
	}
	return r;
}

vector<vector<string>> groupAnagrams(vector<string>& strs) {
	unordered_map<string,vector<string>> mapped_result;
	for(auto& s: strs)
		mapped_result[sortString(s)].push_back(s);

	// move resulting vectors for output
	vector<vector<string>> result;
	for(auto& kvp: mapped_result)
		result.emplace_back(std::move(kvp.second));
	return result;
}