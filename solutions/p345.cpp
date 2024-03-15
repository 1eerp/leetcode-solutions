#include "common.h"

string reverseVowels(string s) {
	// MARK CHARS THAT NEET TO BE REVERSES
	char reverseAlph[256] = {0};
	char start = 'A';
	reverseAlph[start] = 1, reverseAlph[start + 4] = 1,reverseAlph[start + 8] = 1, reverseAlph[start + 14] = 1, reverseAlph[start + 20] = 1; 
	start = 'a';
	reverseAlph[start] = 1, reverseAlph[start + 4] = 1,reverseAlph[start + 8] = 1, reverseAlph[start + 14] = 1, reverseAlph[start + 20] = 1;    
	
	const int n = s.size();
	int l = 0, r = n-1;
	while(l < r)
	{
		while(!reverseAlph[s[l]] && l < r) l++;
		while(!reverseAlph[s[r]] && l < r) r--;
		if (l >= r) break;
		char temp = s[l];
		s[l++] = s[r];
		s[r--] = temp;
	}
	return s;
}