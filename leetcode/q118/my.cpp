#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> yh(numRows);
        for(int i=0; i<numRows; ++i) {
            yh[i].resize(i+1, 1);
        }
        for(int i=1; i<numRows; ++i) {
            for(int j=1; j<i; ++j) {
                yh[i][j] = yh[i-1][j-1] + yh[i-1][j];
            }
        }
        return yh;
    }
};

int main() {
	
	return 0;
}
