#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<unordered_map>
#include<bitset>

using namespace std;

int n, m;
vector<bitset<35>> graph(35);
unordered_map<bitset<35>, int> state;
int ans = 1e9;

int main() {
    cin>>n>>m;
    int a, b;
    for(int i=0; i<n; i++) {
        graph[i].reset();
        graph[i].set(i);
    }
    // 读入图，用邻接矩阵表示
    for(int i=0; i<m; i++) {
        cin>>a>>b;
        a--; b--;
        graph[a].set(b);
        graph[b].set(a);
    }
    for(int i=0; i<(1<<(n/2)); i++) {
        bitset<35> tmp(0);
        int cnt = 0;
        for (int j=0; j<n/2; j++) {
            if((i>>j) & 1) {
                tmp ^= graph[j];
                cnt++;
            }
        }
        if(!state.count(tmp)) {
            state[tmp] = cnt;
        }
        else{
            state[tmp] = min(state[tmp], cnt);
        }
    }
    bitset<35> mask((1LL<<n)-1);
    for (int i=0; i<(1<<(n - n/2)); i++) {
        bitset<35> tmp(0);
        int cnt = 0;
        for(int j=0; j<(n-n/2); j++) {
            if((i>>j)&1) {
                tmp ^= graph[n/2+j];
                cnt++;
            }
        }
        if(state.count(mask ^ tmp)) {
            ans = min(ans, cnt + state[mask ^ tmp]);
        }
    }
    cout<<ans;
	return 0;
}
