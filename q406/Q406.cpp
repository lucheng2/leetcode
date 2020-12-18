// Q406.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
#include <stdlib.h>
#include <list>
#include <algorithm>
using namespace std;

/**
* 套路）：一般这种数对，还涉及排序的，根据第一个元素正向排序，
* 根据第二个元素反向排序，或者根据第一个元素反向排序，根据第二
* 个元素正向排序，往往能够简化解题过程.
* 
* 在本题目中，我首先对数对进行排序，按照数对的元素 1 降序排序，按照数对的元素 2 升序排序。
原因是，按照元素 1 进行降序排序，对于每个元素，在其之前的元素的个数，就是大于等于他的元素的数量，
而按照第二个元素正向排序，我们希望 k 大的尽量在后面，减少插入操作的次数。
**/

int compar(const void* a, const void* b)
{
    // return *(const int*)b - *(const int*)a; 一开始考虑不周，这一步可能导致数值溢出
    if (*(const int*)b > * (const int*)a) return +1;
    if (*(const int*)b < *(const int*)a) return -1;
    return 0;
}

class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        int len = people.size();
        vector<int>* p;
        for (int i = 0; i < len-1; i++) {
            for (int j = len-1; j >=i; j--) {
                if (people[i][0] < people[j][0]) {
                    swap(people[i], people[j]);
                }
                else if (people[i][0] == people[j][0] && people[i][1] > people[j][1]) {
                    swap(people[i], people[j]);
                }
            }
        }
        vector<vector<int>> result;
        for (int i = 0; i < len; i++) {
            if (result.size() <= people[i][1]) {
                result.push_back(people[i]);
            }
            else
            {
                auto it = result.begin();
                for (int j = 0; j < people[i][1]; j++) {
                    it++;
                }
                result.insert(it, people[i]);
            }
        }
        return result;
    }
};

int main()
{
    vector<vector<int>> t = { {7,0},{4,4},{7,1},{5,0},{6,1}, {5,2} };
    Solution s;
    t = s.reconstructQueue(t);
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
