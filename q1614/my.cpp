#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<stack>

using namespace std;

class Solution {
public:
    int maxDepth(string s) {
        int ans = 0;
        stack<char> leftparent;
        for(auto c: s) {
            if (c == '(') {
                leftparent.push(c);
                if(ans<leftparent.size()) {
                    ans = leftparent.size();
                }
            }
            else if (c == ')') {
                leftparent.pop();
            }
        }
        return ans;
    }
};

int main() {
	
	return 0;
}
