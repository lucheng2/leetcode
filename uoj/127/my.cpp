#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<unordered_map>

using namespace std;

int find(vector<int> &parent, int x) {
    if(parent[x] != x)
        parent[x] = find(parent, parent[x]);
    return parent[x];
}

void unionSet(vector<int> &parent, int x, int y) {
    int px = find(parent,x), py = find(parent, y);
    if(px == py)
        return;
    parent[px] = py;
}

int main() {
	int t, n;
    vector<int> parent;
    vector<vector<int>> data;
    scanf("%d", &t);
    vector<string> res(t);
    for(int i=0; i<t; ++i) {
        unordered_map<int, int> hm;
        scanf("%d", &n);
        data.resize(n, vector<int>(3));
        for(int j=0; j<n; ++j)
            scanf("%d %d %d", &data[j][0], &data[j][1], &data[j][2]);
        int id =0;
        // 用hash表映射id
        for(int j=0; j<n; ++j) {
            if(!hm.count(data[j][0]))
                hm[data[j][0]] = id++;
            if(!hm.count(data[j][1]))
                hm[data[j][1]] = id++;
        }
        parent.resize(id);
        for(int j=0; j<id; ++j)
            parent[j] = j;
        for(int j=0; j<n; ++j) {
            if(data[j][2] == 1)
                unionSet(parent, hm[data[j][0]], hm[data[j][1]]);
        }
        for(int j=0; j<n; ++j) {
            if(data[j][2] == 0) {
                if(find(parent, hm[data[j][0]]) == find(parent, hm[data[j][1]])) {
                    res[i] = "NO";
                    break;
                }
            }
        }
        if(res[i] != "NO")
            res[i] = "YES";
    }
    for(int i=0; i<t; i++)
        cout<<res[i]<<endl;

	return 0;
}
