#include<iostream>
#include<stack>

using namespace std;

 struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

void preOder(TreeNode* root){
    if(root == NULL) {
        return ;
    }
    stack<TreeNode*> stk;
    stk.push(root);
    while(!stk.empty()) {
        TreeNode *tmp = stk.top();
        stk.pop();
        printf("%d ", tmp->val);
        if(tmp->right !=NULL) {
            stk.push(tmp->right);
        }
        if(tmp->left != NULL) {
            stk.push(tmp->left);
        }
    }
}


void inOder(TreeNode* root) {
    if(root == NULL) {
        return;
    }
    stack<TreeNode*> stk;
    TreeNode *cur = root;
    while(!stk.empty() || !(cur==NULL)) {
        while(!(cur==NULL)) {
            stk.push(cur);
            cur = cur->left;
        }
        TreeNode *tmp = stk.top();
        stk.pop();
        printf("%d ", tmp->val);
        cur = tmp->right;
    }
}

void afterOrder(TreeNode* root) {
    if(root==NULL) {
        return;
    }
    stack<TreeNode*> stk1, stk2;
    TreeNode *tmp;
    stk1.push(root);
    while(!stk1.empty()) {
        tmp = stk1.top();
        stk2.push(tmp);
        stk1.pop();
        if(tmp->left != NULL) {
            stk1.push(tmp->left);
        }
        if(tmp->right !=NULL) {
            stk1.push(tmp->right);
        }
    }
    while(!stk2.empty()) {
        printf("%d ", stk2.top()->val);
        stk2.pop();
    }
}

void preOderRecur(TreeNode* root) {
    if (root==NULL) {
        return;
    }
    printf("%d ", root->val);
    preOderRecur(root->left);
    preOderRecur(root->right);
}


void inOderRecur(TreeNode* root) {
    if (root==NULL) {
        return;
    }
    inOderRecur(root->left);
    printf("%d ", root->left);
    printf(root->right);
}

void afterOrderRecur(TreeNode *root) {
    if(root == NULL) {
        return;
    }
    afterOrderRecur(root->left);
    afterOrderRecur(root->right);
    printf("%d ", root->val);
}
