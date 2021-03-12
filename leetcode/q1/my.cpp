#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int ,int> hm;
        vector<int> ans(2);
        for(int i=0; i<nums.size(); ++i) {
            if(hm.count(target - nums[i])) {
                ans[0] = hm[target - nums[i]];
                ans[1] = i;
                break;
            }
            hm[nums[i]] = i;
        }
        return ans;
    }
};

int main() {
	
	return 0;
}
