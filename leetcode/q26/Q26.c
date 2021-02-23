#include <stdio.h>
#include <stdlib.h>

/**
Q26
双指针
index指针从0开始，表示不同数字的最后位置；
tail指针从1开始，遍历除第一个字符外的整个数组；
由于数组按照不降的顺序已经排好了，只需要比较index位置和tail位置的数，如果不同就把tail位置的数加到最后即可。
边界情况：数组长度小于2.
*/
int removeDuplicates(int* nums, int numsSize) {
	int tail;
	if (numsSize <= 1) {
		return numsSize;
	}
	int index = 0;
	for (tail = 1; tail < numsSize; tail++) {
		if (nums[index] != nums[tail]) {
			nums[++index] = nums[tail];
		}
	}
	return index + 1;
}

int main() {
	//test
	int test[] = { 1, 1, 2, 3, 3, 4 };
	int lent = 6;
	lent = removeDuplicates(test, lent);
	printf("%d", lent);

	return 0;
}