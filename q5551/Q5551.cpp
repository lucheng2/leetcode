// Q5551.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
using namespace std;

/**
* 动态规划，dp[i][j]表示i,j之间的最小操作数
* 如果s[i,j]平衡，则i左移或则j右移也是平衡的
* 否则要删除其中一个
* base： dp[i][i] = 0;
*/
class Solution {
public:
    int minimumDeletions(string s) {
        int len = s.size();
        vector<vector<int>> dp(len, vector<int>(len, 0));

        for (int i = len-2; i >=0; i--) {
            for (int j = i + 1; j < len;j++) {
                if (check(s, i, j)) {
                    dp[i][j] = min(dp[i + 1][j], dp[i][j-1]);
                }
                else
                {
                    dp[i][j] = min(dp[i + 1][j] + 1, dp[i][j - 1] + 1);
                }
            }
        }
        return dp[0][len - 1];
    }

    bool check(string& s, int i, int j) {
        char top = s[i];
        for (int k = i + 1; k <= j; k++) {
            if (top > s[k]) {
                return false;
            }
            if (top < s[k]) {
                top = s[k];
            }
        }
        return true;
    }
};

int main()
{
    string t = "aababbab";
    Solution s;
    int r = s.minimumDeletions(t);
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
