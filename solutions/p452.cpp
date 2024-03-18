#include "common.h"

int findMinArrowShots(vector<vector<int>>& points) {
	sort(points.begin(), points.end(), [](vector<int>& a , vector<int>& b) {return a[0] < b[0];});


	int result = 0, rangeStart = INT_MIN, rangeEnd = INT_MAX;
	for(auto& point : points)
	{
		if(point[0] > rangeEnd)
		{
			result++;
			rangeStart = point[0];
			rangeEnd = point[1];
		}
		else
		{
			rangeStart = max(rangeStart, point[0]);
			rangeEnd = min(rangeEnd, point[1]);
		}
	}
	
	return result+1;
}