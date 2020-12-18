#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
		int candidate[2] = {nums[0]}, vote[2] = {0};
		int len = nums.size();
		//消耗阶段
		for (int i=0; i<len; i++) {
			//投票阶段
			bool voteFlag = false;
			for (int j=0; j<2; j++) {
				if (candidate[j] == nums[i]) {
					vote[j]++;
					voteFlag = true;
					break;
				}
			}
			if (voteFlag) {
				continue;
			}
			//替换票数为0的候选人
			if(vote[0] == 0) {
				candidate[0] = nums[i];
				vote[0]++;
				continue;
			}
			if(vote[1] == 0) {
				candidate[1] = nums[i];
				vote[1]++;
				continue;
			}
			//都没匹配上，消耗两个候选人得票
			vote[0]--;
			vote[1]--;
		}


		//验证阶段
		vector<int> res;
		vote[0]=0, vote[1]=0;
		for (auto num: nums) {
			if(candidate[0]==num) vote[0]++;
			else if(candidate[1]==num) vote[1]++;
		}
		if (vote[0]>len/3) res.push_back(candidate[0]);
		if (vote[1]>len/3) res.push_back(candidate[1]);
		return res;
    }
};

int main() {
	
	Solution s;
	vector<int> nums = {1,1,1,3,3,2,2,2};
	vector<int> res = s.majorityElement(nums);
	for(auto i:res)
			printf("%d ", i);
	return 0;
}
