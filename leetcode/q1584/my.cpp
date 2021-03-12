#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

struct Edge {
    int len, x, y;
    Edge(int len, int x, int y) : len(len), x(x), y(y) {
    }
};

class DisUnionSet {
public:
    vector<int> parent, numCount;
    int n;
    DisUnionSet(int n): n(n) {
        numCount.resize(n, 1);
        parent.resize(n);
        for(int i=0; i<n; ++i) 
            parent[i] = i;
    }
    int find(int i) {
        if(i != parent[i]) 
            parent[i] = find(parent[i]);
        return parent[i];
    }
    bool unionSet(int x, int y) {
        int px = find(x), py = find(y);
        if(px == py)
            return false;
        if(numCount[px] <= numCount[py])
            swap(px, py);
        parent[py] = px;
        numCount[px] += numCount[py];
        return true;
    }
};

bool myLess(const Edge &a, const Edge &b) {
    return a.len< b.len;
}

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        vector<Edge> edges;
        int n = points.size();
        DisUnionSet dus(n);
        for(int i=0; i<n; i++)
            for(int j=i+1; j<n; j++)
                edges.push_back(Edge(distance(points[i], points[j]), i, j));
        sort(edges.begin(), edges.end(), myLess);
        int ans = 0, num = 1;
        for(auto edge: edges) {
            if(dus.unionSet(edge.x, edge.y)) {
                ans += edge.len;
                num ++;
                if(num == n)
                    return ans;
            }
        }
        return ans;
    }
    int distance(vector<int> x, vector<int> y) {
        return abs(x[0] - y[0]) + abs(x[1] - y[1]);
    }
};


    

int main() {
	
	return 0;
}
