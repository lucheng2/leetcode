// Q1552.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxDistance(vector<int>& position, int m) {
        int length = position.size();
        sort(position.begin(), position.end());
        int leftBound = position[length - 1] - position[0], rightBound = (position[length - 1] - position[0]) / (m - 1);
        for (int i = 1; i < length; i++) {
            if (position[i] - position[i - 1] < leftBound) {
                leftBound = position[i] - position[i - 1];
            }
         }
        if (m == 2) {
            return rightBound;
        }
        else
        {
            while (leftBound <= rightBound) {
                int middle = (rightBound + leftBound) / 2;
                if (check(position, middle, m)) {
                    leftBound = middle + 1;
                }
                else
                {
                    rightBound = middle - 1;
                }
            }
            return leftBound - 1;
        }
    }

    bool check(vector<int>& position, int candidate, int m) {
        int count = 0;
        int target = position[0] + candidate;
        for (int i = 0; i < position.size() - 1; i++) {
            if (position[i] < target && position[i+1] >= target) {
                count++;
                target = position[i+1] + candidate;

            }
        }
        return count >= m - 1;
    }
};

int main()
{
    vector<int> test = { 79, 74, 57, 22 };
    Solution solution;
    int result = solution.maxDistance(test, 4);
    return 0;
}
