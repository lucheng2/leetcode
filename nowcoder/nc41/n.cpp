#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<unordered_map>

using namespace std;

class Solution {
public:
    int maxLength(vector<int>& arr) {
        unordered_map<int, int> hm;
        int i = 0, j  = 0;
        int ans = 0;
        for( ; j < arr.size(); j++) {
            if(hm.count(arr[j])) {
                i = max(i, hm[arr[j]] + 1);
            }
            hm[arr[j]] = j;
            ans = max(ans, j - i + 1);
        }
        return ans;
    }
};
