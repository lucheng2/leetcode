#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0, head);
        ListNode* pre = dummy;
        ListNode* lat = dummy;
        for(int i=0; i<=n; ++i) 
            pre = pre->next;
        while(pre != NULL) {
            pre = pre->next;
            lat = lat->next;
        }
        lat->next = lat->next->next;
        return dummy->next;
    }
};

int main() {
	
	return 0;
}
