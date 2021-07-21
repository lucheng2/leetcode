#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

class Solution {
public:
    int jumpFloor(int number) {
        if(number <= 2)
            return number;
        int pre = 1, after = 2;
        for(int i=0; i<number - 1; i++) {
            int sum = pre + after;
            pre = after, after = sum;
        }
        return pre;
    }
};
