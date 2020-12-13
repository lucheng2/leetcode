// JZOffer42.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
using namespace std;

/**
* 动态规划
* 1.base 0：nums[0]
* 2.status 数组长度
* 3. choice 第i个数字选或者不选
* 4. dp[i] 前i个的最大和
* 边界：nums为空，0
**/

class Solution {
public:
    int lenght;
    int maxSubArray(vector<int>& nums) {
        lenght = nums.size();
        if (lenght == 0) {
            return 0;
        }
        //vector<int> dp(lenght, 0);
        //dp[0] = nums[0];
        //int m = dp[0];
        //for (int i = 1; i < lenght; i++) {
        //    dp[i] = max(nums[i], dp[i - 1] + nums[i]);
        //    if (m < dp[i]) {
        //        m = dp[i];
        //    }
        //}
        //return m;
        int pre = nums[0], lat=nums[0], m=pre;
        for (int i = 1; i < lenght; i++) {
            lat = max(nums[i], pre + nums[i]);
            if (m < lat) {
                m = lat;
            }
            pre = lat;
        }
        return m;
    }
};

int main()
{
    Solution s;
    vector<int> test = { -2,1,-3,4,-1,2,1,-5,4 };
    int r = s.maxSubArray(test);
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
