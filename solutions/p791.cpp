#include "common.h"

string customSortString(string order, string s) {
	string result;
	result.reserve(s.size());
	// Originally used map, but an array should work
	uint8_t ord[256] = {0};
	int count[256] = {0};

	// Mark chars that are in order
	for(int i = 0; i < order.size(); i++) ord[order[i]] = 1;
	// Count chars in s
	for(char c : s) count[c]++;
	// Append chars in order
	for(char c : order) result.append(count[c], c);
	// Append chars not in order
	for(char c = 'a'; c <= 'z'; c++) if(ord[c] == 0) result.append(count[c], c);

	return result;
}