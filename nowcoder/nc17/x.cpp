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
        string str;
        str.resize(2*n+1);
        int j=0;
        for(int i=0; i<n; i++) {
            str[j++] = '#';
            str[j++] = A[i];
        }
        str[j] = '#';
        n = 2*n + 1;
        vector<int> dp(n);
        for(int i=0, l=0, r=-1; i<n; i++) {
            int k = (i > r) ? 1 : min(dp[l + r - i], r - i);
            while (i-k>=0 && i+k<n && str[i-k]==str[i+k])
                k++;
            dp[i] = --k;
            if(i + k > r) {
                r = i+k;
                l = i-k;
            }
        }
        return *max_element(dp.begin(), dp.end());
    }
};
