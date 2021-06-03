#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;
int n, m;
int c[4005], w[4005];
int dp[13000];

void zeroOnePack(int c, int w) {
    for(int v=m; v>=c; v--) {
        dp[v] = max(dp[v], dp[v-c]+w);
    }
}

int main() {
    cin>>n>>m;
    for(int i=1; i<=n; i++) {
        cin>>c[i]>>w[i];
    }
    for(int i=1; i<=n; i++) {
        zeroOnePack(c[i], w[i]);
    }
    cout<<dp[m]<<endl;
	return 0;
}
