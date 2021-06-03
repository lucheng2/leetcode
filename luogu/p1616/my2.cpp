#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int t, m;
int c[10005], w[10005];
long long dp[10000005];

void zeroOnePack(int c, long long w) {
    for(int v=t; v>=c; v--) {
        dp[v] = max(dp[v], dp[v-c]+w);
    }
}
void completePack(int c, int w) {
    int m = t/c;
    int k=1;
    while(k<m) {
        zeroOnePack(k*c, (long long)k*w);
        m -= k;
        k = k<<1;
    }
    zeroOnePack(m*c, (long long)m*w);
}

int main() {
    cin>>t>>m;
    for(int i=1; i<=m; i++) {
        cin>>c[i]>>w[i];
    }
    for(int i=1; i<=m; i++) {
        completePack(c[i], w[i]);
    }
    cout<<dp[t]<<endl;
	return 0;
}
