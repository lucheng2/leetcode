#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<set>
#define ll long long

using namespace std;

set<string> st;
string s;
int mxl = 0;
int dp[200005];

int main() {
    string tmp;
    while(true) {
        cin>>tmp;
        if(tmp == ".")
            break;
        st.insert(tmp);
        int n = tmp.size();
        mxl = max(mxl, n);
    }
    cin>>s;
    dp[0] = 1;
    for(int i=1; i<=s.size(); i++) {
        for(int j=1; j<=mxl && i-j>=0; j++) {
            if(st.find(s.substr(i-j, j)) != st.end() && dp[i-j]) {
                dp[i] = 1;
                break;
            }
        }
    }
    int n = s.size();
    while(n) {
        if(dp[n]) {
            cout<<n<<endl;
            return 0;
        }
        n--;
    }
	return 0;
}
