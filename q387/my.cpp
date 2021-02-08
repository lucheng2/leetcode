#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<unordered_map>

using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> hm;
        for(auto c: s)
            hm[c]++;
        for(int i=0; i<s.length(); ++i) {
            if(hm[s[i]]==1) {
                return i;
            }
        } 
        return -1;
    }
};

int main() {
	
	return 0;
}
