#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;
int T, maxP, W;
int ap[2005], bp[2005], as[2005], bs[2005];
int mem[2005][2005];

int dfs(int i, int stk) {
    if(i>T)
        return 0;
    if(mem[i][stk]!=-1)
        return mem[i][stk];
    int tmp = -1e9;
    for(int j=0; j<=min(maxP-stk, as[i]); j++) {
        for(int k=0; i+k<=T; k++)
            tmp = max(dfs(i+k+W+1, stk+j)-j*ap[i], tmp);
    }
    for(int j=1; j<=min(stk, bs[i]); j++) {
        for(int k=0; i+k<=T; k++)
            tmp = max(dfs(i+k+W+1, stk-j)+j*bp[i], tmp);
    }
    mem[i][stk] = tmp;
    return tmp;
}


int main() {
    cin>>T>>maxP>>W;
    for(int i=1; i<=T; i++) {
        cin>>ap[i]>>bp[i]>>as[i]>>bs[i];
    }
    memset(mem, -1, sizeof(mem));
    int ans = dfs(1, 0);
    cout<<ans<<endl;
	return 0;
}
