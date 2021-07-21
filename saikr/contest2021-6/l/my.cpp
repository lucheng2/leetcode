#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int n;
int dp[1000005];

int main() {
    cin>>n;
    string s;
    cin>>s;
    int cnt = 1;
    dp[0] = 1;
    for(int i=1; i<n; i++) {
        if(s[i] == s[i-1]) {
            cnt++;
        }
        else{
            cnt = 1;
        }
        dp[i] = cnt;
    }
    int sngm=0, zerom=0, onem=0;
    for(int i=n-1; i>=0; ) {
        sngm = max(sngm, dp[i]);
        i -= dp[i];
    }
    vector<int> zeros, ones;
    for(int i=n-1; i>=0; ) {
        if(s[i] == '1'){
            ones.push_back(dp[i]);
        }
        else{
            zeros.push_back(dp[i]);
        }
        i -= dp[i];
    }
    sort(ones.begin(),ones.end(),  greater<int>());
    sort(zeros.begin(), zeros.end(), greater<int>());
	
	return 0;
}
