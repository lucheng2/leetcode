#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<string>
using namespace std;

class Solution {
public:
    string reformatNumber(string number) {
        for(auto it=number.begin(); it!=number.end(); ) {
            if(*it==' ' || *it=='-') {
                it = number.erase(it);
            }
            else {
                it++;
            }
        }
        int len = number.size();
        if(len%3==0 || len%3==2) {
            for(int i=3; i<number.size(); i+=4)
                number.insert(i, "-");
        } else if(len%3==1) {
            for(int i=3; i<number.size()-2; i+=4)
                number.insert(i, "-");
            number.insert(number.size()-2, "-");
        }
        return number;
    }
};

int main() {
    string number = "--17-5 229 35-39475 ";
    Solution s;
    string res = s.reformatNumber(number);
    printf("%s", res.c_str());
	
	return 0;
}
