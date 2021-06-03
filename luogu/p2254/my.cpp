#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int N, M, x, y, K;
int data[205][205];
int s[205], t[205], k[205];
int dir[5][2] = {{0, 0}, {-1, 0}, {1, 0}, {0, -1}, {0, 1}};
char in[205];
int mem[205][205][205];

int dfs(int i, int x, int y) {
    if(i>K) {
        return 0;
    }
    if(mem[i][x][y]!=-1)
        return mem[i][x][y];
    int len = t[i] - s[i] + 1;
    int a = 0;
    int tmp = 0;
    while(a<=len)  {
        if(data[x+a*dir[k[i]][0]][y+a*dir[k[i]][1]])
            tmp = max(dfs(i+1, x+a*dir[k[i]][0], y+a*dir[k[i]][1])+a, tmp);
        else
            break;
        a++;
    }
    mem[i][x][y] = tmp;
    return tmp;
}

int main() {
    cin>>N>>M>>x>>y>>K;
    for(int i=1; i<=N; i++) {
        scanf("%s", in);
        for(int j=1; j<=M; j++){
            data[i][j] = in[j-1]=='.'?1: 0;
        }
    }
    for(int i=1; i<=K; i++)
        cin>>s[i]>>t[i]>>k[i];
    memset(mem, -1, sizeof(mem));
    int ans = dfs(1, x, y);
    cout<<ans<<endl;
	return 0;
}
