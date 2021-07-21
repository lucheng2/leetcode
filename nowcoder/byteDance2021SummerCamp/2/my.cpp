#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<unordered_map>
#include<map>
#include<queue>

using namespace std;

int N, M, in;
unordered_map<int, unordered_map<int, int>> graph;
map<int, int, greater<int>> cand;
priority_queue<pair<int, int>> pq;
int infec[105];

int f[105];

void init() {
    for(int i=0; i<N; i++)
        f[i] = i;
}

int find(int k) {
    if(f[k] == k) 
        return k;
    f[k] = find(f[k]);
    return f[k];
}
void unn(int i, int j) {
    if(find(i) == find(j))
        return;
    f[i] = find(j);
}
bool check() {
    int p = find(infec[0]);
    for(int i=1; i<M; i++) {
        if(p!=find(infec[i]))
            return false;
    }
    return true;
}

int main() {
    cin>>N>>M;
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            scanf("%d", &in);
            if(in==1) {
                graph[i][j] = 1;
                graph[j][i] = 1;
            }
        }
    }
    for(int i=0; i<M; i++)
        cin>>infec[i];
    for(int i=0; i<M; i++) {
        int u = infec[i];
        for(auto it=graph[u].begin(); it!=graph[u].end(); it++) {
            cand[it->first] ++;
        }
    }
    for(auto it: cand) {
        pq.push(make_pair(it.second, it.first));
    }
    int cnt=0;
    init();
    while(!check()) {
        cnt++;
        int u = pq.top().second;
        pq.pop();
        for(auto it: graph[u]) {
            unn(it.first, u);
        }
    }
    cout<<M+cnt<<endl;
	
	return 0;
}
