#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;
int m,n;
int data[100005], f[100005][32];
int query[100005][2];

int main() {
    cin>>m>>n;
    int logn = 31 - __builtin_clz(m);
    for(int i=1; i<=m; i++) {
        scanf("%d", &data[i]);
    }
    for(int i=0; i<n; i++) {
        scanf("%d%d", &query[i][0], &query[i][1]);
    }
    for(int i=1; i<=m; i++) {
        f[i][0] = data[i];
    }
    for(int j=1; j<=logn; j++) {
        for(int i=1; i+(1<<j)-1 <= m; i++) {
            f[i][j] = min(f[i][j-1], f[i+(1<<(j-1))][j-1]);
        }
    }
    for(int i=0; i<n; i++) {
        int x=query[i][0], y=query[i][1];
        int lognq = 31 - __builtin_clz(y-x+1);
        printf("%d ", min(f[x][lognq], f[y-(1<<lognq) + 1][lognq]));
    }
	return 0;
}
