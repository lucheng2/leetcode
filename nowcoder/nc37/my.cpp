#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

  struct Interval {
      int start;
      int end;
      Interval() : start(0), end(0) {}
      Interval(int s, int e) : start(s), end(e) {}
  };

int myCmp(const Interval &a, const Interval &b) {
    if(a.start == b.start)
        return a.end < b.end;
    else
        return a.start < b.start;
}

class Solution {
public:
    vector<Interval> merge(vector<Interval> &intervals) {
        sort(intervals.begin(), intervals.end(), myCmp);
        vector<Interval> ans;
        int i=0, n = intervals.size(); 
        while(i < n) {
            int left = intervals[i].start;
            int right = intervals[i].end;
            while(i< n-1 && intervals[i+1].start <= right) {
                right = max(right, intervals[i+1].end);
                i++;
            }
            ans.push_back(Interval(left, right));
            i++;
        }
        return ans;
    }
};
