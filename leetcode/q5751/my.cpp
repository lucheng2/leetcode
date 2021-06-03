#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>

using namespace std;

class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        map<int, int> kv;
        for(int i=0; i<nums2.size(); i++) {
            kv[nums2[i]] = i;
        }
        int ans = 0;
        for(int i=0; i<nums1.size(); i++) {
            auto it = kv.lower_bound(nums1[i]);
            if(it!=kv.end()) {
                ans = max(it->second - i, ans);
            }
        }
        return ans;
    }
};

int main() {
	
	return 0;
}
