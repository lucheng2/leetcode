#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

class Solution {
public:
    int calculate(string s) {
        int x=1, y=0;
        for(auto c: s) {
            if (c=='A')
                x = 2*x+y;
            else
                y = 2*y+x;
        }
        return x + y;
    }
};

int main() {
	
	return 0;
}
