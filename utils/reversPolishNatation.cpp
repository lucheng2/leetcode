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
        {'+',1}, {'-', 1}, {'(', 0}, {')', 0}
    };
    for(int i=0; i<s.size(); ++i) {
        if(isdigit(s[i])) {
            break;
        }
        if(s[i] == '+' || s[i]=='-') {
            s = "0" + s;
            break;
        }
    }
    stack<string> optStk;
    vector<string> ans;
    for(int i=0; i<s.size(); ++i) {
        if(s[i] == ' ') {
            continue;
        } else if(isdigit(s[i])) {
            int j=i+1;
            while (j<s.size() && (isdigit(s[j])) ) {
                j++;
            }
            ans.push_back(s.substr(i, j-i));
            i = j-1;
        } else if(s[i] == '(') {
            optStk.emplace(s.substr(i, 1));
        } else if(s[i] == ')') {
            while(optStk.top() != "(") {
                ans.push_back(optStk.top());
                optStk.pop();
            }
            optStk.pop();
        } else if(s[i] == '+' || s[i] == '-') {
            while(!optStk.empty() && priorityTable[optStk.top()[0]]  >= priorityTable[s[i]]) {
                ans.push_back(optStk.top());
                optStk.pop();
            }
            optStk.push(s.substr(i, 1));
        }
    }
    while(!optStk.empty()) {
        ans.push_back(optStk.top());
        optStk.pop();
    }
    return ans;
};

int calRPN(vector<string> notation) {
    int ans = 0;
    stack<int> numStk;
    for(int i=0; i<notation.size(); ++i) {
        if(isdigit(notation[i][0])) {
            int num = 0;
            for(int j=0; j<notation[i].size(); ++j) {
                num = num * 10 + (notation[i][j] - '0');
            }
            numStk.push(num);
        }
        else {
            int b = numStk.top();
            numStk.pop();
            int a = numStk.top();
            numStk.pop();
            if(notation[i][0] == '+') {
                a = a + b;
            } else {
                a = a - b;
            }
            numStk.push(a);
        }
    }
    return numStk.top();
}

class Solution {
public:
    int calculate(string s) {
        vector<string> RPN = reversePolishNotation(s);
        int ans = calRPN(RPN);
        return ans;
    }
};

int main() {
	string data = "1234";
    vector<string> ans = reversePolishNotation(data);
    for(auto s: ans) {
        cout<<s;
    }
    cout<<endl;
	return 0;
}
