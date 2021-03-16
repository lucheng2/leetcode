#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<stack>

using namespace std;

class Solution {
public:
    bool isValidSerialization(string preorder) {
        if(preorder.size()<=0)
            return true;
        if(preorder[0]=='#') {
            for(int i=1; i<preorder.size(); ++i) {
                if(preorder[i] != '#')
                    return false;
            }
            return true;
        }
        stack<int> stk;
        stk.emplace(2);
        for(int i=1; i<preorder.size(); ++i) {
            if(stk.empty())
                return false;
            if(preorder[i] == ',')
                continue;
            if(preorder[i] == '#') {
                stk.top()--;
                if(stk.top()<=0) {
                    stk.pop();
                }
            } else {
                while(i<preorder.size() && preorder[i]!=',') {
                    i++;
                }
                stk.top()--;
                if(stk.top()<=0) {
                    stk.pop();
                }
                stk.push(2);
            }
        }
        return stk.empty();
    }
};

int main() {
	
	return 0;
}
