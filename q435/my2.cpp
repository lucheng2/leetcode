#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

struct myCompare {
    bool operator() (const vector<int> & a1, const vector<int> & a2) const {
        return a1[1] < a2[1];
    }
};

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int len = intervals.size();
        if(len<=1)
            return 0;
        sort(intervals.begin(), intervals.end(), myCompare());
        int ans = 1;
        auto firstPos = intervals.begin();
        for(auto pos=firstPos+1; pos != intervals.end();++pos ) {
            if((*pos)[0]>=(*firstPos)[1]) {
                ans++;
                firstPos = pos;
            }
        }
        return len - ans;
    }
};

int main() {
    vector<vector<int>> nums = {{1,2}, {2,3}, {3,4}, {1,3}};
    Solution s;
    int r = s.eraseOverlapIntervals(nums);
    printf("%d\n", r);
	return 0;
}
