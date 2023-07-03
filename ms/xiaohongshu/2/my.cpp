#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define ll long long

using namespace std;

int graph[10][10], visited[10][10];
int dx[] = {1, -1, 0, 0}, dy[]={0, 0, 1, -1};
int ans = 0;
int n;

bool check() {
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            if(visited[i][j] == 0)
                return false;
    return true;
}

void dfs(int x, int y) {
    if(visited[x][y])
        return;
    visited[x][y] = 1;
    if(x+1==n && check()) {
        ans ++;
        return;
    }
    
    for(int i=0; i<4; i++) {
        int xx = x+dx[i], yy=y+dy[i];
        if(xx<0||xx>=n||yy<0||yy>=n||graph[xx][yy]==0||visited[xx][yy])
            continue;
        dfs(xx, yy);
    }
    visited[x][y] = 0;
}

int main() {
    cin>>n;
    string s;
    for(int i=0; i<n; i++) {
        cin>>s;
        for(int j=0; j<n; j++) {
            graph[i][j] = s[j]=='.'?1: 0;
            visited[i][j] = s[j]=='#'?1: 0;
        }
    }
    dfs(0, 0);
    cout<<ans<<endl;
	return 0;
}
