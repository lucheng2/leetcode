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

    void rec_seria(TreeNode *root, string &tree) {
        if(root == NULL)
            tree += "None,";
        else {
            tree += to_string(root->val) + ",";
            rec_seria(root->left, tree);
            rec_seria(root->right, tree);
        }
    }
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string tree = "";
        rec_seria(root, tree);
        return tree;
    }


    TreeNode* rec_deseria(queue<string> & que) {
        if(que.front() == "None") {
            que.pop();
            return nullptr;
        }
        TreeNode *node = new TreeNode(stoi(que.front()));
        que.pop();
        node->left = rec_deseria(que);
        node->right = rec_deseria(que);
        return node;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        queue<string> que;
        int idx = 0;
        while(idx < data.size()) {
            int end = data.find(",", idx);
            string item = data.substr(idx, end-idx);
            que.push(item);
            idx = end + 1;
        }
        return rec_deseria(que);
    }
};
