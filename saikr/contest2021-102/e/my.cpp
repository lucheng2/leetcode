#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int a[50], b[50];
int dp[50];

int main() {
    int n;
    scanf("%d", &n);
    for(int i=0; i<n; i++) 
        scanf("%d", &b[i]);
    for(int i=0; i<n; i++) 
        scanf("%d", &a[i]);
    int V = n;
    for(int i=0; i<n; i++) {
        for(int v=V; v>=b[i]; v--) {
            dp[v] = max(dp[v], dp[v-b[i]]+a[i]);
        }
    }
    cout<<dp[V]<<endl;
	return 0;
}
