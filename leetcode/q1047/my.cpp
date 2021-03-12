#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<stack>

using namespace std;

class Solution {
public:
    string removeDuplicates(string S) {
        stack<char> stk;
        for(int i=0; i<S.length(); ++i) {
            if(stk.empty()) {
                stk.push(S[i]);
            } else if(stk.top() == S[i]) {
                stk.pop();
            } else {
                stk.push(S[i]);
            }
        }
        string ans;
        ans.resize(stk.size());
        for(int i=stk.size() - 1; i>=0; --i) {
            ans[i] = stk.top();
            stk.pop();
        }
        return ans;
    }
};

int main() {
	
	return 0;
}
