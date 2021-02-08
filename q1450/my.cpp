#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

class Solution {
public:
    int busyStudent(vector<int>& startTime, vector<int>& endTime, int queryTime) {
        int ans = 0;
        for(int i=0; i<startTime.size(); i++) {
            if(startTime[i]<=queryTime && queryTime<=endTime[i])
                ++ans;
        }
        return ans;
    }
};

int main() {
	
	return 0;
}
