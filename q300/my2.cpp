#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int len=nums.size();
        if(len<=1) {
            return len;
        }
        vector<int> gd(len+2, 0);
        gd[1] = nums[0];
        int gdLen = 1;
        for(int i=2; i<=len; ++i) {
            if(nums[i-1]>gd[gdLen])
                gd[++gdLen] = nums[i-1];
            else {
                auto pos = lower_bound(gd.begin()+1, gd.begin()+gdLen+1, nums[i-1]);
                *pos = nums[i-1];
            }
        }
        return gdLen;
    }
};

int main() {
	
	return 0;
}
