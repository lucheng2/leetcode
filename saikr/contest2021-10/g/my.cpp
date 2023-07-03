#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<unordered_map>
#include<cmath>
#include<numeric>
#define ll long long

using namespace std;

unordered_map<ll, ll> cal;
ll const mod = 1e9+7;

ll pw(ll n, ll m) {
    ll ans = 1;
    while(m) {
        ans *= n;
        m -- ;
    }
    return ans;
}

ll pow_tem(ll n) {
    if(cal.find(n) != cal.end())
        return cal[n];
    ll res;
    if(n<=9)
        res = pw(10, n);
    else {
        if(n % 2 == 0)
            res = (ll)pw(pow_tem(n / 2), 2) % mod;
        else
            res = 10 * (ll) pw(pow_tem((n-1)/2), 2) % mod;
    }
    cal[n] = res;
    return res;
}

int main() {
    int a[10];
    int cnt = 0;
    int only;
    for(int i=0; i<9; i++) {
        cin>>a[i];
        if(a[i]) {
            cnt++;
            only = i+1;
        }
    }
    ll s = 0;
    if(cnt ==1)
        s = only;
    else {
        for(int i=0; i<9; i++) {
            s = (s + (i+1)*a[i]) % mod;
        }
    }
    ll c = 0;
    ll sum = accumulate(a, a+9, 0);
    for(int i=0; i<sum; i++)
        c = (c+pow_tem(i)) % mod;
    ll r = (s*c) % mod;
    cout<<r;
	
	return 0;
}
