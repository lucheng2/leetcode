#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define ll long long 

using namespace std;

class Solution {
public:
    void getNum(string &s) {
        for(int i=0; i<s.length(); i++) {
            s[i] = s[i]-'a'+'0';
        }
    }
    bool isSumEqual(string firstWord, string secondWord, string targetWord) {
        getNum(firstWord), getNum(secondWord), getNum(targetWord);
        int a=stoi(firstWord), b=stoi(secondWord), c=stoi(targetWord);

        if(a+b==c)
            return true;
        return false;
    }
};
