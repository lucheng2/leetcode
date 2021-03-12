#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<set>
#include<unordered_map>

using namespace std;

class Solution {
public:
    vector<int> countPairs(int n, vector<vector<int>>& edges, vector<int>& queries) {

        unordered_map<int, multiset<int>> hm;
        vector<int> pairCount;
        vector<int> ans(queries.size(), 0);
        for(auto edge: edges) {
            hm[edge[0]].emplace(edge[1]);
            hm[edge[1]].emplace(edge[0]);
        }
        for(int i=1; i<=n; ++i) {
            for(int j=i+1; j<=n; ++j) {
                int count = 0;
                if(hm.count(i))
                    count += hm[i].size();
                if(hm.count(j)) {
                    count += hm[j].size();
                    count -= hm[j].count(i);
                }
                pairCount.emplace_back(count);
            }
        }
        sort(pairCount.begin(), pairCount.end());
        for(int i=0; i<queries.size(); ++i) {
            for(int j=0; j<pairCount.size(); j++) {
                if(pairCount[j] > queries[i]) {
                    ans[i] = pairCount.size() - j;
                    break;
                }
            }
        }
        return ans;
    }
};

int main() {
	
    vector<vector<int>> edges = {{1,2},{2,4}, {1,3}, {2,3}, {2,1}};
    vector<int> queries = {2,3};
    Solution s;
    vector<int> ans = s.countPairs(4,edges , queries);
	return 0;
}
