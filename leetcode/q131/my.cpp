#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

class Solution {
public:
    int n;
    vector<vector<bool>> mem;
    vector<vector<string>> ret;
    vector<string> ans;

    void dfs(string &s, int i) {
        if(i>=n) {
            ret.push_back(ans);
            return;
        }
        for(int j=i; j<n; ++j) {
            if(mem[i][j]) {
                ans.push_back(s.substr(i, j - i + 1));
                dfs(s, j+1);
                ans.pop_back();
            }
        }
    }


    vector<vector<string>> partition(string s) {
        n = s.size();
        mem.resize(n, vector<bool> (n, true));
        for(int i=n-1; i>=0; --i) {
            for(int j=i+1; j<n; ++j) {
                mem[i][j] = (s[i] == s[j]) && mem[i+1][j-1];
            }
        }
        dfs(s, 0);
        return ret;
    }
};

int main() {
	
	return 0;
}
