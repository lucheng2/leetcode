#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define ll long long

using namespace std;

int n, x;
int data[1005][3];
ll dp[1005];

int main() {
    cin>>n>>x;
    for(int i=1; i<=n ;i++) {
        cin>>data[i][0]>>data[i][1]>>data[i][2];
    }
    for(int i=1; i<=n; i++) {
        for(int j=x; j>=0; j--) {
            if(j-data[i][2]>=0)
                dp[j] = max(dp[j]+data[i][0], dp[j-data[i][2]]+data[i][1]);
            else
                dp[j] = dp[j] + data[i][0];
        }
    }
    cout<<5*dp[x]<<endl;
	return 0;
}
