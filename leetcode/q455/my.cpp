#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int j=0, count=0;
        for(int i=0; i<g.size(); ++i) {
            for( ; j<s.size(); ++j) {
                if(s[j] >= g[i]) {
                    count++;
                    ++j; 
                    break;
                }
            }
        }
        return count;
    }
};

int main() {
	
	return 0;
}
