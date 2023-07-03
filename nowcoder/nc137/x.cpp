#include<iostream>
#include<vector>
#include<map>
#include<string>
#include<stack>

using namespace std;

class Solution {
public:
    map<char, int> prio = {
        {'+', 0}, {'-', 0}, {'*', 1}, {'(', -1}
    };
    vector<string> reverseP(string s) {
        vector<string> ans;
        stack<char> stk;
        string num = "";
        for(int i=0; i<s.size(); i++) {
            if(s[i]>='0' && s[i] <= '9') 
                num += s[i];
            else {
                if(num != "") {
                    ans.push_back(num);
                    num = "";
                }
                if(s[i] == '(')
                    stk.push(s[i]);
                else if(s[i] == ')') {
                    while(!stk.empty() && stk.top() != '(') {
                        ans.push_back(string(1, stk.top()));
                        stk.pop();
                    }
                    stk.pop();
                }
                else {
                    while(!stk.empty() && prio[stk.top()] >= prio[s[i]]) {
                        ans.push_back(string(1, stk.top()));
                        stk.pop();
                    }
                    stk.push(s[i]);
                }
            }
        }
        if(num != "")
            ans.push_back(num);
        while(!stk.empty() ) {
            ans.push_back(string(1, stk.top()));
            stk.pop();
        }
        return ans;
    }

    int solve(string s) {
        vector<string> ans = reverseP(s);
        stack<int> stk;
        for(int i=0; i<ans.size(); i++) {
            if(ans[i][0]>='0' && ans[i][0]<='9')
                stk.push(stoi(ans[i]));
            else {
                int b = stk.top(); stk.pop();
                int a = stk.top(); stk.pop();
                int c;
                if(ans[i] == "+") 
                    c = a + b;
                else if(ans[i] == "-")
                    c = a - b;
                else if(ans[i] == "*")
                    c = a * b;
                stk.push(c);
            }
        }
        return stk.top();
    }
};
