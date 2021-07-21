#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<unordered_map>
#define ll long long

using namespace std;

int jeCheng(int n) {
    int ans = 1;
    for(int i=1; i<=n ;i++)
        ans *= i;
    return ans;
}

int main() {
    string s;
    cin>>s;
    unordered_map<char, int> hm;
    for(int i=0; i<s.length(); i++) 
        hm[s[i]] ++;
    int ans = jeCheng(s.size());
    for(auto it: hm) {
        ans /= jeCheng(it.second);
    }
    cout<<ans<<endl;
	return 0;
}
