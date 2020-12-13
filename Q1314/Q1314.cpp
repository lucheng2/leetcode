// Q1314.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
using namespace std;

/**
* 思路：二维的前缀和（图像领域的和图）
* sum[m][n] 前m*n个元素的和
**/

class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int K) {
        int m = mat.size(), n = mat[0].size();
        vector<vector<int>> sum(m, vector<int>(n, 0)), result(m, vector<int>(n, 0));
        sum[0][0] = mat[0][0];
        for (int i = 1; i < m; i++) {
            sum[i][0] = sum[i - 1][0] + mat[i][0];
        }
        for (int j = 1; j < n; j++) {
            sum[0][j] = sum[0][j - 1] + mat[0][j];
        }

        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                sum[i][j] = sum[i - 1][j] + sum[i][j - 1] + mat[i][j] - sum[i - 1][j - 1];
            }
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int ai = i + K < m ? i + K : m - 1;
                int aj = j + K < n ? j + K : n - 1;
                int mi = i - K ;
                int mj = j - K ;
                if (mi <= 0 && mj <= 0) {
                    result[i][j] = sum[ai][aj];
                }
                else if (mi <= 0 && mj > 0) {
                    result[i][j] = sum[ai][aj] - sum[ai][mj-1] ;
                }
                else if (mi > 0 && mj <= 0) {
                    result[i][j] = sum[ai][aj] - sum[mi-1][aj] ;
                }
                else
                {
                    result[i][j] = sum[ai][aj] - sum[ai][mj-1] - sum[mi-1][aj] + sum[mi-1][mj-1];
                }
            }
        }
        return result;
    }
};

int main()
{
    vector<vector<int>> test = { {1,2,3}, {4,5,6}, {7,8,9} };
    Solution s;
    vector<vector<int>> r = s.matrixBlockSum(test, 1);
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
