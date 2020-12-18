// Q174.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
using namespace std;

/**
* 思路：二分查找，左边界：1，右边界：1-(负值的和)
* 需要check函数，用来判断x能否顺利到达右下角；
* 边界条件：只有一个元素, 为负值时，返回1-x;
**/

class Solution {
public:
    int m, n;
    vector<vector<int>> dir = { {0,1}, {1,0} };
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        n = dungeon.size();
        m = dungeon[0].size();
        if (m == 1 && n == 1) {
            return dungeon[0][0] <= 0 ? 1 - dungeon[0][0] : 1;
        }
        int left = 1, right = 1, middle, answer=1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (dungeon[i][j] < 0) {
                    right -= dungeon[i][j];
                }
            }
        }

        while (left <= right) {
            middle = (left + right)>>1;
            if (check(dungeon, 0, 0, middle)) {
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

    bool check(vector<vector<int>>& dungeon, int x, int y, int candidate) {
        //到当前位置，一定会扣血，<=0直接返回false;
        candidate += dungeon[x][y];
        if (candidate <= 0) {
            return false;
        }
        if (x == n - 1 && y == m - 1) {
            return true;
        }
        for (int i = 0; i < 2; i++) {
            int xn = x + dir[i][0];
            int yn = y + dir[i][1];
            if (xn < n && yn < m && candidate + dungeon[xn][yn]>0) {
                //有一条路能走通，则返回true
                if (check(dungeon, xn, yn, candidate)) {
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
    /*vector<vector<int>> test = { {-2,-3,3 }, {-5, -10, 1}, {10, 30, -5} };*/
    vector<vector<int>> test = { {-3,5} };
    int result = s.calculateMinimumHP(test);
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
