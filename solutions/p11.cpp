#include "common.h"

int maxArea(vector<int>& height) {
	int p1 = 0, p2 = height.size() - 1;

	int max = 0;
	while(p1 < p2)
	{
		const int & h1 = height[p1], & h2 = height[p2];
		int vol = (p2-p1) * min(h1, h2);
		max = max * !(vol > max) + vol * (vol > max);
		if(h1 < h2) p1++;
		else p2--;

	}
	return max;
}