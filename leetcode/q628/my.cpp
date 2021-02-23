#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int len = nums.size();
        if(len==3)
            return nums[0]*nums[1]*nums[2];
        sort(nums.begin(), nums.end());
        int res = INT_MIN;
        res = max(res, nums[len-1]*nums[len-2]*nums[len-3]);
        res = max(res, nums[0]*nums[1]*nums[len-1]);
        return res;
    }
};

int main() {
	
	return 0;
}
