#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<unordered_map>
#include<climits>
#include<queue>

using namespace std;

int n;
int data[305][305];
unordered_map<int, unordered_map<int, int>> graph;

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
    cin>>n;
    for(int i=1; i<=n; i++) {
        for(int j=1;j<=n; j++)
            scanf("%d", &data[i][j]);
    }
    for(int i=1; i<=n; i++) {
        int w = 0;
        for(int j=1; j<=n; j++) {
            if(data[i][j] == 1) {
                graph[i][j] = w;
                w++;
            }
        }
    }
    vector<int> dis = Dijsktra(n, 1, graph);
    printf("%d\n", dis[n]);
	return 0;
}
