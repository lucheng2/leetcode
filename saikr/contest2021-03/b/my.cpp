#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<set>

using namespace std;

int main() {
	
    string s = "ibti lbtlovebte lbtlibtinbtnkbtkebtezbas jebte dosadnbtna ovakbtkebtemibtijaxaszxdbtddbtddbtddbtddbtddbtd";
    set<char> st = {'l', 'i', 'n', 'k', 'e'};
    string ans;
    for(int i=0; i<s.size(); ++i) {
        if(st.find(s[i]) != st.end()) {
            if(s[i+1]=='b' && s[i+2]=='t' && s[i+3]==s[i]) {
                i = i+3;
            }
        }
        ans.push_back(s[i]);
    }
    cout<<ans<<endl;
    
	return 0;
}
