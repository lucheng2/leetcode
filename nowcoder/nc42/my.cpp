#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int> > permuteUnique(vector<int> &num) {
        vector<vector<int>> ans;
        sort(num.begin(), num.end());
        do {
            ans.push_back(num);
        } while(next_permutation(num.begin(), num.end()));
        return ans;
    }
};
