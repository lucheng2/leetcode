#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<unordered_map>
#include<climits>

using namespace std;

unordered_map<int, vector<int>> tree;
unordered_map<int, int> weights;
int n, m;
int u, v;
int maxNum=0, minNum=INT_MAX;
int maxNumCD, minNumCD;
vector<bool> visited;

bool allVisited() {
    for(int i=1; i<visited.size(); ++i) {
        if(visited[i]==false)
            return false;
    }
    return true;
}

void dfs(int node) {
    if(visited[node]) {
        return;
    }
    visited[node] = true;
    maxNumCD += weights[node];
    minNumCD = min(minNumCD, weights[node]);
    if(allVisited()) {
        if(maxNum<maxNumCD) {
            maxNum = maxNumCD;
        } else if(maxNum == maxNumCD) {
            minNum = max(minNum, minNumCD);
        }
    } 
    if(tree.count(node)) {
    }



}


int main() {
    scanf("%d%d", &n, &m);
    for(int i=1; i<=n; ++i) {
        scanf("%d", &u);
        weights[i] = u;
    }
    for(int i=0; i<m; ++i) {
        scanf("%d%d", &u, &v);
        if(u>v) {
            swap(u, v);
        }
        if(tree.count(u)) {
            tree[u].push_back(v);
        } else {
            tree[u] = {v};
        }
    }
	
	return 0;
}
