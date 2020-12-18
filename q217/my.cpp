#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<unordered_set>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
		unordered_set<int> s;
		for(int x: nums) {
			if (s.find(x) != s.end()) {
				return true;
			}
			s.insert(x);
		}
		return false;
    }
};

int main() {
	Solution s;
	vector<int> nums = {1,2,3,4};
	bool r = s.	containsDuplicate(nums);
	printf("%d\n", r);
	return 0;
}
