// Q714.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>

using namespace std;

/**
* dp[i][0]: 表示前i天手里没有股票的最大收益，
* dp[i][1]:表示前i天手里有股票的最大收益
* 手续费只在一次交易时付一次，所以在卖出时减去手续费
**/
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int len = prices.size();
        if (len <= 1) {
            return 0;
        }

        vector<vector<int>> dp(len, vector<int>(2, 0));
        dp[0][1] = -prices[0];
        for (int i = 1; i < len; i++) {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i] - fee);
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i]);
        }
        return dp[len - 1][0];
    }
};

int main()
{
    vector<int> t = { 1, 3, 2, 8, 4, 9 };
    int fee = 2;
    Solution s;
    int r = s.maxProfit(t, fee);
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
