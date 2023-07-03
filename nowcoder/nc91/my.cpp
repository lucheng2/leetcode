#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

class Solution {
public:
    vector<int> LIS(vector<int>& arr) {
        vector<int> res, maxLen;
        int n = arr.size();
        if(n<1)
            return res;
        res.emplace_back(arr[0]);
        maxLen.emplace_back(1);
        for(int i=1; i<n; i++) {
            if(res.back() < arr[i]) {
                res.emplace_back(arr[i]);
                maxLen.emplace_back(res.size());
            }
            else {
                int pos = lower_bound(res.begin(), res.end(), arr[i]) - res.begin();
                res[pos] = arr[i];
                maxLen.emplace_back(pos + 1);
            }
        }
        for(int i=n-1, j=res.size(); j>0; --i) {
            if(maxLen[i] == j)
                res[--j] = arr[i];
        }
        return res;
    }
};
