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
    ListNode* ReverseList(ListNode* pHead) {
        ListNode* pre=NULL;
        ListNode* after=pHead;
        while(after) {
            ListNode* tmp = after->next;
            after->next = pre;
            pre = after;
            after = tmp;
        }
        return pre;
    }
};

