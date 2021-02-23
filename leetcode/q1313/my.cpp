#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

class Solution {
public:
    vector<int> decompressRLElist(vector<int>& nums) {
        int len = nums.size() / 2;
        vector<int> res;
        for(int i=0; i<len; i++) {
            for(int j=0; j<nums[2*i]; j++) {
                res.push_back(nums[2*i + 1]);
            }
        }
        return res;
    }
};

int main() {
	
	return 0;
}
