#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cctype>

using namespace std;

class Automation {
    vector<vector<int>> table = {
        {1, 3, 2, 8, 8},
        {8, 9, 2, 8, 8},
        {8, 3, 2, 5, 8},
        {8, 8, 4, 8, 8},
        {8, 8, 4, 5, 8},
        {7, 8, 6, 8, 8},
        {8, 8, 6, 8, 8},
        {8, 8, 6, 8, 8},
        {8, 8, 8, 8, 8},
        {8, 8, 4, 5, 8},
    };
    int getInputType(char c) {
        if(c=='+' || c=='-')
            return 0;
        if(c=='.')
            return 1;
        if(isdigit(c))
            return 2;
        if(c=='e' || c=='E')
            return 3;
        return 4;
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
    bool isNumber(string s) {
        Automation a;
        for(char c: s) {
            if(a.input(c) == 8) {
                return false;
            }
        }
        if(a.state==2 || a.state==3 ||a.state==4||a.state==6||a.state==9)
            return true;
        return false;
        
    }
};

int main() {
	
	return 0;
}
