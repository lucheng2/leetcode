#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<climits>

using namespace std;

class Solution {
public:
    int minCut(string s) {
        int n = s.size();
        vector<vector<int>> mem(n, vector<int> (n, true));
        for(int i=n-1; i>=0; --i) {
            for(int j=i+1; j<n; ++j) {
                mem[i][j] = (s[i]==s[j]) && mem[i+1][j-1];
            }
        }
        vector<int> dp(n, INT_MAX);
        dp[0] = 0;
        for(int i=0; i<n; ++i) {
            if(mem[0][i]) {
                dp[i] = 0;
            } else {
                for(int j=0; j<i; ++j) {
                    if(mem[j+1][i])
                        dp[i] = min(dp[i], dp[j]+1);
                }
            }
        }
        return dp[n-1];
    }
};

int main() {
	
	return 0;
}
