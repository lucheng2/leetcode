#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

class Solution {
public:
    int fib(int n) {
        if(n<=1) {
            return n;
        }
        int pre = 0, lat = 1, tmp;
        int index = 1;
        while(index != n) {
            index++;
            tmp = pre + lat;
            pre = lat; 
            lat = tmp;
        }
        return lat;
    }
};

int main() {
	
	return 0;
}
