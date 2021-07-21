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
        if(headA==NULL || headB==NULL)
            return NULL;
        ListNode *pa, *pb;
        pa = headA, pb = headB;
        while(true) {
            if(pa == pb)
                return pa;
            pa = (pa == NULL) ? headB: pa->next;
            pb = (pb == NULL) ? headA: pb->next;
        }
    }
};
