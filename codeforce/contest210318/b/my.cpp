#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;
int t;

int main() {
	
    cin>>t;
    while(t--) {
        string str;
        cin>>str;
        int index = 0;
        bool s11exist = false;
        bool s00exist = false;
        for( ;index<str.length() - 1; index++) {
            if(str.substr(index, 2) == "11") {
                s11exist = true;
                break;
            }
        }
        for( ; index<str.length() - 1; index++) {
            if(str.substr(index, 2) == "00") {
                s00exist = true;
            }
        }
        if(s11exist && s00exist) {
            cout<<"NO"<<endl;
        }
        else {
            cout<<"YES"<<endl;
        }
    }
	return 0;
}
