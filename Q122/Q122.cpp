// Q122.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>

using namespace std;

/**
* 子问题：dp[i][0] 前i天手里没有股票时的最大收益
*           dp[i][1] 前i天手里有股票时的最大收益
* 考虑第i天：dp[i][0], 可能前i-1天手里也没有股票，或者前i-1天有股票，但在第i天卖掉了.
* dp[i][0] = dp[i-1][0], dp[i-1][1]+prices[i]
* 
* dp[i][1], 可能前i-1天有股票，且第i天也没卖；或者前i-1天没股票，在第i天买入了
* dp[i][1]= dp[i-1][1], dp[i-1][0] - prices[i]
* 
* base: dp[0][0] = 0; d[0][1] = -prices[0]
* 
**/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        if (len <= 1) {
            return 0;
        }

        /*vector<vector<int>> dp(len, vector<int>(2, 0));
        dp[0][1] = -prices[0];

        for (int i = 1; i < len; i++) {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i]);
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i]);
        }
        return dp[len-1][0];*/

        //优化空间-滚动数组
        vector<vector<int>> dp(2, vector<int>(2, 0));
        dp[0][1] = -prices[0];
        for (int i = 1; i < len; i++) {
            dp[1][0] = max(dp[0][0], dp[0][1] + prices[i]);
            dp[1][1] = max(dp[0][1], dp[0][0] - prices[i]);
            dp[0][0] = dp[1][0];
            dp[0][1] = dp[1][1];
        }
        return dp[0][0];

        
    }
};

int main()
{
    vector<int> t = { 7,1,5,3,6,4 };
    Solution s;
    int r = s.maxProfit(t);
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
