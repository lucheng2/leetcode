#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#define ll long long 

using namespace std;

 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string tree = "";
        if(root == NULL)
            return tree;
        queue<TreeNode*> que;
        que.push(root);
        while(que.size()) {
            TreeNode *node = que.front();
            que.pop();
            if(node == NULL) {
                tree += "None,";
            }
            else {
                tree += to_string(node->val) + ",";
                que.push(node->left);
                que.push(node->right);
            }
        }
        return tree;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data == "")
            return nullptr;
        vector<string> tree;
        int idx = 0;
        while(idx < data.size()) {
            int end = data.find(",", idx);
            string item = data.substr(idx, end-idx);
            tree.push_back(item);
            idx = end + 1;
        }
        queue<TreeNode*> que;
        TreeNode* root = new TreeNode(stoi(tree[0]));
        que.push(root);
        idx = 1;
        while(que.size()) {
            TreeNode * node = que.front();
            que.pop();
            if(tree[idx] != "None") {
                node->left = new TreeNode(stoi(tree[idx]));
                que.push(node->left);
            }
            idx ++;
            if(tree[idx] != "None") {
                node->right = new TreeNode(stoi(tree[idx]));
                que.push(node->right);
            }
            idx ++;
        }
        return root;
    }
};

