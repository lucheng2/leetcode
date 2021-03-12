#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()) {
            return false;
        }
        int hm[26];
        for(int i=0; i<26; ++i)
            hm[i] = 0;
        for(char c: s) {
            hm[c - 'a'] ++;
        }
        for(char c: t) {
            hm[c - 'a'] --;
        }
        for(int i=0; i<26; ++i) {
            if(hm[i] != 0) {
                return false;
            }
        }
        return true;
    }
};

int main() {
	
	return 0;
}
