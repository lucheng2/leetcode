#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<climits>
#include<algorithm>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low=0, high=nums.size()-1;
        int ans = INT_MAX;
        while(low <= high) {
            int mid = low + (high - low) / 2;
            if(nums[mid] > target) {
                high = mid - 1;
            }
            else if(nums[mid] < target) {
                low = mid + 1;
            }
            else {
                ans = min(ans, mid);
                high = mid - 1;
            }
        }
        return ans == INT_MAX? -1: ans;
    }
};
