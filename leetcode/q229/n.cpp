#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define ll long long 

using namespace std;

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> ans;
        pair<int, int> cand1, cand2;
        for(auto n:  nums) {
            if(n == cand1.first) {
                cand1.second++;
                continue;
            }
            if(n == cand2.first) {
                cand2.second++;
                continue;
            }
            if(cand1.second == 0) {
                cand1.first = n;
                cand1.second = 1;
                continue;
            }
            if(cand2.second == 0) {
                cand2.first = n;
                cand2.second = 1;
                continue;
            }
            cand1.second --;
            cand2.second --;
        }
        int cnt1=0, cnt2=0;
        for(auto n: nums) {
            if(cand1.first == n) {
                cnt1 ++;
                continue;
            }
            if(cand2.first == n)
                cnt2 ++;
        }
        if(cnt1 > nums.size() / 3)
            ans.push_back(cand1.first);
        if(cnt2 > nums.size() / 3)
            ans.push_back(cand2.first);
        return ans;
    }
};
