#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define ll long long 

using namespace std;

class Solution {
public:
    vector<vector<int>> mt;
    int mx = 1e9;
    vector<int> mn;
    int n, m, t;
    int ans = 1e9;
    void dfs(int i, int sum) {
        if(i == n) {
            ans = min(ans, abs(t - sum));
            if(sum > t)
                mx = min(mx, sum);
            return;
        }
        mn[i] = max(mn[i], sum);
        if(sum >= mx)
            return;
        for(int j=m-1; j>=0; j--) {
            dfs(i+1, sum + mt[i][j]);
        }
    }

    int minimizeTheDifference(vector<vector<int>>& mat, int target) {
        mt = mat;
        t = target;
        n = mat.size();
        m = mat[0].size();
        mn.resize(n, 0);
        for(int i=0; i<n; i++)
            sort(mat[i].begin(), mat[i].end());
        dfs(0, 0);
        return ans;
    }
};
