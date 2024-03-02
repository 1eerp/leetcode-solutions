#include "common.h"

int minimumTotal(vector<vector<int>>& triangle) {
	int m = triangle.size();
	vector<int> result(m, 0), temp(m);
	result[0] = triangle[0][0];
	for(int i = 1; i < m; i++)
	{
		temp = result;
		result[0] += triangle[i][0];
		for(int j = 1; j < i; j++)
			result[j] = triangle[i][j] + min(temp[j-1], temp[j]);
		result[i] = triangle[i][i] + temp[i-1];
	}

	int min = INT_MAX;
	for(int i: result)
		min = (i < min) * i+ !(i < min) * min;
	
	return min;
}