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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* p = head;
        int cnt = 0;
        while(p) {
            cnt ++;
            p = p->next;
        }
        if(cnt < n)
            return NULL;
        if(cnt == n)
            return head->next;
        p = head;
        int idx = cnt - n - 1;
        while(idx > 0) {
            idx --;
            p = p->next;
        }
        p->next = p->next->next;
        return head;
    }
};
