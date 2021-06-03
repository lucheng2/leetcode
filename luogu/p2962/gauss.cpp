#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<bitset>

using namespace std;

int n, m;
//增广矩阵augmented matrix，数学上记为A
vector<bitset<40>> aug;
bitset<40> state;
int ans = 1e9;

//只是化为下三角矩阵
void gauss() {
    int i, j, k, bl;
    for(k=0; k<n; k++) {
        bl = k;
        for(i=k+1; i<n; i++) {
            if(aug[i][k]) {
                bl = i;
                break;
            }
        }
        if(bl!=k)
            swap(aug[k], aug[bl]);
        for(i=k+1; i<n; i++) {
            if(aug[i][k])
                aug[i] ^= aug[k];
        }
    }
}
void dfs(int idx, int tot) {
    if(tot>ans)
        return;
    if(idx<0) {
        ans = min(ans, tot);
        return;
    }
    if(aug[idx][idx]) {
        state[idx] = aug[idx][n];
        for(int j=n-1; j>idx; j--) {
            state[idx] = state[idx]^(state[j]&aug[idx][j]);
        }
        if(state[idx])
            dfs(idx-1, tot+1);
        else
            dfs(idx-1, tot);
    } else {
        state[idx] = 0;
        dfs(idx-1, tot);
        state[idx] = 1;
        dfs(idx-1, tot+1);
    }
}

int main() {
    cin>>n>>m;
    aug.resize(n);
    int u, v;
    for(int i=0; i<n; i++) {
        aug[i][i] = 1;
        aug[i][n] = 1;
    }
    for(int i=0; i<m; i++) {
        cin>>u>>v;
        u--, v--;
        aug[u][v] = 1;
        aug[v][u] = 1;
    }
    gauss();
    dfs(n-1, 0);
    cout<<ans;
	
	return 0;
}
