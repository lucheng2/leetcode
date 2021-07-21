#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define ll long long 

using namespace std;

struct node{
    int val;
    node * next;
    node(int v) :val(v) {};
};

node* reverse(node* head) {
    if(head == NULL || head->next == NULL)
        return head;
    node * newHead = reverse(head->next);
    head->next->next = head;
    head->next = NULL;
    return newHead;
}

int main() {
    node * root = new node(0);
    node * test = root;
    for(int i=1; i<=5; i++) {
        test->next = new node(i);
        test = test->next;
    }
    node * ans = reverse(root->next);
    while(ans) {
        printf("%d ", ans->val);
        ans = ans->next;
    }

}
