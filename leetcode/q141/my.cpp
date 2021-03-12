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
    bool hasCycle(ListNode *head) {
        ListNode * dummy = new ListNode(0);
        dummy->next = head;
        ListNode * fast = dummy->next;
        ListNode * slow = dummy;
        while(fast != slow) {
            if(fast == NULL || fast->next == NULL) {
                return false;
            }
            fast = fast->next->next;
            slow = slow->next;
        }
        return true;
    }
};

int main() {
	
	return 0;
}
