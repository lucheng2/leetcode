#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int t;
int n;
int a[100010];

int main() {
    cin>>t;
    while(t--) {
        cin>>n;
        for(int i=1; i<=n; ++i) {
            cin>>a[i];
        }
        bool all=true;
        for(int i=2; i<=n; i++) {
            if(a[i] != a[i-1]) {
                all = false;
                break;
            }
        }
        if(n<=2 || all) {
            cout<<0<<endl;
            continue;
        }
        bool has_same = false;
        for(int i=2; i<=n; i++) {
            if(a[i]==a[i-1]) {
                has_same = true;
                break;
            }
        }
        if(has_same) {
            cout<<-1<<endl;
            continue;
        }
        int c;
        if(a[1] < a[2]) {
            c = a[2] - a[1];
        } else {
            c = a[3] - a[2];
        }
        if(c<0) {
            cout<<-1<<endl;
            continue;
        }
        int m;
        for(int i=2; i<=n; i++) {
            if(a[i] - a[i-1]<0) {
                m = a[i-1] - a[i] + c;
            }
        }
        bool flag = true;
        if(a[1] >= m) 
            flag = false;
        for(int i=2; i<=n; i++) {
            if(a[i] != (a[i-1] + c) % m) {
                flag = false;
                break;
            }
        }
        if(flag)
            cout<<m<<" "<<c<<endl;
        else 
            cout<<-1<<endl;
    }
	
	return 0;
}
