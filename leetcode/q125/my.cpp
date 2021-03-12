#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cctype>

using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        int pre = 0, lat = s.size() -1;
        while(pre < lat) {
            while(pre<lat && !isalnum(s[pre])) {
                pre ++;
            }
            while(pre< lat && !isalnum(s[lat]) ) {
                lat --;
            }
            if(pre < lat) {
                if(tolower(s[pre]) != tolower(s[lat])) {
                    return false;
                } 
            }
            pre++;
            lat--;
        }
        return true;
    }

};

int main() {
	
	return 0;
}
