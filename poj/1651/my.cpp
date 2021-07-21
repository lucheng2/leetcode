#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

long long mx = 1e18;

int main() {
    int N;
    long long data[105], dp[105][105];
    cin>>N;
    for(int i=0; i<N; i++) 
        cin>>data[i];
    int n = N -1;
    for(int i = 1; i<=n; i++)
        dp[i][i] = 0;
    for(int len=2; len<=n; len++) {
        for(int i=1; i+len-1<=n; i++) {
            int j=i+len-1;
            dp[i][j] = mx;
            for(int k=i; k<j; k++) {
                dp[i][j] = min(dp[i][j], dp[i][k]+dp[k+1][j]+data[i-1]*data[k]*data[j]);
            }
        }
    }
    cout<<dp[1][n]<<endl;
	return 0;
}
