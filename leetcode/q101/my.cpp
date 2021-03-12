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
    bool check(TreeNode * p1, TreeNode * p2) {
        if(p1==NULL && p2==NULL)
            return true;
        if(p1==NULL || p2==NULL)
            return false;
        return p1->val==p2->val && check(p1->left, p2->right) && check(p1->right, p2->left);
    }
    bool isSymmetric(TreeNode* root) {
        return check(root, root);
    }
};

int main() {
	
    Solution s;
    TreeNode * root = new TreeNode(1, 
            new TreeNode(2, new TreeNode(2, NULL, NULL), NULL), 
            new TreeNode(2, new TreeNode(2, NULL, NULL), NULL) );
    bool res = s.isSymmetric(root);
    printf("%d\n", res);
	return 0;
}
