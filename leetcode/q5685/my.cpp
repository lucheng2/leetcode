#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int n1 = word1.length(), n2 = word2.length();
        int n = min(n1, n2);
        string ans = "";
        for(int i=0; i<2*n; i++) {
            if(i%2==0) {
                ans += word1[i/2];
            } else {
                ans += word2[i/2];
            }
        }
        if(n == n2) {
            ans += word1.substr(n, n1 - n);
        } else {
            ans += word2.substr(n, n2 - n);
        }
        return ans;
    }
};

int main() {
	
	return 0;
}
