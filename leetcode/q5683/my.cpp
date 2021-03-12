#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<set>
#include<unordered_map>
#include<utility>
#include<map>

using namespace std;

class Solution {
public:
    vector<int> countPairs(int n, vector<vector<int>>& edges, vector<int>& queries) {
        //节点的度，deg[0]不要算进去了
        vector<int> deg(n+1, 0);
        for(int i=0; i<edges.size(); ++i) {
            deg[edges[i][0]] ++;
            deg[edges[i][1]] ++;
        }
        //边的计数，针对重边情况
        map<pair<int, int>, int> edgeCount;
        for(auto &e: edges) {
            if(e[0] > e[1])
                swap(e[0], e[1]);
            edgeCount[make_pair(e[0], e[1])] ++;
        }
        
        //经过排序后的度，方便用双指针找两个点的度之和 >  x的数量
        vector<int> sortedDeg = deg;
        //注意要把第一个排除掉
        sort(sortedDeg.begin() + 1, sortedDeg.end());
        vector<int> ret;
        for(int x: queries) {
            int ans = 0;
            // 双指针法计算度之和大于x的数量，当然有重复计数的以及不满足要求的，要依次减掉
            for(int i=1, j=sortedDeg.size() -1; i<sortedDeg.size(); ++i) {
                while(j>=1 && sortedDeg[i] + sortedDeg[j] > x) {
                    j --;
                }
                ans += sortedDeg.size() - 1 - j;
            }
            //删除节点自己与自己度和大于x的情况
            for(int i=0; i<n; ++i) {
                if(deg[i]*2 > x)
                    ans --;
            }
            //计算了2遍，除以2
            ans = (ans>>1);
            //删掉两个节点之间有边，边计算了两遍，使得度之和大于x的情况
            for(auto it: edgeCount) {
                if(deg[it.first.first] + deg[it.first.second] > x && deg[it.first.first] + deg[it.first.second] - it.second <= x) {
                    ans --;
                }
            }
            ret.push_back(ans);
        }
        return ret;
    }
};

int main() {
	
    vector<vector<int>> edges = {{1,2},{2,4}, {1,3}, {2,3}, {2,1}};
    vector<int> queries = {2,3};
    Solution s;
    vector<int> ans = s.countPairs(4,edges , queries);
	return 0;
}
