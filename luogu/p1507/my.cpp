#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define ll long long

using namespace std;

int V, M, n;
int dv[400], dm[400], dg[400];
int dp[400][400];

int main() {
    cin>>V>>M;
    cin>>n;
    for(int i=0; i<n; i++) {
        cin>>dv[i]>>dm[i]>>dg[i];
    }

    for(int k=0; k<n; k++) {
        for(int i=V; i>=0; i--) {
            for(int j=M; j>=0; j--) {
                if(i-dv[k]>=0 && j-dm[k]>=0)
                    dp[i][j] = max(dp[i][j], dp[i-dv[k]][j-dm[k]] + dg[k]);
            }
        }
    }
    cout<<dp[V][M]<<endl;
	return 0;
}
