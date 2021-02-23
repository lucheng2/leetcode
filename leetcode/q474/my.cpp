#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

// 二维费用问题
class Solution {
public:
    int F[110][110];
    int findMaxForm(vector<string>& strs, int m, int n) {
        int len = strs.size();
        vector<vector<int>> data(len+1, vector<int>(2, 0));
        for(int i=0; i<len; ++i) {
            for(int j=0; j<strs[i].length(); ++j)
                data[i][strs[i][j]-'0'] ++;
        }
        memset(F, 0, sizeof(F));
        for(int i=1; i<=len; ++i) {
            for(int j=m; j>=data[i-1][0]; --j) {
                for(int k=n; k>=data[i-1][1]; --k) {
                    F[j][k] = max(F[j][k], F[j-data[i-1][0]][k-data[i-1][1]] +1);
                }
            }
        }
        return F[m][n];
    }
};

int main() {
	
	return 0;
}
