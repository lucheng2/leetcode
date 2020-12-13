// Q300.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>

using namespace std;

/**
* 动态规划
* 1. dp[i] 以i结尾的最大长度
* 2. 基础 dp[0]
* 3. 转移方程
**/

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int length = nums.size();
        if (length == 0) {
            return 0;
        }
        vector<int> dp(length, 0);
        dp[0] = 1;
        int m = 1;
        for (int i = 1; i < length; i++) {
            dp[i] = 1;
            for (int j = i - 1; j >= 0; j--) {
                if (nums[i] > nums[j]) {
                    dp[i] = max(dp[j] + 1, dp[i]);
                }
            }
            if (m < dp[i]) {
                m = dp[i];
            }
        }
        return m;
    }
};

int main()
{
    Solution s;
    vector<int> t = { 10,9,2,5,3,7,101,18 };
    int r = s.lengthOfLIS(t);
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
