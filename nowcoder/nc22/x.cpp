#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        int i = m -1, j = n - 1, end = m + n - 1;
        while(end >= 0) {
            if(i < 0 || (j >=0 && A[i] < B[j]))
                A[end--] = B[j--];
            else
                A[end--] = A[i--];
        }
    }
};
