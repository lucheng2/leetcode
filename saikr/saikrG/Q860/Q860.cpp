// Q860.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
using namespace std;

//只需要优先找大额的钱即可
class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        vector<int> cash(2, 0);
        int len = bills.size();
        for (int i = 0; i < len; i++) {
            switch (bills[i])
            {
            case 5:
                cash[0]++;
                break;
            case 10:
                cash[1]++;
                if (!change(cash, 5)) {
                    return false;
                }
                break;
            case 20:
                if (!change(cash, 15)) {
                    return false;
                }
                break;
            default:
                //出错
                return false;
            }
        }
        return true;
    }

    bool change(vector<int> &cash, int c) {
        switch (c)
        {
        case 5:
            if (cash[0] > 0) {
                cash[0]--;
                return true;
            }
            else
            {
                return false;
            }
        case 15:
            if (cash[1] > 0) {
                cash[1]--;
                if (cash[0] > 0) {
                    cash[0]--;
                    return true;
                }
                else {
                    return false;
                }
            }
            else if (cash[0] >= 3) {
                cash[0] = cash[0] - 3;
                return true;
            }
            else
            {
                return false;
            }

        default:
            return false;
        }
    }
};

int main()
{
    Solution s;
    vector<int> t = { 5,5,10,10,20 };
    bool r = s.lemonadeChange(t);
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
