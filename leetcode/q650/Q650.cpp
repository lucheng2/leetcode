// Q650.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
using namespace std;

/**
* 分析，当元素为素数时，只能1个1个往上加，即 n / 1 = 次数；
当元素不是为素数时，此时可以进行分解 ，例如 6 = 2 * 3, 那么dp[6] = min (dp[3] + 2, dp[2] + 3);
以此类推，求解得答案。
**/
class Solution {
public:
    int minSteps(int n) {
        vector<int> dp(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            dp[i] = i;
        }
        dp[1] = 0;
        if (n <= 3) {
            return dp[n];
        }

        for (int i = 4; i <= n; i++) {
            int minCount = INT_MAX;
            for (int j = 1; j <= i; j++) {
                if (i % j == 0) {
                    minCount = min(minCount, dp[j] + i / j);
                }
                dp[i] = minCount;
            }
        }
        return dp[n];
    }
};


int main()
{
    Solution s;
    int r = s.minSteps(5);
    std::cout << "Hello World!\n";
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
