#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

class Solution {
public:
    vector<int> countBits(int num) {
        int highBit = 0;
        vector<int> ans(num+1);
        for(int i=1; i<=num; ++i) {
            if((i&(i-1)) == 0)
                highBit = i;
            ans[i] = ans[i - highBit] + 1;
        }
        return ans;
    }
};

int main() {
	
	return 0;
}
