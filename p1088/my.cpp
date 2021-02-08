#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int data[101][101];
int mem[101][101];
int R, C;
int dp(int i, int j) {
    if(mem[i][j]!=0) 
        return mem[i][j];
    int res = 1;
    if(i-1>=1 && data[i-1][j]<data[i][j])
        res = max(dp(i-1,j)+1, res);
    if(i+1<=R && data[i+1][j]<data[i][j])
        res = max(dp(i+1, j) +1, res);
    if(j-1>=1 && data[i][j-1]<data[i][j])
        res = max(dp(i, j-1) +1, res);
    if(j+1<=C && data[i][j+1]<data[i][j])
        res = max(dp(i, j+1) +1, res);
    mem[i][j] = res;
    return res;
}

int main() {
    scanf("%d%d", &R, &C);
    for(int i=1; i<=R; ++i)
        for(int j=1; j<=C; ++j)
            scanf("%d", &data[i][j]);

    for(int i=1; i<=R; ++i) {
        for(int j=1; j<=C; ++j) {
            dp(i, j);
        }
    }
    int ans = mem[1][1];
    for(int i=1; i<=R; ++i)
        for(int j=1; j<=C; ++j)
            if(ans < mem[i][j])
                ans = mem[i][j];

    printf("%d\n", ans);
	return 0;
}
