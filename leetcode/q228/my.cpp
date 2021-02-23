#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        int i=0, j;
        for( i=0; i<nums.size(); ) {
            for(j=i+1; j<nums.size(); ++j) {
                if(nums[j-1]+1!=nums[j])
                    break;
            }
            if(j-i>1)
                ans.emplace_back(to_string(nums[i]) + "->" + to_string(nums[j-1]));
            else
                ans.emplace_back(to_string(nums[i]));
            i = j;
        }
        return ans;
    }
};

int main() {
	
	return 0;
}
