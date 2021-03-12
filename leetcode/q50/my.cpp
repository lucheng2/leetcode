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
        if(n == 0)
            return 1.0;
        double y = quickMul(x, n/2);
        return (n&1) ? y * y * x : y * y;
    }
};

int main() {
	
	return 0;
}
