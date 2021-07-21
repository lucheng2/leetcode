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
        bool fa=true, fb=true;
        while(fa || fb || pa || pb) {
            if(pa == pb)
                return pa;
            if(pa == NULL) {
                pa = headB;
                fa = false;
            }
            else{
                pa = pa->next;
            }
            if(pb == NULL) {
                pb = headA;
                fb = false;
            }
            else
                pb = pb->next;
        }
        return NULL;
    }
};
