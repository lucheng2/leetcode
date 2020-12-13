#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
	int majorityElement(vector<int>& nums) {
		int major, count=0, length = nums.size();
		for (int i = 0; i < length; i++) {
			if (count == 0) {
				major = nums[i];
				count++;
			}
			else
			{
				if (major == nums[i]) {
					count++;
				}
				else
				{
					count--;
				}
			}
		}

		if (count == 0) {
			return -1;
		}
		else
		{
			count = 0;
			for (int i = 0; i < length; i++) {
				if (nums[i] == major) {
					count++;
				}
			}
			return (2 * count - length)>0 ? major : -1;
		}
	}
};

int main() {
	Solution solution;
	vector<int> nums = { 1,1,2 };
	int reuslt = solution.majorityElement(nums);
	return 0;
}