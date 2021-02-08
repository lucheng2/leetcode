#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<stack>

using namespace std;

class Solution {
public:
    int balancedStringSplit(string s) {
        stack<char> stk;
        int len = s.length();
        int count = 0;
        for(int i=0; i<len; ++i) {
            if(stk.empty()) {
                stk.push(s[i]);
            } else {
                if(stk.top() == s[i]) {
                    stk.push(s[i]);
                } else {
                    stk.pop();
                    if(stk.empty()) {
                        count++;
                    }
                }
            }
        }
        return count;
    }
};

int main() {
	
	return 0;
}
