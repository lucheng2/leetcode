#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size()<=0)
            return "";
        string longestPP = strs[0];
        for(int i=1; i<strs.size(); ++i) {
            int len = min(longestPP.size(), strs[i].size());
            int j;
            for(j=0; j<len; ++j) {
                if(strs[i][j] == longestPP[j]) {
                    continue;
                } else {
                    if(j==0) 
                        return "";
                    else
                        break;
                }
            }
            longestPP = longestPP.substr(0, min(j, len));
        }
        return longestPP;
    }
};

int main() {
	
	return 0;
}
