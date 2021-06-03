#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>

using namespace std;

class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        map<int, int> mp;
        for(auto log: logs) {
            for(int i=log[0]; i<log[1]; i++) {
                mp[i] ++;
            }
        }
        auto ans = mp.begin();
        for(auto it=mp.begin(); it!=mp.end(); it++) {
            if(it->second>ans->second) {
                ans = it;
            }
        }
        return ans->first;
    }
};

int main() {
	
	return 0;
}
