#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

class Solution {
public:
    int getLongestPalindrome(string A, int n) {
        if(n<=1)
            return n;
        vector<int> d1(n), d2(n);
        for(int i=0; i<n; i++) {
            d1[i] = 1;
            while(i-d1[i]>=0 && i+d1[i]<n && A[i-d1[i]]==A[i+d1[i]])
                d1[i]++;
            d2[i] = 0;
            while(i-d2[i]-1>=0 && i+d2[i]<n && A[i-d2[i]-1]==A[i+d2[i]])
                d2[i]++;
        }
        return max(*max_element(d1.begin(), d1.end())*2-1, *max_element(d2.begin(), d2.end())*2);
    }
};
