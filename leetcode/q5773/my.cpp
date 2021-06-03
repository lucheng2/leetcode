#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define ll long long 

using namespace std;

class Solution {
public:
    string maxValue(string n, int x) {
        bool isNeg = n[0]=='-' ? true: false;
        int index;
        char t = (char)x + '0';
        if(isNeg) {
            index=1;
            for(; index<n.size(); index++) {
                if(n[index]>=t) {
                    break;
                }
            }
        }
        else{
            index = 0;
            for(; index<n.size(); index++) {
                if(n[index]<=t)
                    break;
            }
        }
        if(index==n.size()){
            n.push_back(t);
        }
        else{
            n.insert(index,1, t);
        }
        return n;
    }
};

