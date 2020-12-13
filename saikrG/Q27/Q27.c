#include <stdio.h>

/**
* Q27
* ˼·��˫ָ�룬index��0��ʼ��tail[0, numsSiez)��������������������ֵ��index
* �߽磺����Ϊ��.
**/
int removeElement(int* nums, int numsSize, int val) {
	int index = 0, tail = 0;
	for (tail = 0; tail < numsSize; tail++) {
		if (val != nums[tail]) {
			nums[index++] = nums[tail];
		}
	}
	return index;
}

int main() {
	int test[] = { 3,2,2,3 };
	int length = 4;
	int val = 3;
	int result = removeElement(test, length, val);
	printf("%d ", result);

}