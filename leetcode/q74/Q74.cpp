// Q74.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>

using namespace std;
/**
* 思路：矩阵是有序的，用二分查找[0, m*n-1]，转换成矩阵下标：相当于转换为m进制的数
* 边界条件：矩阵为空
**/
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        if (m <= 0) {
            return false;
        }
        int n = matrix[0].size();
        int left = 0, right = m * n - 1;

        while (left <= right) {
            int middle = (left + right) / 2;
            int i = middle / n, j = middle % n;
            if (matrix[i][j] == target) {
                return true;
            }
            else if (matrix[i][j] < target) {
                left = middle + 1;
            }
            else
            {
                right = middle - 1;
            }
        }
        return false;
    }
};

int main()
{
    vector<vector<int>> m = { {1, 2, 3}, {4, 5, 6} };
    Solution s;
    bool result = s.searchMatrix(m, 4);
    return 0;
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
