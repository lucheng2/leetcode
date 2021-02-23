// saikrG.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <stdio.h>

int com(int n, int i) {
    int result = 1;
    for (int j = 1; j < i + 1; j++) {
        result = result * (n - i + j) / j % (1000000007);
    }
    return result;
}

int main()
{
    int k, a, b, l, r;
    scanf("%d %d %d %d %d", &k, &a, &b, &l, &r);

    int result = 0, fl = 1, fr = 1;
    for (int i = 0; i < l - 1; i++) {
        int temp = fr;
        fr = a * fr + b * fl;
        fl = temp;
    }
    for (int i = l; i < r + 1; i++) {
        result = (result + com(fl, k)) % 1000000007;
        int temp = fr;
        fr = a * fr + b * fl;
        fl = temp;
    }
    printf("%d", result);
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
