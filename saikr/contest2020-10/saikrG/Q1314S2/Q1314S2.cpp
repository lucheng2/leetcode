// Q1314S2.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>

using namespace std;
/**
* 前缀和的精简版
* m+1， n+1
**/

class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int K) {
        int m = mat.size(), n = mat[0].size();
        vector<vector<int>> sum(m + 1, vector<int>(n + 1, 0)), result(m , vector<int>(n , 0));
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j < n; j++) {
                sum[i][j] = sum[i - 1][j] + sum[i][j - 1] + sum[i - 1][j - 1] + mat[i-1][j-1];
            }
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                result[i][j] = get(sum, m, n, i + K + 1, j + K + 1) - get(sum, m, n, i - K, j + K + 1) - get(sum, m, n, i + K + 1, j - K) + get(sum, m, n, i - K, j - K);
            }
        }
        return result;
    }

    int get(vector<vector<int>>& sum, int m, int n, int i, int j) {
        int x = max(min(i, m), 0);
        int y = max(min(j, n), 0);
        return sum[x][y];
    }
};


int main()
{
    Solution s;
    vector<vector<int>> t = { {1,2,3}, {4,5,6}, {7,8,9} };
    t = s.matrixBlockSum(t, 1);
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
