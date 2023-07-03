#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>

using namespace std;

class Solution {
public:
    int cnt = 0;
    vector<int> dx = {1, -1, 0, 0};
    vector<int> dy = {0, 0, 1, -1};
    int row, col;

    int solve(vector<vector<char> >& grid) {
        row = grid.size();
        col = grid[0].size();
        queue<pair<int, int>> que;

        for(int i=0; i<row; i++) {
            for(int j=0; j<col; j++) {
                if(grid[i][j] == '1') {
                    cnt++;
                    que.push(make_pair(i, j));
                    while(que.size()) {
                        auto p = que.front();
                        que.pop();
                        grid[p.first][p.second] = '0';
                        for(int k=0; k<4; k++) {
                            int xx=p.first + dx[k], yy=p.second + dy[k];
                            if(xx<0||xx>=row||yy<0||yy>=col||grid[xx][yy]=='0')
                                continue;
                            que.push(make_pair(xx, yy));
                        }
                    }
                }
            }
        }
        return cnt;
    }
};
