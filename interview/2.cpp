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

node * head;
void reverse(node* lst, node* nxt) {
    if(nxt->next != NULL)
        reverse(lst->next, nxt->next);
    else
        head = nxt;
    nxt->next = lst;
    lst->next = NULL;
}

int main() {
    node * root = new node(0);
    node * test = root;
    for(int i=1; i<=5; i++) {
        test->next = new node(i);
        test = test->next;
    }
    node * tmp = root->next;
    reverse(root->next, root->next->next);
    node* ans = head;
    while(ans) {
        printf("%d ", ans->val);
        ans = ans->next;
    }

}
