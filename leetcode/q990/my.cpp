#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
        int len = equations.size();
        vector<int> parent(26);
        for(int i=0; i<26; i++) {
           parent[i] = i; 
        }
        for(auto & str: equations)
            if(str[1] == '=')
                unionSet(parent, str[0] - 'a', str[3] - 'a');
        for( auto &str: equations)
            if(str[1] == '!')
                if(findParent(parent, str[0] -'a') == findParent(parent, str[3] - 'a'))
                    return false;
        return true;

    }
    int findParent(vector<int> &parent, int node) {
        if(parent[node] != node)
            parent[node] = findParent(parent, parent[node]);
        return parent[node];
    }
    void unionSet(vector<int> &parent, int x, int y) {
        parent[findParent(parent, x)] = findParent(parent, y);
    }
};

int main() {
	
	return 0;
}
