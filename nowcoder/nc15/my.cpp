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
        queue<pair<int,TreeNode*>> que;
        vector<vector<int>> ans;
        que.push(make_pair(0, root));
        while(que.size()) {
            auto node = que.front();
            que.pop();
            if(ans.size() <= node.first) {
                ans.push_back({});
            }
            ans[node.first].push_back(node.second->val);
            if(node.second->left) 
                que.push(make_pair(node.first+1, node.second->left));
            if(node.second->right)
                que.push (make_pair(node.first+1, node.second->right));
        }
        return ans;
    }
};
