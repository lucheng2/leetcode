#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
		for (int i=0; i<nums.size(); i++) {
			nums[i] = nums[i] * nums[i];
		}
		sort(nums.begin(), nums.end());
		return nums;
    }
};

int main() {
	Solution s;
	vector<int> nums = {-4,-1,0,3,10};
	nums = s.sortedSquares(nums);
	for(auto i: nums)
		printf("%d ", i);
	return 0;

}
