#include<queue>
#include<iostream>

using namespace std;

struct node {
    int val;
    node * left;
    node * right;
    node(int val) : val(val) {
    }
};

void tree_change(node * head) {
    if(head == NULL)
        return;
    swap(head->left, head->right);
    tree_change(head->left);
    tree_change(head->right);
}

int main() {
    node *head = new node(0);
    head->left = new node(1);
    head->right = new node(2);
    head->left->left = new node(3);
    tree_change(head);
    queue<node*> q;
    q.push(head);
    while(q.size()) {
        node * u = q.front();
        q.pop();
        if(u) {
            cout<<u->val<<endl;
            q.push(u->left);
            q.push(u->right);
        }
        else
            cout<<"NULL"<<endl;
    }
}
