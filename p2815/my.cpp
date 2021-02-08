#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int R, C;
int room[60][60];
int color[60][60];
int roomNum=0, maxNum=0, maxNumTurn=0;

void dfs(int i, int j) {
    if(color[i][j]!=0)
        return;
    color[i][j] = roomNum;
    maxNumTurn++;
    if((room[i][j] & 1) == 0 ) 
        dfs(i, j-1);
    if((room[i][j] & 2) == 0 )
        dfs(i-1, j);
    if((room[i][j] & 4) == 0 )
        dfs(i, j+1);
    if((room[i][j] & 8) == 0 )
        dfs(i+1, j);
}

int main() {
    scanf("%d%d", &R, &C);
    for(int i=0; i<R; ++i) {
        for(int j=0; j<C; ++j)
            scanf("%d", &room[i][j]);
    }
    memset(color, 0, sizeof(color));
    for(int i=0; i<R; ++i)
        for(int j=0; j<C; ++j) {
            if(color[i][j]==0) {
                roomNum++;
                maxNumTurn = 0;
                dfs(i, j);
                maxNum = max(maxNum, maxNumTurn);
            }
        }
    printf("%d\n%d", roomNum, maxNum);
	return 0;
}
