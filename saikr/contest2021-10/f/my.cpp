#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int main() {
    int t;
    cin>>t;
    int i=1, ans=0, cnt=0;
    while(t>0) {
        i = i<<1;
        cnt++;
        if(t>i) {
            ans += i*cnt;
            t -= i;
        } else {
            ans += t*cnt;
            t=0;
        }
    }
    cout<<ans;
	return 0;
}
