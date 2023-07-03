#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size() == 0)
            return "";
        if(strs.size() == 1)
            return strs[0];
        int idx = 0;
        bool flag = true;
        while(flag) {
            if(strs[0].size() <= idx) {
                flag = false;
                break;
            }
            for(int i=1; i<strs.size(); i++) {
                if(strs[i].size() <= idx || strs[i][idx] != strs[0][idx]) {
                    flag = false;
                }
            }
            if(flag)
                idx ++;
        }
        return strs[0].substr(0, idx);
    }
};
