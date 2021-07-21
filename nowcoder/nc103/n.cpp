#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

class Solution {
public:
    string solve(string str) {
        string::iterator low = str.begin();
        string::iterator high = str.end();
        while(low != high && low != --high) {
            swap(*low, *high);
            low ++;
        }
        return str;
    }
};
