#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int T, M;
int cost[105], weight[105];
int dp[1005];

void oneZeroPack(int c, int w) {
    for(int i=T; i>=c; i--)
        dp[i] = max(dp[i], dp[i-c]+w);
}

int main() {
    cin>>T>>M;
    for(int i=1; i<=M; i++) {
        cin>>cost[i]>>weight[i];
    }
    dp[0] = 0;
    for(int i=1; i<=M; i++) 
        oneZeroPack(cost[i], weight[i]);
    cout<<dp[T]<<endl;
	return 0;
}
