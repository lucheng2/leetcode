#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

class Solution {
public:
    int maxsumofSubarray(vector<int>& arr) {
        int sum = 0;
        int mx = 0, mn = 0;
        for(int i=0; i<arr.size(); i++) {
            sum += arr[i];
            sum = max(sum, 0);
            mx = max(mx, sum);
            mn = min(mn, sum);
        }
        return mx - mn;
    }
};
