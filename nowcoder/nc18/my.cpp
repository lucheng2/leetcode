#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int> > rotateMatrix(vector<vector<int> > mat, int n) {
        if(n == 0)
            return mat;
        int lmt = (n) / 2;
        for(int i=0; i<lmt; i++) {
            for(int j=0; j<n; j++) 
                swap(mat[i][j], mat[n-1-i][j]);
        }
        for(int i=0; i<n; i++)
            for(int j=0; j<i; j++)
                swap(mat[i][j], mat[j][i]);
    
        return mat;
    }
};

