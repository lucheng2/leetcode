#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define MAX 1003

using namespace std;
int data[MAX];
int dp[MAX];
int N;

int main() {
    scanf("%d", &N);
    for(int i=1; i<=N; ++i) {
        scanf("%d", &data[i]);
        dp[i] = 1;
    }    
    for(int i=2; i<=N; ++i) {
        for(int j=1; j<i; ++j) {
            if(data[i] > data[j]) {
                dp[i] = max(dp[i], dp[j]+1);
            }
        }
    }
    int res = * max_element(dp+1, dp+N+1);
    printf("%d\n", res);
	return 0;
}
