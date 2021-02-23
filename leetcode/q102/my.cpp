#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(root==NULL) {
            return res;
        }
        queue<TreeNode*> nodeQueue;
        nodeQueue.push(root);
        while(!nodeQueue.empty()) {
            vector<int> levelList;
            int levelSize = nodeQueue.size();
            for(int i=0; i<levelSize; i++) {
                auto node = nodeQueue.front();
                nodeQueue.pop();
                levelList.emplace_back(node->val);
                if(node->left != NULL) {
                    nodeQueue.push(node->left);
                }
                if(node->right!=NULL) {
                    nodeQueue.push(node->right);
                }
            }
            res.push_back(levelList);
        }
        return res;
    }
};

int main() {
	
	return 0;
}
