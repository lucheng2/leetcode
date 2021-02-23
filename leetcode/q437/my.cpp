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
    int pathSum(TreeNode* root, int sum) {
        if(root== NULL)
            return 0;
        return count(root, sum) + pathSum(root->left, sum) + pathSum(root->right, sum);
    }
    int count(TreeNode* node, int sum) {
        if(node == NULL)
            return 0;
        return (node->val == sum) + count(node->left, sum - node->val) + count(node->right, sum - node->val);
    }
};

int main() {
	
	return 0;
}
