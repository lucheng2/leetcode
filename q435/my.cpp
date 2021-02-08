#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

struct myCompare {
    bool operator() (const vector<int> & a1, const vector<int> & a2) const {
        return a1[0] < a2[0];
    }
};

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int len = intervals.size();
        if(len<=1)
            return 0;
        sort(intervals.begin(), intervals.end(), myCompare());
        vector<int> dp(len+2, 1);
        for(int i=2; i<=len; ++i) {
            for(int j=1; j<i; ++j) {
                if(intervals[j-1][1] <= intervals[i-1][0]) 
                    dp[i] = max(dp[i], dp[j]+1);
            } 
        }
        return len - *max_element(dp.begin(), dp.end());
    }
};

int main() {
	
	return 0;
}
