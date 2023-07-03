#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define ll long long

using namespace std;

int data[2][100005];

int main() {
    int t, m;
    cin>>t;
    while(t) {
        t--;
        cin>>m;
        for(int i=1; i<=m; i++) {
            cin>>data[0][i];
        }
        for(int i=1; i<=m; i++) {
            cin>>data[1][i];
        }
        data[0][0]=0, data[1][0]=0, data[0][m+1]=0, data[1][m+1]=0;
        for(int i=m-1; i>0; i--) {
            data[0][i] += data[0][i+1];
        }
        for(int i=2; i<=m; i++)
            data[1][i] += data[1][i-1];
        int ans = 1e9;
        for(int i=1; i<=m; i++) {
            ans = min(ans, max(data[0][i+1], data[1][i-1]));
        }
        cout<<ans<<endl;
    }
	return 0;
}
