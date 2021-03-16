#include <stdio.h>
#include <math.h>

int mySqrt(int x) {
	return (int)sqrt((double) x);
}
int main() {
	int test = 8;
	int result = mySqrt(test);
	return 0;
}