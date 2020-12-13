#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Solution {
public:
	int majorityElement(vector<int>& nums) {
		map<int, int> coll;

		int length = nums.size();
		for (int i = 0; i < length; i++) {
			if (coll.find(nums[i]) != coll.end()) {
				coll[nums[i]] += 1;
			}
			else
			{
				coll[nums[i]] = 1;
			}
		}
		map<int, int>::iterator pos;
		int maxCount = 0, key;
		for (pos = coll.begin(); pos != coll.end(); pos++) {
			if (pos->second > maxCount) {
				maxCount = pos->second;
				key = pos->first;
			}
		}
		if (maxCount > length / 2) {
			return key;
		}
		else
		{
			return -1;
		}
	}
};

int main() {
	Solution solution;
	vector<int> nums = { 1,1,2 };
	int reuslt = solution.majorityElement(nums);
}

