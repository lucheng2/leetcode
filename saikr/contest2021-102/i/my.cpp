#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<unordered_map>

using namespace std;

int mycmp(vector<int> a, vector<int> b) {
    return a[1] > b[1];
}

int main() {
    int n, a, q, p, d;
    cin>>n;
    unordered_map<int, vector<vector<int>>> hm;
    for(int i=0; i<n; i++) {
        cin>>a>>p>>q;
        d = p - q;
        hm[a].push_back({p, d});
    }
    for(auto iter=hm.begin(); iter!=hm.end(); iter++) {
        sort(iter->second.begin(), iter->second.end(), mycmp);
    }
    long long ans=0;
    for(auto iter=hm.begin(); iter!=hm.end(); iter++) {
        int s = iter->second.size();
        int i=0;
        for(; i<s-1; i++) {
            if(iter->second[i][1] > 0) 
                ans += iter->second[i][0];
            else {
                break;
            }
        }
        while(i<s) {
            ans += iter->second[i][0] - iter->second[i][1];
            i++;
        }
    }
    cout<<ans<<endl;
	return 0;
}
