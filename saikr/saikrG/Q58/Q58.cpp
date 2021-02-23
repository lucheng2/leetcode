#include <stdio.h>
#include <string.h>

int lengthOfLastWord(char* s) {
	int length = strlen(s);
	if (length <= 0) {
		return 0;
	}
	int index = length;
	while (index-1>=0 && s[index - 1] == ' ') {
		index--;
	}
	if (index < 0) {
		return 0;
	}
	int end = index;
	while (index - 1 >= 0 && s[index - 1] != ' ') {
		index--;
	}
	return end - index;
	
}

int main() {
	char test[] = "  adsd   dfsdfs  ";
	int result = lengthOfLastWord(test);
	printf("%d", result);
	return 0;
}