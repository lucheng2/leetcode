#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<stack>
#define ll long long

using namespace std;

int main() {
    string s;
    cin>> s;
    stack<int> stk;
    int num = 0;
    for(int i=0; i<s.length(); i++) {
        if(s[i] >= '0' && s[i] <= '9')
            num = num*10 + (s[i] - '0');
        else {
            if(s[i] == '.') {
                stk.push(num);
                num = 0;
            }
            else {
                if(s[i] == '+') {
                    int n2 = stk.top();
                    stk.pop();
                    int n1 = stk.top();
                    stk.pop();
                    stk.push(n1 + n2);
                }
                else if(s[i] == '-') {
                    int n2 = stk.top();
                    stk.pop();
                    int n1 = stk.top();
                    stk.pop();
                    stk.push(n1 - n2);
                }
                else if(s[i] == '*') {
                    int n2 = stk.top();
                    stk.pop();
                    int n1 = stk.top();
                    stk.pop();
                    stk.push(n1 * n2);
                }
                else if(s[i] == '/') {
                    int n2 = stk.top();
                    stk.pop();
                    int n1 = stk.top();
                    stk.pop();
                    stk.push(n1 / n2);
                }
            }
        }
    }
    cout<<stk.top()<<endl;
	
	return 0;
}
