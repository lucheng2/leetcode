#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<stack>

using namespace std;

class Solution {
public:
    map<char, int> prio = {
        {'+', 0},
        {'-', 0},
        {'*', 1},
        {'(', -1}
    };
    
    vector<string> reverseP(string s) {
        stack<char> stk;
        int n = s.size();
        vector<string > ans;
        int l, r;
        l = 0, r = l;
        bool isNum = false;
        while(r < n) {
            if(s[r]>='0' && s[r] <= '9') {
                isNum = true;
                r++;
            }
            else {
                if(isNum) {
                    ans.push_back(s.substr(l, r-l));
                    isNum = false;
                    r--;
                }
                else if(s[r] == '(') {
                    stk.push(s[r]);
                } 
                else if(s[r] == ')') {
                    while(!stk.empty() && stk.top() != '(') {
                        ans.push_back(string(1, stk.top()));
                        stk.pop();
                    }
                    stk.pop();
                }
                else {
                    while(!stk.empty() && prio[stk.top()] >= prio[s[r]]) {
                        ans.push_back(string(1, stk.top()));
                        stk.pop();
                    }
                    stk.push(s[r]);
                }
                r++;
                l = r;
            }
        }
        if(r > l)
            ans.push_back(s.substr(l));
        while(stk.size()) {
            ans.push_back(string(1, stk.top()));
            stk.pop();
        }
        return ans;
    }
    
    int solve(string s) {
        vector<string> ans = reverseP(s);
        stack<int> stk;
        for(int i=0; i<ans.size(); i++) {
            if(ans[i][0] >='0' && ans[i][0]<='9') {
                stk.push(stoi(ans[i]));
            } else {
                int b = stk.top(); stk.pop();
                int a = stk.top(); stk.pop();
                int c;
                if(ans[i][0] == '+')
                    c = a + b;
                else if(ans[i][0] == '-')
                    c = a - b;
                else if(ans[i][0] == '*')
                    c = a * b;
                stk.push(c);
            }
        }
        return stk.top();
    }
};
