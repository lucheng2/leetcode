#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int nums[2] = {0};
        for(auto stu: students)
            nums[stu]++;
        for(int i=0; i<sandwiches.size(); i++) {
            if(nums[sandwiches[i]]>0) {
                nums[sandwiches[i]]--;
            } else {
                break;
            }
        }
        return nums[0] + nums[1];
    }
};

int main() {
	
	return 0;
}
