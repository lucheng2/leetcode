// Q5528.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>

using namespace std;

/**
* 思路：依次遍历信号塔坐标，在坐标的信号范围内计算信号值
* 范围：信号最大的坐标一定是在塔坐标确定的矩形内
**/

class Solution {
public:
    vector<int> bestCoordinate(vector<vector<int>>& towers, int radius) {
        int length = towers.size();
        if ( length== 0) {
            return vector<int>(2, 0);
        }

        int xl = towers[0][0], xh = towers[0][0];
        int yl = towers[0][1], yh = towers[0][1];
        for (int i = 1; i < length; i++) {
            if (xl >= towers[i][0] && yl >= towers[i][1]) {
                xl = towers[i][0];
                yl = towers[i][1];
            }
            if (xh <= towers[i][0] && yh <= towers[i][1]) {
                xh = towers[i][0];
                yh = towers[i][1];
            }
        }
        int m = xh - xl;
        int n = yh - yl;
        vector < vector<int>> signal(m, vector<int>(n));
        
        for (int i = 0; i < length; i++) {

        }
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
