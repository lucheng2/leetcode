#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<unordered_map>
#include<queue>
#define ll long long 

using namespace std;

class Solution {
public:
    int visited[505][505];
    int dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int m=grid1.size(), n=grid1[0].size();
        int cnt = 0;
        memset(visited, 0, sizeof(visited));
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(visited[i][j] || !grid2[i][j])
                    continue;
                int ans = 1;
                queue<pair<int, int>> q;
                q.push(make_pair(i, j));
                visited[i][j] = 1;
                while(q.size()) {
                    auto tmp = q.front();
                    q.pop();
                    visited[tmp.first][tmp.second] = 1;
                    if(grid1[tmp.first][tmp.second] == 0)
                        ans = 0;
                    for(int k=0; k<4; k++) {
                        int x = tmp.first + dx[k];
                        int y = tmp.second + dy[k];
                        if(x<0 || x >=m || y<0 || y>=n || visited[x][y] || grid2[x][y]==0)
                            continue;
                        q.push(make_pair(x, y));
                        visited[x][y] = 1;
                    }
                }
                cnt += ans;
            }
        }
        return cnt;
    }
};
