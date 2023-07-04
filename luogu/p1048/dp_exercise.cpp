# include<iostream>

using namespace std;

long long T, M;
long long cost[105], weight[105];
long long dp[105][1005];

int main() {
    cin >> T >> M;
    for(int i=1; i<=M; i++) {
        cin>>cost[i]>>weight[i];
    }

    for(int i=1; i<=M; i++) {
        for(int j=cost[i]; j<=T; j++) {
            dp[i][j] = max(dp[i-1][j], dp[i-1][j-cost[i]] + weight[i]);
        }
        for(int j=0; j<cost[i]; j++) {
            dp[i][j] = dp[i-1][j];
        }
    }
    cout<<dp[M][T]<<endl;
    return 0;
}
