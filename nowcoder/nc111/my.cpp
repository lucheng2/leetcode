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
        for(int i=0; i<data.size(); i++) {
            for(int j=i+1; j<data.size(); j++) {
                if(data[i]+data[j] < data[j]+data[i])
                    swap(data[i], data[j]);
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
