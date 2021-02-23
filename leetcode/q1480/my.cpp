#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;
class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        int presum = 0;
        vector<int> dsum(nums.size());
        for (int i=0; i<nums.size(); i++) {
            presum += nums[i];
            dsum[i] = presum;
        }
        return dsum;
    }
};

int main() {
	
	return 0;
}
