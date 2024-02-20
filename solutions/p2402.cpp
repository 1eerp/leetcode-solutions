#include "common.h"


using uint_pair = pair<unsigned int, unsigned int>;
int mostBooked(int n, vector<vector<int>>& meetings) {
	// SORT by Meeting start time
	std::sort(meetings.begin(), meetings.end(), [](vector<int>& a, vector<int>& b) { return a[0] < b[0];});
	priority_queue<uint_pair, vector<uint_pair>, greater<uint_pair>> roomQueue;
	priority_queue<uint32_t, vector<uint32_t>, greater<uint32_t>> ars;

	for(int i = 0; i < n; i++)
		ars.push(i);
	
	vector<int> meetingsCount(n,0);
	for(int i = 0; i < meetings.size(); i++)
	{
		unsigned int nextMS = static_cast<unsigned int>(meetings[i][0]), nextME =  static_cast<unsigned int>(meetings[i][1]);
		// AR = AVAIALBALE ROOM, ET = END TIME, ARI = ARIndex
		unsigned int nextARE, nextARI;

		while(roomQueue.size() && nextMS >= roomQueue.top().first)
		{
			nextARI = roomQueue.top().second;
			ars.push(nextARI);
			roomQueue.pop();
		}
		
		if(ars.size())
		{
			nextARI = ars.top();
			ars.pop();
		}
		else
		{
			const uint_pair temp = roomQueue.top();
			nextARE = temp.first;
			nextARI = temp.second;
			nextME += nextARE - nextMS;
			roomQueue.pop();
		}
		
		roomQueue.push({nextME, nextARI});
		meetingsCount[nextARI]++;
	}
	
	int maxIndex = 0;
	for(int i = 1; i < n; i++)
	{
		bool t = meetingsCount[i] > meetingsCount[maxIndex];
		maxIndex = i * t + maxIndex * !t;
	}

	return maxIndex;
}