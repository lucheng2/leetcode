// M0801.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
using namespace std;

/**
* 动态规划：状态转移方程dp[i] = dp i-1, i-2， i-3之和
* 空间优化：用滚动数组，只需要4个long int即可
**/
class Solution {
public:
    int waysToStep(int n) {
        vector<long int> dp(4);
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 3;
        dp[3] = 4;
        if (n <= 3) {
            return dp[n];
        }
        for (int i = 4; i <= n; i++) {
            dp[0] = dp[1];
            dp[1] = dp[2];
            dp[2] = dp[3];
            dp[3] = (dp[0] + dp[1] + dp[2]) % 1000000007;
        }
        return dp[3];
    }
};

int main()
{
    int n = 5;
    Solution s;
    int r = s.waysToStep(n);
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
