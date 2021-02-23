// Q978.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
using namespace std;

/**
* 思路：动态规划
* 1. dp[i][2] 以i结束的湍流子串长度, 0:第i个应该比后一个大，1：否则
* 2. base[0]
* 3. 转移方程
* 边界条件A为空
**/

class Solution {
public:
    int maxTurbulenceSize(vector<int>& A) {
        int length = A.size();
        if (length == 0) {
            return 0;
        }
        vector<vector<int>> dp(length, vector<int>(2, 1));
        int m = 1;
        for (int i = 1; i < length; i++) {
            if (A[i] > A[i - 1]) {
                dp[i][0] = dp[i - 1][1] + 1;
            }
            else if(A[i]< A[i-1])
            {
                dp[i][1] = dp[i - 1][0] + 1;
            }
            else
            {
                continue;
            }
            m = max(dp[i][0], max(m, dp[i][1]));
        }
        return m;
    }
};

int main()
{
    Solution s;
    vector<int> t = { 9,4,2,10,7,8,8,1,9 };
    int r = s.maxTurbulenceSize(t);
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
