#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

  struct ListNode {
 	int val;
    struct ListNode *next;
    ListNode(int x): val(x), next(NULL) {}
    ListNode(int x, ListNode* n): val(x), next(n) {}
  };
 

class Solution {
public:
    /**
     * 
     * @param head ListNode类 
     * @param k int整型 
     * @return ListNode类
     */
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(k<=1)
            return head;
        ListNode *dummy = new ListNode(0, head);
        int len = 0;
        while(head!=NULL&&len<k) {
            len++;
            head = head->next;
        }
        if(len<k)
            return dummy->next;
        head = dummy->next;
        ListNode* klast=head->next->next;
        ListNode* second = head->next;
        for(int i=1; i<k; ++i) {
            second->next = head;
            head = second;
            second = klast;
            klast = klast->next;
        }
        dummy->next->next = reverseKGroup(second, k);
        return head;
    }
};

int main() {
    Solution s;
    ListNode *root = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5)))));
    root = s.reverseKGroup(root, 3);
	return 0;
}
