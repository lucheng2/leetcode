#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

class Solution {
public:
    int longestOnes(vector<int>& A, int K) {
        int n = A.size();
        vector<int> preSum(n+1, 0);
        for(int i=1; i<=n; ++i) {
            preSum[i] = preSum[i-1] + (1-A[i-1]);
        }
        int ans = 0;
        for(int right=0;right<n;++right) {
            int left = lower_bound(preSum.begin(), preSum.end(), preSum[right+1]-K) - preSum.begin();
            ans = max(ans, right - left + 1);
        }
        return ans;
    }
};

int main() {
	
	return 0;
}
