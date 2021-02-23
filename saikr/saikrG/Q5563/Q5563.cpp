// Q5563.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
* 思路：先排序，然后依次消掉最高的“峰”，直到结束。
**/
class Solution {
public:
    int maxProfit(vector<int>& inventory, int orders) {
        sort(inventory.rbegin(), inventory.rend());
        long long int value = 0;

        while (true)
        {
            if (inventory.size() == 1) {
                value = (2 * (long long int)inventory[0] - orders + 1) * orders / 2 % 1000000007;
                break;
            }
            int w = 1, h = inventory[0];
            for (int i = 1; i < inventory.size(); i++) {
                if (inventory[i] == inventory[i - 1]) {
                    w++;
                }
                else
                {
                    h = inventory[i - 1] - inventory[i];
                    break;
                }
            }
            long long int preValue;
            int preOrder = w * h;
            if (preOrder <= orders) {
                preValue = (2 * (long long int)inventory[0] - h + 1) * h / 2 * w;
                value = (value + preValue) % 1000000007;
                orders = orders - w * h;
                for (int i = 0; i < w; i++) {
                    inventory[i] -= h;
                }
                continue;
            }
            else
            {
                int ph = orders / w;
                if (ph > 0) {
                    preValue = (2 * (long long int)inventory[0] - ph + 1) * ph / 2 * w;
                    value = (value + preValue) % 1000000007;

                    for (int i = 0; i < w; i++) {
                        inventory[i] -= ph;
                    }
                }

                int pw = orders % w;
                if (pw > 0) {
                    preValue = (long long int) inventory[0] * pw;
                    value = (value + preValue) % 1000000007;
                }
                break;
            }
        }
        return value;
    }
};

int main()
{
    vector<int> i = { 1000000000 };
    int order = 1000000000;
    Solution s;
    int r = s.maxProfit(i, order);
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
