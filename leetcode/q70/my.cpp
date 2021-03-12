#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<unordered_map>

using namespace std;

class Solution {
public:
    unordered_map<int, int> mem;
    int climbStairs(int n) {
        if(n<=1) {
            return 1;
        }
        if(mem.count(n))
            return mem[n];
        mem[n] = climbStairs(n-1) + climbStairs(n-2);
        return mem[n];
    }
};

int main() {
	
	return 0;
}
