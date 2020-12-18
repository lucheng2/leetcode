#include<iostream>
#include<vector>

using namespace std;

/**
* 思路：输入矩阵为N*M， 新建一个M*N的矩阵，依次复制元素到新矩阵即可。
* 时间复杂度O(M*N), 空间复杂度O(N*M)
* PS：考虑cache命中率的因素？
**/
class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& A) {
        int N = A.size(), M = A[0].size();
        vector<vector<int>> B(M, vector<int>(N, 0));
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                B[j][i] = A[i][j];
            }
        }
        return B;
    }
};

int main() {
    vector<vector<int>> A = { {1,2}, {3,4} };
    Solution solution;
    vector<vector<int>> B = solution.transpose(A);
    return 0;
}