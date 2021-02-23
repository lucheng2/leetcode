// M17_16.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include<vector>
using namespace std;
/**
* 动态规划
* 1. dp[i][0]表示第i个不选的最大值，dp[i][1]表第i个要选的最大值
* 2. dp[i][0] = max(dp[i-1][0], dp[i-1][1])
* dp[i][1] = max(dp[i-1][0] + nums[i], dp[i-1][1])
* 3. 遍历nums
* 边界：nums为空，返回0
**/

class Solution {
public:
    int massage(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }
        vector<vector<int>> dp(nums.size(), vector<int>(2));
        dp[0][0] = 0;
        dp[0][1] = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);
            dp[i][1] = max(dp[i - 1][0] + nums[i], dp[i - 1][1]);
        }
        int max = dp[0][0];
        for (int i = 0; i < dp.size(); i++) {
            if (max < dp[i][0]) {
                max = dp[i][0];
            }
            if (max < dp[i][1]) {
                max = dp[i][1];
            }
        }
        return max;
    }
};

int main()
{
    Solution s;
    vector<int> test = { 1,2,3,1 };
    int result = s.massage(test);
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
