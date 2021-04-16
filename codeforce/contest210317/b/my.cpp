#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>
#include<list>

using namespace std;

int t, n, m;

int main() {
    scanf("%d", &t); 
    while(t--) {
        scanf("%d%d", &n, &m);
        map<int, int> cnt;
        while(n--) {
            int x;
            cin>>x;
            cnt[x % m]++;
        }
        int ans = 0;
        for(auto &c: cnt) {
            if(c.first == 0) {
                ans ++;
                continue;
            }
            if(c.first * 2 == m) {
                ans ++;
                continue;
            }
            if(c.first*2 < m ||  cnt.find(m-c.first) == cnt.end()) {
                int x=c.second, y=cnt[m-c.first];
                ans += 1 + max(0, abs(x-y) - 1);
            }
        }
        cout<<ans<<endl;
    }
	return 0;
}
