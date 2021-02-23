#include <stdio.h>
#include <stdlib.h>

/**
* Q28
* ˼·�����ν�haystack�ַ�����[0,hl-el+1]���ַ���Ϊ���ַ�����needle�ַ����бȽϣ������ȫ��ͬ�ˣ��ͷ�������ַ���index�����û�ҵ���ȫ��ͬ�ģ�����-1��
* �߽������needle�ַ�������Ϊ0��
**/
int strStr(char* haystack, char* needle) {
	int index = 0, i, haystackLength = strlen(haystack), needleLength = strlen(needle);
	if (needleLength == 0) {
		return 0;
	}
	for (; index <= haystackLength - needleLength; index++) {
		for (i = 0; i < needleLength; i++) {
			if (haystack[index + i] != needle[i]) {
				break;
			}
		}
		if (i == needleLength) {
			return index;
		}

	}
	return -1;
}

int main() {

	char h[] = "abcde";
	char n[] = "dc";
	int result = strStr(h, n);
	printf("%d", result);

	return 0;
}
