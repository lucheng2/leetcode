// Q494.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>

using namespace std;

/**
* 思路：转换为子集划分问题。nums分为A和B两个子集，A、B子集所有数的符号分别为+ 和 -；nums和为sum
* A + B = sum;
* A - B = S;
* A = (sum + S)/2
* 即在nums中选出子集A满足条件即可，要求子集A的个数。
* 转换为经典的0-1背包问题：有nums个物品，要求装进背包里面，价值恰好为target
* 
* dp[n][target+1]：表示前n件物品，恰好放入容量为target的背包的方法。
* 转移方程：“前n件物品放入容量为target的背包的放法”这一子问题，如果只看第n件物品，就可以转化为只与前n-1件物品相关的子问题：
* 如果第n件物品不放，则dp[n][target] = dp[n-1][target]
* 如果要放，dp[n][target] = dp[n-1][target-nums[n]]
* 
* base：target=0， 则为1，A为空集即可; n=0, 则说明数组为空，当target不为0时，放法数为0；
**/

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        int len = nums.size();
        long long int sum = 0;
        for (auto n : nums) {
            sum += n;
        }

        if ((sum + S) % 2 == 1) {
            return 0;
        }
        if (S > sum) {
            return 0;
        }
        int target = (sum + S)/2;

        vector<vector<int>>dp(len + 1, vector<int>(target + 1, 0));
        for (int i = 0; i <= len; i++) {
            dp[i][0] = 1;
        }

        for (int i = 1; i <= len; i++) {
            for (int j = 0; j <=target; j++) {
                if (j < nums[i - 1]) {
                    dp[i][j] = dp[i - 1][j];
                }
                else
                {
                    dp[i][j] = dp[i - 1][j] + dp[i - 1][j - nums[i - 1]];
                }
            }
        }

        return dp[len][target];

        //// 优化空间后的版本
        //vector<int> dp(target + 1, 0);

        //dp[0] = 1;//表示从前0个物品中选取若干放入背包承重量为0的恰好装满的方案数
        //for (int i = 1; i <= nums.size(); i++) {
        //    for (int j = target; j >= nums[i - 1]; j--) {
        //        dp[j] = dp[j] + dp[j - nums[i - 1]];
        //    }
        //}
        //return dp[target];
    }
};

int main()
{
    vector<int> t = { 1, 1, 1, 1, 1 };

    vector<int> t2 = { 1000 };
    int S = 1000;
    Solution s;
    int r = s.findTargetSumWays(t, 3);
    int r2 = s.findTargetSumWays(t2, S);

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
