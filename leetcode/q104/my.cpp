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
    int maxD = 0;
    int depth = 0;
    int maxDepth(TreeNode* root) {
        if(root == NULL)
            return maxD;
        depth ++;
        maxD = max(maxD, depth);
        maxDepth(root->left);
        maxDepth(root->right);
        depth --;
        return maxD;
    }
};

int main() {
	
	return 0;
}
