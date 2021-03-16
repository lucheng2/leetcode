#include <stdio.h>
#include <stdlib.h>

struct ListNode {
	int val;
	struct ListNode* next;
};

/**
* 思路：用一个节点当链表的头，依次将最小的值加在链表的后面。注意如果一个链表为空了，则可以直接把另一个链表的剩余部分接到后面。
* 边界条件：无。
**/

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
	struct ListNode t3, * tail = &t3;
	t3.val = 0;
	t3.next = NULL;
	struct ListNode* head = tail;
	// 循环直到两个链表都空
	while (l1 != NULL || l2 != NULL) {
		//某个链表为空，则直接选另一个链表的节点
		if (l1 == NULL) {
			tail->next = l2;
			break;
		}
		if (l2 == NULL) {
			tail->next = l1;
			break;
		}
		//两个链表都不空，则比较选择较小的节点
		if (l1->val > l2->val) {
			tail->next = l2;
			tail = tail->next;
			l2 = l2->next;
		}
		else {
			tail->next = l1;
			tail = tail->next;
			l1 = l1->next;
		}
	}
	return head->next;
}


int main() {
	struct ListNode t1, t2, * l1 = &t1, * l2 = &t2;
	l1->val = 1;
	l1->next = NULL;
	l2->val = 2;
	l2->next = NULL;

	l1 = mergeTwoLists(l1, l2);
	while(l1 != NULL) {
		printf("%d, ", l1->val);
		l1 = l1->next;
	};
	return 0;
}