#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<unordered_map>

using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int len = s1.length();
        if(len<=0) 
            return true;
        if(len > s2.length())
            return false;
        unordered_map<int,int> hm;
        for(auto c:s1)
            hm[c-'a']++;
        for(int i=0; i<len; ++i)
            hm[s2[i] - 'a'] --;
        if(check(hm))
            return true;
        for(int j=0; j<s2.length() -len; j++) {
            hm[s2[j] -'a'] ++;
            hm[s2[j+len] -'a'] --;
            if(check(hm))
                return true;
        }
        return false;

    }
    bool check(unordered_map<int, int> &hm) {
        for(auto it: hm)
            if(it.second !=0)
                return false;

        return true;
    }
};

int main() {
	
	return 0;
}
