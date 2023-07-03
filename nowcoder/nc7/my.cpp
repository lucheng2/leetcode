#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n <= 0)
            return 0;
        vector<int> mn(n);
        int m = prices[0];
        mn[0] = m;
        for(int i=1; i<n; i++) {
            m = min(m, prices[i]);
            mn[i] = m;
        }
        int ans = 0;
        for(int i=1; i<n; i++) {
            ans = max(ans, prices[i] - mn[i]);
        }
        return ans;
    }
};
