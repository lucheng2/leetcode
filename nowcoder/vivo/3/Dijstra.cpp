#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<unordered_map>
#include<queue>
#include<climits>

using namespace std;

// 最短路径算法-优先级队列优化
// n: 节点数量，节点编号1--n
// start：起点的编号
// graph：图的邻接表表示（u, v, w）,计算度很方便
vector<int> Dijsktra(int n, int start, unordered_map<int, unordered_map<int, int>> & graph) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> dis(n + 1, INT_MAX);
    vector<bool> visited(n, false);
    dis[start] = 0;
    pq.push({0, start});
    while(!pq.empty()) {
        int u = pq.top().second, d = pq.top().first;
        pq.pop();
        if(visited[u]) {
            continue;
        }
        visited[u] = true;
        for(auto it : graph[u]) {
            int v = it.first, weight = it.second;
            if(dis[v] > dis[u] + weight) {
                dis[v] = dis[u] + weight;
                pq.push({dis[v], v});
            }
        }
    }
    return dis;
}

int main() {
	
	return 0;
}
