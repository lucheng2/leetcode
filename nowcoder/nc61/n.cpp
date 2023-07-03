#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        unordered_map<int, int> hm;
        for(int i=0; i<numbers.size(); i++) {
            if(hm.find(target - numbers[i]) != hm.end()) {
                return {hm[target-numbers[i]]+1, i + 1};
            }
            hm[numbers[i]] = i;
        }
        return {};
    }
};
