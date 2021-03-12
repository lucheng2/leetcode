#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<stack>

using namespace std;

class Solution {
public:
    vector<double> getCollisionTimes(vector<vector<int>>& cars) {
        int n = cars.size();
        vector<double> ans(n);
        stack<int> stk;
        ans[n-1] = -1;
        stk.push(n-1);
        for(int i=n-2; i>=0; --i) {
            while(stk.size()) {
                if(cars[i][1] <= cars[stk.top()][1] || (ans[stk.top()] > 1e-5 && (double)(cars[stk.top()][0] - cars[i][0]) / (double)( cars[i][1] - cars[stk.top()][1]) > ans[stk.top()])) 
                    stk.pop();
                else 
                    break;
            }
            if(stk.size()) {
                ans[i] = (double)(cars[stk.top()][0] - cars[i][0]) / (double)( cars[i][1] - cars[stk.top()][1]);
            } else {
                ans[i] = -1;
            }
            stk.push(i);
        }
        return ans;
    }
};

int main() {
	
	return 0;
}
