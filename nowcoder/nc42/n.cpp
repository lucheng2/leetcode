#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> ans;
    vector<int> visited;
    vector<int> vec;

    void dfs(vector<int> &num) {
        if(vec.size() == num.size()) {
            ans.push_back(vec);
            return;
        }
        for(int i=0; i<num.size(); i++) {
            if(visited[i] || (i>0 && num[i]==num[i-1] && !visited[i-1]))
                continue;
            visited[i] = 1;
            vec.push_back(num[i]);
            dfs(num);
            vec.pop_back();
            visited[i] = 0;
        }
    }

    vector<vector<int> > permuteUnique(vector<int> &num) {
        visited.resize(num.size(), 0);
        sort(num.begin(), num.end());
        dfs(num);
        return ans;
    }
};
