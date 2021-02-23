#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<stack>
#include<unordered_map>
#include<unordered_set>

using namespace std;

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<string, char> sc;
        unordered_map<char, string> cs;
        int m = s.length();
        int i=0;
        for (auto c: pattern) {
            if(i>=m)
                return false;
            int j=i;
            while (j<m && s[j] != ' ')
                j++;
            const string &tmp = s.substr(i, j-i);
            if (sc.count(tmp) && sc[tmp] != c)
                return false;
            if (cs.count(c) && cs[c] != tmp)
                return false;
            sc[tmp] = c;
            cs[c] = tmp;
            i = j+1;
        }
        return i>=m;
    }
};

int main() {
	Solution s;
    string pattern = "abba", str = "dog cat cat dog";
    bool r = s.wordPattern(pattern, str);
    printf("%d, ", r);
	return 0;
}
