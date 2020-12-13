// Q1105.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
using namespace std;

/**
* 子问题：dp[i]表示从第i本书到最后一本书的书架最低高度（第i本书是第一排的起点）。
* 则dp[i]可由dp[i+1]~dp[len]推出：
* 依次将i+1, i+2, ...本书放到这一层书架，直到第一层放不下。最小的高度是min(max(hi,hi+1,...,j)+dp[j])
* base:dp[len]=0, dp[len-1]=h[len-1]
* 
**/

class Solution {
public:
    int minHeightShelves(vector<vector<int>>& books, int shelf_width) {
        int len = books.size();
        vector<int> dp(len + 1, INT_MAX);
        dp[len] = 0;
        for (int i = len - 1; i >= 0; i--) {
            int max_book_height = 0;
            //剩下的宽度
            int left_width = shelf_width;
            // 把第 j 本书拿到第 i 本书后面
            for (int j = i; j < books.size() && left_width >= books[j][0]; ++j) {
                max_book_height = max(max_book_height, books[j][1]);
                dp[i] = min(dp[i], max_book_height + dp[j + 1]);
                left_width -= books[j][0];
            }
        }
        return dp[0];
    }
};

int main()
{
    vector<vector<int>> books = { {1,1}, {2,3},{2,3},{1,1},{1,1},{1,1},{1,2} };
    Solution s;
    int r = s.minHeightShelves(books, 4);
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
