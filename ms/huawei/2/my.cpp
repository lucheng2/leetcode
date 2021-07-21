#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<set>
#include<algorithm>
#define ll long long

using namespace std;

int main() {
    // string s;
    //getline(cin, s);
    char s[100];
    cin.getline(s, 100);
    set<char> yuan = {'a', 'e', 'i', 'o', 'u'};
    set<char> fu = {'B', 'C', 'D', 'F', 'G', 'H', 'J', 'K', 'L', 'M', 'N', 'P', 'Q', 'R', 'S', 'T', 'V', 'W', 'X', 'Y', 'Z'};
    // int n = s.length();
    int n = strlen(s);
    for(int i=0; i<n; i++) {
        if(s[i] == ' ')
            continue;
        else if(yuan.find(s[i]) != yuan.end()) {
            s[i] = s[i] - 'a' + 'A';
        }
        else if(fu.find(s[i]) != fu.end()) {
            s[i] = s[i] - 'A' + 'a';
        }
    }
    cout<<s<<endl;
	
	return 0;
}
