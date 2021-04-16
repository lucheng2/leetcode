#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int t;
int n, k1, k2;
int w, b;

int main() {
    cin>>t;
    while(t--) {
        cin>>n>>k1>>k2;
        cin>>w>>b;
        if(k1>k2) {
            swap(k1, k2);
        }
        int w_num = k1 + (k2-k1) / 2;
        k1 = n - k1;
        k2 = n - k2;
        int b_num = k2 + (k1 - k2) /2;
        if(w_num>=w && b_num>=b)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
	return 0;
}
