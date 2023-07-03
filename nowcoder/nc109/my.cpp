#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

class Solution {
public:
    vector<int> fa;
    vector<int> dx = {1, -1, 0, 0};
    vector<int> dy = {0, 0, 1, -1};
    int cnt;

    void init(vector<vector<char>> & g) {
        int n=g.size(), m=g[0].size();
        fa = vector<int> (n * m);
        cnt = 0;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(g[i][j] == '1') {
                    fa[i*m + j] = i*m + j;
                    cnt++;
                }
            }
        }
    }

    int find(int n) {
        if(fa[n] != n) 
            fa[n] = find(fa[n]);
        return fa[n];
    }

    void unionSet(int x, int y) {
        int fax = find(x);
        int fay = find(y);
        if(fax != fay) {
            fa[fax] = fay;
            cnt--;
        }
    }

    int solve(vector<vector<char> >& grid) {
        int n = grid.size();
        int m = grid[0].size();
        init(grid);
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(grid[i][j] == '1') {
                    for(int k=0; k<4; k++) {
                        int xx = i + dx[k], yy = j+dy[k];
                        if(xx<0||xx>=n||yy<0||yy>=m||grid[xx][yy]=='0')
                            continue;
                        else {
                            unionSet(i*m +j, xx*m+yy);
                        }
                    }
                }
            }
        }
        return cnt;
    }
};
