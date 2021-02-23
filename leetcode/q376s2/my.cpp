#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
		int n = nums.size();
		if (n<2) {
			return n;
		}
		int preDiff = nums[1] - nums[0];
		int res = preDiff==0?1:2;
		for(int i=2; i<n; i++) {
			int diff = nums[i] - nums[i-1];
			if((preDiff<=0 && diff>0) || (preDiff>=0 &&diff<0)) {
				res++;
				preDiff = diff;
			}
		}
		return res;
    }
};

int main() {
	
	Solution s;
	vector<int> nums = {1,7,4,9,2,5};
	int res = s.wiggleMaxLength(nums);
	printf("%d\n", res);
	return 0;
}
