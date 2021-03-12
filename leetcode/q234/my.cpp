#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<stack>

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
    bool isPalindrome(ListNode* head) {
        ListNode* dummy = new ListNode(0, head);
        int n = 0;
        while(head!=NULL) {
            n++;
            head = head->next;
        }
        int len = n/2;
        stack<ListNode*> stk;
        head = dummy->next;
        for(int i=0; i<len; ++i) {
            stk.push(head);
            head = head->next;
        }
        if(n&1) {
            head = head->next;
        }
        for(int i=0; i<len; ++i) {
            if(stk.top()->val != head->val) {
                return false;
            } else {
                stk.pop();
                head = head->next;
            }
        }
        return true;
    }
};

int main() {
	
	return 0;
}
