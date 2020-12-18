#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<unordered_map>

using namespace std;

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
		unordered_map<int, int> m;
		int len = nums.size();
		for (int i=0; i<len; i++) {
			auto got = m.find(nums[i]);
			if(got!= m.end()) {
				m[nums[i]] ++;
			} else {
				m[nums[i]] = 1;
			}
		}
		vector<int> res;
		int threshold = len / 3;
		for (auto i = m.begin(); i!=m.end(); i++) {
			if (i->second > threshold) {
					res.push_back(i->first);
			}
		}
		return res;
    }
};

int main() {
	Solution s;
	vector<int> nums = {1,1,1,3,3,2,2,2};
	vector<int> res = s.majorityElement(nums);
	for(auto i: res) {
			printf("%d ", i);
	}
	
	return 0;
}
