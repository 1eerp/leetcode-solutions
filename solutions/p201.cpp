#include "common.h"

int rangeBitwiseAnd(int left, int right) {
	int difference = right - left;
	int count = 0;
	while(difference > 0)
	{
		difference >>= 1;
		count++;
	}
	
	return left & (0x7fffffff << count) & right;
}