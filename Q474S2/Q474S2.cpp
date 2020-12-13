// Q474S2.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>

using namespace std;
/**
* 思路：动态规划
* 1. dp[i][m][n]表示dp[前i字符串][m个0][n个1]的最大数量
* 2. dp[i][m][n] = max(dp[i-1][m][n], 1+dp[i-1][m-cost0[i]][n-cost1[i]]), dp[i][m][n]选当前和上一步的最大值.起始条件：dp[i][0][0] = 0;
* 3. 遍历strs
* 边界条件strs为空，返回0；
**/
class Solution {
public:
    int length;
    int findMaxForm(vector<string>& strs, int m, int n) {
        length = strs.size();
        if (length == 0) {
            return 0;
        }
        vector<int> cost0(length), cost1(length);
        count01(strs, cost0, cost1);
        vector<vector<vector<int>>> dp(length+1, vector<vector<int>>(m+1, vector<int>(n+1, 0)));

        for (int i = 0; i < length; i++) {
            for (int j = 0; j < m + 1; j++) {
                for (int k = 0; k < n + 1; k++) {
                    //能装进去
                    if (j - cost0[i] >= 0 && k - cost1[i] >= 0) {
                        dp[i + 1][j][k] = max(dp[i][j][k], 1 + dp[i][j - cost0[i]][k - cost1[i]]);
                    }
                    //取较大的
                    dp[i + 1][j][k] = max(dp[i][j][k], dp[i + 1][j][k]);
                }
            }
           
        }
        return dp[length][m][n];
    }

    void count01(vector<string>& strs, vector<int>& cost0, vector<int>& cost1) {
        int count0;
        for (int i = 0; i < length; i++) {
            count0 = 0;
            for (int j = 0; j < strs[i].size(); j++) {
                if (strs[i][j] == '0') {
                    count0++;
                }
            }
            cost0[i] = count0;
            cost1[i] = strs[i].size() - count0;
        }
    }
};

int main()
{
    vector<string> test = { "10", "0001", "111001", "1", "0" };
    Solution s;
    int result = s.findMaxForm(test, 5, 3);
    std::cout << result;
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
