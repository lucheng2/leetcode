#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int T, M;
int cost[105], weight[105];

int dfs(int pos, int volume) {
    if(pos>=M) {
        return 0;
    }
    if(volume>=cost[pos]) {
        int res1 = dfs(pos+1, volume);
        int res2 = dfs(pos+1, volume-cost[pos]) + weight[pos];
        return max(res1, res2);
    }
    else{
        return dfs(pos+1, volume);
    }
}

int main() {
    cin>>T>>M;
    for(int i=0; i<M; i++) {
        cin>>cost[i]>>weight[i];
    }
    cout<<dfs(0, T)<<endl;
	return 0;
}
