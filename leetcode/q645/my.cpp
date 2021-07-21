#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define ll long long 

using namespace std;

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        vector<int> hm(n+1, 0);
        for(int i=0; i<n; i++) {
            hm[nums[i]] ++;
        }
        vector<int> ans(2);
        for(int i=1; i<=n; i++) {
            if(hm[i] == 2) 
                ans[0] = i;
            if(hm[i] == 0)
                ans[1] = i;
        }
        return ans;
    }
};
