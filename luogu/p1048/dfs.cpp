#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int T, M;
int cost[105], weight[105];
int ans = 0;

void dfs(int pos, int volume, int total) {
    if(pos>=M) {
        ans = max(ans, total);
        return;
    }
    if(volume>=cost[pos]) {
        dfs(pos+1, volume, total);
        dfs(pos+1, volume-cost[pos], total+weight[pos]);
    }
    else{
        dfs(pos+1, volume, total);
    }
}

int main() {
    cin>>T>>M;
    for(int i=0; i<M; i++) {
        cin>>cost[i]>>weight[i];
    }
    dfs(0, T, 0);
    cout<<ans<<endl;
	return 0;
}
