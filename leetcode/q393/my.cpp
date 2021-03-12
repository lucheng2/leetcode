#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

class Automation{
    vector<vector<int>> table = {
        {0, 4, 1, 2, 3, 4},
        {4, 0, 4, 4, 4, 4},
        {4, 1, 4, 4, 4, 4},
        {4, 2, 4, 4, 4, 4},
        {4, 4, 4, 4, 4, 4}
    };

    vector<unsigned char> mask = {0b10000000, 0b11000000, 0b11100000, 0b11110000, 0b11111000};
    vector<unsigned char> type = {0b00000000, 0b10000000, 0b11000000, 0b11100000, 0b11110000};

    int getInputType(unsigned char c) {
        for(int i=0; i<5; ++i) {
            if( (c&mask[i])  == type[i] ) 
                return i;
        }
        return 5;
    }

public:
    int state = 0;
    int input(char c) {
        state = table[state][getInputType(c)];
        return state;
    }
};

class Solution {
public:
    bool validUtf8(vector<int>& data) {
        Automation automation;
        for(int i: data) {
            unsigned char d = (unsigned char) i;
            if(automation.input(d) == 4) 
                return false;
        }
        return automation.state==0? true: false;
    }
};

int main() {
    Solution s;
    vector<int> data = {235, 140, 4};
    bool res = s.validUtf8(data);
    printf("%d\n", res);
	return 0;
}
