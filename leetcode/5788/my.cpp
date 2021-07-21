#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define ll long long 

using namespace std;

class Solution {
public:
    string largestOddNumber(string num) {
        int n = num.size();
        while(n>0) {
            if((num[n-1]-'0')%2==1) {
                break;
            }
            n--;
        }
        return num.substr(0, n);
    }
};
