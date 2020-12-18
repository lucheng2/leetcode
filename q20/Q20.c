#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

/**
* Q20
* 用栈结构来表示括号的匹配关系：左括号入栈，右括号出栈。当右括号出栈没有对应的左括号时，判断不合法。
* 字符串遍历完成，栈为空则合法，不空则非法。
* 用hash表来返回对应的左括号。
**/

char getLeft(char c) {
	if (c == '}') return '{';
	if (c == ')') return '(';
	if (c == ']') return '[';
	return (char)0;
}

bool isValid(char* s) {
	int length = strlen(s);
	char* stack = (char*)malloc(sizeof(char) * length);
	int top = 0, i;
	for (i = 0; i < length; i++) {
		if (getLeft(s[i]) == 0) {
			//入栈
			stack[top++] = s[i];
		}
		else
		{
			if (top-1<0 || stack[top - 1] != getLeft(s[i])) {
				return false;
			}
			else
			{
				//出栈
				top--;
			}
		}
	}
	if (top == 0) {
		return true;
	}
	else
	{
		return false;
	}
	
}

int main() {
	char test[] = "{}([])";
	bool result = isValid(test);
	printf("%d", result);
	return 0;
}

//int main() {
//	int n, i;
//	scanf("%d", &n);
//	if (n <= 3) {
//		printf("error");
//		return 0;
//	}
//	int sqrtN = (int) sqrt((double)n);
//	for (i = 2; i <= sqrtN; i++) {
//		if (n % i == 0) {
//			printf("no");
//			return 0;
//		}
//	}
//	printf("yes");
//	return 0;
//}