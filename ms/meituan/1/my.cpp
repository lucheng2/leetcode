#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define ll long long

using namespace std;

int t, n, k;
int data[100005];

bool check(int mid) {
    int l = 0, r= n - 1;
    // ans 指向第一个>=mid的数的下标
    int ans = n;
    while(l<=r) {
        int m = (l+r) / 2;
        if(data[m] >= mid) {
            r = mid - 1;
            ans = min(ans, m);
        }
        else
            l = mid + 1;
    }
    if(ans == k-1)
        return true;
    else
        return false;
}

int main() {
    cin>>t;
    while(t>0) {
        t--;
        cin>>n>>k;
        for(int i=0; i<n; i++)
            cin>>data[i];
        sort(data, data+n);
        int l=1, r=n;
        int ans = n + 1;
        while(l<=r) {
            int mid = (l+r) / 2;
            if(check(mid)) {
                ans = min(ans, mid);
                r = mid - 1;
            }
            else {
                l = mid + 1;
            }
        }
        if(ans == n+1)
            cout<<"NO"<<endl;
        else
            cout<<"YES"<<""<<endl<<ans<<endl;
    }
	
	return 0;
}
