#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<unordered_set>

using namespace std;

class Solution {
public:
    unordered_set<char> hs = {'a','e', 'i', 'o', 'u', 'A', 'E','I', 'O', 'U'};
    bool halvesAreAlike(string s) {
        int len = s.length();
        int count[2] = {0};
        int i=0;
        for(; i<len/2; ++i) {
            if(hs.find(s[i]) != hs.end()) {
               count[0]++;
            }
        }
        for(; i<len; ++i)
            if(hs.find(s[i]) != hs.end())
                count[1]++;
        return count[0]==count[1];
    }
};

int main() {
	
	return 0;
}
