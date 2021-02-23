#include <stdio.h>



struct ListNode {
    int val;
    struct ListNode *next;
};
 
/**
* 双指针法，用相邻的两个指针做比较，如果相同就把后一个指针对应的结构体跳过。
* 边界条件：链表为空
**/
struct ListNode* deleteDuplicates(struct ListNode* head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }
    struct ListNode* former, *latter;
    former = head;
    latter = former->next;
    while (latter != NULL) {
        if (former->val == latter->val) {
            former->next = latter->next;
            latter = latter->next;
        }
        else
        {
            former = latter;
            latter = former->next;
        }
    }
    return head;
}

int main() {
    struct ListNode n1 = { 3, NULL };
    struct ListNode n2 = { 2, &n1 };
    struct ListNode n3 = { 2, &n2 };
    struct ListNode* head = &n3;
    deleteDuplicates(head);
    return 0;
}