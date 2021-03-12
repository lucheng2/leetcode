#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<unordered_map>

using namespace std;
class Solution {
public:
    vector<int> parent;

    int find(int x) {
        if(x != parent[x])
            parent[x] = find(parent[x]);
        return parent[x];
    }

    void unionSet(int x, int y) {
        int px = find(x), py = find(y);
        if(px == py)
            return;
        parent[px] = py;
    }

    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        if(pairs.size() == 0)
            return s;
        int n = s.length();
        parent.resize(n);
        for(int i=0; i<n; ++i)
            parent[i] = i;

        for(auto pair: pairs)
            unionSet(pair[0], pair[1]);

        unordered_map<int, vector<char> > hm;
        for(int i=0; i<s.length(); ++i) {
            hm[find(i)].push_back(s[i]);
        }
        for(auto it=hm.begin(); it!=hm.end(); ++it)
            sort(it->second.begin(), it->second.end(), greater<char>());
        for(int i=0; i<s.length(); ++i) {
            s[i] = hm[find(i)].back();
            hm[find(i)].pop_back();
        }
        return s;
    }
};

int main() {
    string s = "dcab";
    vector<vector<int>> pairs = {{0,3}, {1,2}, {0,2}};
    Solution slu;
    string res = slu.smallestStringWithSwaps(s, pairs);
	
	return 0;
}
