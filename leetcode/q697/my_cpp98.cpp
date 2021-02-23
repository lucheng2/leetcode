#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<unordered_map>

using namespace std;

class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int, vector<int>> hm;
        int n = nums.size();
        for(int i=0; i<n; ++i) {
            if(hm.count(nums[i])) {
                hm[nums[i]][0]++;
                hm[nums[i]][2] = i;
            } 
            else
                hm[nums[i]] = {1, i, i};
        }
        int maxCount=0, minLen;
        for(auto it = hm.begin(); it!=hm.end(); ++it) {
            if(maxCount<it->second[0]) {
                maxCount = it->second[0];
                minLen = it->second[2] - it->second[1] + 1;
            }
            else if(maxCount == it->second[0])
                minLen = min(minLen, it->second[2] - it->second[1] + 1);
        }
        return minLen;
    }
};

int main() {
	
	return 0;
}
