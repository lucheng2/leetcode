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
        if(envelopes.size()==0)
            return 0;
        sort(envelopes.begin(), envelopes.end(), myGreater);
        vector<int> res(envelopes.size());
        int len = 1;
        res[0] = envelopes[0][1];
        for(int i=1; i<envelopes.size(); ++i) {
            if(envelopes[i][1] > res[len-1]) {
                res[len++] = envelopes[i][1];
            } else {
                auto it = lower_bound(res.begin(), res.begin() + len , envelopes[i][1]);
                *it = envelopes[i][1];
            }
        }
        return len;
    }
};

int main() {
	
	return 0;
}
