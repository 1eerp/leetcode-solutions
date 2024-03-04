#include "common.h"

int bagOfTokensScore(vector<int>& tokens, int power) {
	sort(tokens.begin(), tokens.end());
	int score = 0;
	int maxScore = 0;
	int l = 0, r = tokens.size()-1;
	if(!tokens.size()) return 0;

	do
	{
		if(tokens[l] <= power)
		{
			score++, power -= tokens[l++];  
			if(score > maxScore) maxScore = score;
		}
		else if(score > 0)
		{
			power += tokens[r--];
			score--;
		}
		else break;
	}
	while(l <= r);

	return maxScore;
}