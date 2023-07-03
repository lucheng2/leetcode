#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

class Solution {
public:
    string LCS(string s1, string s2) {
        int n1 = s1.size(), n2 = s2.size();
        if(n1==0 || n2==0)
            return "-1";
        vector<vector<int>> dp(n1+1, vector<int>(n2+1));
        vector<vector<int>> m(n1+1, vector<int>(n2+1));
        for(int i=1; i<=n1; i++) {
            for(int j=1; j<=n2; j++) {
                if(s1[i-1] == s2[j-1]) {
                    dp[i][j] = dp[i-1][j-1] + 1;
                }
                else if(dp[i-1][j] >= dp[i][j-1]) {
                    dp[i][j] = dp[i-1][j];
                    m[i][j] = 1;
                }
                else {
                    dp[i][j] = dp[i][j-1];
                    m[i][j] = 2;
                }
            }
        }
        string ans;
        int i=n1, j=n2;
        while(i && j) {
            if(m[i][j] == 0) {
                ans.push_back(s1[i-1]);
                i--, j--;
            }
            else if(m[i][j] == 1)
                i--;
            else
                j--;
        }
        if(ans.size() == 0)
            return "-1";
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
