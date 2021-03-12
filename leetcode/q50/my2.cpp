#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        long long int N = n;
        return N>=0? quickMul(x, N) : 1 / quickMul(x, -N);
    }
    

    double quickMul(double x, long long int n) {
        double ans = 1.0;
        double x_contribute = x;
        while (n>0) {
            if(n&1) {
                ans *= x_contribute;
            }
            x_contribute *= x_contribute;
            n = n>>1;
        }
        return ans;
    }
};

int main() {
	
	return 0;
}
