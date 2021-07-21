#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<set>
#include<map>
#define ll long long 

using namespace std;

class Solution {
public:
    vector<vector<string>> displayTable(vector<vector<string>>& orders) {
        map<int, map<string, int>> hm;
        set<string> st;
        for(int i=0; i<orders.size(); i++) {
            st.insert(orders[i][2]);
            hm[stoi(orders[i][1])][orders[i][2]] ++;
        }
        vector<vector<string>> ans(hm.size() + 1);
        ans[0].push_back("Table");
        for(auto food: st) {
            ans[0].push_back(food);
        }
        int idx = 0;
        for(auto it: hm) {
            idx ++;
            ans[idx].push_back(to_string(it.first));
            for(auto food: st) {
                string tmp = it.second.count(food)? to_string(it.second[food]) : "0";
                ans[idx].push_back(tmp);
            }
        }
        return ans;
    }
};
