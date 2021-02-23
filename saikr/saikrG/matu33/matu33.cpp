#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void my_strcpy(char* destination, char* source) {
	if (destination != NULL && source != NULL) {
		int len = strlen(source);
		//memmove内存重叠情况也适用
		memmove(destination, source, len+1);
		//strcpy(destination, source);
		int i = 0;
		for (i = 0; i < strlen(destination); i++) {
			if (destination[i] == ' ') {
				destination[i] = '\0';
				return;
			}
		}
	}
	else {
		printf("%s", "error");
	}
}

int main() {
	char* destination, *source;
	source = (char*)malloc(10*sizeof(char));
	source[0] = '1';
	source[1] = '3';
	source[2] = 'a';
	source[3] = '.';
	source[4] = '\0';
	destination = source + 3;
	my_strcpy(destination, source);
	printf("%s", destination);
	return 0;
}