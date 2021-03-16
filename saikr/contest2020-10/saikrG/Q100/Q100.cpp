#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};
 
/**
* 思路：用树的遍历法（深度或广度优先），依次比较两个节点的值，不等则返回false
* 先序深度优先遍历
**/


bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
    if (p == NULL && q == NULL) {
        return true;
    }
    else if (p == NULL || q == NULL) {
        return false;
    }
    if (p->val != q->val) {
        return false;
    }
    else
    {
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
}

int main() {
    struct TreeNode p1 = { 1, NULL, NULL };
    struct TreeNode p2 = { 2, &p1, NULL };

    struct TreeNode q1 = { 1, NULL, NULL };
    struct TreeNode q2 = { 2, NULL, &q1 };
    bool result = isSameTree(&p2, &q2);

    return 0;
}