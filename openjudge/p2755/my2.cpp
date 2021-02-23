#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int n, data[21];
int dp[41][21];

int main() {
    scanf("%d", &n);
    for(int i=0; i<n; ++i)
        scanf("%d", &data[i+1]);
    memset(dp, 0, sizeof(dp));
    for(int i=1; i<=n; ++i) {
        dp[0][i] = 1;
    }
    dp[0][0] = 1;
    for(int i=1; i<=40; ++i) {
        for(int j=1; j<=n; ++j) {
            dp[i][j] = dp[i][j-1];
            if(i-data[j]>=0)
                dp[i][j] += dp[i-data[j]][j-1];
        }
    }
    printf("%d\n", dp[40][n]); 
	return 0;
}
