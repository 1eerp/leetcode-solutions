#include "common.h"

int uniquePaths(int m, int n) {
	vector<vector<int>> pathsFromPos(m, vector<int>(n,1));
	
	for(int i = m - 2; i > -1; i--)
		for(int j = n - 2; j > -1; j--)
			pathsFromPos[i][j] = pathsFromPos[i+1][j] + pathsFromPos[i][j+1];
	
	return pathsFromPos[0][0];
}