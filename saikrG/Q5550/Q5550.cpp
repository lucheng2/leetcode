// Q5550.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int len = code.size();
        vector<int> decode(len);
        if (k == 0) {
            for (int i = 0; i < len; i++) {
                decode[i] = 0;
            }
        }
        else if (k < 0) {
            int sum = 0;
            for (int i = len-1; len-1-i < -k; i--) {
                sum += code[i];
            }
            for (int i = len - 1; i >= 0;i--) {
                sum = sum - code[i] + code[(len+i+k) % len];
                decode[i] = sum;
            }
        }
        else
        {
            int sum = 0;
            for (int i = 0; i < k; i++) {
                sum += code[i];
            }
            for (int i = 0; i < len; i++) {
                sum = sum - code[i] + code[(i + k) % len];
                decode[i] = sum;
            }
        }
        return decode;
    }
};

int main()
{
    vector<int> t = { 5,7,1,4 };
    Solution s;
    t = s.decrypt(t, -1);
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
