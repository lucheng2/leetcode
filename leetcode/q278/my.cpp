#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int left = 1, right = n;
        int ans = n;
        while(left<=right) {
            int mid = (right - left) / 2 + left;
            if(isBadVersion(mid)) {
                ans = min(ans, mid);
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return ans;
    }
};

int main() {
	
	return 0;
}
