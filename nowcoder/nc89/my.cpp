#include<string>
#include<iostream>

using namespace std;

class Solution {
public:
    string trans(string s, int n) {
        int rr = n, ll;
        string ans;
        while(rr>0) {
            ll = rr - 1;
            while(ll >= 0 && s[ll] != ' ') {
                ll --;
            }
            for(int start=ll+1; start<rr; start++) {
                if(s[start] >= 'a' && s[start] <= 'z') {
                    ans.push_back(s[start]-'a' + 'A');
                } 
                if(s[start] >= 'A' && s[start] <= 'Z') {
                    ans.push_back(s[start] - 'A' + 'a');
                }
            }
            if(ll>=0)
                ans.push_back(s[ll]);
            rr = ll;
        }
        return ans;
    }
};


int main() {
    string s = "This is a sample";
    Solution sl;
    string ans = sl.trans(s, s.size()); 
    string std = "SAMPLE A IS tHIS";
    cout<<(ans == std)<<endl;
    return 0;
}
