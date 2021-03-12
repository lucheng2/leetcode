#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

bool myGreater(vector<int> &a, vector<int> &b) {
    // 由于是< 关系，所以当相等的时候，第二维度从大到小排序即可
    return a[0]<b[0] || (a[0]==b[0] && a[1]>b[1]);
}

class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(), myGreater);
        vector<int> dp(envelopes.size() +1, 1);
        for(int i=0; i<envelopes.size(); ++i) {
            for(int j=i-1; j>=0; --j) {
                if(envelopes[j][1] < envelopes[i][1])
                    dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        int ans = 1;
        for(int i=0; i<dp.size(); i++)
            ans = max(ans, dp[i]);
        return ans;
    }
};

int main() {
	
	return 0;
}
