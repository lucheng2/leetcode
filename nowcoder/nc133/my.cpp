#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

  struct ListNode {
 	int val;
 	struct ListNode *next;
 	ListNode(int x) : val(x), next(nullptr) {}
  };

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        ListNode *dummyOdd = new ListNode(0);
        ListNode *dummyEven = new ListNode(0);
        ListNode *po = dummyOdd, *pe = dummyEven;
        int i = 1;
        while(head) {
            if(i&1) {
                po->next = head;
                po = po->next;
            }
            else {
                pe->next = head;
                pe = pe->next;
            }
            head = head->next;
            i++;
        }
        po->next = dummyEven->next;
        pe->next = NULL;
        return dummyOdd->next;
    }
};
