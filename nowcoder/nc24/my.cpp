#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

  struct ListNode {
 	int val;
 	struct ListNode *next;
  };
 

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode * dummy = new ListNode(0);
        ListNode * p = dummy;
        while(head) {
            if(head->next && head->val == head->next->val) {
                while(head->next && head->val == head->next->val) {
                    head = head->next;
                }
                head = head->next;
            }
            else {
                p->next = head;
                p = head;
                ListNode* tmp = head->next;
                head->next = NULL;
                head = tmp;
            }
        }
        return dummy->next;
    }
};
