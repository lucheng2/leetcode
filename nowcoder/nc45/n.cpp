#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<stack>
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
        vector<vector<int>> ans;
        ans.push_back(pre_order(root));
        ans.push_back(mid_order(root));
        ans.push_back(after_order(root));
        return ans;
    }

    vector<int> pre_order(TreeNode *root) {
        vector<int> ans;
        stack<TreeNode*> stk;
        TreeNode * p = root;
        while(p || stk.size()) {
            while(p) {
                ans.push_back(p->val);
                stk.push(p);
                p = p->left;
            }
            p = stk.top();
            stk.pop();
            p = p->right;
        }
        return ans;
    }

    vector<int> mid_order(TreeNode *root) {
        vector<int> ans;
        stack<TreeNode*> stk;
        TreeNode* p = root;
        while(p || stk.size()) {
            while(p) {
                stk.push(p);
                p = p->left;
            }
            p = stk.top();
            stk.pop();
            ans.push_back(p->val);
            p = p->right;
        }
        return ans;
    }

    vector<int> after_order(TreeNode *root) {
        vector<int> ans;
        stack<TreeNode*> stk;
        TreeNode* p = root, *last = NULL;
        while(p || stk.size()) {
            while(p) {
                stk.push(p);
                p = p->left;
            }
            p = stk.top();
            if(p->right==NULL || p->right == last) {
                stk.pop();
                ans.push_back(p->val);
                last = p;
                p = NULL;
            }
            else {
                p = p->right;
            }
        }
        return ans;
    }
};
