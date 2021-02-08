#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode more(0), less(0);
        ListNode *mhead = &more, *lhead = &less;
        while(head!=NULL) {
            if(head->val<x) {
                lhead->next = head;
                lhead = lhead->next;
            } else {
                mhead->next = head;
                mhead = mhead->next;
            }
            head = head->next;
        }
        mhead->next = NULL;
        lhead->next = more.next;
        return less.next;
    }
};

int main() {
    ListNode p1(1), p2(4), p3(3), p4(2), p5(5), p6(2);
    p1.next = &p2;
    p2.next = &p3;
    p3.next = &p4;
    p4.next = &p5;
    p5.next = &p6;

    Solution s;
    ListNode * ans = s.partition(&p1, 3);
	return 0;
}
