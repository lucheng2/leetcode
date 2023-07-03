#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<unordered_set>
#define ll long long 

using namespace std;

class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums[0].size();
        int cnt = 1<<n;
        unordered_set<string> hs;
        for(int i=0; i<nums.size(); i++) 
            hs.insert(nums[i]);
        int s = 0;
        while(s < cnt) {
            string tmp = "";
            for(int i=n-1; i>=0; i--) {
                tmp.push_back((s&(1<<i))?'1' : '0');
            }
            if(hs.find(tmp) == hs.end()) {
                return tmp;
            }
            s++;
        }
        return "";
    }
};

