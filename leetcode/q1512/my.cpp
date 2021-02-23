#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<unordered_map>
#define ll long long

using namespace std;

ll Cnm(int n, int m) {
    if(n - m < m)
        m = n - m;
    ll ans = 1;
    for(int i=1; i<=m; i++) {
        ans = ans*(n-i+1)/i;
    }
    return ans;
}

class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        unordered_map<int, int> hm;
        for(int i=0; i<nums.size(); i++) {
            hm[nums[i]] ++;
        }
        int ans = 0;
        for (const auto &[k,v] : hm) {
            ans += v * (v-1) / 2;
        }
        return ans;
    }
};

int main() {
	
	return 0;
}
