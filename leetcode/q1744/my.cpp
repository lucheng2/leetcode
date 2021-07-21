#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define ll long long 

using namespace std;

class Solution {
public:
    vector<bool> canEat(vector<int>& candiesCount, vector<vector<int>>& queries) {
        int n = candiesCount.size();
        vector<ll> sum(n);
        sum[0] = candiesCount[0];
        for(int i=1; i<n; i++)
            sum[i] = sum[i-1] + candiesCount[i];
        
        vector<bool> ans;
        for(auto q: queries) {
            int ftype = q[0], fday = q[1], dailyCap = q[2];
            ll x1 = fday + 1;
            ll y1 = (ll)(fday+1) * dailyCap;
            ll x2 = ftype==0? 1: sum[ftype-1]+1;
            ll y2 = sum[ftype];
            ans.push_back(!(x1>y2 || x2>y1));
        }
        return ans;
    }
};
