#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define ll long long 

using namespace std;

class Solution {
public:
    void solve(vector<ll> & cur) {
        int n = cur.size();
        for(int i=1; i<n; i++) {
            cur[i] = max(cur[i], cur[i-1] - 1);
        }
        for(int i=n-2; i>=0; i--) {
            cur[i] = max(cur[i], cur[i+1] - 1);
        }
    }

    long long maxPoints(vector<vector<int>>& points) {
        int n = points.size(), m = points[0].size();
        vector<ll> cur(m);
        for(int i=0; i<n; i++) {
            solve(cur);
            for(int j=0; j<m; j++) {
                cur[j] += points[i][j];
            }
        }
        return * max_element(cur.begin(), cur.end());
    }
};
