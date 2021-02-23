#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
class Solution {
public:
    string reverseLeftWords(string s, int n) {
        return s.substr(n, s.length() - n) + s.substr(0, n);
    }
};

int main() {
    string s = "abcedf";
    Solution sl;
    string r = sl.reverseLeftWords(s, 2);
    printf("%s", r.c_str());
	return 0;
}
