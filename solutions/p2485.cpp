#include "common.h"

int seq(int n)
{
	return n * (n + 1) / 2; 
}

int pivotInteger(int n) {
	// x(x+1)/2 = n(n+1)/2 - x(x+1)/2 + x 
	// x(x+1) = n(n+1)/2 + x
	// x2 + x = (n2+n)/2 + x
	// x2 = (n2+n)/2
	// x = sqrt((n2+n)/2)

	int sum = seq(n);
	// Store the resulting pivot in an int, because pivot cannot be a decimal
	int pivot = sqrt(sum);
	
	// If pivot was a decimal that information is lost and the square will not evaluate to the sum
	return pivot * pivot == sum ? pivot : -1;
}