#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        vector<int> tmp(m+n);
        int ttl = m + n;
        int i=0, j=0, s=0;
        while(s<ttl) {
            if(i>=m || (j<n && A[i] > B[j]))
                tmp[s++] = B[j++];
            else
                tmp[s++] = A[i++];
        }
        for(int i=0; i<ttl; i++)
            A[i] = tmp[i];
    }
};
