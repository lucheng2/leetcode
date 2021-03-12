#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

class Solution {
public:
    bool checkPowersOfThree(int n) {
        if(n <= 1)
            return true;
        
        int i=0, base=1;
        while(base < n) {
            base *= 3;
            i++;
        }
        if(base == n)
            return true;
        if(2*base / 3 <= n )
            return false;
        return checkPowersOfThree(n - base/3);
    }

};

int main() {
	
	return 0;
}
