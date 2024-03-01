#include "common.h"

int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
	int lastRow = obstacleGrid.size() - 1;
	int lastCol = obstacleGrid[0].size() - 1;

	vector<vector<unsigned int>> matSpace(lastRow + 1, vector<unsigned int>(lastCol + 1, 0));
	matSpace[lastRow][lastCol] = !obstacleGrid[lastRow][lastCol];

	for(int i = lastRow - 1; i >= 0; i--)
		if(!obstacleGrid[i][lastCol] && matSpace[i+1][lastCol]) matSpace[i][lastCol] = 1;
	
	for(int i = lastCol - 1; i >= 0; i--)
		if(!obstacleGrid[lastRow][i] && matSpace[lastRow][i+1]) matSpace[lastRow][i] = 1;
	
	for(int i = lastRow - 1; i >= 0; i--)
		for(int j = lastCol - 1; j >= 0; j--)
			if(!obstacleGrid[i][j]) matSpace[i][j] = matSpace[i][j+1] + matSpace[i+1][j];

	return matSpace[0][0];
}