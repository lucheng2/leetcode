#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>

using namespace std;

int L, R, C;
char dungeon[40][40][40];
bool visited[40][40][40];
int step[40][40][40];
int dir[6][3] = {
    {0, 0, -1},
    {0, 0, 1},
    {0, -1, 0},
    {0, 1, 0},
    {-1, 0, 0},
    {1, 0, 0}
};
struct point{
    int x, y, z;
} in, out, start;

int bfs() {
    queue<point> que;
    que.push(start);
    visited[start.x][start.y][start.z] = true;
    while(!que.empty()) {
        out = que.front();
        que.pop();
        for(int i=0; i<6; i++) {
            in.x = out.x + dir[i][0];
            in.y = out.y + dir[i][1];
            in.z = out.z + dir[i][2];
            if(dungeon[in.x][in.y][in.z] == 'E')
                return step[out.x][out.y][out.z] + 1;
            if(dungeon[in.x][in.y][in.z]=='#' || visited[in.x][in.y][in.z])
                continue;
            que.push(in);
            visited[in.x][in.y][in.z] = true;
            step[in.x][in.y][in.z] = step[out.x][out.y][out.z] + 1;
        }
    }
    return -1;
}

int main() {
    while(true) {
        memset(dungeon, '#', sizeof(dungeon));
        memset(visited, false, sizeof(visited));
        memset(step, 0, sizeof(step));
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
                        start.x = i;
                        start.y = j;
                        start.z = k;
                    }
                }
            }
        }
        int ans = bfs();

        if(ans > 0) {
            printf("Escaped in %d minute(s).\n", ans);
        }
        else{
            cout<<"Trapped!"<<endl;
        }
    }
	
	return 0;
}
