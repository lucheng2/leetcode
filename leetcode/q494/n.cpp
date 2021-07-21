#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<numeric>
#define ll long long 

using namespace std;

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if((sum+target)&1)
            return 0;
        int negSum = (sum+target) / 2;
        vector<int> dp(negSum+1, 0);
        dp[0] = 1;
        for(int i=0; i<nums.size(); i++) {
            for(int j=negSum; j>=0; j--) {
                if(j>=nums[i])
                    dp[j] = dp[j] + dp[j-nums[i]];
            }
        }
        return dp[negSum];
    }
};

