#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

class Solution {
public:
    int beautySum(string s) {
        int ans = 0;
        for(int i=0; i<s.size(); i++) {
            int hm[26];
            for(int j=0; j<26; ++j) {
                hm[j] = 0;
            }
            for(int j=i; j<s.size(); ++j) {
                hm[s[j] - 'a'] ++;
                int maxFreq = 0, minFreq = s.length();
                for(int x: hm) {
                    if(x>0) {
                        maxFreq = max(maxFreq, x);
                        minFreq = min(minFreq, x);
                    }
                }
                ans += maxFreq - minFreq;
            } 
        }
        return ans;
    }
};

int main() {
    string s = "aabcb";
    Solution slu;
    int res = slu.beautySum(s);
	return 0;
}
