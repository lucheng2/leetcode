#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<unordered_map>
#include<queue>
#include<climits>

using namespace std;

vector<int> Dijsktra(int n, int start, unordered_map<int, unordered_map<int, int>> & graph) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> dis(n + 1, INT_MAX);
    vector<bool> visited(n, false);
    dis[start] = 0;
    pq.push({0, start});
    while(!pq.empty()) {
        int u = pq.top().second, d = pq.top().first;
        pq.pop();
        if(visited[u]) {
            continue;
        }
        visited[u] = true;
        for(auto it : graph[u]) {
            int v = it.first, weight = it.second;
            if(dis[v] > dis[u] + weight) {
                dis[v] = dis[u] + weight;
                pq.push({dis[v], v});
            }
        }
    }
    return dis;
}

void split(const string s, const string c, vector<string>& ret) {
    string::size_type last, index;
    last = 0;
    index = s.find(c);
    while(index != string::npos) {
        ret.push_back(s.substr(last, index-last));
        last = index + c.size();
        index = s.find(c, last);
    }
    if(last != s.length())
        ret.push_back(s.substr(last));
}

unordered_map<int, unordered_map<int, int>> graph;

string input;
int w[100005];

int main() {
    cin>>input;
    vector<string> ret;
    split(input, ",", ret);
    for(auto i: ret)
        cout<<i<<endl;
	return 0;
}


