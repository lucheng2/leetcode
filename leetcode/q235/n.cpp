#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define ll long long 

using namespace std;

 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int mx = max(p->val, q->val);
        int mn = min(p->val, q->val);
        if(root->val < mn) {
            return lowestCommonAncestor(root->right, p, q);
        }
        else if(root->val > mx)
            return lowestCommonAncestor(root->left, p, q);
        else
            return root;

    }
};
