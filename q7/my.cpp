#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<climits>

using namespace std;

class Solution {
public:
    int reverse(int x) {
        bool neg = false;
        if(x<0) {
            neg = true;
            x = abs(x);
        }
        string xstr = to_string(x);
        int len = xstr.length();
        char tmp;
        for(int i=0; i<len/2; i++) {
            tmp = xstr[i];
            xstr[i] = xstr[len-1-i];
            xstr[len-1-i] = tmp;
        }
        long rx = stol(xstr);
        if(neg)
            rx = -rx;
        if(rx<=INT_MAX && rx>=INT_MIN) 
            return rx;
        return 0;
    }
};

int main() {
	
    printf("%d", INT_MAX);
	return 0;
}
