#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k = k%nums.size();
        flip(nums, 0, nums.size()-1);
        flip(nums, 0, k-1);
        flip(nums, k, nums.size()-1);
    }

    void flip(vector<int> &nums, int start, int end) {
        while(start<end) {
            swap(nums[start], nums[end]);
            start++;
            end--;
        }
    }
};

int main() {
    Solution s;
    vector<int> nums = {1,2,3,4,5};
    s.rotate(nums, 3);
    for(auto n:nums)
        printf("%d ", n);
	return 0;
}
