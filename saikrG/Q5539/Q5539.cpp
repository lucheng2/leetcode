// Q5539.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> index(nums.size(), 0), count(nums.size(), 1), result(nums.size(), 0);
        index[0] = 0;
        int k = 0;
        //双指针
        for (int i = 0; i < nums.size()-1;) {
            int c = 1;
            for (int j = i + 1; j < nums.size(); j++) {
                if (nums[i] == nums[j]) {
                    c++;
                }
                else
                {
                    count[k] = c;
                    i = j;
                    index[++k] = j;
                    break;
                }
            }
        }

        int id = 0;
        for (int i = 0; i <= k; i++) {
            int minn = count[0], minnIndex = 0;
            for (int j = 0; j <= k; j++) {
                if (minn >= count[j]) {
                    minn = count[j];
                    minnIndex = j;
                }
            }

            for (int j = 0; j < count[minnIndex]; j++) {
                result[id++] = nums[index[minnIndex] + j];
            }

            count[minnIndex] = INT_MAX;
        }
        return result;
    }
};

int main()
{
    vector<int> test = { -1,1,-6,4,5,-6,1,4,1 };
    Solution s;
    vector<int> r = s.frequencySort(test);
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
