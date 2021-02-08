#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>
#include<unordered_map>
using namespace std;

class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> res(nums.size());
        map<int, int> m;
        unordered_map<int, int> hm;
        for(auto n: nums)
            m[n]++;
        for(auto it = m.begin(); it!=m.end(); it++) {
            if(it==m.begin())
                hm[it->first] = 0;
            else {
                auto tmp = it;
                --tmp;
                hm[it->first] = tmp->second;
                it->second += tmp->second;
            }
        }
        for(int i=0; i<nums.size(); i++) {
            res[i] = hm[nums[i]];
        }
        return res;
    }
};

int main() {
	
	return 0;
}
