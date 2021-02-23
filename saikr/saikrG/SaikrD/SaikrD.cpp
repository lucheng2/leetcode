// SaikrD.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

float max(float a, float b) {
    return a >= b ? a : b;
}
float min(float a, float b) {
    return a >= b ? b : a;
}
int main()
{
    int n;
    char* s[4];
    scanf("%d", &n);
    for (int i = 0; i < 4; i++) {
        s[i] = (char*)malloc(n * sizeof(char));
        scanf("%s", s[i]);
    }
    float result[4];
    for (int i = 0; i < 4; i++) {
        float acceTime = 0, totalTime=0, oneTime=0;
        for (int j = 0; j < n; j++) {
            if (acceTime > 0) {
                if (s[i][j] == '.') {
                    if (acceTime >= 0.5) {
                        totalTime += 0.5;
                        acceTime -= 0.5;
                    }
                    else
                    {
                        totalTime += 1 - 2 * acceTime + acceTime;
                        acceTime = 0;
                    }
                }
                else if (s[i][j] == 'w') {
                    if (acceTime >= 1) {
                        totalTime += 1;
                        acceTime -= 1;
                    }
                    else
                    {
                        totalTime += (1 - acceTime) * 2 + acceTime;
                        acceTime = 0;
                    }
                }
                else if (s[i][j] == '>') {
                    acceTime = 4.5;
                    totalTime += 0.5;
                }
                else if (s[i][j] == 's') {
                    totalTime += 1;
                    acceTime -= 1;
                    if (acceTime > 0) {
                        totalTime += 0.5;
                        acceTime -= 0.5;
                    }
                    else
                    {
                        totalTime += 1;
                    }
                }
                else if (s[i][j] == 'm') {
                    totalTime += 2;
                    acceTime -= 2;
                    if (acceTime > 0) {
                        totalTime += 0.5;
                        acceTime -= 0.5;
                    }
                    else
                    {
                        totalTime += 1;
                    }
                }
            }
            else {
                if (s[i][j] == '.') {
                    totalTime += 1;
                }
                else if (s[i][j] == 'w') {
                    totalTime += 2;
                }
                else if (s[i][j] == '>') {
                    totalTime += 0.5;
                    acceTime = 4.5;
                }
                else if (s[i][j] == 's') {
                    totalTime += 2;
                }
                else if (s[i][j] == 'm') {
                    totalTime += 3;
                }
            }
        }
        result[i] = totalTime;
    }
    printf("%.1f %.1f %.1f %.1f", result[0], result[1], result[2], result[3]);
    return 0;

}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
