#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define ll long long 

using namespace std;

class Solution {
public:
    bool nextPermutation(string & s) {
        int i = s.length() - 2;
        while(i>=0 && s[i]>=s[i+1])
            i--;
        if(i<0)
            return false;
        int j = s.length() - 1;
        while(j>=0 && s[i]>=s[j])
            j--;
        swap(s[i], s[j]);
        reverse(s.begin()+i+1, s.end());
        return true;
    }
    vector<string> permutation(string s) {
        sort(s.begin(), s.end());
        vector<string> res;
        do {
            res.push_back(s);
        } while(nextPermutation(s));
        return res;
    }
};
