#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<unordered_map>

using namespace std;

class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int res = 0, len = nums.size();
        int left=0, right=0;
        unordered_map<int, int> hm;
        int tmp = 0;
        for(; left<len; left++) {
            for(; right<len; right++) {
                if(hm.find(nums[right])==hm.end()) {
                    hm[nums[right]] = 1;
                    tmp += nums[right];
                } else {
                    break;
                }
            }
            if(res<tmp)
                res = tmp;
            hm.erase(nums[left]);
            tmp -= nums[left];
        }
        return res;
    }
};

int main() {
	
	return 0;
}
