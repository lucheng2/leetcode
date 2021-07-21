#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<stack>
#include<algorithm>
#define ll long long 

using namespace std;

class Solution {
public:
    string convertToTitle(int columnNumber) {
        string ans = "";
        while(columnNumber) {
            int col = (columnNumber-1) % 26 + 1;
            ans += (char)col + 'A' - 1;
            columnNumber = (columnNumber - col + 1) / 26;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
