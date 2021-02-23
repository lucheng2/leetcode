#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<unordered_map>

using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.length()!=t.length())
            return false;
        unordered_map<char, char> hs, hb;
        for(int i=0; i<s.length(); ++i) {
            if(hs.find(s[i]) ==hs.end() && hb.find(t[i]) == hb.end()) {
                hs[s[i]] = t[i];
                hb[t[i]] = s[i];
            }
            else if(hs.find(s[i]) ==hs.end() || hb.find(t[i])==hb.end() ) {
                return false;
            } else if(hs[s[i]] != t[i] || hb[t[i]] != s[i]) {
                return false;
            }
        }
        return true;
        
    }
};

int main() {
	
	return 0;
}
