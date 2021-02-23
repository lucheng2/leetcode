#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        int mr = nums.size();
        int mc = nums[0].size();
        if(mr*mc != r*c)
            return nums;
        vector<vector<int>> reshaped(r, vector<int>(c, 0));
        int amount = mr*mc;
        for(int i=0; i<amount; ++i)
            reshaped[i/c][i%c] = nums[i/mc][i%mc];
        return reshaped;

    }
};

int main() {
	
	return 0;
}
