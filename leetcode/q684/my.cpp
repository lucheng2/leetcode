#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

class Solution {
public:
    vector<int> parent;
    int find(int x) {
        if(parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

    void unionSet(int x, int y) {
        if(find(parent[x]) == find(parent[y]))
            return;
        parent[find(parent[x])] = find(parent[y]);
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int N = edges.size();
        parent.resize(N+1);
        for(int i=1; i<=N; ++i)
            parent[i] = i;


        for(auto edge: edges) {
            if(find(edge[0]) == find(edge[1]))
                return edge;
            else
                unionSet(edge[0], edge[1]);
        }
        return edges[edges.size() - 1];
    }
};

int main() {
	
	return 0;
}
