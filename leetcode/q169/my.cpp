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
        int key = nums[0], cnt = 1;
        for(int i=1; i<nums.size(); i++) {
            if(nums[i] == key) {
                cnt ++;
            }
            else if(cnt > 0) {
                cnt --;
            }
            else {
                key = nums[i];
                cnt = 1;
            }
        }
        return key;
    }
};
