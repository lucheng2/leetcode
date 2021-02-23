#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

class Solution {
public:
    int subtractProductAndSum(int n) {
        int pro=1, sum=0, tmp;
        while(n!=0) {
            tmp = n%10;
            n /= 10;
            pro = pro * tmp;
            sum += tmp;
        }
        return pro - sum;
    }
};

int main() {
	
	return 0;
}
