#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define ll long long 

using namespace std;

class Solution {
public:
    int addRungs(vector<int>& rungs, int dist) {
        int ans = 0;
        for(int i=0; i<rungs.size(); i++) {
            if(i == 0)
                ans = (rungs[i] - 1) / dist;
            else
                ans += (rungs[i] - rungs[i-1] - 1) / dist;
        }
        return ans;
    }
};

int main() {
    Solution s;
    vector<int> test = {1, 3, 5, 10};
    int ans = s.addRungs(test, 2);
    cout<<ans<<endl;
}
