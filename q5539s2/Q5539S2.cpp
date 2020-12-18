// Q5539S2.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include<vector>
using namespace std;

class Solution {
public:
    //hash table
    vector<int> frequencySort(vector<int>& nums) {
        vector<int> hashTable(202, -1), result(nums.size());
        for (int i = 0; i < nums.size(); i++) {
            if (hashTable[nums[i] + 100] == -1) {
                hashTable[nums[i] + 100] = 1;
            }
            else
            {
                hashTable[nums[i] + 100] ++;
            }
        }
        int index = 0, count = 0;
        for (int i = 0; i < 202; i++) {
            if (hashTable[i] > 0) {
                count++;
            }
        }
        for (int j = 0; j < count; j++) {
            int min = INT_MAX, id = 0;
            for (int i = 0; i < 202; i++) {
                if (hashTable[i] > 0 && min >= hashTable[i]) {
                    min = hashTable[i];
                    id = i;
                }
            }
            if (min == INT_MAX) {
                continue;
            }
            do {
                result[index++] = id - 100;
                hashTable[id] --;
            } while (hashTable[id] > 0);
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
