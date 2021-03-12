#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<unordered_map>

using namespace std;

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> hm;
        vector<int> ans;
        for(int i: nums1) {
            hm[i] ++;
        }
        for(int j: nums2) {
            if(hm.count(j) && hm[j]>0) {
                ans.push_back(j);
                hm[j] --;
            }
        }
        return ans;
    }
};

int main() {
	
	return 0;
}
