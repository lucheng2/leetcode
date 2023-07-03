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
    ListNode* reverseList(ListNode* head) {
        ListNode *pre = NULL, *cur = head, *nxt;
        while(cur) {
            nxt = cur->next;
            cur->next = pre;
            pre = cur;
            cur = nxt;
        }
        return pre;
    }
};

