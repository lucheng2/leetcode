#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        if(root == NULL || (root->left==NULL && root->right==NULL)) {
            return true;
        }
        if(root->left!=NULL && root->right!=NULL) {
            if(maxNode(root->left, root->left->val) < root->val && minNode(root->right, root->right->val) > root->val) {
                return isValidBST(root->left) && isValidBST(root->right);
            } else {
                return false;
            }
        } else if(root->left!=NULL) {
            if(maxNode(root->left, root->left->val) < root->val) {
                return isValidBST(root->left);
            } else 
                return false;
        } else {
            if(minNode(root->right, root->right->val) > root->val) {
                return isValidBST(root->right);
            } else 
                return false;
        }
    }
    int maxNode(TreeNode* root, int val) {
        if(root == NULL) 
            return val;
        val = max(val, root->val);
        return max(maxNode(root->left, val), maxNode(root->right, val));
    }
    int minNode(TreeNode* root, int val) {
        if(root == NULL) 
            return val;
        val = min(val, root->val);
        return min(minNode(root->left, val), minNode(root->right, val));
    }
};

int main() {
	
	return 0;
}
