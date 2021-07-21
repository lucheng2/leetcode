#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

class Solution {
public:
    string solve(string str) {
        reverse(str.begin(), str.end());
        return str;
    }
};
