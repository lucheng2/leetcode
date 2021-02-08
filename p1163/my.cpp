#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define MAX 101

using namespace std;

int d[MAX][MAX];
int N;

int maxSum(int i, int j) {
    if(i==N) {
        return d[i][j];
    }
    int x = maxSum(i+1, j);
    int y = maxSum(i+1, j+1);
    return max(x, y) + d[i][j];
}

int main() {
    scanf("%d", &N);
    for(int i=1; i<=N; ++i) {
        for(int j=1; j<=i; ++j) {
            scanf("%d", &d[i][j]);
        }
    }
    int res = maxSum(1, 1);
    printf("%d\n", res);
	return 0;
}
