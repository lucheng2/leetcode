#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define ll long long 

using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int n = matrix.size(), m = matrix[0].size();
        int end = m*n;
        int l=0, r=m-1, t=0, b=n-1;
        while(end>0) {
            for(int i=l; i<=r && end; i++) {
                ans.push_back(matrix[t][i]);
                end--;
            }
            t++;
            for(int i=t; i<=b && end; i++) {
                ans.push_back(matrix[i][r]);
                end--;
            }
            r--;
            for(int i=r; i>=l && end; i--) {
                ans.push_back(matrix[b][i]);
                end--;
            }
            b--;
            for(int i=b; i>=t && end; i--) {
                ans.push_back(matrix[i][l]);
                end--;
            }
            l++;
        }
        return ans;
    }
};
