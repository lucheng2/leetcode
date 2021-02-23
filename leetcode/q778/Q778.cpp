// Q778.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>

using namespace std;

/**
* 思路：二分查找可以游过去的最小值，左界：0；右界：max(grid)， 或者题目给的范围：N*N-1
* 需要写check函数，check函数是重点，判断middle是否是可以游过去的。用DFS
* 边界条件：grid为空，返回0；grid只有一个值，返回0。
**/
class Solution {
    vector<vector<int>> direction = { {0, 1}, {0, -1}, {-1, 0}, {1, 0} };
    int N;
public:
    int swimInWater(vector<vector<int>>& grid) {
        N = grid.size();
        //边界
        if (N <= 1) {
            return 0;
        }

        int left = 0, right = 0, middle, answer=0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (grid[i][j] > right) {
                    right = grid[i][j];
                }
            }
        }
        while (left <= right) {
            middle = (left + right) / 2;
            vector<vector<bool>> visited(N, vector<bool>(N, false));
            if (check(grid, 0, 0, middle, visited)) {
                answer = middle;
                right = middle - 1;
            }
            else
            {
                left = middle + 1;
            }
        }
        return answer;
    }

    bool check(vector<vector<int>>& grid, int x, int y, int cadidate, vector<vector<bool>> &visited) {
        visited[x][y] = true;
        //已经到目标点了，返回true
        if (x == N - 1 && y == N - 1) {
            return true;
        }
        //四个方向依次遍历
        for (int i = 0; i < 4; i++) {
            int xi = x + direction[i][0];
            int yi = y + direction[i][1];
            if (xi >= 0 && xi < N && yi >= 0 && yi < N && !visited[xi][yi] && grid[x][y] <= cadidate && grid[xi][yi] <= cadidate) {
                //如果有一个方向的结果为ture， 则说明可达， 返回ture；注意这里不是return check()!!
                if (check(grid, xi, yi, cadidate, visited)) {
                    return true;
                }
            }
        }
        return false;
    }
};


int main()
{
    Solution s;
    vector<vector<int>> test = { {0, 1}, {2, 3} };
    int result = s.swimInWater(test);
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
