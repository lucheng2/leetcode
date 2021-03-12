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
    TreeNode* recur(vector<int> &nums, int start, int end) {
        if(start>end) 
            return NULL;
        if(start == end) {
            return new TreeNode(nums[start]);
        }
        int mid = start + (end - start) / 2;
        return new TreeNode(nums[mid], recur(nums, start, mid-1), recur(nums, mid+1, end));
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return recur(nums, 0, nums.size()-1);
    }
};

int main() {
	
	return 0;
}
