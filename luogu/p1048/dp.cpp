#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int T, M;
int cost[105], weight[105];
int dp[105][1005];


int main() {
    cin>>T>>M;
    for(int i=1; i<=M; i++) {
        cin>>cost[i]>>weight[i];
    }
    memset(dp[0], 0, sizeof(dp[0]));
    for(int i=1; i<=M; i++) {
        for(int v=cost[i]; v<=T; v++) {
            dp[i][v] = max(dp[i-1][v], dp[i-1][v-cost[i]]+weight[i]);
        }
        for(int v=0; v<cost[i]; v++)
            dp[i][v] = dp[i-1][v];
    }
    cout<<dp[M][T]<<endl;
	return 0;
}
