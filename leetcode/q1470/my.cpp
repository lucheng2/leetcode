#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;
class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> res(2*n);
        for(int i=0; i<n; i++) {
            res[2*i] = nums[i];
            res[2*i + 1] = nums[n + i];
        }
        return res;
    }
};

int main() {
	
	return 0;
}
