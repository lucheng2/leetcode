#include <stdio.h>
#include <stdlib.h>

// 递增排序的比较函数
int compare(const void* a, const void* b) {
	const int* p = a;
	const int* q = b;

	return *p - *q;
}

int isSpecialNum(int* nums, int numsSize, int key) {
	// 边界条件
	if (key == 0) {
		if (nums[numsSize - 1] < key) {
			return key;
		}
		else {
			return -1;
		}
	}
	else if (key == numsSize) {
		if (nums[0] >= key) {
			return key;
		}
		else {
			return -1;
		}
	}
	else
	{
		if (nums[numsSize - key] >= key && nums[numsSize - key - 1] < key) {
			return key;
		}
		else
		{
			return -1;
		}
	}
}

int specialArray(int* nums, int numsSize) {
	qsort(nums, numsSize, sizeof(nums[0]), compare);
	int i, result = -1;
	for (i = 0; i <= numsSize; i++) {
		result = isSpecialNum(nums, numsSize, i);
		if (result != -1) {
			return result;
		}
	}
	return result;
	}



int main() {
	int test[] = { 0, 1 };
	int result = specialArray(test, 2);
	printf("%d", result);
	return 0;
}