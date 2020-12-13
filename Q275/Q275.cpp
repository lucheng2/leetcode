// Q275.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>

using namespace std;

/**
* 思路：二分查找， 下界：0， 上界：数组长度，要有判断函数check。如果满足髙引，则左边界右移；不满足则右边界左移，直到区间遍历结束。
* 边界条件：数组为空，返回0。
**/
class Solution {
public:
    int hIndex(vector<int>& citations) {
        int length = citations.size();
        if (length == 0) {
            return 0;
        }
        //至少有1篇文章
        int left = 0, right = length, answer=0;
        while (left <= right) {
            int middle = (left + right) / 2;
            if (check(citations, middle)) {
                // check为true时，更新answer
                answer = middle;
                left = middle + 1;
            }
            else
            {
                right = middle - 1;
            }
        }
        return answer;
    }

    bool check(vector<int>& citations, int h) {
        int length = citations.size();
        for (int i = 0; i < h; i++) {
            if (citations[length - 1 - i] < h) {
                return false;
            }
        }
        return true;
    }
};

int main()
{
    vector<int> c = { 0 };
    Solution s;
    int result = s.hIndex(c);
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
