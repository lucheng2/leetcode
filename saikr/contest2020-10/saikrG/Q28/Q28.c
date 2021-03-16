#include <stdio.h>
#include <stdlib.h>

/**
* Q28
* 思路：依次将haystack字符串的[0,hl-el+1]个字符作为首字符，与needle字符进行比较，如果完全相同了，就返回这个字符的index；如果没找到完全相同的，返回-1。
* 边界情况：needle字符串长度为0。
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
