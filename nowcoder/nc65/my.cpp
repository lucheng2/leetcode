#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

class Solution {
public:
    int Fibonacci(int n) {
        int pre = 0, cur = 1;
        for(int i=0; i<n; i++) {
            int tmp = cur;
            cur += pre;
            pre = tmp;
        }
        return pre;
    }
};
