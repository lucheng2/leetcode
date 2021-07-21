#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define ll long long 

using namespace std;

 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:
    void retrovers(TreeNode* root, vector<TreeNode*> &road, TreeNode* p) {
        while(root != p) {
            road.push_back(root);
            if(root->val < p->val) 
                root = root->right;
            else
                root = root->left;
        }
        road.push_back(root);
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> proad, qroad;
        retrovers(root, proad, p);
        retrovers(root, qroad, q);
        TreeNode * ans;
        int n = min(proad.size(), qroad.size());
        for(int i=0; i<n; i++) {
            if(proad[i] == qroad[i])
                ans = proad[i];
            else
                break;
        }
        return ans;
    }
};
