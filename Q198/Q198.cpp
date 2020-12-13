// Q198.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>

using namespace std;
/**
* 1. base 空时返回0
* 2. state 偷的钱
* 3. choice 是否偷某家
* 4. dp[n+1][0] 第i家不偷
* 
* 边界：nums为空
**/

class Solution {
public:
    int rob(vector<int>& nums) {
        int length = nums.size();
        if (length == 0) {
            return 0;
        }
        vector<vector<int>> dp(length, vector<int> (2, 0));
        dp[0][1] = nums[0];
        for (int i = 1; i < length ; i++) {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);
            dp[i][1] = max(dp[i - 1][0] + nums[i], dp[i][0]);
        }
        return dp[length - 1][0] > dp[length - 1][1] ? dp[length - 1][0] : dp[length - 1][1];
    }
};

int main()
{
    Solution s;
    vector<int> test = { 1,2,3,1 };
    int result = s.rob(test);
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
