#include <stdio.h>

/**
* Q35 
* 思路：二分查找
* 取begin end索引的中间值half，比较位置上的数值与目标的大小。如果相等，则返回half；如果小于，则递归调用[half end]; 如果大于，则递归调用[begin half].
* 直到begin 与 end只间隔一个，做最后的判断。
* 边界条件：numsize<=1, target不在数组中间
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