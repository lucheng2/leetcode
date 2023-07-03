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
    ListNode* sortInList(ListNode* head) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        bool flag = true;
        while(flag) {
            flag = false;
            for(ListNode* j=dummy; j->next && j->next->next; j=j->next) {
                if(j->next->val > j->next->next->val) {
                    flag = true;
                    ListNode* pre = j->next;
                    ListNode* nxt = j->next->next;
                    pre->next = nxt->next;
                    nxt->next = pre;
                    j->next = nxt;
                }
            }
        }
        return dummy->next;
    }
};
