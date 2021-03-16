#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

class Solution {
public:
    vector<int> createTargetArray(vector<int>& nums, vector<int>& index) {
        vector<int> res;
        for(int i=0; i<index.size(); i++) {
            res.insert(res.begin() + index[i], nums[i]);
        }
        return res;
    }
};

int main() {
	
	return 0;
}