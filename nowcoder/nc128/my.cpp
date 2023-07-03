#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

class Solution {
public:
    long long maxWater(vector<int>& arr) {
        int n = arr.size();
        vector<int> lmax(n+2), rmax(n+2);
        lmax[0] = arr[0];
        rmax[n+1] = arr[n-1];
        for(int i=1; i<=n; i++) {
            lmax[i] = max(lmax[i-1], arr[i-1]);
        }
        for(int i=n; i>0; i--) {
            rmax[i] = max(rmax[i+1], arr[i-1]);
        }
        long long ans = 0;
        for(int i=1; i<=n; i++) {
            ans += max(0, min(lmax[i], rmax[i]) - arr[i-1]);
        }
        return ans;
    }
};
