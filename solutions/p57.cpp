#include "common.h"

// TODO: This is a naive solution, rethink for a more readable solution 
vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
	const int n = intervals.size();
	vector<vector<int>> result;
	int i = 0;
	while(i < n && intervals[i][0] < newInterval[0] && intervals[i][1] < newInterval[0]) 
		result.emplace_back(intervals[i++]);

	if(i < n) newInterval[0] = min(newInterval[0], intervals[i][0]);
	while(i < n && (intervals[i][0] <= newInterval[1] || intervals[i][1] <= newInterval[1]))
		newInterval[1] = max(newInterval[1], intervals[i++][1]);
	result.emplace_back(newInterval);

	while(i < n)
		result.emplace_back(intervals[i++]);

	return result;
}