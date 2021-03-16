#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cctype>
#include<queue>
#define N 128

using namespace std;
string s;
char str[N];
string ans;
vector<string> vec;

bool isGoodWord(string s) {
    if(s.size()<=1) 
        return false;
    if(!isupper(s[0]))
        return false;
    for(int i=1; i<s.size(); ++i) {
        if(!islower(s[i])) {
            return false;
        }
    }
    return true;
}
string line;
int main() {
    while(getline(cin, line)) {
        s = line;
        for(int i=0; i<s.length(); ++i) {
            if(isalpha(s[i])) {
                int j=i+1;
                while(j<s.length() && isalpha(s[j])) {
                    j++;
                }
                vec.push_back(s.substr(i, j-i));
                i = j-1;
            }
            else{
                vec.push_back(s.substr(i, 1));
            }
        }
        vec.push_back("@@");
    }
    for(int i=0; i<vec.size(); ++i) {
        if(isGoodWord(vec[i])) {
            int j = i+1;
            int count = 1;
            string akd = vec[i].substr(0, 1);
            for( ; j<vec.size(); ++j) {
                if(vec[j] == " " || vec[j] == "@@") {
                    continue;
                }
                if(!isGoodWord(vec[j])) {
                    break;
                }
                count++;
                akd += vec[j].substr(0, 1);
            }
            if(count>=2) {
                vec[i] = akd+" ("+ vec[i];
                while(j>i) {
                    if(isGoodWord(vec[j])) {
                        vec[j] += ")";
                        break;
                    }
                    j--;
                }
            }
            i = j;
        }
    }
    string ans;
    for(int i=0; i<vec.size(); i++) {
        if(vec[i] == "@@") {
            printf("\n");
        } else {
            cout<<vec[i];
        }
    }
	
	return 0;
}
