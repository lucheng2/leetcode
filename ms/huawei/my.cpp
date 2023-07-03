#include<iostream>

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
    ListNode* revers(ListNode* head) {
        if(head == NULL || head->next == NULL)
            return head;
        ListNode* pre = NULL, *cur = head;
        while(cur) {
            ListNode *tmp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = tmp;
        }
        return pre;
    }

    // [left, right)
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(right - left <= 1)
            return head;
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        
        int cnt = 0;
        ListNode *pre = dummy;
        while(cnt<left) {
            if(pre->next == NULL)
                return dummy->next;
            cnt ++;
            pre = pre->next;
        }

        ListNode *lhead = pre;
        while(pre->next && cnt<right) {
            cnt++;
            pre = pre->next;
        }
        ListNode* rhead = pre;
        ListNode* p = lhead->next;
        lhead->next = rhead;
        while(p != rhead) {
            pre->next = p;
            pre = p;
            p = p->next;
        }
        p->next = 

    }
};

