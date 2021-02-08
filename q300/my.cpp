#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int len=nums.size();
        if(len<=1) {
            return len;
        }
        vector<int> dp(len+2, 1);
        for(int i=2; i<=len; ++i) {
            for(int j=1; j<i; ++j) {
                if(nums[j-1]<nums[i-1])
                    dp[i] = max(dp[i], dp[j]+1);
            }
        }
        return *(max_element(dp.begin(), dp.end()));
    }
};

int main() {
	
	return 0;
}
