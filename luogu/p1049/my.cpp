#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define ll long long

using namespace std;

int v, n;
int dp[20005], w[32];

int main() {
    cin>>v>>n;
    for(int i=1; i<=n; i++) {
        cin>>w[i];
    }
    for(int i=1; i<=n; i++) 
        for(int j=v; j>=w[i]; j--) {
            dp[j] = max(dp[j], dp[j-w[i]] + w[i]);
        }
    cout<<v - dp[v]<<endl;
	return 0;
}
