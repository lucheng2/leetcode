#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;
char com[2001];
char first[2001];
char second[2001];
string scom;
int main() {
    vector<string> filename;
    int n;
    scanf("%d", &n);
    for(int i=0; i<n; i++) {
        scanf("%s", com);
        scom = string(com);
        if(scom == "touch") {
            scanf(" %s", first);
            string tmp = string(first);
           bool flag = true;

           for(int j=0; j<filename.size(); j++) {
               if(filename[i]==tmp) {
                   flag = false;
                   break;
               }
           }
           if(flag)
               filename.emplace_back(tmp);
        }
        else if(scom == "rm") {
            scanf(" %s", first);
            string tmp = string(first);
            for(int j=0; j<filename.size(); j++) {
               if(filename[j]==tmp) {
                   filename.erase(filename.begin() + j);
               }
           }

        }
        else if(scom == "ls") {
            for(auto f:filename) {
                printf("%s\n", f.c_str());
            }
        }
        else if(scom == "rename") {
            scanf(" %s", first);
            scanf(" %s", second);
            string tmp = string(first);
            string tmp2 = string(second);
            for(int j=0; j<filename.size(); j++ ){
                if(filename[j] == tmp)
                    filename[j] = tmp2;
            }
        }
    }
	
	return 0;
}
