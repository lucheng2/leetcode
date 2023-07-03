#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

class Solution {
public:
    int kmp(string S, string T) {
        string s = S + "#" + T;
        int n = s.size();
        vector<int> pi(n, 0);
        for(int i=1; i<n; i++) {
            int j = pi[i-1];
            while(j > 0 && s[i] != s[j])
                j = pi[j-1];
            if(s[i] == s[j])
                j++;
            pi[i] = j;
        }
        int cnt = 0;
        int SLen = S.size();
        for(int i=SLen; i<n; i++) {
            if(pi[i] == SLen)
                cnt++;
        }
        return cnt;
    }
};
