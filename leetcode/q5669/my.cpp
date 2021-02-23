#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

class Solution {
public:
    bool canChoose(vector<vector<int>>& groups, vector<int>& nums) {
        int n = nums.size();
        int index=0;
        int j;
        for(int i=0; i<groups.size(); ++i) {
            for( j=0; j<groups[i].size() && index<n; ) {
                if(groups[i][j] == nums[index]) {
                    j++;
                    index++;
                }
                else{
                    index = index - j + 1;
                    j = 0;
                }
            }
            if(index>=n&&j<groups[i].size())
                return false;
        }
        return true;

    }
};

int main() {
	
	return 0;
}
