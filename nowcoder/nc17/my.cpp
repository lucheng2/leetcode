#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

class Solution {
public:
    int getLongestPalindrome(string A, int n) {
        if(n<=1)
            return n;
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        int ans = 1;
        for(int right=1; right<n; right++) {
            for(int left=right; left>=0; left--) {
                if(A[left] != A[right])
                    continue;
                if(right - left <= 2)
                    dp[left][right] = true;
                else
                    dp[left][right] = dp[left+1][right-1];
                if(dp[left][right])
                    ans = max(ans, right - left + 1);
            }
        }
        return ans;
    }
};
