#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<set>

using namespace std;
class Solution {
public:
    string longestNiceSubstring(string s) {
        int maxLen = 0, index = 0;
        for(int i=0; i<s.length()-1; ++i)
            for(int j=i+1; j<s.length(); ++j) {
                if(check(s, i, j)) {
                    if(j-i>maxLen) {
                        maxLen = j - i;
                        index = i;
                    }
                }
            }
        if(maxLen == 0)
            return "";
        else
            return s.substr(index, maxLen);

    }

    bool check(string &s, int i, int j) {
        set<char> ss;
        for(int k=i; k<j; ++k)
            ss.insert(s[k]);
        for(auto c: ss) {
            if(c<='Z') {
                if(ss.find(c-'A' + 'a') == ss.end())
                    return false;
            } else {
                if(ss.find(c-'a'+'A') == ss.end())
                    return false;
            }
        }
        return true;
    }
};

int main() {
	
	return 0;
}
