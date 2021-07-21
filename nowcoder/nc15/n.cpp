#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>

using namespace std;

struct TreeNode {
	int val;
 	struct TreeNode *left;
 	struct TreeNode *right;
};

class Solution {
public:
    vector<vector<int> > levelOrder(TreeNode* root) {
        if(root == NULL)
            return {};
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        q.push(root);
        while(q.size()) {
            int num = q.size();
            vector<int> level;
            while(num--) {
                TreeNode* node = q.front();
                q.pop();
                level.push_back(node->val);
                if(node->left)
                    q.push(node->left);
                if(node->right)
                    q.push(node->right);
            }
            if(level.size())
                ans.push_back(level);
        }
        return ans;
    }
};
