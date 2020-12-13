#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

int main() {
	char input[21];
	scanf("%s", input);
	//½Ø¶Ï
	input[20] = '\0';
	int length = strlen(input);
	//³ö´íÅÐ¶Ï
	if (length <= 0) {
		printf("error");
		return 0;
	}
	int i;
	for (i = 0; i < length; i++) {
		if (input[i] < 'A' || (input[i] > 'Z' && input[i] < 'a') || input[i] > 'z') {
			printf("error");
			return 0;
		}
	}

	for (i = 0; i < length; i++) {
		if ((input[i] >= 'A' && input[i] <= 'V') || (input[i] >= 'a' && input[i] <= 'v')) {
			input[i] += 4;
		}
		else
		{
			input[i] += 4 - 26;
		}
	}
	printf("%s", input);
	return 0;

}