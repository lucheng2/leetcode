# include<iostream>
# include<algorithm>

using namespace std;

long long T, M;
long long cost[105], weight[105];
long long dp[1005];

void oneZeroPack(int c, int w) {
    for(int j=T; j>=c; j--) {
        dp[j] = max(dp[j], dp[j-c]+w);
    }
}

int main() {
    cin >> T >> M;
    for(int i=1; i<=M; i++) {
        cin>>cost[i]>>weight[i];
    }

    for(int i=1; i<=M; i++) {
        oneZeroPack(cost[i], weight[i]);
    }
    cout<<dp[T]<<endl;
    return 0;
}
