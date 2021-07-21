#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<unordered_map>
#define ll long long 

using namespace std;

class Solution {
public:
    int n, k;
    int ans = 0;
    unordered_map<int, vector<int>> hm;

    void bfs(int num, int idx) {
        if(idx == k) {
            if(num == n-1)
                ans ++;
            return;
        }
        for(auto next: hm[num]) {
            bfs(next, idx + 1);
        }
    }

    int numWays(int n, vector<vector<int>>& relation, int k) {
        this->n = n;
        this->k = k;
        for(int i=0; i<relation.size(); i++) {
            hm[relation[i][0]].push_back(relation[i][1]);
        }
        bfs(0, 0);
        return ans;
    }
};
