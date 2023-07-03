#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

class Solution {
public:
    int kmp(string S, string T) {
        int n = S.size();
        vector<int> pi(n, 0);
        for(int i=1; i<n; i++) {
            int j=pi[i-1];
            while(j>0 && S[i]!=S[j])
                j = pi[j-1];
            if(S[i] == S[j])
                j++;
            pi[i] = j;
        }
        int j = 0;
        int cnt = 0;
        for(int i=0; i<T.size(); i++) {
            while(j>0 && S[j]!=T[i])
                j = pi[j-1];
            if(S[j] == T[i])
                j++;
            if(j == n) {
                cnt++;
                j = pi[j-1];
            }
        }
        return cnt;
    }
};
