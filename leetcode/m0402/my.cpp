#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<stack>
#include<cstdlib>

using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return makeTree(nums, 0, nums.size());

    }
    TreeNode* makeTree(vector<int> &nums, int index, int n) {
        if(n==0) {
            return NULL;
        }
        int rootIndex = (n+1)/2 - 1 + index;
        TreeNode *root = new TreeNode(nums[rootIndex]);
        root->left = makeTree(nums, index, rootIndex-index );
        root->right = makeTree(nums, rootIndex+1, index + n -1 -rootIndex);
        return root;
    }
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

void afterOder(TreeNode* root) {
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

int main() {
    vector<int> nums = {-10,-3,0,5,9};
    Solution s;
    TreeNode *root = s.sortedArrayToBST(nums);
    inOder(root);
    preOder(root);
    afterOder(root);
	return 0;
}
