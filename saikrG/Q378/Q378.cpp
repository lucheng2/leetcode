// Q378.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>

using namespace std;

/**
* 思路：类比乘法表，用二分查找，左边界min：右边界max
* 需要实现check函数，用来判断当前的x是否满足前k个的条件。
* 边界条件：只有1个时，返回唯一的元素
**/
class Solution {
public:
    int n;
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        n = matrix.size();
        if (n == 1) {
            return matrix[0][0];
        }
        int left = matrix[0][0], right = matrix[n-1][n-1], middle, answer=1;
        while (left <= right) {
            middle = (left + right) / 2;
            if (check(matrix, k, middle)) {
                answer = middle;
                right = middle - 1;
            }
            else
            {
                left = middle + 1;
            }
        }
        return answer;
    }
    bool check(vector<vector<int>>& matrix, int k, int candidate) {
        int count = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] <= candidate) {
                    count++;
                    if (count >= k) {
                        return true;
                    }
                }
                else {
                    break;
                }
            }
        }
        return false;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> test = { {1,2,3},{4,7,11},{7,10,13} };
    int result = s.kthSmallest(test, 5);
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
