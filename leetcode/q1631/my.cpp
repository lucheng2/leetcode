#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

class UnionSet {
public:
    vector<int> parent;
    UnionSet(int n) {
        parent.resize(n);
        for(int i=0; i<n; ++i)
            parent[i] = i;
    }

    int find(int x) {
        if(x != parent[x])
            parent[x] = find(parent[x]);
        return parent[x];
    }

    void unionSet(int x, int y) {
        int px = find(x), py = find(y);
        if(px == py)
            return;
        parent[px] = py;
    }

    bool isConnected(int x, int y) {
        return find(x) == find(y);
    }
};
bool myLess(const vector<int> &a, const vector<int> &b) {
    return a[2] < b[2];
}
class Solution {
public:

    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<int>> edges;
        for(int i=0; i<n; ++i)
            for(int j=0; j<m; ++j) {
                int id = i*m + j;
                if(i>0)
                    edges.push_back({id - m, id, abs(heights[i][j] - heights[i-1][j])});
                if(j>0)
                    edges.push_back({id-1, id, abs(heights[i][j] - heights[i][j-1])});
            }
        sort(edges.begin(), edges.end(), myLess);
        int ans = 0;
        UnionSet us(n*m);

        for(auto edge: edges) {
            us.unionSet(edge[0], edge[1]);
            if(us.isConnected(0, n*m-1)) {
                ans = edge[2];
                break;
            }
        }
        return ans;
    }
};

int main() {
	
	return 0;
}
