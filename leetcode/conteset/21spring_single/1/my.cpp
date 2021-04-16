#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

class Solution {
public:
    int mod = 1e9 + 7;
    int purchasePlans(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        long long ans = 0;
        for(int i=0; i<nums.size() - 1; i++) {
            int left = i+1, right = nums.size() - 1;
            int mxi = left;
            while(left <= right) {
                int mid = (left + right) / 2;
                if(nums[mid] + nums[i] <= target) {
                    mxi = max(mxi, mid);
                    left = mid + 1;
                }
                else {
                    right = mid - 1;
                }
            }
            ans += mxi - i;
            ans = ans % mod;
        }
        return (int) ans;
    }
};

int main() {
	
	return 0;
}
