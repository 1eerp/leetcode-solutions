#include "common.h"

vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
	map<int, vector<pair<int,int>>> sortedM;
	for(auto& m : meetings)
		sortedM[m[2]].push_back({m[0],m[1]});
	
	vector<int> knows(n, 0);
	knows[0] = 1;
	knows[firstPerson] = 1;
	// n = 5, meetings = [[3,4,2],[1,2,1],[2,3,1]], firstPerson = 1
	// 

	for(auto& ms : sortedM)
	{
		int t;
		do
		{
			t=0;
			for(auto& m : ms.second)
			{
				if(knows[m.first] ^ knows[m.second])
				{
					knows[m.first] = 1;
					knows[m.second] = 1;
					t++;
				}
			}
		}
		while(t);
	}
	vector<int> result;
	result.reserve(n);
	for(int i = 0; i<n; i++)
		if(knows[i]) result.push_back(i);
	return result;
}