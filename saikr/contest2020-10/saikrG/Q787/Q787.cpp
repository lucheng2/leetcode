// Q787.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
using namespace std;

/**
* 思路1：Dijkstra算法, 区别，这里有个最长路径的限制：
* 思路2：动态规划
* dp[i][k] 表示src经过k步到达i的最小距离
* base：dp[0][k] = 0, dp[i][K+1] = intMax
* 转移方程：
* 边界条件：无
* 注意，这是有向图！！！
**/
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        vector<vector<int>> dp(n, vector<int>(K + 2, INT_MAX));
        for (int i = 0; i < K + 2; i++) {
            dp[src][i] = 0;
        }
        for (int i = 1; i < K + 2; i++) {
            for (auto& flight : flights) {
                //如果在flight[0], 即起点的时候，就已经是不可达的了，就不必再搜索
                if (dp[flight[0]][i - 1] != INT_MAX) {
                    //状态转移方程：未到达前都是IntMax
                    dp[flight[1]] [i] = min(dp[flight[1]] [i], dp[flight[0]] [i - 1] + flight[2]);
                }
            }
        }
        return dp[dst][K+1] == INT_MAX? -1 : dp[dst][K+1];
    }
};

int main()
{
    vector<vector<int>> t = { {0,1,100}, {1,2,100}, {0,2,500} };
    //vector<vector<int>> t = { {4, 1, 1}, {1,2,3}, {0,3,2}, {0, 4, 10}, {3, 1, 1}, {1, 4, 3} };
    Solution s;
    int r = s.findCheapestPrice(3, t, 0, 2, 1);
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
