#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

class Solution {
public:
    string solve(string s, string t) {
        reverse(s.begin(), s.end());
        reverse(t.begin(), t.end());
        string ans;
        int i=0, j=0, c=0;
        while(i < s.length() || j < t.length()) {
            if(i < s.length()) {
                c += s[i] - '0';
                i++;
            }
            if(j < t.length()) {
                c += t[j] - '0';
                j++;
            }
            ans.push_back('0' + c % 10);
            c /= 10;
        }
        if(c)
            ans.push_back('0' + c);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
