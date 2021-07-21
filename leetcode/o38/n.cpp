#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define ll long long 

using namespace std;

class Solution {
public:
    vector<string> ans;
    vector<bool> vis;
    void backtrack(string &s, string &p, int i, int n) {
        if(i==n) {
            ans.push_back(p);
            return;
        }
        for(int j=0; j<n; j++) {
            if(vis[j] || (j>0&&!vis[j-1]&&s[j-1]==s[j]))
                continue;
            p.push_back(s[j]);
            vis[j] = true;
            backtrack(s, p, i+1, n);
            vis[j] = false;
            p.pop_back();
        }
    }
    vector<string> permutation(string s) {
        int n=s.size();
        vis.resize(n);
        sort(s.begin(), s.end());
        string p;
        backtrack(s, p, 0, n);
        return ans;
    }
};
