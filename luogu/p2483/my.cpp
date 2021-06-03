#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#define ll long long

using namespace std;

struct node {
    int nxt;
    double weight;
    node(){};
    node(int n, double w): nxt(n), weight(w){};
};

// g(x) 的节点
struct g {
    int u;
    double gx;
    g(int u, double gx): u(u), gx(gx) {};
    bool operator < (g a) const {
        return gx > a.gx;
    }
};

// g(x) + h(x) 的节点
vector<double> f;

struct gh{
    int u;
    double ghx;
    gh(int u, double ghx): u(u), ghx(ghx) {};
    bool operator < (gh a) const {
        return ghx + f[u] > a.ghx + f[a.u];
    }
};

// 正向图
vector<vector<node>> graph;
// 反向图，用于计算h(x)
vector<vector<node>> back_graph;
int N, M, E;

priority_queue<g> pg_g;
priority_queue<gh> pg_gh;

// 计算从n到所有节点的最短路
void dijkstra() {

}

int main() {
    cin>>N>>M>>E;
    graph.resize(N);
    int s, t;
    double e;
    for(int i=0; i<M; i++) {
        cin>>s>>t>>e;
        s--, t--;
        graph[s].push_back(node(t, e));
        back_graph[t].push_back(node(s, e));
    }
	return 0;
}
