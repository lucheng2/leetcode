#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int n, M, T;
int m[105], t[105];
int dp[205][205];

void zeroOnePack(int c1, int c2 ) {
    for(int i=M; i>=c1; i--) {
        for(int j=T; j>=c2; j--) {
            dp[i][j] = max(dp[i][j], dp[i-c1][j-c2]+1);
        }
    }
}

int main() {
    cin>>n>>M>>T;
    for(int i=1; i<=n; i++) {
        cin>>m[i]>>t[i];
    }
    for(int k=1; k<=n; k++) {
        zeroOnePack(m[k], t[k]);
    }
    cout<<dp[M][T]<<endl;
	return 0;
}
