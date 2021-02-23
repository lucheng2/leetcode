#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**
* 思路：始终保持a>=b， la + 1，作为结果的长度；
* 然后从低位开始做加法，直到字符串被遍历，如果进位位carry是1，则结果是la+1，否则返回la长度。
* 边界条件：加数为空字符串（题目中说了测试用例没有）
**/
char* addBinary(char* a, char* b) {
	int La = strlen(a), Lb = strlen(b);
	if (La < Lb) {
		char* temp = b;
		b = a;
		a = temp;
		int Ltemp = La;
		La = Lb;
		Lb = Ltemp;
	}
	int indexA = La - 1, indexB = Lb -1, index;
	char carry = 0, tempResult;
	char* result = (char*)malloc(sizeof(char) * (La + 2));
	result[La + 1] = '\0';
	for (index = La; indexA >= 0 || indexB >= 0; index--) {
		if (indexB >= 0) {
			tempResult = (a[indexA--] - '0') + (b[indexB--] - '0') + carry;
			result[index] = tempResult % 2 + '0';
			carry = tempResult / 2;
		}
		else
		{
			tempResult = (a[indexA--] - '0') + carry;
			result[index] = tempResult % 2 + '0';
			carry = tempResult / 2;
		}
	}
	if (carry == 0) {
		return result + 1;
	}
	else
	{
		result[0] = '1';
		return result;
	}
}

int main() {
	char c1[] = "1101", c2[] = "0001";
	char* result = addBinary(c1, c2);
	printf("%s", result);
	return 0;
}