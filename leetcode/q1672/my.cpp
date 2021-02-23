#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;
class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int m=accounts.size(), n = accounts[0].size();
        int amax = 0, imax = 0;
        for (int i=0; i<m; i++) {
            imax = 0;
            for (int j=0; j<n; j++) {
                imax += accounts[i][j];
            }
            if (amax<imax)
                amax = imax;
        }
        return amax;
    }
};

int main() {
	
	return 0;
}
