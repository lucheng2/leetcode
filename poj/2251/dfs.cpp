#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int L, R, C;
char dungeon[40][40][40];
bool visited[40][40][40];
const int limit = 1e9;
int ans;
int dir[6][3] = {
    {0, 0, -1},
    {0, 0, 1},
    {0, -1, 0},
    {0, 1, 0},
    {-1, 0, 0},
    {1, 0, 0}
};
int start[3];
int cnt;

void dfs(int i, int j, int k) {
    if(dungeon[i][j][k] == 'E') {
        ans = min(ans, cnt);
        return;
    }
    if(visited[i][j][k] || dungeon[i][j][k]=='#' || cnt >= ans-1) {
        return;
    }
    visited[i][j][k] = true;
    cnt++;
    for(int m=0; m<6; m++) {
        dfs(i+dir[m][0], j+dir[m][1], k+dir[m][2]);
    }
    cnt--;
    visited[i][j][k] = false;
}

int main() {
    while(true) {
        memset(dungeon, '#', sizeof(dungeon));
        memset(visited, false, sizeof(visited));
        ans = limit;
        cnt = 0;
        cin>>L>>R>>C;
        if(!L && !R && !C) {
            break;
        }
        for(int i=1; i<=L; i++) {
            char in[40];
            for(int j=1; j<=R; j++) {
                scanf("%s", in);
                for(int k=1; k<=C; k++) {
                    dungeon[i][j][k] = in[k-1];
                    if(in[k-1]=='S') {
                        start[0] = i;
                        start[1] = j;
                        start[2] = k;
                    }
                }
            }
        }
        dfs(start[0], start[1], start[2]);

        if(ans<limit) {
            printf("Escaped in %d minute(s).\n", ans);
        }
        else{
            cout<<"Trapped!"<<endl;
        }
    }
	
	return 0;
}
