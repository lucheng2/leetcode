#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**
* ˼·��ʼ�ձ���a>=b�� la + 1����Ϊ����ĳ��ȣ�
* Ȼ��ӵ�λ��ʼ���ӷ���ֱ���ַ����������������λλcarry��1��������la+1�����򷵻�la���ȡ�
* �߽�����������Ϊ���ַ�������Ŀ��˵�˲�������û�У�
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