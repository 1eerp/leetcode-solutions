#include "common.h"

int maximalSquare(vector<vector<char>>& matrix) {
	int rows = matrix.size();
	int cols = matrix[0].size();
	vector<vector<int>> dp(rows, vector<int>(cols, 0));

	int mx = 0;
	for(int i = 0; i < rows; i++)
		mx += dp[i][0] = matrix[i][0] - '0';
	
	for(int i = 1; i < cols; i++)
		mx += dp[0][i] = matrix[0][i] - '0';
	
	mx = mx > 0;
	for(int i = 1; i < rows; i++)
	{
		for(int j = 1; j < cols; j++)
		{
			char cur = (matrix[i][j] - '0');
			dp[i][j] = cur * min(min(dp[i][j-1], dp[i-1][j-1]), dp[i-1][j]) + cur;
			mx = max(mx, dp[i][j]);
		}
	}

	return mx*mx;
}