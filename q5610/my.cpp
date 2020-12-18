#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<vector>

using namespace std;

long long sum[100000] = { 0 };
class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        sum[0] = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            sum[i] = sum[i - 1] + nums[i];
        }
        vector<int> res(nums.size());
        for (int i = 1; i < nums.size() - 1; i++) {
            res[i] = (nums[i] * i) - sum[i - 1] + sum[nums.size() - 1] - sum[i] - (nums[i] * (nums.size() - i - 1));
        }
        res[0] = sum[nums.size() - 1] - nums[0] - (nums.size() - 1) * nums[0];
        res[nums.size() - 1] = (nums.size() - 1) * nums[nums.size() - 1] - sum[nums.size() - 2];
        return res;
    }
};

int main() {
    Solution s;
    vector<int> t = { 2,3,5 };
    vector<int> r = s.getSumAbsoluteDifferences(t);
}