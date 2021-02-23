#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<set>

using namespace std;

class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        multiset<int> s;
        int ans = 0;
        int left = 0, right = 0;
        while(right<nums.size()) {
            s.insert(nums[right]);
            while(*s.rbegin() - *s.begin() > limit) 
                s.erase(s.find(nums[left++]));
            ans = max(ans, right - left +1);
            right ++;
        }
        return ans;

    }
};

int main() {
	
	return 0;
}
