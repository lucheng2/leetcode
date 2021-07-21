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
        while(j<arr.size()) {
            if(hm.count(arr[j])) {
                while(arr[i] != arr[j]) {
                    hm.erase(arr[i]);
                    i++;
                }
                i++, j++;
            }
            else {
                hm[arr[j++]] = 1;
                ans = max(ans, (int)hm.size());
            }
        }
        return ans;
    }
};
