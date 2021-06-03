#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define ll long long 
#include<set>

using namespace std;

class Solution {
public:
    int maxSumMinProduct(vector<int>& nums) {
        vector<ll> presum(nums.size(), 0);
        presum[0] = nums[0];
        for(int i=1; i<nums.size(); i++) 
            presum[i] = presum[i-1] + nums[i];
        int logn = 31 - __builtin_clz(nums.size());
        vector<vector<int>> f(nums.size(), vector<int>(logn, 0));
        for(int i=0; i<f.size(); i++) 
            f[i][0] = nums[i];
        for(int j=1; j<=logn; j++) {
            for(int i=0; i+(1<<j)-1<f.size(); i++)
                f[i][j] = min(f[i][j-1], f[i+(1<<(j-1))][j-1]);
        }
        set<int> s;
        ll ans = 0;
        for(int i=0; i<nums.size(); i++) {
            for(int j=nums.size()-1; j>=i; j--) {
                int ln = 31 - __builtin_clz(j-i+1);
                int mi = min(f[i][ln], f[j-(1<<ln)+1][ln]);
                if(!s.count(mi)) {
                    ll tmp = mi*(presum[j]-presum[i]);
                    s.insert(mi);
                    ans = max(ans, tmp);
                }
            }
        }
        return ans;
    }
};
