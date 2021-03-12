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
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
 
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        queue<TreeNode*> que;
        que.push(root);
        que.push(root);
        while(!que.empty()) {
            TreeNode * p1 = que.front();
            que.pop();
            TreeNode * p2 = que.front();
            que.pop();
            if(p1==NULL && p2==NULL) {
                continue;
            } else if(p1==NULL || p2==NULL) {
                return false;
            } else {
                if(p1->val != p2->val) {
                    return false;
                } else {
                    que.push(p1->left);
                    que.push(p2->right);
                    que.push(p1->right);
                    que.push(p2->left);
                }
            }
        }
        return true;
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
