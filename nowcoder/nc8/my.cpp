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
    vector<int> record;
    vector<vector<int>> ans;

    void dfs(TreeNode* root, int sum) {
        if(root == NULL) {
            return;
        }
        if(root->left == NULL && root->right == NULL) {
            if(root->val == sum) {
                record.push_back(root->val);
                ans.push_back(record);
                record.pop_back();
            }
            return;
        }
        record.push_back(root->val);
        if(root->left)
            dfs(root->left, sum - root->val);
        if(root->right)
            dfs(root->right, sum - root->val);
        record.pop_back();
    }

    vector<vector<int> > pathSum(TreeNode* root, int sum) {
        dfs(root, sum);
        return ans;
    }
};
