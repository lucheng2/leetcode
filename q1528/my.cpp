#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        string res(s);
        for(int i=0; i<indices.size(); ++i) {
            res[indices[i]] = s[i];
        }
        return res;
    }
};

int main() {
	
	return 0;
}
