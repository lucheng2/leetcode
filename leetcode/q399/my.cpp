#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<unordered_map>

using namespace std;

class UnionSet {
public:
    vector<int> parent;
    vector<double> weight;

    UnionSet(int n) {
        parent.resize(n);
        weight.resize(n, 1.0);
        for(int i=0; i<n; ++i)
            parent[i] = i;
    }

    int find(int x) {
        if(x != parent[x]) {
            int origin = parent[x];
            parent[x] = find(parent[x]);
            weight[x] *= weight[origin];
        }
        return parent[x];
    }

    void unionSet(int x, int y, double value) {
        int px = find(x), py = find(y);
        if(px == py)
            return;
        weight[px] = value * weight[y] / weight[x];
        parent[px] = py;
    }

    double calculate(int x, int y) {
        int px = find(x), py = find(y);
        if(px != py)
            return -1.0L;
        return weight[x] / weight[y];
    }

};

class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        int n = equations.size();
        UnionSet us(2*n);
        unordered_map<string, int> hm;
        int id = 0;
        for( int i=0; i<n; ++i) {
            if(!hm.count(equations[i][0]))
                hm[equations[i][0]] = id++;
            if(!hm.count(equations[i][1]))
                hm[equations[i][1]] = id++;
            us.unionSet(hm[equations[i][0]], hm[equations[i][1]], values[i]);
        }
        vector<double> ans(queries.size(), -1.0L);
        for(int i=0; i<queries.size(); ++i) {
            if(hm.count(queries[i][0]) && hm.count(queries[i][1]))
                ans[i] = us.calculate(hm[queries[i][0]], hm[queries[i][1]]);
        }
        return ans;
    }
};

int main() {
	
	return 0;
}
