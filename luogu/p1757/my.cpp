#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<unordered_map>
#define ll long long

using namespace std;

int m, n;
unordered_map<int, vector<pair<int, int>>> hm;
int a, b, c;
int dp[1005];

int main() {
    cin>>m>>n;
    for(int i=0; i<n; i++) {
        cin>>a>>b>>c;
        hm[c].push_back(make_pair(a, b));
    }
    for(auto it=hm.begin(); it!=hm.end(); it++) {
        for(int v=m; v>=0; v--) {
            for(auto item: it->second) {
                if(v-item.first>=0)
                    dp[v] = max(dp[v], dp[v-item.first] + item.second);
            }
        }
    }
    cout<<dp[m]<<endl;
	return 0;
}
