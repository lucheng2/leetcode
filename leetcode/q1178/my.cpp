#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<unordered_map>

using namespace std;

class Solution {
public:
    vector<int> findNumOfValidWords(vector<string>& words, vector<string>& puzzles) {
        unordered_map<int, int> wordFrequent;
        for(const string &word: words) {
            int mask = 0;
            for(char c: word)
                mask = mask | (1<<(c-'a'));
            if(countOne(mask)<=7)
                wordFrequent[mask]++;
        }
        vector<int> ans;
        for(const string puzzle: puzzles) {
            int count = 0;
            
            int mask = 0;
            for(int i=1; i<7; ++i)
                mask = mask | (1<<(puzzle[i] - 'a'));
            int subset = mask;
            do {
                int s = subset | (1<<(puzzle[0] - 'a'));
                if(wordFrequent.count(s))
                    count += wordFrequent[s];
                subset = (subset -1) & mask;
            } while(subset != mask);
            ans.push_back(count);
        }
        return ans;
    }

    int countOne(int value) {
        int count = 0;
        while(value!=0) {
            if(value&1)
                count++;
            value = value >> 1;
        }
        return count;
    }
};

int main() {
    Solution s;
    printf("%d\n", s.countOne(7));
    
	return 0;
}
