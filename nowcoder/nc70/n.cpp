#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

  struct ListNode {
 	int val;
 	struct ListNode *next;
    ListNode(int v): val(v) {};
  };

class Solution {
public:
    ListNode* mergeSort(ListNode* head) {
        if(head==NULL || head->next==NULL)
            return head;
        ListNode *fast = head, *slow = head, *pre;
        while(fast && fast->next) {
            pre = slow;
            fast = fast->next->next;
            slow = slow->next;
        }
        pre->next = NULL;
        ListNode* left = mergeSort(head);
        ListNode* right = mergeSort(slow);
        ListNode* dummy = new ListNode(0);
        ListNode* p = dummy;
        while(left || right) {
            if(left == NULL || (right && right->val < left->val)) {
                p->next = right;
                right = right->next;
            }
            else{
                p->next = left;
                left = left->next;
            }
            p = p->next;
        }
        return dummy->next;
    }
    ListNode* sortInList(ListNode* head) {
        return mergeSort(head);
    }
};
