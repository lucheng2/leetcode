#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<climits>

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
    long long pre = (long long) INT_MIN - 1;
    bool inorderRec(TreeNode *root) {
        if(root == NULL)
            return true;
        if(!inorderRec(root->left)) {
            return false;
        }
        if(root->val <= pre) {
            return false;
        } else {
            pre = root->val;
        }
        return inorderRec(root->right);
    }
    bool isValidBST(TreeNode* root) {
        return inorderRec(root);
    }
};

int main() {
	
	return 0;
}
