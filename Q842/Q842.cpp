// Q842.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
using namespace std;

/**
*回溯法
*/

class Solution {
public:
    vector<int> splitIntoFibonacci(string S) {
        vector<int> list;
        backtrack(list, S, S.length(), 0, 0, 0);
        return list;
    }

    bool backtrack(vector<int>& list, string S, int length, int index, long long sum, int prev) {
        /*
        * sum表示列表中最后两个数的和
        * prev表示列表中最后一个数
        */
        if (index == length) {
            return list.size() >= 3;
        }
        long long curr = 0;
        for (int i = index; i < length; i++) {
            //剪枝，当以0开头时，拆出的数只能是0，不必尝试i-index>0的拆分
            if (i > index && S[index] == '0') {
                break;
            }
            curr = curr * 10 + S[i] - '0';
            //剪枝，当大于最大的int数时，不必再往下尝试
            if (curr > INT_MAX) {
                break;
            }
            if (list.size() >= 2) {
                //当小于时，（斐波拉契数列要求等于）,continue，不会将当前的数push到lish里面
                if (curr < sum) {
                    continue;
                }
                //剪枝，当curr比前两个数之和还大，就不满足斐波拉契公式了，不必再往下尝试
                else if (curr > sum) {
                    break;
                }
            }
            //当前的数满足斐波拉契数列，加入list进行尝试
            list.push_back(curr);
            if (backtrack(list, S, length, i + 1, prev + curr, curr)) {
                return true;
            }
            //尝试后为false，弹出curr
            list.pop_back();
        }
        return false;
    }
};


int main()
{
    Solution s;
    string test = "123456579";
    vector<int> r = s.splitIntoFibonacci(test);
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
