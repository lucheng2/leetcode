#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<stack>

using namespace std;

  struct ListNode {
 	int val;
 	struct ListNode *next;
  };

class Solution {
public:
    bool isPail(ListNode* head) {
        ListNode* fast = head, *slow = head;
        while(fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode *left = head, *right;
        right = fast==NULL? slow: slow->next;
        stack<ListNode*> stk;
        while(right) {
            stk.push(right);
            right = right->next;
        }
        while(stk.size()) {
            if(stk.top()->val != left->val)
                return false;
            stk.pop();
            left = left->next;
        }
        return true;
    }
};
