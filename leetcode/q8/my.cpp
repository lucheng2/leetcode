#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cctype>
#include<climits>
#include<unordered_map>

using namespace std;

class Automation {
    unordered_map<string, vector<string>> table = {
        {"start", {"start", "signed", "in_number", "end"}}, 
        {"signed", {"end", "end", "in_number", "end"}},
        {"in_number", {"end", "end", "in_number", "end"}}, 
        {"end", {"end", "end", "end", "end"}}
    };
    int get_col(char c) {
        if(c == ' ')
            return 0;
        if(c=='+' || c=='-')
            return 1;
        if(isdigit(c))
            return 2;
        return 3;
    }
public:
    int sign = 1;
    long long ans = 0;
    string state = "start";
    void input(char c) {
        state = table[state][get_col(c)];
        if(state == "in_number") {
            ans = ans * 10 + (c - '0');
            ans = (sign==1 ? min(ans, (long long) INT_MAX): min(ans, -(long long)INT_MIN));
        }
        else if(state == "signed") {
            sign = (c=='+' ? 1 : -1);
        }
    }
};

class Solution {
public:
    int myAtoi(string s) {
        Automation a;
        for(auto c: s) {
            a.input(c);
        }
        return a.ans * a.sign;
    }
};

int main() {
    string i = "   -42";
    Solution s;
    int res = s.myAtoi(i);
    printf("%d\n", res);
	return 0;
}
