#include "common.h"

int minPathSum(vector<vector<int>>& grid) {
	int lastRowI = grid.size()-1;
	int lastColI = grid[0].size()-1;

	vector<vector<int>> matrix(lastRowI+1, vector<int>(lastColI+1, 0));
	matrix[lastRowI][lastColI] = grid[lastRowI][lastColI];

	// Calculate path matrix last column
	for(int i = lastRowI-1; i >= 0; i--)
		matrix[i][lastColI] = grid[i][lastColI] + matrix[i+1][lastColI];
	
	// Calculate path matrix last column
	for(int i = lastColI-1; i >= 0; i--)
		matrix[lastRowI][i] = grid[lastRowI][i] + matrix[lastRowI][i+1];
	
	// Calculate path from all other squares
	for(int i = lastRowI - 1; i >= 0; i--)
		for(int j = lastColI - 1; j >= 0; j--)
			matrix[i][j] = grid[i][j] + min(matrix[i+1][j], matrix[i][j+1]);

	return matrix[0][0];
}