#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<math.h>

using namespace std;

class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int len = points.size();
        if(len<=1)
            return 0;
        int ans = 0;
        for( int i=1; i<len; i++) {
            ans += max(abs(points[i][0]-points[i-1][0]), abs(points[i][1] - points[i-1][1]));
        }
        return ans;
    }
};

int main() {
	
	return 0;
}
