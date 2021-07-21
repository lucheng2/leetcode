#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define ll long long 

using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        int i = 0;
        int n = s.size();
        while(i < s.size()) {
            int j = i + 1;
            while(j < n && s[j] != ' ') 
                j ++;
            reverse(s.begin() + i, s.begin() + j);
            i = j+1;
        }
        return s;
    }
};
