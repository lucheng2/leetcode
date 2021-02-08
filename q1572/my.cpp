#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int res = 0;
        int n = mat.size();
        for(int i=0; i<n; i++) {
            res += mat[i][i] + mat[i][n-1-i];
        }
        if(n&1)
            res -= mat[(n>>1)][(n>>1)];
        return res;
    }
};

int main() {
	
	return 0;
}
