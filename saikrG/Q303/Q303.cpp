// Q303.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>

using namespace std;

/**
* 思路：前缀和，用sum[i]表示0-i元素的和
**/
class NumArray {
public:
    vector<long long int> sum;
    NumArray(vector<int>& nums) {
        if (nums.size() == 0) {
            this->sum = vector<long long int>(0);
            return;
        }
        this->sum = vector<long long int>(nums.size(), 0);
        sum[0] = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            sum[i] = sum[i - 1] + nums[i];
        }
    }

    int sumRange(int i, int j) {
        if (i == 0) {
            return (int)sum[j];
        }
        return (int)sum[j] - sum[i-1];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */

int main()
{
    vector<int> test = { -2, 0, 3, -5, 2, -1 };
    NumArray numArray(test);
    int i = numArray.sumRange(0, 2); // return 1 ((-2) + 0 + 3)
    i = numArray.sumRange(2, 5); // return -1 (3 + (-5) + 2 + (-1)) 
    i = numArray.sumRange(0, 5); // return -3 ((-2) + 0 + 3 + (-5) + 2 + (-1))
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
