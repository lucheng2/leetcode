#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define ll long long

using namespace std;

int main() {
    int t;
    ll n;
    cin>>t;
    while(t) {
        t--;
        cin>>n;
        if(n<=6) {
            cout<<15<<endl;
            continue;
        }
        else {
            cout<<20 + (n-6-1) / 2 * 5 <<endl;
        }
            
    }
	return 0;
}
