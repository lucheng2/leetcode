#include <stdio.h>
#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize) {
	int carry = 0, index = digitsSize;
	do
	{
		if (index-1>=0)
		{
			digits[index - 1] ++;
			carry = digits[index - 1] / 10;
			digits[index - 1] %= 10;
			index--;
		}
		else
		{
			break;
		}
	} while (carry!=0);

	int* result = (int*)malloc(sizeof(int) * (digitsSize + 1));
	int i = 0;
	for (i = 0; i < digitsSize; i++) {
		result[i + 1] = digits[i];
	}
	if (carry == 0) {
		result = &result[1];
		*returnSize = digitsSize;
	}
	else
	{
		result[0] = carry;
		*returnSize = digitsSize + 1;
	}
	return result;
}

int main() {
	int test[] = { 9 }, returnSize;
	int* result = plusOne(test, 1, &returnSize);
	return 0;
}