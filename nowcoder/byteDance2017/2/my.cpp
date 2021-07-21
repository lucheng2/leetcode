#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>
#define ll long long

using namespace std;

int main() {
    map<int, int, greater<int>> mp;
    ll sum = 0;
    int n, i, L, cnt=0;
    cin>>n;
    while(n) {
        n--;
        scanf("%d%d", &i, &L);
        if(i==1) {
            mp[L] ++;
            sum += L;
            cnt++;
        }
        else{
            sum -= L;
            if(mp[L]>1)
                mp[L]--;
            else{
                mp.erase(L);
            }
            cnt--;
        }
        ll mx = mp.begin()->first;
        if(cnt<3 || mx >= sum - mx) {
            printf("No\n");
        }
        else{
            printf("Yes\n");
        }
    }
	return 0;
}
