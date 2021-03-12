#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<stack>
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
    bool isValidBST(TreeNode* root) {
        stack<TreeNode*> stk;
        long long pre = (long long) INT_MIN -1;
        if(root == NULL)
            return true;
        while(root != NULL || !stk.empty()) {
            while(root != NULL) {
                stk.push(root);
                root = root->left;
            }
            root = stk.top();
            stk.pop();
            if(root->val <= pre) {
                return false;
            } else {
                pre = root->val;
            }
            root = root->right;
        }
        return true;
    }
};

int main() {
	
	return 0;
}
