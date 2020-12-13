#include <stdio.h>

/**
* Q35 
* ˼·�����ֲ���
* ȡbegin end�������м�ֵhalf���Ƚ�λ���ϵ���ֵ��Ŀ��Ĵ�С�������ȣ��򷵻�half�����С�ڣ���ݹ����[half end]; ������ڣ���ݹ����[begin half].
* ֱ��begin �� endֻ���һ�����������жϡ�
* �߽�������numsize<=1, target���������м�
**/

int binarySearch(int* nums, int begin, int end, int target) {
	if (begin + 1 == end) {
		if (nums[begin] == target) {
			return begin;
		}
		else if (nums[end] == target) {
			return end;
		}
		else
		{
			return end;
		}
	}

	int half = (begin + end) / 2;
	if (nums[half] == target) {
		return half;
	}
	else if (nums[half] < target) {
		return binarySearch(nums, half, end, target);
	}
	else
	{
		return binarySearch(nums, begin, half, target);
	}
}

int searchInsert(int* nums, int numsSize, int target) {
	if (numsSize == 0 || target <= nums[0]) {
		return 0;
	}
	if (numsSize == 1) {
		return nums[0] >= target ? 0 : 1;
	}
	if (nums[numsSize - 1] < target) {
		return numsSize;
	}
	return binarySearch(nums, 0, numsSize, target);
}

int main() {
	//int test[] = { 1 };
	int test[] = { 1, 3, 4, 5, 7 };
	int target = 0;
	int numsSize = 5;
	int result = searchInsert(test, numsSize, target);
	printf("%d", result);
	return 0;
}