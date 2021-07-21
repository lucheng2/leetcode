#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define ll long long 

using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        pair<int, int> cand;
        for(auto n: nums) {
            if(cand.first == n) {
                cand.second ++;
            }
            else {
                if(cand.second == 0) {
                    cand.first = n;
                    cand.second = 1;
                }
                else
                    cand.second --;
            }
        }
        if(cand.second > 0) {
            int cnt = 0;
            for(auto n: nums) {
                if(n == cand.first)
                    cnt++;
            }
            if(cnt>nums.size()/2)
                return cand.first;
            else 
                return -1;
        }
        return -1;
    }
};
