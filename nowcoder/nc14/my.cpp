#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>

using namespace std;

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};

class Solution {
public:
    vector<vector<int> > Print(TreeNode* pRoot) {
        vector<vector<int>> ans;
        if(pRoot == NULL)
            return ans;
        int reverseFlag = 0;
        queue<TreeNode*> que;
        que.push(pRoot);
        TreeNode *p;
        while(!que.empty()) {
            int n = que.size();
            vector<int> level;
            while(n>0) {
                n--;
                p = que.front();
                que.pop();
                level.push_back(p->val);
                if(p->left)
                    que.push(p->left);
                if(p->right)
                    que.push(p->right);
            }
            if(reverseFlag & 1)
                reverse(level.begin(), level.end());
            reverseFlag++;
            ans.push_back(level);
        }
        return ans;
    }
};
