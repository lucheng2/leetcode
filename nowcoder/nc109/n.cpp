#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

class Solution {
public:
    int cnt = 0;
    vector<int> dx = {1, -1, 0, 0};
    vector<int> dy = {0, 0, 1, -1};
    int row, col;
    void dfs(vector<vector<char>> &grid, int i, int j) {
        grid[i][j] = '0';
        for(int k=0; k<4; k++) {
            int xx=i+dx[k], yy=j+dy[k];
            if(xx<0||xx>=row||yy<0||yy>=col||grid[xx][yy]=='0')
                continue;
            dfs(grid, xx, yy);
        }
    }

    int solve(vector<vector<char> >& grid) {
        row = grid.size();
        col = grid[0].size();
        for(int i=0; i<row; i++) {
            for(int j=0; j<col; j++) {
                if(grid[i][j] == '1') {
                    cnt++;
                    dfs(grid, i, j);
                }
            }
        }
        return cnt;
    }
};
