#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        if(n==0)
            return;
        if(m==0) {
            for(int i=0; i<n; i++)
                A[i] = B[i];
            return;
        }
        int ttl = m+n;
        for(int i=ttl-1; i>=n; i--)
            A[i] = A[i-n];
        int i=n, j=0, s=0;
        while(s < ttl) {
            if(i >= ttl || (j < n && A[i] > B[j]))
                A[s++] = B[j++];
            else
                A[s++] = A[i++];
        }
    }
};
