#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<unordered_set>
#define ll long long

using namespace std;
int t, p, q;
int ans;

int bfs() {
    ans = 0;
    queue<int> que;
    unordered_set<int> visited;
    que.push(p);
    visited.insert(p);
    while(que.size()) {
        int len = que.size();
        for(int i=0; i<len; i++) {
            int tmp = que.front();
            que.pop();
            if(tmp == q)
                return ans;
            vector<int> c = {1, -1, -2, tmp};
            for(int i=0; i<4; i++) {
                int a = tmp + c[i];
                if(visited.find(a) != visited.end())
                    continue;
                if(a<=0)
                    continue;
                if(tmp>q && c[i]>0)
                    continue;
                visited.insert(a);
                que.push(a);
            }
        }
        ans ++;
    }
    return ans;
}

int main() {
    cin>>t;
    while(t>0) {
        t--;
        cin>>p>>q;
        int ans = bfs();
        cout<<ans<<endl;
    }
	return 0;
}
