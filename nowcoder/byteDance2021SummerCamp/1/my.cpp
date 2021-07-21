#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define ll long long 

using namespace std;

int n;
ll a[100005], mem[100005], mem2[100005];
ll dp2(int k);

ll dp(int k) {
    if(k>n) {
        return 0;
    }
    if(mem[k] > 0) {
        return mem[k];
    }
    ll res = a[k] + dp2(k<<1) + dp2((k<<1)+1);
    mem[k] = res;
    return res;
}
ll dp2(int k) {
    if(k>n)
        return 0;
    if(mem2[k] > 0)
        return mem2[k];
    ll res = max(dp(k<<1), dp2(k<<1)) + max(dp((k<<1)+1), dp2((k<<1)+1));
    mem2[k] = res;
    return res;
}

int main() {
    cin>>n;
    for(int i=1; i<=n; i++) {
        scanf("%lld", &a[i]);
    }
    ll ans = dp(1);
    ans = max(ans, dp2(1));
    cout<<ans<<endl;
	
	return 0;
}
