#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};

class Solution {
public:
    ListNode* EntryNodeOfLoop(ListNode* pHead) {
        if(pHead == NULL)
            return NULL;
        if(pHead->next == pHead)
            return pHead;
        ListNode* tmp = pHead->next;
        pHead->next = pHead;
         return EntryNodeOfLoop(tmp);
    }
};
