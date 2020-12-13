// Q5540.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

//思路：二分查找， 要实现check

class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        set<int> xset;
        for (auto point : points) {
            xset.insert(point[0]);
        }
        int length = xset.size();
        vector<int> x(length);
        sort(x.begin(), x.end());

        int index = 0;
        for (auto temp: xset) {
            x[index++] = temp;
        }

        int left = 0, right = x[x.size() - 1] - x[0];
        int result = 0;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (check(mid, x)) {
                result = mid;
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }
        return result;
    }

    bool check(int mid, vector<int> &x) {
        for (int i = 0; i < x.size() - 1; i++) {
            if (x[i + 1] - x[i] >= mid) {
                return true;
            }
        }
        return false;
    }
};

int main()
{
    vector<vector<int>> test = { {3,1}, {9,0}, {1, 0}, {1, 4}, {5, 3}, {8, 8} };
    Solution s;
    int r = s.maxWidthOfVerticalArea(test);
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
