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
    ListNode* reverse_list(ListNode* head) {
        ListNode* pre = NULL, *next = head;
        while(head) {
            ListNode* tmp = head->next;
            head->next = pre;
            pre = head;
            head = tmp;
        }
        return pre;
    }
    ListNode* addInList(ListNode* head1, ListNode* head2) {
        head1 = reverse_list(head1);
        head2 = reverse_list(head2);
        int c = 0;
        ListNode* dummy = new ListNode(0);
        ListNode* head3 = dummy;
        while(head1 && head2) {
            c += head1->val + head2->val;
            head3->next = new ListNode(c % 10);
            c /= 10;
            head3 = head3->next;
            head1 = head1->next;
            head2 = head2->next;
        }
        while(head1) {
            c += head1->val;
            head3->next = new ListNode(c % 10);
            c /= 10;
            head3 = head3->next;
            head1 = head1->next;
        }
        while(head2) {
            c += head2->val;
            head3->next = new ListNode(c % 10);
            c /= 10;
            head3 = head3->next;
            head2 = head2->next;
        }
        if(c)
            head3->next = new ListNode(c);
        head3 = reverse_list(dummy->next);
        return head3;
    }
};
