#include <stdio.h>
#include <stdlib.h>
#include<stdbool.h>

/**
* Q1
 * Note: The returned array must be malloced, assume caller calls free().
 * ����ѭ�������ν������[0,length-1)������Ϊһ������[index�� length-1]������Ϊ��һ��������ӵ���target�򷵻ض�Ӧ������������
 * �߽���������
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
	int* result = NULL;
	int i = 0, j = 0;
	for (i = 0; i < numsSize - 1; i++) {
		for (j = i + 1; j < numsSize; j++) {
			if (nums[i] + nums[j] == target) {
				result = (int*)malloc(sizeof(int) * 2);
				result[0] = i;
				result[1] = j;
				*returnSize = 2;
				return result;
			}
		}
	}
	return result;
}

int main() {
	int test[] = { 2, 7, 11, 15 };
	int i = 0;
	int* result = twoSum(test, 4, 9, &i);
	printf("%d %d", result[0], result[1]);
	free(result);

	return 0;
}