#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

class Solution {
public:
    string solve(vector<int>& nums) {
        if(nums.size()==0)
            return "";
        vector<string> data;
        for(int i=0; i<nums.size(); i++)
            data.push_back(to_string(nums[i]));
        bool flag = true;
        while(flag) {
            flag = false;
            for(int i=1; i<data.size(); i++) {
                if(data[i-1]+data[i] < data[i] + data[i-1]) {
                    flag = true;
                    swap(data[i], data[i-1]);
                }
            }
        }
        string ans = "";
        if(data[0] == "0")
            return "0";
        for(int i=0; i<data.size(); i++)
            ans += data[i];
        return ans;
    }
};
