// Q5530.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>

using namespace std;

class Fancy {
public:
    vector<int> array;

    Fancy() {

    }

    void append(int val) {
        array.push_back(val);
    }

    void addAll(int inc) {
        for (int i = 0; i < array.size(); i++) {
            array[i] += inc;
        }
    }

    void multAll(int m) {
        for (int i = 0; i < array.size(); i++) {
            array[i] *= m;
        }
    }

    int getIndex(int idx) {
        if (idx >= array.size()) {
            return -1;
        }
        return array[idx] % 10 ^ 9 + 7;
    }
};

/**
 * Your Fancy object will be instantiated and called as such:
 * Fancy* obj = new Fancy();
 * obj->append(val);
 * obj->addAll(inc);
 * obj->multAll(m);
 * int param_4 = obj->getIndex(idx);
 */


int main()
{
    Fancy fancy;
    fancy.append(2);   // 奇妙序列：[2]
    fancy.addAll(3);   // 奇妙序列：[2+3] -> [5]
    fancy.append(7);   // 奇妙序列：[5, 7]
    fancy.multAll(2);  // 奇妙序列：[5*2, 7*2] -> [10, 14]
    fancy.getIndex(0); // 返回 10
    fancy.addAll(3);   // 奇妙序列：[10+3, 14+3] -> [13, 17]
    fancy.append(10);  // 奇妙序列：[13, 17, 10]
    fancy.multAll(2);  // 奇妙序列：[13*2, 17*2, 10*2] -> [26, 34, 20]
    fancy.getIndex(0); // 返回 26
    fancy.getIndex(1); // 返回 34
    fancy.getIndex(2); // 返回 20
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
