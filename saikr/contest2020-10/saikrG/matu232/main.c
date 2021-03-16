#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main() {
	char input[100];
	char output[150];
	scanf("%s", input);
	int len = strlen(input), i,j;
	for (i = 0, j = 0; i <= len; i++, j++) {
		output[j] = input[i];
		//每两个字符加一个*，最后的不加
		if (i % 2 == 1 && i != len-1) {
			output[++j] = '*';
		}
	}
	printf("%s\n", output);
}

