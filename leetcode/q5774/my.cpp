#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#define ll long long 

using namespace std;

class Solution {
public:
    struct node1{
        int w, id, tm;
        bool operator < (const node1 &a) const {
            if(tm != a.tm)
                return tm > a.tm;
            if(w != a.w)
                return w > a.w;
            return id > a.id;
        }
    };

    struct node2{
        int w, id, tm;
        bool operator < (const node2 &a) const {
            if(w != a.w)
                return w > a.w;
            return id > a.id;
        }
    };

    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        priority_queue<node1> heap1;
        priority_queue<node2> heap2;
        vector<int> ans;
        for(int i=0; i<servers.size(); i++) {
            heap2.push({servers[i], i, 0});
        }
        for(int i=0; i<tasks.size(); i++) {
            int x = tasks[i];
            while(heap1.size() && heap1.top().tm <= i) {
                auto &s = heap1.top();
                heap2.push({s.w, s.id, s.tm});
                heap1.pop();
            }
            if(heap2.size()) {
                auto &s = heap2.top();
                heap1.push({s.w, s.id, i+x});
                ans.push_back(s.id);
                heap2.pop();
            }
            else  {
                auto s = heap1.top();
                heap1.pop();
                heap1.push({s.w, s.id, s.tm+x});
                ans.push_back(s.id);
            }
        }
        return ans;
    }
};
