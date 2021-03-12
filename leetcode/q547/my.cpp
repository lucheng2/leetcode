#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int cites = isConnected.size();
        vector<int> parent(cites);
        for(int i=0; i<cites; ++i) {
            parent[i] = i;
        }
        for(int i=0; i<cites; ++i) 
            for(int j=i+1; j<cites; ++j) {
                if(isConnected[i][j] == 1)
                    unionSet(parent, i, j);
            }
        int provience = 0;
        for(int i=0; i<cites; ++i)
            if(i == findParent(parent, i))
                provience ++;
        return provience;

    }
    int findParent(vector<int> &parent, int node) {
        if(parent[node] != node) {
            parent[node] = findParent(parent, parent[node]);
        }
        return parent[node];
    }
    void unionSet(vector<int> &parent, int x, int y) {
        parent[findParent(parent, x)] = findParent(parent, y);
    }
};

int main() {
	
	return 0;
}
