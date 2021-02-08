#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<set>

using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int len = nums.size();
        vector<int> res;
        multiset<int, greater<int>> window;
        for(int i=0; i<k-1; ++i) {
            window.insert(nums[i]);
        }
        for(int i=k-1; i<len; ++i) {
            window.insert(nums[i]);
            res.emplace_back(*window.begin());
            window.erase(window.find(nums[i-k+1]));
        }
        return res;
    }
};

int main() {
    vector<int> nums = {1,3,-1,-3,5,3,6,7};
    Solution s;
    vector<int> res = s.maxSlidingWindow(nums, 3);
    for(auto a:res)
        printf("%d ", a);
	
	return 0;
}
