// Q1122.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
using namespace std;
/**
* hash表
*/
class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        vector<int> ht(1001, 0);
        int len = arr1.size();
        for (int i = 0; i < len; i++) {
            ht[arr1[i]]++;
        }
        vector<int> result(len);
        int index = 0;
        //先把arr2里的放前面
        for (int i = 0; i < arr2.size(); i++) {
            while (ht[arr2[i]] > 0) {
                result[index++] = arr2[i];
                ht[arr2[i]]--;
            }
        }
        //再放不在arr2里的
        for (int i = 0; i <= 1000; i++) {
            while (ht[i] > 0) {
                result[index++] = i;
                ht[i]--;
            }
        }
        return result;
    }
};

int main()
{
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
