#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//¹þÏ£±í


int romanToInt(char* s) {
	int *luomaTable = (int*)malloc(sizeof(int) * 128);
	luomaTable['I'] = 1;
	luomaTable['V'] = 5;
	luomaTable['X'] = 10;
	luomaTable['L'] = 50;
	luomaTable['C'] = 100;
	luomaTable['D'] = 500;
	luomaTable['M'] = 1000;

	int slength = strlen(s), i, result = 0;
	for (i = 0; i < slength; i++) {
		if (luomaTable[s[i]] < luomaTable[s[i + 1]]) {
			result -= luomaTable[s[i]];
		}
		else
		{
			result += luomaTable[s[i]];
		}
	}
	return result;
}

int main() {
	int j = 0x1111111122222222LL;
	char test[] = "IXIV";
	int result = romanToInt(test);
	printf("%d", result);
	return 0;

}