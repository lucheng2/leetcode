#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string s1="", s2="";
        for(auto tmp: word1)
            s1 += tmp;
        for(auto tmp: word2)
            s2 += tmp;
        return s1 == s2;
    }
};

int main() {
	
	return 0;
}
