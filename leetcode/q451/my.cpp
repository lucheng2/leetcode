#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<unordered_map>
#include<map>
#define ll long long 

using namespace std;

class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> hm;
        for(int i=0; i<s.length(); i++)
            hm[s[i]] ++;
        map<int, vector<char>, greater<int>> srt;
        for(auto it: hm) {
            srt[it.second].push_back(it.first);
        }
        string ans;
        for(auto it: srt) {
            for(auto itc: it.second)
                ans.append(it.first, itc);
        }
        return ans;
    }
};
