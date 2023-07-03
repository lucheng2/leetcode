#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<climits>

using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int> >& matrix) {
        int n = matrix.size(), m=matrix[0].size();
        vector<vector<int>> dp(n, vector<int>(m, INT_MAX));
        dp[0][0] = matrix[0][0];
        for(int i=1; i<n; i++)
            dp[i][0] = matrix[i][0] + dp[i-1][0];
        for(int i=1; i<m; i++)
            dp[0][i] = matrix[0][i] + dp[0][i-1];
        for(int i=1; i<n; i++) {
            for(int j=1; j<m; j++) {
                dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + matrix[i][j];
            }
        }
        return dp[n-1][m-1];
    }
};
