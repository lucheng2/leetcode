#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<stack>

using namespace std;

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        if(nums.size()<=0) {
            return vector<int>(0);
        }
        vector<int> ans (nums.size(), -1);
        stack<int> stk;
        for(int i=0; i<nums.size() * 2 -1; ++i) {
            while(!stk.empty() && nums[stk.top()] < nums[i%nums.size()]) {
                ans[stk.top()] = nums[i%nums.size()];
                stk.pop();
            }
            stk.push(i % nums.size());
        }
        return ans;
    }
};

int main() {
	
	return 0;
}
