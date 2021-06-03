#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int T, M;
int cost[105], weight[105];
int mem[105][1005];

int dfs(int pos, int volume) {
    if(pos>=M) {
        return 0;
    }
    if(mem[pos][volume]!=-1)
        return mem[pos][volume];
    int res1, res2=-1;
    res1 = dfs(pos+1, volume);
    if(volume>=cost[pos])
        res2 = dfs(pos+1, volume-cost[pos]) + weight[pos];
    mem[pos][volume] = max(res1, res2);
    return mem[pos][volume];
}

int main() {
    cin>>T>>M;
    for(int i=0; i<M; i++) {
        cin>>cost[i]>>weight[i];
    }
    memset(mem, -1, sizeof(mem));
    cout<<dfs(0, T)<<endl;
	return 0;
}
