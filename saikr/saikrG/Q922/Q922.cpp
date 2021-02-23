// Q922.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
using namespace std;

/**
* 思路：三指针i,j,k
* j,k倒着遍历，j指着奇数，k指着偶数
* i正着遍历
**/
class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& A) {
        int len = A.size();
        int i = 0, j = len - 1, k = j;
        k = pointEven(A, len-1);
        j = pointOdd(A, len-1);

        for (i = 0; i < len; i++) {
            if (i % 2 == 0) {
                if (A[i] % 2 != 0) {
                    int temp = A[i];
                    A[i] = A[k];
                    A[k] = temp;
                    k = pointEven(A, len-1);
                    j = pointOdd(A, len - 1);
                }
            }
            else
            {
                if (A[i] % 2 != 1) {
                    int temp = A[i];
                    A[i] = A[j];
                    A[j] = temp;
                    j = pointOdd(A, len-1);
                    k = pointEven(A, len - 1);
                }
            }
        }
        return A;
    }
    int pointOdd(vector<int>& A, int j) {
        while (j >= 0) {
            if (A[j] % 2 == 1) {
                return j;
            }
            j--;
        }
        return 0;
    }
    int pointEven(vector<int>& A, int k) {
        while (k>=0) 
        {
            if (A[k] % 2 == 0) {
                return k;
            }
            k--;
        }
        return 0;
    }
};

int main()
{
    vector<int> t = { 1,4,4,3,0,3 };
    Solution s;
    s.sortArrayByParityII(t);
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
