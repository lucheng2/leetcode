#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void Merge(int* nums, int left, int medium, int right) {
	int Llength = medium - left, Rlength = right - medium;
	int* L = (int*)malloc(sizeof(int) * (Llength + 1));
	int* R = (int*)malloc(sizeof(int) * (Rlength + 1));
	int i, j, k;
	for (i = 0; i < Llength; i++) {
		L[i] = nums[left + i];
	}
	for (i = 0; i < Rlength; i++) {
		R[i] = nums[medium + i];
	}
	L[Llength] = INT_MAX;
	R[Rlength] = INT_MAX;

	for (k = left, i = 0, j = 0; k < right; k++) {
		if (L[i] < R[j]) {
			nums[k] = L[i++];
		} else{
			nums[k] = R[j++];
		}
	}
}
/**
* nums: 要排序的数组
* left: 数组左边的索引（排序时包含）
* right: 数组右边的索引（排序时不包含）
**/
void MergeSort(int* nums, int left, int right) {
	if (left < right - 1) {
		int medium = (left + right) / 2;
		MergeSort(nums, left, medium);
		MergeSort(nums, medium, right);
		Merge(nums, left, medium, right);
	}
}

int main() {
	int test[] = { 2, 1, 4, 7, 9, 0 };
	MergeSort(test, 0, 6);
	return 0;
}