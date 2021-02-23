#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

class Solution {
public:
    char findTheDifference(string s, string t) {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        int i;
        for(i=0; i<s.length(); i++) {
            if(s[i] != t[i])
                return t[i];
        }
        return t[i];
    }
};

int main() {
    string s="abcd", t="abcde";
    Solution sl;
    char r = sl.findTheDifference(s,t);
    printf("%c,", r);
	return 0;
}
