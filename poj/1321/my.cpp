#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<set>

using namespace std;

int n, k;
int data[10][10];
int ans = 0;
int col[10];

void dfs(int l, int step) {
    if(step == k) {
        ans ++;
        return;
    }
    for(int i=l+1; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(data[i][j] && !col[j]){
                col[j] = 1;
                dfs(i, step+1);
                col[j] = 0;
            }
        }
    }
}

int main() {
    while(true) {
        cin>>n>>k;
        if(n==-1)
            break;
        for(int i=0; i<n; i++) {
            char in[10];
            scanf("%s", in);
            for(int j=0; j<n; j++) {
                data[i][j] = in[j]=='#'? 1: 0;
            }
        }
        memset(col, 0, sizeof(col));
        ans = 0;
        dfs(-1, 0);
        cout<<ans<<endl;
    }
	
	return 0;
}
