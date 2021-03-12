#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> yh(rowIndex+1, 0);
        yh[0] = 1;
        for(int i=1; i<=rowIndex; ++i) {
            for(int j=i; j>0; --j) {
                yh[j] += yh[j-1];
            }
        }
        return yh;
    }
};

int main() {
	
	return 0;
}
