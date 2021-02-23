#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
		bool hs[26] = {false};
		int len = allowed.size();
		for(int i=0; i<len; i++) {
			hs[allowed[i] - 'a'] = true;
		}
		int count = 0;
		for(int i=0; i<words.size(); i++) {
			int j;
			for(j=0; j<words[i].size(); j++) {
				if(!hs[words[i][j] - 'a']) {
					break;
				}
			}
			if(j>=words[i].size()) {
				count++;
			}
		}
		return count;
    }
};

int main() {
	Solution s;
	string test = "ab";
	vector<string> words = {"ad", "bd", "aaab", "baa", "badab"};
	int r = s.countConsistentStrings(test, words);
	printf("%d\n", r);
	return 0;
}
