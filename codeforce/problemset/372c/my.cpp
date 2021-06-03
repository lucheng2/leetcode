#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;
int n, m, d;
long long a[305], b[305], t[305];
long long dp[2][150005];

int fl;
int que[150005];

void dpf() {
    fl = 1;
    memset(dp[0], 0, sizeof(dp[0]));
    memset(que, 0, sizeof(que));
    for(int i=1; i<=m ;i++) {
        int l=1, r=0, k=1;
        for(int j=1; j<=n; j++) {
            for(; k<=min(1ll*n, j+d*(t[i]-t[i-1])); k++) {
                while(l<=r && dp[fl^1][que[r]]<=dp[fl^1][k])
                    r--;
                que[++r] = k;
            }
            while(l<=r && que[l]<max(1ll, j-d*(t[i]-t[i-1])))
                l++;
            dp[fl][j] = dp[fl^1][que[l]] - abs(a[i]-j) + b[i];
        }
        fl = fl ^ 1;
    }
}

int main() {
    cin>>n>>m>>d;
    for(int i=1; i<=m; i++) {
        cin>>a[i]>>b[i]>>t[i];
    }
    dpf();
    long long ans = -1e18;
    for(int i=1; i<=n; i++)
        ans = max(ans, dp[fl^1][i]);
    cout<<ans<<endl;
	return 0;
}
