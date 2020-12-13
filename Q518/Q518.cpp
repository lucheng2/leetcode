// Q518.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>

using namespace std;

/**
* 完全背包问题
* 状态转移方程：
* dp[i][v]: 前i个物品放入容量为v时的放法数
* 递推，考虑第i个物品：
* 不放入：dp[i][v] = dp[i-1][v]
* 放入（可以若干次，只要放得下都可以）： dp[i][v] = dp[i][v-Ci]
* 
* base: v=0, 为1， 一枚硬币都不选就可以了
* i=0, v!=0, 为0, 凑不出来
**/

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int len = coins.size();
        //边界情况
        if (amount != 0 && len == 0) {
            return 0;
        }

        /*vector<vector<int>> dp(len + 1, vector<int>(amount + 1, 0));
        for (int i = 0; i <= len; i++) {
            dp[i][0] = 1;
        }

        for (int i = 1; i <= len; i++) {
            for (int j = 0; j <= amount; j++) {
                if (j < coins[i - 1]) {
                    dp[i][j] = dp[i - 1][j];
                }
                else
                {
                    dp[i][j] = dp[i - 1][j] + dp[i][j - coins[i - 1]];
                }
            }
        }
        return dp[len][amount];*/

        //优化存储

        vector<int> dp(amount + 1, 0);
        dp[0] = 1;
        for (auto coin : coins) {
            //正着遍历, 原因：物品可以重复加入。具体分析请见《背包九讲》2.5节
            for (int j = coin; j <= amount; j++) {
                dp[j] = dp[j] + dp[j - coin];
            }
        }

        return dp[amount];
    }
};

int main()
{
    vector<int> t = { 2, 1, 5 };
    Solution s;
    int r = s.change( 5, t);
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
