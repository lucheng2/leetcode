#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<unordered_map>

using namespace std;

class Solution {
public:
    int countMatches(vector<vector<string>>& items, string ruleKey, string ruleValue) {
        int index = 0;
        if(ruleKey == "color")
            index = 1;
        if(ruleKey == "name")
            index = 2;
        unordered_map<string, int> hm;
        for(auto item: items) {
            hm[item[index]] ++;
        }
        if(hm.count(ruleValue))
            return hm[ruleValue];
        return 0;
    }
};

int main() {
	
	return 0;
}
