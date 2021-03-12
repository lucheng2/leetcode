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
    bool recursion(TreeNode* root, long long low, long long up) {
        if(root == NULL)
            return true;
        if(root->val<=low || root->val>=up)
            return false;
        return recursion(root->left, low, root->val) && recursion(root->right, root->val, up);
    }
    bool isValidBST(TreeNode* root) {
        long long low = (long long)INT_MIN -1;
        long long up = (long long ) INT_MAX + 1;
        return recursion(root, low, up);
    }
};

int main() {
	
	return 0;
}
