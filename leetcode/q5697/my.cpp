#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

class Solution {
public:
    bool checkOnesSegment(string s) {
        int i = 0;
        while(i<s.size()) {
            if(s[i] == '0')
                break;
            i++;
        }
        if(i>=s.size()) {
            return true;
        }
        i++;
        while(i<s.size()) {
            if(s[i] == '1')
                return false;
            i++;
        }
        return true;
    }
};

int main() {
	
	return 0;
}
