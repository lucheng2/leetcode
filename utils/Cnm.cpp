#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>

#define ll long long

using namespace std;

ll Cnm(int n, int m) {
    if(n - m < m)
        m = n - m;
    ll ans = 1;
    for(int i=1; i<=m; i++) {
        ans = ans*(n-i+1)/i;
    }
    return ans;
}

int main() {
	
	return 0;
}
