#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int t, m;
int c[10005], w[10005];
long long dp[10000005];

void completePack(int c, int w) {
    for(int v=c; v<=t; v++) {
        dp[v] = max(dp[v], dp[v-c]+w);
    }
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
