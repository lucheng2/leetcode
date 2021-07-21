#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<unordered_map>
#include<set>
#define ll long long

using namespace std;
int n, m, cnt=0;
int v, p, q;
int dp[320005];
unordered_map<int, vector<vector<int>>> hm;
unordered_map<int, set<pair<int, int>>> groupData;
int data[70][2];

void zeroOnePack(int c, int w, int V) {
    for(int i=V; i>=c; i--) {
        dp[i] = max(dp[i], dp[i-c] + w);
    }
}

int main() {
    cin>>n>>m;
    for(int i=1; i<=m; i++) {
        cin>>v>>p>>q;
        if(q==0) {
            cnt++;
            data[cnt][0] = v;
            data[cnt][1] = p;
        } else{
            hm[q].push_back({v, p});
        }
    }
    // 对每一个主件做01背包
    for(int i=1; i<=cnt; i++) {
        int Ck = data[i][0], Wk=data[i][0]*data[i][1];
        if(hm.find(i) != hm.end()) {
            memset(dp, 0, sizeof(dp));
            int V=n-Ck;
            for(auto it=hm[i].begin(); it!=hm[i].end(); it++) {
                zeroOnePack((*it)[0], (*it)[0] * (*it)[1], n);
            }
            for(int v=Ck; v<=n; v++) {
                groupData[i].insert(make_pair(v, dp[v-Ck]+Wk));
            }
        }
        else{
            groupData[i].insert(make_pair(Ck,Wk));
        }
    }
    memset(dp, 0, sizeof(dp));
    for(auto it=groupData.begin(); it!=groupData.end(); it++) {
        for(int v=n; v>=0; v--) {
            for(auto i: it->second) {
                if( v - i.first >= 0) {
                    dp[v] = max(dp[v], dp[v-i.first] + i.second);
                }
            }
        }
    }
    cout<<dp[n]<<endl;
	return 0;
}
