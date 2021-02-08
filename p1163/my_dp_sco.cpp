#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define MAX 101

int d[MAX][MAX];
int *dp;
int N;

using namespace std;

int main() {
    scanf("%d", &N);
    for(int i=1; i<=N; ++i)
        for(int j=1; j<=i; ++j) {
            scanf("%d", &d[i][j]);
        }
    dp = d[N];
    for(int i=N-1; i>=1; --i) {
        for(int j=1; j<=i; ++j) {
            dp[j] = max(dp[j], dp[j+1]) + d[i][j];
        }
    }    
    printf("%d\n", dp[1]);
	return 0;
}
