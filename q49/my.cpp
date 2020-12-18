#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<unordered_map>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
		unordered_map<string, vector<string>> m;
		for (string &str: strs) {
			string key = str;
			sort(key.begin(), key.end());
			m[key].emplace_back(str);
		}
		vector<vector<string>> ans;
		for (auto it= m.begin(); it!=m.end(); it++) {
			ans.emplace_back(it->second);
		}
		return ans;
    }
};

int main() {
	
	Solution s;
	vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
	vector<vector<string>> ans = s.groupAnagrams(strs);
	for(auto i: ans) {
		for (auto j: i)
		//	cout<<j<<" ";
			printf("%s ", j.c_str());
		printf("\n");
	}
	return 0;
}
