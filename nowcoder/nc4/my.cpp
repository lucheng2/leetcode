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
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* pre = head;
        ListNode* lat = dummy;
        while(pre!=NULL && pre->next!=NULL) {
            if(pre==lat)
                return true;
            pre = pre->next->next;
            lat = lat->next;
        }
        return false;
    }
};

int main() {
	
	return 0;
}
