#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

class Solution {
public:
    int ans = -1;
    int closestCost(vector<int>& baseCosts, vector<int>& toppingCosts, int target) {
        int n = baseCosts.size();
        for(int i=0;i<n; i++) {
            dfs(toppingCosts, target, baseCosts[i], 0);
        }
        return ans;
    }

    void dfs(vector<int> &toppingCosts, int target, int cost, int pos) {
        if(pos >= toppingCosts.size()) {
            if(ans < 0 || abs(target - cost) < abs(target - ans) || (abs(target-cost) == abs(ans - cost) && cost < ans))
                ans = cost;
            return;
        }
        dfs(toppingCosts, target, cost, pos + 1);
        dfs(toppingCosts, target, cost + toppingCosts[pos], pos + 1);
        dfs(toppingCosts, target, cost + 2*toppingCosts[pos], pos+1);
    }
};

int main() {
	
	return 0;
}
