// Q5555.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>

using namespace std;

//思路： 动态规划
// dp[n][i=5] 最高位为i的数量. dp[0]=0, dp[1][:] = 1;
// dp[i][j] = 求和j： (5-j)*dp[i-1][j]

class Solution {
public:
    int countVowelStrings(int n) {
        if (n == 0) {
            return 0;
        }
        vector<vector<int>> dp(n + 1, vector<int>(5,0));
        for (int i = 0; i < 5; i++) {
            dp[1][i] = 1;
        }

        for (int i = 2; i <= n; i++) {
            for (int j = 0; j < 5; j++) {
                for (int k = 0; k <= j; k++) {
                    dp[i][j] += dp[i - 1][k];

                }
            }
        }
        int r = 0;
        for (int i = 0; i < 5; i++) {
            r += dp[n][i];
        }
        return r;
    }
};

int main()
{
    Solution s;
    int r = s.countVowelStrings(33);
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
