// Q392.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>

using namespace std;

/**
* 1. dp数组含义，思路：对t做预处理，以动态规划的方式，得到一个二维数组dp[i][j]，表示t中第i个字符j，在t中的位置。后面只需要在这个表中做查询就可以了。
* 2. base dp[length][...] = length
* 3. 转移方程 dp[i] = d[i+1][j], t[i]!=j;
*                   = i, t[i]==j;
**/

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int length = t.length();
        vector<vector<int>> dp(length + 1, vector<int>(26, length));
        //预处理
        for (int i = length - 1; i >= 0; i--) {
            for (int j = 0; j < 26; j++) {
                if (t[i] == (char)(j + 'a')) {
                    dp[i][j] = i;
                }
                else
                {
                    dp[i][j] = dp[i + 1][j];
                }
            }
        }
        //判断s
        int index = 0;
        for (int i = 0; i < s.length(); i++) {
            index = dp[index][s[i] - 'a'] + 1;
            if ( index > length) {
                return false;
            }
        }
        return true;
    }
};

int main()
{
    string s = "abc", t = "ahbgdc";
    Solution sl;
    bool r = sl.isSubsequence(s, t);
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
