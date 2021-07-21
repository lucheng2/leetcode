#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define ll long long

using namespace std;

int main() {
    string s;
    cin>>s;
    int n = s.length();
    string str;
    str.resize(n*2+1);
    int j=0;
    for(int i=0; i<n; i++) {
        str[j++] = '#';
        str[j++] = s[i];
    }
    str[j] = '#';
    n = 2*n + 1;
    vector<int> d1(n);
    for(int i=0, l=0, r=-1; i<n; i++) {
        int k = i > r ? 1 : min(d1[l + r - i], r - i);
        while(i-k>=0 && i+k<n && str[i-k]== str[i+k])
            k++;
        d1[i] = --k;
        if(i+k > r) {
            r = i+k;
            l = i-k;
        }
    }
    int ans = *max_element(d1.begin(), d1.end());
    cout<<ans<<endl;
	return 0;
}
