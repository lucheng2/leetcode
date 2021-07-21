#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define ll long long 

using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        int m=word1.size(), n=word2.size();
        if(m*n==0)
            return m+n;
        int dp[m+1][n+1];
        for(int i=0; i<=m; i++)
            dp[i][0] = i;
        for(int i=0; i<=n; i++)
            dp[0][i] = i;

        for(int i=1; i<=m; i++) {
            for(int j=1; j<=n; j++) {
                int adl = dp[i-1][j] + 1;
                int adr = dp[i][j-1] + 1;
                int rep = dp[i-1][j-1];
                if(word1[i-1]!=word2[j-1])
                    rep ++;
                dp[i][j] = min(adl, min(adr, rep));
            }
        }
        return dp[m][n];
    }
};
