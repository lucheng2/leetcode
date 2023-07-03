#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define ll long long

using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n, vector<int>(n));
        int cnt = 1, lmt = n*n;
        int l=0, r=n-1, t=0, b=n-1;
        while(cnt<=lmt) {
            for(int i=l; i<=r&&cnt<=lmt; i++) 
                ans[t][i] = cnt++;
            t++;
            for(int i=t; i<=b&&cnt<=lmt; i++)
                ans[i][r] = cnt++;
            r--;
            for(int i=r; i>=l&&cnt<=lmt; i--)
                ans[b][i] = cnt++;
            b--;
            for(int i=b; i>=t&&cnt<=lmt; i--)
                ans[i][l] = cnt++;
            l++;
        }
        return ans;
    }
};
