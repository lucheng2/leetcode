#include<iostream>
#include<vector>

using namespace std;

/**
* ˼·���������ΪN*M�� �½�һ��M*N�ľ������θ���Ԫ�ص��¾��󼴿ɡ�
* ʱ�临�Ӷ�O(M*N), �ռ临�Ӷ�O(N*M)
* PS������cache�����ʵ����أ�
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