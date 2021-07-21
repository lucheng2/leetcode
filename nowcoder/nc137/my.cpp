#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>
#include<stack>

using namespace std;

class Solution {
public:
    map<char, int> priority = {{'+', 0}, {'-', 0}, {'*', 1}, {'(', -1}};

    vector<string> reversP(string s) {
        vector<string> ans;
        stack<char> stk;
        int n = s.length();
        int l = 0, r = l;
        bool isnum = false;
        while(r<n) {
            if(s[r]>='0' && s[r]<='9') {
                isnum = true;
                r ++;
            }
            else {
                if(isnum) {
                    ans.push_back(s.substr(l, r-l));
                    isnum = false;
                    r--;
                }
                else if(s[r] == '(') {
                    stk.push(s[r]);
                }
                else if(s[r] == ')') {
                    while(stk.top() != '(') {
                        ans.push_back(string(1, stk.top()));
                        stk.pop();
                    }
                    stk.pop();
                }
                else {
                    while(!stk.empty() && priority[stk.top()] >= priority[s[r]]) {
                        ans.push_back(string(1, stk.top()));
                        stk.pop();
                    }
                    stk.push(s[r]);
                }
                r++;
                l = r;
            }
        }
        if(r-l>0)
            ans.push_back(s.substr(l));
        while(!stk.empty()) {
            ans.push_back(string(1, stk.top()));
            stk.pop();
        }
        return ans;
    }

    int cul(vector<string> & exp) {
        stack<int> stk;
        for(int i=0; i<exp.size(); i++) {
            if(isdigit(exp[i][0]))
                stk.push(stoi(exp[i]));
            else {
                if(exp[i] == "+") {
                    int a = stk.top();
                    stk.pop();
                    int b = stk.top();
                    stk.pop();
                    stk.push(b + a);
                }
                else if(exp[i] == "-") {
                    int a = stk.top();
                    stk.pop();
                    int b = stk.top();
                    stk.pop();
                    stk.push(b - a);
                }
                else {
                    int a = stk.top();
                    stk.pop();
                    int b = stk.top();
                    stk.pop();
                    stk.push(b * a);
                }
            }
        }
        return stk.top();
    }

    int solve(string s) {
        vector<string> exp = reversP(s);
        int ans = cul(exp);
        return ans;
    }
};

int main() {
    string s;
    cin>>s;
    Solution so;
    cout<<so.solve(s);
    return 0;
}
