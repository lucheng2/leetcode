#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define ll long long

using namespace std;

string ts, te;
int n, V;
int data[10005][3];
int dp[10005];

void zeroOnePack(int c, int w) {
    for(int i=V; i>=c; i--) 
        dp[i] = max(dp[i], dp[i-c] + w);
}
void completePack(int c, int w) {
    for(int i=c; i<=V; i++)
        dp[i] =  max(dp[i], dp[i-c]+w);
}
void multipack(int c, int w, int m) {
    if(c*m>=V){
        completePack(c, w);
        return;
    }
    int k = 1;
    while(k<m) {
        zeroOnePack(k*c, k*w);
        m = m - k;
        k = k<<1;
    }
    zeroOnePack(m*c, m*w);
}

int main() {
    cin>>ts>>te>>n;
    int tsh=stoi(ts.substr(0, ts.find(":")));
    int tsm=stoi(ts.substr(ts.find(":")+1));
    int teh=stoi(te.substr(0, te.find(":")));
    int tem=stoi(te.substr(te.find(":")+1));
    V = 60*(teh-tsh) + (tem-tsm);
    for(int i=0; i<n; i++) {
        cin>>data[i][0]>>data[i][1]>>data[i][2];
    }
    for(int i=0; i<n; i++) {
        if(data[i][2] == 0) {
            completePack(data[i][0], data[i][1]);
        }
        else if(data[i][2] == 1) {
            zeroOnePack(data[i][0], data[i][1]);
        }
        else{
            multipack(data[i][0], data[i][1], data[i][2]);
        }
    }
    cout<<dp[V]<<endl;
	return 0;
}
