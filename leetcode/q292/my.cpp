#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define ll long long 

using namespace std;

class Solution {
public:
    bool canWinNim(int n) {
        return n % 4? true: false;
    }
};
