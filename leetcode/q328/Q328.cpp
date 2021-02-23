// Q328.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
using namespace std;

 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
 
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }
        ListNode even(0), odd(0);
        ListNode* p, * evenHead = &even, * oddHead = &odd;
        p = head;
        bool o = true;
        while (p != NULL) {
            if (o) {
                oddHead->next = p;
                oddHead = oddHead->next;
            }
            else
            {
                evenHead->next = p;
                evenHead = evenHead->next;
            }
            p = p->next;
            o = !o;
        }
        evenHead->next = NULL;
        oddHead->next = even.next;
        return head;
    }
};

int main()
{
    ListNode h1(1),h2(2),h3(3), h4(4), h5(5), *head=&h1;
    h1.next = &h2;
    h2.next = &h3;
    h3.next = &h4;
    h4.next = &h5;
    Solution s;
    head = s.oddEvenList(head);
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
