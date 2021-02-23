#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        //难点在旋转的划分上, 要不重复也不遗漏
        //分奇偶讨论, 然后得出划分的方法
        //1. n为偶数, 则要转换的次数: n*n/4 = n/2 * (n+1)/2
        //2. n为奇数, 则要转换的次数: (n*n-1)/4 = (n-1)(n+1)/4 = n/2 * (n+1)/2
        for(int i=0; i< (n)/2; i++) {
            for(int j=0; j< (n+1)/2; j++) {
                int tmp = matrix[i][j];
                matrix[i][j] = matrix[n-1-j][i];
                matrix[n-1-j][i] = matrix[n-1-i][n-1-j];
                matrix[n-1-i][n-1-j] = matrix[j][n-1-i];
                matrix[j][n-1-i] = tmp;
            }
        }

    }
};


int main() {
	
	return 0;
}
