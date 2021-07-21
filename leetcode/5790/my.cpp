#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define ll long long 

using namespace std;

class Solution {
public:
    int cnt[100005][101];
    vector<int> minDifference(vector<int>& nums, vector<vector<int>>& queries) {
        for(int i=1; i<=nums.size(); i++) {
            for(int j=1; j<=100; j++)
                cnt[i][j] = cnt[i-1][j];
            cnt[i][nums[i-1]] ++;
        }
        vector<int> ans;
        for(int i=0; i<queries.size(); i++) {
            int l=queries[i][0], r=queries[i][1];
            int least=-1e9, anss=1e9;
            for(int j=1; j<=100; j++) {
                if(cnt[r+1][j]!=cnt[l][j]) {
                    anss = min(anss, j-least);
                    least = j;
                }
            }
            ans.push_back(anss==1e9? -1 : anss);
        }
        return ans;
    }
};
