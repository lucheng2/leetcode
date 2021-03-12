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
    vector<TreeNode*> generateTrees(int n) {
        if(n<=0)
            return {NULL};
        return searchTrees(1, n);
    }

    vector<TreeNode*> searchTrees(int start, int end) {
        if(start > end) {
            return {NULL};
        }
        vector<TreeNode*> allTrees;
        for(int i=start; i<=end; ++i) {
            vector<TreeNode*> leftTrees = searchTrees(start, i-1);
            vector<TreeNode*> rightTrees = searchTrees(i+1, end);
            for(auto leftTree: leftTrees) {
                for(auto rightTree: rightTrees) {
                    TreeNode* head = new TreeNode(i);
                    head->left = leftTree;
                    head->right = rightTree;
                    allTrees.push_back(head);
                }
            }
        }
        return allTrees;
    }
};

int main() {
	
	return 0;
}
