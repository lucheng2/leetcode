// Q668.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>

using namespace std;

/**
* 思路：对乘法表中的值的返回做二分查找，左边界：1，右边界：m*n
* 要实现check函数，描述了x 是否足够大可以成为乘法表中的 k-th值。
* 边界条件：乘法表只有一个值，返回1
**/

class Solution {
public:
    int findKthNumber(int m, int n, int k) {
        int left = 1, right = m * n, middle, answer=0;
        while (left <= right) {
            middle = (left + right) / 2;
            if (check(m, n, middle, k)) {
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

    bool check(int m, int n, int candidate, int k) {
        int count = 0;
        for (int i = 1; i <= m; i++) {
            count += min(n, candidate/i);
            if (count >= k) {
                return true;
            }
        }
        return false;
    }
};

int main()
{
    int m = 3, n = 3, k = 9;
    Solution s;
    int result = s.findKthNumber(m, n, k);
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
