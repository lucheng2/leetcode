#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<unordered_set>

using namespace std;

class Solution {
public:
    int numJewelsInStones(string J, string S) {
        unordered_set<char> hs;
        for(auto c: J)
            hs.insert(c);
        int res = 0;
        for(auto c: S)
            if (hs.find(c) != hs.end())
                res++;
        return res;
    }
};

int main() {
	
	return 0;
}
