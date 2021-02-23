#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> largeGroupPositions(string s) {
        vector<vector<int>> res;
        if(s.length()<3)
            return res;
        int i,j;
        for(i=0; i<=s.length()-3;) {
            for( j=i+1; j<s.length(); ++j) {
                if(s[i] != s[j])
                    break;
            }
            if(j-i>=3) {
                vector<int> tmp = {i, j-1};
                res.emplace_back(tmp);
            }
            i = j;
        }
        return res;
    }
};

int main() {
	
	return 0;
}
