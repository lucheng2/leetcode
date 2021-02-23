#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

class Solution {
public:
    int numberOfSteps (int num) {
        int ans = 0;
        while(num!=0) {
            ++ans;
            if(num&1)
                num = num & 0xfffffffe;
            else
                num = num>>1;
        }
        return ans;
    }
};

int main() {
	
	return 0;
}
