#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>

using namespace std;

int myCmp(pair<string, int> &a, pair<string, int> &b) {
    if(a.second != b.second)
        return a.second > b.second;
    return a.first < b.first;
}

class Solution {
public:
    vector<vector<string> > topKstrings(vector<string>& strings, int k) {
        map<string, int> mp;
        for(auto s: strings) {
            mp[s] ++;
        }
        vector<pair<string, int>> data;
        for(auto it: mp) {
            data.push_back(make_pair(it.first, it.second));
        }
        sort(data.begin(), data.end(), myCmp);
        vector<vector<string>> ans;
        for(int i=0; i<k; i++) {
            ans.push_back({data[i].first, to_string(data[i].second)});
        }
        return ans;
    }
};
