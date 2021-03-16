#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<unordered_map>

using namespace std;

  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
 
class Solution {
public:
    unordered_map<int, int> hm;

    TreeNode* build(vector<int> & pre, int pre_left, int pre_right, vector<int> &vin, int vin_left, int vin_right) {
        if(pre_left>pre_right) {
            return NULL;
        }
        TreeNode * root = new TreeNode(pre[pre_left]);
        int root_index = hm[pre[pre_left]];
        root->left = build(pre, pre_left+1, pre_left + root_index - vin_left - 1, vin, vin_left, root_index - 1);
        root->right = build(pre, pre_left + root_index - vin_left + 1, pre_right,  vin, root_index + 1, vin_right);
        return root;
    }
    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
        for(int i=0; i<vin.size(); ++i) {
            hm[vin[i]] = i;
        }
        return build(pre, 0, pre.size()-1, vin, 0, vin.size()-1);
    }
};

int main() {
	Solution s;
    vector<int> pre = {1,2,4,7,3,5,6,8};
    vector<int> vin = {4,7,2,1,5,3,8,6};
    TreeNode * root = s.reConstructBinaryTree(pre, vin);
	return 0;
}
