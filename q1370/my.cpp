#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>
using namespace std;

class Solution {
public:
    string sortString(string s) {
        map<char, int> hm1;
        for(auto c: s) {
            hm1[c]++;
        }
        string ans = "";
        while(!hm1.empty()) {
            for(auto it=hm1.begin(); it!=hm1.end(); ) {
                ans.append(1, it->first);
                if(it->second<=1) {
                    hm1.erase(it++);
                } else {
                    it->second --;
                    it++;
                }
            }
            for(auto it=hm1.rbegin(); it!=hm1.rend(); ) {
                ans.append(1, it->first);
                it->second --; 
                it++;
            }
            for(auto it=hm1.begin(); it!=hm1.end();) 
                if(it->second<=0)
                    hm1.erase(it++);
                else
                    it++;
        }
        return ans;
    }
};

int main() {
    Solution sl;
    string s = "aaaabbbbcccc";
    string res = sl.sortString(s);
    printf("%s", res.c_str());    
	return 0;
}
