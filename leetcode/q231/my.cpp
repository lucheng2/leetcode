#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define ll long long 

using namespace std;

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n < 0)
            return false;
        int cnt = __builtin_popcount(n);
        return cnt == 1? true: false;
    }
};
