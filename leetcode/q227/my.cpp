#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<unordered_map>
#include<stack>

using namespace std;

vector<string> reversePolishNotation(string &s) {
    unordered_map<char, int> priorityTable = {
        {'+', 1}, {'-', 1}, {'*', 2}, {'/', 2}
    };
    vector<string> ans;
    stack<char> opt;
    for(int i=0; i<s.size(); ++i) {
        if(s[i] == ' ') {
            continue;
        }
        else if(isdigit(s[i])) {
            int j= i+1;
            while(j<s.size() && isdigit(s[j])) {
                j++;
            }
            ans.push_back(s.substr(i, j-i));
            i = j -1;
        }
        else if(s[i]=='+'||s[i]=='-'||s[i]=='*'||s[i]=='/') {
            while(!opt.empty() && priorityTable[opt.top()] >= priorityTable[s[i]]) {
                ans.push_back(string(1, opt.top()));
                opt.pop();
            }
            opt.push(s[i]);
        }
    }
    while(!opt.empty()) {
        ans.push_back(string(1, opt.top()));
        opt.pop();
    }
    return ans;
}

int cal(vector<string> &RPN) {
    int ans = 0;
    stack<int> stk;
    for(int i=0; i<RPN.size(); ++i) {
        if(isdigit(RPN[i][0])) {
            int num = 0;
            for(int j=0; j<RPN[i].size(); ++j) {
                num = num*10 + (RPN[i][j] - '0');
            }
            stk.push(num);
        }
        else {
            int b = stk.top();
            stk.pop();
            int a = stk.top();
            stk.pop();
            if(RPN[i][0] == '+') {
                a += b;
            } else if(RPN[i][0] =='-') {
                a -= b;
            } else if(RPN[i][0] == '*') {
                a *= b;
            } else if(RPN[i][0] == '/') {
                a /= b;
            }
            stk.push(a);
        }
    }
    return stk.top();
}

class Solution {
public:
    int calculate(string s) {
        vector<string> RPN =  reversePolishNotation(s);
        int res = cal(RPN);
        return res;
    }
};

int main() {
	
	return 0;
}
