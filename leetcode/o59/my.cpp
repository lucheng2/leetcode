#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#define ll long long 

using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans;
        if(n==0 || k==0 || n<k)
            return ans;
        deque<int> dq;
        for(int i=0; i<n; i++) {
            while(!dq.empty() && nums[dq.back()] < nums[i])
                dq.pop_back();
            dq.push_back(i);
            if(dq.front() + k <= i)
                dq.pop_front();
            if(i+1 >= k)
                ans.push_back(nums[dq.front()]);
        }
        return ans;
    }
};
