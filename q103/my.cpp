#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<deque>

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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        queue<TreeNode*> nodeQueue;
        vector<vector<int>> res;
        if(root==NULL){
            return res;
        }
        bool isOrderLeft = true;
        nodeQueue.push(root);
        while(!nodeQueue.empty()) {
            deque<int> levelList;
            int size = nodeQueue.size();
            for(int i=0; i<size; i++ ){
                auto node = nodeQueue.front();
                nodeQueue.pop();
                if(isOrderLeft) {
                    levelList.push_back(node->val);
                }
                else {
                    levelList.push_front(node->val);
                }
                if(node->left != NULL) {
                    nodeQueue.push(node->left);
                }
                if(node->right != NULL) {
                    nodeQueue.push(node->right);
                }
            }
            res.emplace_back(vector<int> {levelList.begin(), levelList.end()});
            isOrderLeft = !isOrderLeft;
        }
        return res;
    }
};

int main() {
	
	return 0;
}
