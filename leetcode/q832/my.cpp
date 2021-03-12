#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        int n = A.size();
        int m = A[0].size();
        int tmp;
        for(int i=0; i<n; ++i) {
            for(int j=0; j<m/2; ++j) {
                tmp = A[i][j];
                A[i][j] = A[i][m-j-1];
                A[i][m-j-1] = tmp;
            }
            for(int j=0; j<m; ++j)
                A[i][j] ^= 1;
        }
        return A;

    }
};

int main() {
	
	return 0;
}
