#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define ll long long

using namespace std;

int n, V;
int prm[1005];
int data[1005];
ll dp[1005];

void getPrm() {
    memset(prm, 1, sizeof(prm));
    for(int i=2; i<=V; i++) {
        if(prm[i]) {
            for(int j=i+i; j<=V; j+=i)
                prm[j] = 0;
        }
    }
    n = 0;
    for(int i=2; i<=V; i++) {
        if(prm[i]) {
            data[n++] = i;
        }
    }
}

int main() {
    cin>>V;
    getPrm();
    dp[0] = 1;
    for(int i=0; i<n; i++) {
        for(int j=data[i]; j<=V; j++)
            dp[j] += dp[j-data[i]];
    }
    cout<<dp[V]<<endl;
	return 0;
}
