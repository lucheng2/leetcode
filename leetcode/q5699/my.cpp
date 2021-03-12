#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<unordered_map>
#include<set>
#include<queue>
#define MaxDis 1000000007

using namespace std;

class Solution {
public:
    unordered_map<int, unordered_map<int, int>> graph;
    vector<int> dis;
    vector<int> mem;

    int countRestrictedPaths(int n, vector<vector<int>>& edges) {
        for(auto e: edges) {
            graph[e[0]][e[1]] = e[2];
            graph[e[1]][e[0]] = e[2];
        }
        dis = Dijsktra(n, n, graph);
        mem.resize(n + 1, -1);
        mem[n] = 1;
        return dfs(1);
    }

    int dfs(int u) {
        mem[u] = 0;
        for(auto it: graph[u]) {
            if(dis[it.first] < dis[u]) {
                if(mem[it.first] == -1)
                    dfs(it.first);
                mem[u] += mem[it.first];
                mem[u] %= MaxDis;
            }
        }
        return mem[u];
    }
    
    // 最短路径算法-优先级队列优化
    vector<int> Dijsktra(int n, int start, unordered_map<int, unordered_map<int, int>> & graph) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> dis(n + 1, MaxDis);
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


};

int main() {
	
    vector<vector<int>> edges = {{1,2,3}, {1,3,3}, {2,3,1}, {1,4,2}, {5,2,2}, {3,5,1}, {5,4,10}};
    Solution s;
    s.countRestrictedPaths(5, edges);
	return 0;
}
