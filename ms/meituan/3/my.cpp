#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>
#define ll long long

using namespace std;

long long data[100005], pre[100005];

int find(map<long long, int>::iterator first, map<long long, int>::iterator last, const long long val) {
    map<long long, int>::iterator it, ans=first;
    iterator_traits<map<long long, int>::iterator>::difference_type cnt, step;
    cnt = distance(first, last);
    while(cnt>0) {
        it = first; step=cnt/2; advance(it, step);
        if(it->first < val) {
            ans = it;
            first = ++it;
            cnt -= step + 1;
        }
        else
            cnt=step;
    }
    return ans->first;
}

int main() {
    int n;
    map<long long, int> mp;
    cin>>n;
    for(int i=1; i<=n; i++)
        cin>>data[i];
    mp[0] = 1;
    for(int i=1; i<=n; i++) {
        pre[i] = find(mp.begin(), mp.end(), data[i]);
        mp[data[i]] ++;
        cout<<pre[i]<<" ";
    }
    ll ans = 0;
    for(int i=1; i<=n; i++)
        ans += i*pre[i];
	
    cout<<ans<<endl;
	return 0;
}
