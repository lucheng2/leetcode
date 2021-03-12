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
        return longestCP(strs, 0, strs.size() - 1);
    }

    string longestCP(const vector<string> &strs, int start, int end) {
        if(start==end) {
            return strs[start];
        }
        else {
            int mid = (start + end) /2;
            string pre = longestCP(strs, start, mid);
            string lat = longestCP(strs, mid+1, end);
            return commonPrefix(pre, lat);
        }
    }

    string commonPrefix(string s1, string s2) {
        int len = min(s1.length(), s2.length());
        int i;
        for(i=0; i<len; ++i) {
            if(s1[i] == s2[i]) 
                continue;
            else 
                break;
        }
        return s1.substr(0, min(i, len));
    }
};

int main() {
	
	return 0;
}
