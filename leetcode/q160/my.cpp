#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<unordered_map>
#define ll long long 

using namespace std;

 struct ListNode {
     int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_map<ListNode*, int> hm;
        ListNode* head = headA;
        while(head) {
            hm[head] = 1;
            head = head->next;
        }
        head = headB;
        while(head) {
            if(hm.count(head))
                return head;
            head = head->next;
        }
        return NULL;
    }
};
