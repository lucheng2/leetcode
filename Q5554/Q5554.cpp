// Q5554.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool canFormArray(vector<int>& arr, vector<vector<int>>& pieces) {
        int larr = arr.size(), lpieces = pieces.size();
        int index=0;
        for (int n = 0; n < pieces.size(); n++) {
            int j;
            for (j = 0; j < pieces.size(); j++) {
                int i = index, k;
                for (k = 0; k < pieces[j].size(); k++) {
                    if (arr[i] == pieces[j][k]) {
                        i++;
                    }
                    else
                    {
                        break;
                    }
                }
                if (k == pieces[j].size()) {
                    //pieces.erase(pieces.at(j));
                    index = i;
                    break;
                }
            }
            if (j == pieces.size()) {
                return false;
            }
        }
        return true;
    }
};

int main()
{
    Solution s;
    vector<int> arr = { 49, 18, 16 };
    vector<vector<int>> test = { {16, 18, 49} };
    bool r = s.canFormArray(arr, test);
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
