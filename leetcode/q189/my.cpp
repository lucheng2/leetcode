#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int len = nums.size();
        k = k % len;
        if(len<=1 || k==0)
            return;
        vector<int> tmp(k);
        for(int i=0; i<k; ++i) {
            tmp[k-1-i] = nums[len-1-i];
        }
        for(int i=0; i<k; ++i) {
            for(int j=len-1-i; j-k>=0; j=j-k) {
                nums[j] = nums[j-k];
            }
        }
        for(int i=0; i<k; ++i) {
            nums[i] = tmp[i];
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
