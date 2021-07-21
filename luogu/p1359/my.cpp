#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define ll long long

using namespace std;
int n;
int data[205][200];
int dp[205];

int main() {
    cin>>n;
    for(int i=0; i<n-1; i++) {
        for(int j=1; i+j<n; j++)
            cin>>data[i][i+j];
    }
    memset(dp, 1000000, sizeof(dp));
    dp[0] = 0;
    for(int i=1; i<n; i++) {
        for(int j=0; j<=i; j++) {
            dp[i] = min(dp[i], dp[j]+data[j][i]);
        }
    }
    cout<<dp[n-1]<<endl;
	
	return 0;
}
