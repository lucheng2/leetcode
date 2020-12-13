// Q121.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>

using namespace std;

/**
* 动态规划：
* 1、最优解子结构，设f[i]为前i天交易的最大收益, lowest[i]表示前i天的最低价格
* 2、递归解，f[i] = max(f[i-1], prices[i] - lowest[i-1]); lowest[i] = min(prices[i], lowest[i-1])
* 边界：
* 3、遍历prices
* 边界情况：数组为空，返回0。
**/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() <= 0) {
            return 0;
        }
        vector<int> f(prices.size()), lowest(prices.size());
        f[0] = 0;
        lowest[0] = prices[0];
        for (int i = 1; i < prices.size(); i++) {
            f[i] = max(f[i - 1], prices[i] - lowest[i - 1]);
            lowest[i] = min(prices[i], lowest[i - 1]);
        }
        int m = f[0];
        for (int i = 1; i < f.size(); i++) {
            if (m < f[i]) {
                m = f[i];
            }
        }
        return m;
    }
};

int main()
{
    Solution s;
    vector<int> test = { 7,1,5,3,6,4 };
    int result = s.maxProfit(test);
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
