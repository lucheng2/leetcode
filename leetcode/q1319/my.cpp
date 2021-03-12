#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

class Solution {
public:
    vector<int> parent;
    
    int find(int x) {
        if(parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

    void unionSet(int x, int y) {
        int px = find(x), py = find(y);
        if(px == py)
            return;
        else
            parent[px] = py;
    }

    int makeConnected(int n, vector<vector<int>>& connections) {
        int wireNum = connections.size();
        if(wireNum < n -1)
            return -1;
        parent.resize(n);
        for(int i=0; i<n; ++i)
            parent[i] = i;

        for(auto connection: connections) {
            unionSet(connection[0], connection[1]);
        }
        int countRoot = 0;
        for(int i=0; i<n; ++i) {
            if(i == find(i))
                countRoot ++;
        }
        return countRoot - 1;
    }
};

int main() {
	
	return 0;
}
