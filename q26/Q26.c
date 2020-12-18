#include <stdio.h>
#include <stdlib.h>

/**
Q26
˫ָ��
indexָ���0��ʼ����ʾ��ͬ���ֵ����λ�ã�
tailָ���1��ʼ����������һ���ַ�����������飻
�������鰴�ղ�����˳���Ѿ��ź��ˣ�ֻ��Ҫ�Ƚ�indexλ�ú�tailλ�õ����������ͬ�Ͱ�tailλ�õ����ӵ���󼴿ɡ�
�߽���������鳤��С��2.
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