#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define ll long long 

using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if(!next_permutation(nums.begin(), nums.end())) {
            sort(nums.begin(), nums.end());
        }
    }
};
