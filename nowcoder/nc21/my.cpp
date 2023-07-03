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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode *pre = dummy;
        for(int i=0; i<m-1; i++) {
            pre = pre->next;
        }
        ListNode *cur = pre->next, *nxt;
        for(int i=0; i<n-m; i++) {
            nxt = cur->next;
            cur->next = nxt->next;
            nxt->next = pre->next;
            pre->next = nxt;
        }
        return dummy->next;
    }
};
