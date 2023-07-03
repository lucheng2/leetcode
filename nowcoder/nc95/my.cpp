#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<set>
#include<stack>

using namespace std;

class Solution {
public:
    int MLS(vector<int>& arr) {
        set<int> st;
        for(auto i: arr) {
            st.insert(i);
        }
        stack<int> stk;
        int cnt = 0, ans = 0;
        for(auto it: st) {
            if(stk.size()) {
                if(stk.top() + 1 == it) {
                    cnt++;
                    stk.push(it);
                }
                else{
                    ans = max(ans, cnt);
                    while(stk.size())
                        stk.pop();
                    stk.push(it);
                    cnt = 1;
                }
            }
            else{
                stk.push(it);
                cnt++;
            }
        }
        ans = max(ans, cnt);
        return ans;
    }
};
