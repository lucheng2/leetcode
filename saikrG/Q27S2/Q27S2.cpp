#include <stdio.h>

/**
* Q27
* ˼·������һ�Σ�����˳���ǿ��Ա仯�ģ����indexλ�õ�ֵ����val��ֻ��Ҫ���������һ��δ��֤��������λ�ã���������֤���ɡ�
* �߽磺����Ϊ��.
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