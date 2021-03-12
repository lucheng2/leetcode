#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

class NumMatrix {
public:
    vector<vector<int>> preSum;
    NumMatrix(vector<vector<int>>& matrix) {
        int n = matrix.size();
        if(n>0)
            preSum.resize(n+1, vector<int> (matrix[0].size() +1));
        for(int i=1; i<=n; ++i)
            for(int j=1; j<=matrix[0].size(); ++j) {
                preSum[i][j] = preSum[i-1][j] + preSum[i][j-1] - preSum[i-1][j-1] + matrix[i-1][j-1];
            }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int result = preSum[row2+1][col2+1] - preSum[row1][col2+1] - preSum[row2+1][col1] + preSum[row1][col1];
        return result;
    }
};

int main() {
    vector<vector<int>> input = {{1,2}};
    NumMatrix n(input);
    int result = n.sumRegion(0, 0, 0, 0);
    result = n.sumRegion(0, 0, 0, 1);
    result = n.sumRegion(0,1,0,1);
    printf("%d\n", result);
	return 0;
}
