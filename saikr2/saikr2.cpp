// saikr2.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <stdio.h>
#include <algorithm>
using namespace std;

/**
* 带条件的背包问题：在连续的k个物体内必须要选一个
* 解决思路：先依次在k个间隔内的物体中选出价值最大的那一个，保证必要条件满足了之后，再在剩下的物品中用经典的0-1背包问题求解。
* 在上面的基础上加一个外层循环，数量为k，记录周期内的最大值。
* 
*/

int main()
{
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);
    vector<int> a(n, 0);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    int realMax = 0;
    int mcopy = m, ncopy = n;
    for (int z = 0; z < k; z++) {
        m = mcopy, n = ncopy;
        vector<int> iarray(n, 0);
        int nessValue = 0, nessCount = 0;

        if (z > 0) {
            int mi = 0, mv = a[0];
            for (int i = 0; i < z; i++) {
                if (mv < a[i]) {
                    mv = a[i];
                    mi = i;
                }
            }
            iarray[mi] = 1;
            nessValue += mv;
            nessCount++;
        }

        for (int index = z; index<n&&nessCount<m; ) {
            int mi = index, mv = a[index];
            for (int i = index; i < n && i < index + k; i++) {
                if (mv < a[i]) {
                    mv = a[i];
                    mi = i;
                }
            }
            iarray[mi] = 1;
            nessValue += mv;
            nessCount++;
            if (index + k >= n) {
                break;
            }
            index = mi+1;
        }

        vector<int> value(n - nessCount);
        int index = 0;
        for (int i = 0; i < n; i++) {
            if (iarray[i] != 1) {
                value[index++] = a[i];
            }
        }
        m = m - nessCount;

        vector<int> dp(m + 1, 0);
        for (int i = 0; i < value.size(); i++) {
            for (int j = m; j > 0; j--) {
                dp[j] = max(dp[j], dp[j - 1] + value[i]);
            }
        }

        realMax = max(realMax, dp[m] + nessValue);
    }
    printf("%d", realMax);
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
