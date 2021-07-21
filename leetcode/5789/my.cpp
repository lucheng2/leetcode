#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define ll long long 

using namespace std;

class Solution {
public:
    int numberOfRounds(string startTime, string finishTime) {
        int sh = stoi(startTime.substr(0, 2));
        int sm = stoi(startTime.substr(3));
        int fh = stoi(finishTime.substr(0, 2));
        int fm = stoi(finishTime.substr(3));
        if(fh>sh || (fh==sh &&fm>sm)) {
            fm = (fm/15) * 15;
            sm = sm%15==0? sm : (sm/15+1)*15;
            return ((fh-sh)*60 + fm - sm) / 15;
        }
        else {
            fm = (fm/15) * 15;
            sm = sm%15==0? sm : (sm/15+1)*15;
            int a1 = (24-sh)*60 - sm;
            int a2 = fh*60 + fm;
            return (a1+a2) / 15;
        }
    }
};
