#include <stdio.h>
#include <stdlib.h>

struct ListNode {
	int val;
	struct ListNode* next;
};

/**
* ˼·����һ���ڵ㵱�����ͷ�����ν���С��ֵ��������ĺ��档ע�����һ������Ϊ���ˣ������ֱ�Ӱ���һ�������ʣ�ಿ�ֽӵ����档
* �߽��������ޡ�
**/

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
	struct ListNode t3, * tail = &t3;
	t3.val = 0;
	t3.next = NULL;
	struct ListNode* head = tail;
	// ѭ��ֱ������������
	while (l1 != NULL || l2 != NULL) {
		//ĳ������Ϊ�գ���ֱ��ѡ��һ������Ľڵ�
		if (l1 == NULL) {
			tail->next = l2;
			break;
		}
		if (l2 == NULL) {
			tail->next = l1;
			break;
		}
		//�����������գ���Ƚ�ѡ���С�Ľڵ�
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