// Q746.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
using namespace std;
/**
    1. base 0阶和1阶都要给定
    2. status 阶梯数
    3. choise 第i级踩不踩
    4. dp[i][0] 第i级不踩 dp[i][1]要踩
    边界：空或长度为1：为0
 **/

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int length = cost.size();
        if (length <= 1) {
            return 0;
        }
        vector<vector<int>> dp(length, vector<int>(2, 0));
        dp[0][0] = 0;
        dp[0][1] = cost[0];
        dp[1][0] = cost[0];
        dp[1][1] = cost[1];

        for (int i = 2; i < length; i++) {
            dp[i][0] = dp[i - 1][1];
            dp[i][1] = min(dp[i - 1][0] + cost[i], dp[i - 1][1] + cost[i]);
        }
        return min(dp[length - 1][0], dp[length - 1][1]);
    }
};

int main()
{
    Solution s;
    vector<int> test = { 1, 100, 1, 1, 1, 100, 1, 1, 100, 1 };
    int r = s.minCostClimbingStairs(test);
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
