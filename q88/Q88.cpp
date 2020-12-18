#include <stdio.h>

/**
* ˼·����nums1��m����������ƶ�n����Ȼ���úϲ������merge���ϲ��������飬����Ҫע��ĳ���������֮��Ĳ�����
* �߽�������1��������һ������Ϊ�գ�
**/
void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
	int i, j, k;
	if (n == 0) {
		return;
	}
	if (m == 0) {
		for (i = 0; i < n; i++) {
			nums1[i] = nums2[i];
		}
		return;
	}

	for (i = m-1; i >= 0; i--) {
		nums1[i + n] = nums1[i];
	}

	for (i = 0, j = 0, k = 0; i < m && j < n; k++) {
		if (nums1[i + n] <= nums2[j]) {
			nums1[k] = nums1[i + n];
			i++;
		}
		else {
			nums1[k] = nums2[j];
			j++;
		}
	}

	if (i == m) {
		for (; j < n; j++, k++) {
			nums1[k] = nums2[j];
		}
	}
}

int main() {
	int nums1[] = { 1,2,3,0,0 }, nums2[] = { 1, 5 };
	merge(nums1, 5, 3, nums2, 2, 2);
	return 0;
}