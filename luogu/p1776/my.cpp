#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;
int n, W;
int c[105], w[105], m[105];
int dp[40005];

void zeorOnePack(int c, int w) {
    for(int v=W; v>=c; v--) {
        dp[v] = max(dp[v], dp[v-c]+w);
    }
}
void completePack(int c, int w) {
    for(int v=c; v<=W; v++) {
        dp[v] = max(dp[v], dp[v-c]+w);
    }
}
void multiPack(int c, int w, int m) {
    if(c*m>=W) {
        completePack(c, w);
        return;
    }
    int k = 1;
    while(k<m) {
        zeorOnePack(k*c, k*w);
        m = m -k;
        k = k*2;
    }
    zeorOnePack(m*c, m*w);
}

int main() {
    cin>>n>>W;
    for(int i=1; i<=n; i++) {
        cin>>w[i]>>c[i]>>m[i];
    }
    for(int i=1; i<=n; i++) {
        multiPack(c[i], w[i], m[i]);
    }
    cout<<dp[W]<<endl;
	
	return 0;
}
