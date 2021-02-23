#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

class Solution {
public:
    int totalMoney(int n) {
        int a = n/7, b=n%7;
        int res = 21+7*a;
        res += (28+7*a + 28+7*a+b)*b/2;
        return res;
    }
};

int main() {
	
	return 0;
}
