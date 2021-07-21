#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define ll long long

using namespace std;

int n, m;
int v, p;
int data[30][2], dp[30005];

int main() {
    cin>>n>>m;
    for(int i=0; i<m; i++) {
        cin>>v>>p;
        data[i][0] = v;
        data[i][1] = v * p;
    }
    for(int i=0; i<m; i++) {
        for(int j=n; j>= data[i][0]; j--) 
            dp[j] = max(dp[j], dp[j-data[i][0]] + data[i][1]);
    }
    cout<<dp[n]<<endl;
	return 0;
}
