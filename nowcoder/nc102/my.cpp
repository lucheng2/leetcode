#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

 struct TreeNode {
 	int val;
	struct TreeNode *left;
	struct TreeNode *right;
 };

class Solution {
public:
    int lowestCommonAncestor(TreeNode* root, int o1, int o2) {
        return commonAncestor(root, o1, o2)->val;
    }

    TreeNode* commonAncestor(TreeNode* root, int o1, int o2) {
        if(root == NULL || root->val == o1 || root->val == o2)
            return root;
        TreeNode * left = commonAncestor(root->left, o1, o2);
        TreeNode * right = commonAncestor(root->right, o1, o2);
        if(left == NULL)
            return right;
        if(right == NULL)
            return left;
        return root;
    }
};
