// Q53.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>

using namespace std;

/**
* 思路：动态规划，解题步骤：
* 1、描述最优解的结构特征
* 2、递归定义最优解的值
* 3、按自底向上的方式计算出最优解的值
* 4、由计算的结果构造一个最优解
* 本题中只需要前三步即可。
* 1、求什么设什么，用 f[i] 代表以第 i 个数结尾的“连续子数组的最大和”。
* 2、如何求f[i]，取决于nums[i]和 f(i - 1) + nums[i]的大小，大的那一个会使得和更大, 
于是转移方程f[i] = max(nums[i], f[i-1]+nums[i]). 边界条件f[0]=nums[0].
* 3、遍历nums即可
**/
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int> f(nums.size(), INTMAX_MIN);
        f[0] = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            f[i] = max(f[i - 1] + nums[i], nums[i]);
        }
        int max = f[0];
        for (int i = 1; i < f.size(); i++) {
            if (max < f[i]) {
                max = f[i];
            }
        }
        return max;
    }
};

int main()
{
    Solution s;
    vector<int> test = { -2,1,-3,4,-1,2,1,-5,4 };
    int result = s.maxSubArray(test);
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
