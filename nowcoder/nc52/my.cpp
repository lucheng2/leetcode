#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<stack>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        int n = s.length();
        stack<char> stk;
        for(int i=0; i<n; i++) {
            if(stk.size()) {
                switch (s[i]) {
                    case ')':
                        if(stk.top() == '(')
                            stk.pop();
                        else
                            stk.push(s[i]);
                        break;
                    case '}':
                        if(stk.top() == '{')
                            stk.pop();
                        else
                            stk.push(s[i]);
                        break;
                    case ']':
                        if(stk.top() == '[')
                            stk.pop();
                        else
                            stk.push(s[i]);
                        break;
                    default:
                        stk.push(s[i]);
                }
            }
            else{
                stk.push(s[i]);
            }
        }
        return stk.empty()? true: false;
    }
};
