#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        string disc = "1", mid;
        for(int i=1; i<n; ++i) {
            for(int j=0; j<disc.size(); ) {
                int k = j+1;
                int count = 1;
                while(k<disc.size() && disc[j] == disc[k]) {
                    k++;
                    count ++;
                }
                mid.push_back(count + '0');
                mid.push_back(disc[j]);
                j = k;
            }
            disc = mid;
            mid.clear();
        }
        return disc;
    }
};

int main() {
    Solution s;
    string ans = s.countAndSay(4);
	return 0;
}
