// Q416.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>

using namespace std;

/**
* 子集划分为A B
* 有A+B=sum
* A=B
* A= sum/2
* 
* dp[n][target]: 前n个物品放入容量为target的背包是否可行；
* 考虑第n个物品：不放背包,dp[n][target] = dp[n-1][target]
* 放入： dp[n][target] = dp[n-1][target-nums[i-1]]
* 
* base: target=0, true;
* n=0, target!=0, false;
**/

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int len = nums.size();
        long long int sum = 0;
        for (int i = 0; i < len; i++) {
            sum += nums[i];
        }

        if (sum % 2 == 1) {
            return 0;
        }
        int target = sum / 2;


        //vector<vector<bool>> dp(len + 1, vector<bool>(target + 1, false));
        //for (int i = 0; i <= len; i++) {
        //    dp[i][0] = true;
        //}        

        //for (int i = 1; i <= len; i++) {
        //    for (int j = 0; j <= target; j++) {
        //        //容量不够，不能放入背包
        //        if (j < nums[i - 1]) {
        //            dp[i][j] = dp[i - 1][j];
        //        }
        //        else
        //        {
        //            dp[i][j] = dp[i-1][j] | dp[i - 1][j - nums[i - 1]];
        //        }
        //    }
        //}
        //return dp[len][target];

        //优化空间

        vector<bool> dp(target + 1, false);
        dp[0] = true;
        for (auto num : nums) {
            for (int i = target; i >= num; i--) {
                dp[i] = dp[i] | dp[i - num];
            }
        }

        return dp[target];
    }
};

int main()
{
    vector<int> t = { 2, 2, 1, 1 };
    Solution s;
    bool r = s.canPartition(t);
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
