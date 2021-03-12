#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int pre=0, bak=0;
        while(pre < nums.size()) {
            if(nums[pre] != 0) {
                nums[bak++] = nums[pre++];
            }
            else {
                pre++;
            }
        }
        while(bak < nums.size()) {
            nums[bak++] = 0;
        }
    }
};

int main() {
	
	return 0;
}
