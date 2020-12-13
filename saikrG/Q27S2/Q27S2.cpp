#include <stdio.h>

/**
* Q27
* 思路：遍历一次，由于顺序是可以变化的，如果index位置的值等于val，只需要把它与最后一个未验证的数交换位置，再重新验证即可。
* 边界：长度为０.
**/
int removeElement(int* nums, int numsSize, int val) {
	int sameCount = 0, index = 0, temp;
	for (index = 0; index < numsSize - sameCount; index++) {
		if (nums[index] == val) {
			temp = nums[index];
			nums[index] = nums[numsSize - sameCount - 1];
			nums[numsSize - sameCount - 1] = temp;
			index--;
			sameCount++;
		}
	}
	return numsSize - sameCount;
}

int main() {
	int test[] = { 3,2,2,3 };
	int length = 4;
	int val = 3;
	int result = removeElement(test, length, val);
	printf("%d ", result);

}