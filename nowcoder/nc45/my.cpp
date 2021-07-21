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
    vector<vector<int> > threeOrders(TreeNode* root) {
        vector<vector<int>> ans(3);
        pre_order(root, ans[0]);
        mid_order(root, ans[1]);
        after_order(root, ans[2]);
        return ans;
    }

    void pre_order(TreeNode* root, vector<int> & ans) {
        if(root == NULL)
            return;
        ans.push_back(root->val);
        pre_order(root->left, ans);
        pre_order(root->right, ans);
    }

    void mid_order(TreeNode* root, vector<int> & ans) {
        if(root == NULL)
            return;
        mid_order(root->left, ans);
        ans.push_back(root->val);
        mid_order(root->right, ans);
    }

    void after_order(TreeNode* root, vector<int> & ans) {
        if(root == NULL)
            return;
        after_order(root->left, ans);
        after_order(root->right, ans);
        ans.push_back(root->val);
    }
};
