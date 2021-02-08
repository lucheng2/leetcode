#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int n, data[21];
int dp[41][21];

int ways(int w, int k) {
    if(w == 0) {
        return 1;
    }
    if(w<0||k<=0) {
        return 0;
    }
    if(dp[w][k] != 0)
        return dp[w][k];
    int ret = ways(w, k-1) + ways(w-data[k], k-1);
    dp[w][k] = ret;
    return ret;
}

int main() {
    scanf("%d", &n);
    for(int i=0; i<n; ++i)
        scanf("%d", &data[i+1]);
    int ans = ways(40, n);
    printf("%d\n", ans); 
	return 0;
}
